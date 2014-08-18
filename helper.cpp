#include "helper.h"

//native Popups:
#include <aknnotewrappers.h>
#include <akndiscreetpopup.h>
#include <AknGlobalNote.h>

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

void Helper::close() const
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

    if (!running)
    {
        TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Error")), (_L("WhatsApp isn't running.")),KAknsIIDNone, KNullDesC, 0, 0, 0x00000001));

    }

    else
    {
        CAknGlobalNote* note = CAknGlobalNote::NewLC();
        TRequestStatus iStatus2;
        note->ShowNoteL(iStatus2, EAknGlobalConfirmationNote, _L("Closed WhatsApp."));

        kill(_L("*[2002B306]*"));
        kill(_L("*[2002B310]*"));
        kill(_L("*[2002B30D]*"));

        User::WaitForRequest(iStatus2);
        CleanupStack::PopAndDestroy(note);
    }
}

void Helper::note() const
{
    TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Info:")), (_L("You have to enable Open4All patch!")),KAknsIIDNone, KNullDesC, 0, 0, 0x00000001));
}

void Helper::icon(const QString &mif) const
{
    if(remove())
    {
        RFs fsSession;
        CleanupClosePushL(fsSession);
        User::LeaveIfError(fsSession.Connect());
        CFileMan* fileMan = CFileMan::NewL(fsSession);
        CleanupStack::PushL(fileMan);

        TPtrC16 ipath(reinterpret_cast<const TUint16*>(QString("E:\\icons\\" + mif + ".mif").utf16()));

        TBool success = EFalse;
        if(fileMan->Copy(ipath,c) == KErrNone) success = ETrue;
        if(fileMan->Copy(ipath,e) == KErrNone) success = ETrue;
        if(fileMan->Copy(ipath,f) == KErrNone) success = ETrue;

        CleanupStack::PopAndDestroy(fileMan);
        CleanupStack::PopAndDestroy(&fsSession);

        if(success)
        {
            CAknGlobalNote* note = CAknGlobalNote::NewLC();
            TRequestStatus iStatus2;
            note->ShowNoteL(iStatus2,
                            EAknGlobalConfirmationNote,
                            TPtrC16 (reinterpret_cast<const TText*>(QString("Copied " + mif + ".mif").constData()))
                            );
            User::WaitForRequest(iStatus2);
            CleanupStack::PopAndDestroy(note);
        }
        else
        {
            error();
        }
    }
}

void Helper::del() const
{
    if(!remove()) return;
    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus2;
    note->ShowNoteL(iStatus2, EAknGlobalConfirmationNote, _L("Removed all whatsapp_aif.mif files."));

    User::WaitForRequest(iStatus2);
    CleanupStack::PopAndDestroy(note);
}

void Helper::reboot() const
{
    RStarterSession starter;
    User::LeaveIfError(starter.Connect());
    starter.Reset(RStarterSession::ELanguageSwitchReset);
    starter.Close();
}

void Helper::clear()
{
    AknIconConfig::EnableAknIconSrvCache(EFalse);
    AknIconConfig::EnableAknIconSrvCache(ETrue);

    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus2;
    note->ShowNoteL(iStatus2, EAknGlobalConfirmationNote, _L("Done. Cleared icon cache. Re-add the icon to homescreen to show the new one."));

    User::WaitForRequest(iStatus2);
    CleanupStack::PopAndDestroy(note);
}

TAny Helper::kill(const TDesC &process) const
{
    TFullName res;
    TFindProcess find(process);
    while(find.Next(res) == KErrNone)
    {
        RProcess ph;
        User::LeaveIfError(ph.Open(find));
        ph.Kill(KErrNone);
        ph.Close();
    }
}

TBool Helper::remove() const
{
    TBool status = EFalse;
    RFs fsSession;
    CleanupClosePushL(fsSession);
    User::LeaveIfError(fsSession.Connect());

    if(BaflUtils::FileExists(fsSession, _L("Z:\\sys\\bin\\avkon.dll")))
    {

        fsSession.SetAtt(c,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
        fsSession.SetAtt(e,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
        fsSession.SetAtt(f,KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);

        CFileMan* fileMan=CFileMan::NewL(fsSession);
        CleanupStack::PushL(fileMan);

        fileMan->Delete(c);
        fileMan->Delete(e);
        fileMan->Delete(f);

        CleanupStack::PopAndDestroy(fileMan);

        status = ETrue;
    }
    else
    {
        error();
    }
    CleanupStack::PopAndDestroy(&fsSession);
    return status;
}

TAny Helper::error() const
{
    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus2;
    note->ShowNoteL(iStatus2,
                    EAknGlobalErrorNote,
                    _L("An error occurred, please enable Open4All.")
                    );

    User::WaitForRequest(iStatus2);
    CleanupStack::PopAndDestroy(note);
}
