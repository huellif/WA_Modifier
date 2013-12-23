#include "helper.h"

//native Popups:
#include <aknnotewrappers.h>
#include <akndiscreetpopup.h>

//File operations:
#include <bautils.h>
#include <f32file.h>

//Clear AknIconSrv cache
#include <akniconconfig.h>

//native Reboot API
#include <starterclient.h>

_LIT(path, "C:\\system\\data\\whatsapp_notifier.rsc");
_LIT(c, "C:\\resource\\apps\\whatsapp_aif.mif");
_LIT(e, "E:\\resource\\apps\\whatsapp_aif.mif");
_LIT(f, "F:\\resource\\apps\\whatsapp_aif.mif");

void Helper::launch() const
{
    RProcess proc;
    User::LeaveIfError(proc.Create(_L("WhatsApp.exe"),KNullDesC));
    proc.Resume();
    proc.Close();
}

void Helper::close(bool hidden)
{
    TBool running = EFalse;
    TFullName res;
    TFindProcess find;
    while(find.Next(res) == KErrNone) {
        RProcess ph;
        User::LeaveIfError( ph.Open(res) );
        if(ph.SecureId() == 0x2002B30D)
        if (ph.ExitType() == EExitPending) {
            running = ETrue;
            break;
        }
        ph.Close();
    }

    if (!running) {
        if (!hidden){
            TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Error")), (_L("WhatsApp isn't running.")),KAknsIIDNone, KNullDesC, 0, 0, 0x00000001));
        }
    }
    else {
        CAknConfirmationNote* killed = new (ELeave) CAknConfirmationNote;
        QT_TRAP_THROWING(killed->ExecuteLD(_L("Closed WhatsApp.")));

        kill(_L("*[2002B306]*"));
        kill(_L("*[2002B310]*"));
        kill(_L("*[2002B30D]*"));
    }
}

void Helper::hide()
{
    close(true);
    reset();
    CAknConfirmationNote* hidden = new (ELeave) CAknConfirmationNote;
    QT_TRAP_THROWING(hidden->ExecuteLD(_L("Disabled the popup.")));

    RFs fsSession;
    CleanupClosePushL(fsSession);
    User::LeaveIfError(fsSession.Connect());

    RFile rFile;
    User::LeaveIfError(rFile.Create(fsSession, path, EFileRead));
    rFile.Close();

    User::LeaveIfError(fsSession.SetAtt(path ,KEntryAttHidden|KEntryAttSystem,KEntryAttArchive));
    CleanupStack::PopAndDestroy(&fsSession);
}

void Helper::reset() const
{
    RFs fsSession;
    CleanupClosePushL(fsSession);
    User::LeaveIfError(fsSession.Connect());

    if (BaflUtils::FileExists(fsSession, path)){
        User::LeaveIfError(fsSession.SetAtt(path, KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden));
        CFileMan* fileMan=CFileMan::NewL(fsSession);
        CleanupStack::PushL(fileMan);
        fileMan->Delete(path);
        CleanupStack::PopAndDestroy(fileMan);
    }

    CleanupStack::PopAndDestroy(&fsSession);
}

void Helper::resetNote()
{
    close(true);
    reset();

    CAknConfirmationNote* note = new (ELeave) CAknConfirmationNote;
    QT_TRAP_THROWING(note->ExecuteLD(_L("Enabled the popup.")));
}

void Helper::note() const
{
    TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Info:")), (_L("You have to enable Open4All patch!")),KAknsIIDNone, KNullDesC, 0, 0, 0x00000001));
}

void Helper::icon(QString mif) const
{
    RFs fsSession;
    CleanupClosePushL(fsSession);
    User::LeaveIfError(fsSession.Connect());
    fsSession.SetAtt(c,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
    fsSession.SetAtt(e,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
    fsSession.SetAtt(f, KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);

    CFileMan* fileMan=CFileMan::NewL(fsSession);
    CleanupStack::PushL(fileMan);
    fileMan->Delete(c);
    fileMan->Delete(e);
    fileMan->Delete(f);

    QString path = "E:\\icons\\" + mif + ".mif";
    TPtrC16 ipath(reinterpret_cast<const TUint16*>(path.utf16()));

    fileMan->Copy(ipath,c);
    fileMan->Copy(ipath,e);
    fileMan->Copy(ipath,f);

    CleanupStack::PopAndDestroy(2);

    QString newmif = "Copied " + mif + ".mif";
    TPtrC16 note(reinterpret_cast<const TUint16*>(newmif.utf16()));
    TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Done.")), note ,KAknsIIDNone, KNullDesC, 0, 0, 0x00000001));
}

void Helper::del() const
{
    RFs fsSession;
    CleanupClosePushL(fsSession);
    User::LeaveIfError(fsSession.Connect());
    fsSession.SetAtt(c,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
    fsSession.SetAtt(e,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
    fsSession.SetAtt(f,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);

    CFileMan* fileMan=CFileMan::NewL(fsSession);
    CleanupStack::PushL(fileMan);
    fileMan->Delete(c);
    fileMan->Delete(e);
    fileMan->Delete(f);

    CleanupStack::PopAndDestroy(2);

    CAknConfirmationNote* note = new (ELeave) CAknConfirmationNote;
    QT_TRAP_THROWING(note->ExecuteLD(_L("Removed all whatsapp_aif.mif files.")));
}

void Helper::reboot() const
{
    RStarterSession starter;
    User::LeaveIfError(starter.Connect());
    starter.Reset(RStarterSession::ELanguageSwitchReset);
    starter.Close();
}

void Helper::clear() const
{
    close(false);
    AknIconConfig::EnableAknIconSrvCache(EFalse);
    AknIconConfig::EnableAknIconSrvCache(ETrue);

    CAknConfirmationNote* note = new (ELeave) CAknConfirmationNote;
    QT_TRAP_THROWING(note->ExecuteLD(_L("Done. Cleared icon cache. Re-add the icon to homescreen to show the new one.")));
}

void Helper::kill(const TPtrC &UID) const
{
    TFullName res;
    TFindProcess find(UID);
    while(find.Next(res) == KErrNone){
        RProcess ph;
        ph.Open(find);
        ph.Kill(KErrNone);
        ph.Close();
    }
}
