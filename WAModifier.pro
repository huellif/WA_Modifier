QT += declarative
symbian {
#free UID from 0xE range
TARGET.UID3 = 0xE3359D3D

#adding information for .sis
my_deployment.pkg_prerules += vendorinfo
DEPLOYMENT += my_deployment addFiles
DEPLOYMENT.display_name += WA_Modifier
vendorinfo += "%{\"huellif\"}" ":\"huellif\""
VERSION = 1.3.1
TARGET.CAPABILITY += PowerMgmt #to kill processes and reboot the phone
LIBS += -lavkon -lefsrv -lbafl -apgrfx.lib #needed Symbian libs

#adding files to E:\icons in .sis
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXblack.mif\" - \"E:\\icons\\BelleXblack.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXblue.mif\" - \"E:\\icons\\BelleXblue.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXdefault.mif\" - \"E:\\icons\\BelleXdefault.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXgreen.mif\" - \"E:\\icons\\BelleXgreen.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXred.mif\" - \"E:\\icons\\BelleXred.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXwhite.mif\" - \"E:\\icons\\BelleXwhite.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BlackBerry.mif\" - \"E:\\icons\\BlackBerry.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BlackViral.mif\" - \"E:\\icons\\BlackViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BlueStyle.mif\" - \"E:\\icons\\BlueStyle.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BlueViral.mif\" - \"E:\\icons\\BlueViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\ChocViral.mif\" - \"E:\\icons\\ChocViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\Default.mif\" - \"E:\\icons\\Default.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\DefaultViral.mif\" - \"E:\\icons\\DefaultViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\GoldViral.mif\" - \"E:\\icons\\GoldViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\GreenViral.mif\" - \"E:\\icons\\GreenViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\GreenViral2.mif\" - \"E:\\icons\\GreenViral2.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\MagentaViral.mif\" - \"E:\\icons\\MagentaViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\NewStyle.mif\" - \"E:\\icons\\NewStyle.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\PurpleViral.mif\" - \"E:\\icons\\PurpleViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\RedViral.mif\" - \"E:\\icons\\RedViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\Transparent.mif\" - \"E:\\icons\\Transparent.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\TransViral.mif\" - \"E:\\icons\\TransViral.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\Weed.mif\" - \"E:\\icons\\Weed.mif\""
}

#embedding files into .exe
RESOURCES += QRC.qrc

#UI needs Symbian components
CONFIG += qt-components


#well the main code
SOURCES += main.cpp

#Symbian stuff
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

#helper class
HEADERS += helper.h

#show .qml fils only in QtCreator, not in .sis build
OTHER_FILES += qml/*.*

#to prevent compiler errors with popups and Belle SDK
gccOption = "OPTION gcce -fpermissive"
MMP_RULES += gccOption
