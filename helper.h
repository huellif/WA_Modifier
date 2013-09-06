#ifndef HELPER_H
#define HELPER_H
#include <QObject>
#include <QString>
#include <QUrl>
#include <QDir>
#include <QFile>
#include <QtCore>
#include <QProcess>
#include <QApplication>

//Symbian headers
#include <aknnotewrappers.h>
#include <aknglobalnote.h>
#include <e32base.h>
#include <bautils.h>
#include <f32file.h>
#include <apgtask.h>
#include <eikenv.h>
#include <akndiscreetpopup.h>

class Helper : public QObject
{
    Q_OBJECT
public:
    Helper(QObject *parent = 0) : QObject(parent){ }


    Q_INVOKABLE void launch() //launching WhatsApp
    {        
        QProcess *myP = new QProcess;
        myP->start("WhatsApp.exe");
    }


    Q_INVOKABLE void close2() //closing WhatsApp and show a note if it doesn't run
    {
    bool running = false;


        TFullName res;
        TFindProcess find;
        while(find.Next(res) == KErrNone)
        {
            RProcess ph;
            ph.Open(res);

            if(ph.SecureId() == 0x2002B30D)

            if (ph.ExitType() == EExitPending)
            {
                running = true;
                break;
            }

            ph.Close();
        }

    if (running == false)
    {
        TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Error")), (_L("WhatsApp doesn't run.")),KAknsIIDNone, KNullDesC, 0, 0, KAknDiscreetPopupDurationLong));
    }
    else
    {

        CAknConfirmationNote* run = new (ELeave) CAknConfirmationNote;
        QT_TRAP_THROWING(run->ExecuteLD(_L("Closed WhatsApp.")));

        TFullName res1;
        TFindProcess find1(_L("*[2002B306]*"));
        while(find1.Next(res1) == KErrNone)
        {
            RProcess ph1;
            ph1.Open(find1);
            ph1.Kill(KErrNone);
            ph1.Close();
        }

        TFullName res2;
        TFindProcess find2(_L("*[2002B310]*"));
        while(find2.Next(res2) == KErrNone)
        {
            RProcess ph2;
            ph2.Open(find2);
            ph2.Kill(KErrNone);
            ph2.Close();
        }

        TFullName res3;
        TFindProcess find3(_L("*[2002B30D]*"));
        while(find3.Next(res3) == KErrNone)
        {
            RProcess ph3;
            ph3.Open(find3);
            ph3.Kill(KErrNone);
            ph3.Close();
        }
        }
    }


    Q_INVOKABLE void close() //close WhatsApp, if it's running
    {
    bool running = false;


        TFullName res;
        TFindProcess find;
        while(find.Next(res) == KErrNone)
        {
            RProcess ph;
            ph.Open(res);

            if(ph.SecureId() == 0x2002B30D)

            if (ph.ExitType() == EExitPending)
            {
                running = true;
                break;
            }

            ph.Close();
        }

    if (running == false)
    {        
    }
    else
    {

        CAknConfirmationNote* run = new (ELeave) CAknConfirmationNote;
        QT_TRAP_THROWING(run->ExecuteLD(_L("Closed WhatsApp.")));
        TFullName res1;
        TFindProcess find1(_L("*[2002B306]*"));
        while(find1.Next(res1) == KErrNone)
            {
                    RProcess ph1;
                    ph1.Open(find1);
                    ph1.Kill(KErrNone);
                    ph1.Close();
            }

        TFullName res2;
        TFindProcess find2(_L("*[2002B310]*"));
        while(find2.Next(res2) == KErrNone)
            {
                RProcess ph2;
                ph2.Open(find2);
                ph2.Kill(KErrNone);
                ph2.Close();
            }

        TFullName res3;
        TFindProcess find3(_L("*[2002B30D]*"));
        while(find3.Next(res3) == KErrNone)
            {
                RProcess ph3;
                ph3.Open(find3);
                ph3.Kill(KErrNone);
                ph3.Close();
            }
        }
    }


    Q_INVOKABLE void hide(){ //copy the fake .rsc to C:\system\data and set it ReadOnly

            CAknConfirmationNote* noteConfirm = new (ELeave) CAknConfirmationNote;
            QT_TRAP_THROWING(noteConfirm->ExecuteLD(_L("Disabled the popup.")));
            QFile::copy(":/whatsapp_notifier.rsc", "C://system/data/whatsapp_notifier.rsc");
            RFs fsSession;
            fsSession.Connect();
            fsSession.SetAtt((_L("C:\\system\\data\\whatsapp_notifier.rsc")),KEntryAttReadOnly,KEntryAttHidden);
            fsSession.Close();
        }


