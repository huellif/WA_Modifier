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

void Helper::close(/*bool hidden*/)
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
        //if (!hidden){
            TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Error")), (_L("WhatsApp isn't running.")),KAknsIIDNone, KNullDesC, 0, 0, 0x00000001));
        //}
    }
    else {
        CAknGlobalNote* note = CAknGlobalNote::NewLC();
        TRequestStatus iStatus2;
        note->ShowNoteL(iStatus2, EAknGlobalConfirmationNote, _L("Closed WhatsApp."));
        kill(537047814);
        kill(537047824);
        kill(537047821);
        User::WaitForRequest(iStatus2);
        CleanupStack::PopAndDestroy(note);
    }
}

void Helper::hide()
{
    //close(true);
    reset();

    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus2;
    note->ShowNoteL(iStatus2, EAknGlobalConfirmationNote, _L("Disabled the popup."));
    User::WaitForRequest(iStatus2);
    CleanupStack::PopAndDestroy(note);


    //fileserver stuff
    RFs fsSession;
    CleanupClosePushL(fsSession);
    User::LeaveIfError(fsSession.Connect());

    //creating an empty file
    RFile rFile;
    User::LeaveIfError(rFile.Create(fsSession, path, EFileRead));
    rFile.Close();

    //setting file attributes
    User::LeaveIfError(fsSession.SetAtt(path, KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden, KEntryAttNormal));

    //no memory leaks so far
    CleanupStack::PopAndDestroy(&fsSession);
}

void Helper::reset() const
{
    //fileserver stuff
    RFs fsSession;
    CleanupClosePushL(fsSession);
    User::LeaveIfError(fsSession.Connect());

    //check if the file exits or not
    if (BaflUtils::FileExists(fsSession, path)){
        User::LeaveIfError(fsSession.SetAtt(path, KEntryAttNormal, KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden));
        CFileMan* fileMan=CFileMan::NewL(fsSession);
        CleanupStack::PushL(fileMan);
        fileMan->Delete(path);
        CleanupStack::PopAndDestroy(fileMan);
    }

    CleanupStack::PopAndDestroy(&fsSession);
}

void Helper::resetNote()
{
    //close(true);
    reset();
    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus2;
    note->ShowNoteL(iStatus2, EAknGlobalConfirmationNote, _L("Enabled the popup."));
    User::WaitForRequest(iStatus2);
    CleanupStack::PopAndDestroy(note);
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
    fsSession.SetAtt(c, KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
    fsSession.SetAtt(e, KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);
    fsSession.SetAtt(f, KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem | KEntryAttHidden);

    CFileMan* fileMan = CFileMan::NewL(fsSession);
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
    //close(false);
    AknIconConfig::EnableAknIconSrvCache(EFalse);
    AknIconConfig::EnableAknIconSrvCache(ETrue);

    CAknGlobalNote* note = CAknGlobalNote::NewLC();
    TRequestStatus iStatus2;
    note->ShowNoteL(iStatus2, EAknGlobalConfirmationNote, _L("Done. Cleared icon cache. Re-add the icon to homescreen to show the new one."));

    User::WaitForRequest(iStatus2);
    CleanupStack::PopAndDestroy(note);
}

void Helper::kill(const int &a) const
{
    TInt ret = KErrNone;

    TFullName pName;
    TFindProcess finder(_L("*"));

    TUid tUid = {a};

    while((ret = finder.Next(pName)) == KErrNone)
    {
        if (pName == KNullDesC)
            break;

        RProcess process;
        ret = process.Open(pName);
        if (ret != KErrNone)
            return;

        if (tUid == process.Type()[2])
        {
            process.Kill(0);
            process.Close();
            break;
        }

        process.Close();
    }
}
