symbian {
TARGET.UID3 = 0xE3359D3D

my_deployment.pkg_prerules += vendorinfo
DEPLOYMENT += my_deployment addFiles
DEPLOYMENT.display_name += WA_Modifier
vendorinfo += "%{\"huellif\"}" ":\"huellif\""
VERSION = 1.7.0
TARGET.CAPABILITY += PowerMgmt WriteDeviceData
LIBS += -lavkon -lefsrv -lbafl -laknicon -lStarterClient
ICON += WAModifier.svg

addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXblack.mif\" - \"E:\\icons\\BelleXblack.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXblue.mif\" - \"E:\\icons\\BelleXblue.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXdefault.mif\" - \"E:\\icons\\BelleXdefault.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXgreen.mif\" - \"E:\\icons\\BelleXgreen.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXred.mif\" - \"E:\\icons\\BelleXred.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BelleXwhite.mif\" - \"E:\\icons\\BelleXwhite.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BlackBerry.mif\" - \"E:\\icons\\BlackBerry.mif\""
addFiles.pkg_postrules += "\"C:\\workspace\\WA_Modifier\\mifs\\BlackBerry_flat.mif\" - \"E:\\icons\\BlackBerry_flat.mif\""
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

CONFIG += qt-components

QT += declarative

OTHER_FILES += qml/*.*

RESOURCES += QRC.qrc

HEADERS += \
    helper.h

SOURCES += \
    main.cpp \
    helper.cpp


MMP_RULES += "OPTION gcce -O3"
MMP_RULES += "OPTION gcce -march=armv6"
MMP_RULES += "OPTION gcce -mfpu=vfp"
MMP_RULES += "OPTION gcce -mfloat-abi=softfp"
MMP_RULES += "OPTION gcce -marm"
MMP_RULES += "OPTION gcce -fpermissive"
#MMP_RULES += "OPTION gcce -w"
MMP_RULES += "OPTION gcce -ffast-math"

DEFINES += QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS QT_NO_CAST_TO_ASCII
DEFINES *= QT_USE_QSTRINGBUILDER