    Q_INVOKABLE void reset() //reset the attributes of the .rsc and remove it
        {
            RFs fsSession;
            fsSession.Connect();
            fsSession.SetAtt((_L("C:\\system\\data\\whatsapp_notifier.rsc")),KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem);
            fsSession.Close();
            QDir *myDir = new QDir;
            myDir->remove("C://system/data/whatsapp_notifier.rsc");
         }

    Q_INVOKABLE void resetNote() //note for enabling the popup
    {
        CAknConfirmationNote* noteConfirm = new (ELeave) CAknConfirmationNote;
        QT_TRAP_THROWING(noteConfirm->ExecuteLD(_L("Enabled the popup.")));
    }

    Q_INVOKABLE void note() //info when opening .mif changer
    {
        TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Info:")), (_L("You have to enable Open4All patch!")),KAknsIIDNone, KNullDesC, 0, 0, KAknDiscreetPopupDurationLong));
    }

    Q_INVOKABLE void icon(QString mif) //change the current icon. QString mif is generated by the mif changer dialog,
    {
        RFs fsSession;
        fsSession.Connect();
        fsSession.SetAtt((_L("C:\\resource\\apps\\whatsapp_aif.mif")),KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem);
        fsSession.SetAtt((_L("E:\\resource\\apps\\whatsapp_aif.mif")),KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem);
        fsSession.SetAtt((_L("F:\\resource\\apps\\whatsapp_aif.mif")),KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem);

        QDir *delFile2 = new QDir;
        delFile2->remove("C://resource/apps/whatsapp_aif.mif");
        delFile2->remove("E://resource/apps/whatsapp_aif.mif");
        delFile2->remove("F://resource/apps/whatsapp_aif.mif");

        QString path = "E:\\icons\\" + mif + ".mif";
        TPtrC16 ipath(reinterpret_cast<const TUint16*>(path.utf16()));

        CFileMan* fileMan=CFileMan::NewL(fsSession);
        fileMan->Copy(ipath,(_L("C:\\resource\\apps\\whatsapp_aif.mif")));
        fileMan->Copy(ipath,(_L("E:\\resource\\apps\\whatsapp_aif.mif")));
        fileMan->Copy(ipath,(_L("F:\\resource\\apps\\whatsapp_aif.mif")));
        fsSession.Close();

        TRAP_IGNORE(CAknDiscreetPopup::ShowGlobalPopupL((_L("Done.")), (_L("Copied new .mif file.")),KAknsIIDNone, KNullDesC, 0, 0, KAknDiscreetPopupDurationLong));
    }

    Q_INVOKABLE void remove(){ //remove all WhatsApp .mif files

        RFs fsSession;
        fsSession.Connect();
        fsSession.SetAtt((_L("C:\\resource\\apps\\whatsapp_aif.mif")),KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem);
        fsSession.SetAtt((_L("E:\\resource\\apps\\whatsapp_aif.mif")),KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem);
        fsSession.SetAtt((_L("F:\\resource\\apps\\whatsapp_aif.mif")),KEntryAttNormal,KEntryAttReadOnly | KEntryAttSystem);
        fsSession.Close();

        QDir *delFile2 = new QDir;
        delFile2->remove("C://resource/apps/whatsapp_aif.mif");
        delFile2->remove("E://resource/apps/whatsapp_aif.mif");
        delFile2->remove("F://resource/apps/whatsapp_aif.mif");

        CAknConfirmationNote* noteConfirm5 = new (ELeave) CAknConfirmationNote;
        QT_TRAP_THROWING(noteConfirm5->ExecuteLD(_L("Removed all whatsapp_aif.mif fils.")));
    }

    Q_INVOKABLE void reboot(){
        TFullName res2;
        TFindProcess find2(_L("*[100058F3]*"));
        while(find2.Next(res2) == KErrNone)
            {
                RProcess ph2;
                ph2.Open(find2);
                ph2.Kill(KErrNone);
                ph2.Close();
            }
    }
};

#endif // HELPER_H
