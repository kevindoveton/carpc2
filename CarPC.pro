QT += qml quick location sql core

CONFIG += c++11

SOURCES += src/main.cpp \
    src/CPP/Music/MusicAlbum.cpp \
    src/CPP/Music/Music.cpp \
    src/CPP/Music/Player.cpp \
    src/CPP/Music/MusicArtist.cpp \
    src/CPP/SystemVolume/SystemVolume.cpp \
    src/CPP/Music/MusicSong.cpp
RESOURCES += \
    resources/resources.qrc \
    src/QML/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
#QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/qtquickcontrols2.conf \
    src/Header.qml \
    src/main.qml \
    src/Sidebar.qml \
    src/VerticalLine.qml \
    src/Maps.qml \
    src/Music.qml \
    src/Phone.qml \
    src/MenuModel.qml \
    resources/icons/camera.png \
    resources/icons/contacts.png \
    resources/icons/maps.png \
    resources/icons/messages.png \
    resources/icons/music.png \
    resources/icons/phone.png \
    src/AppStack.qml \
    src/MainMenu.qml \
    src/QML/qtquickcontrols2.conf \
    src/QML/Apps/Maps/Maps.qml \
    src/QML/Apps/Music/Music.qml \
    src/QML/Apps/Phone/Phone.qml \
    src/QML/Menu/Header.qml \
    src/QML/Menu/MainMenu.qml \
    src/QML/Menu/MenuModel.qml \
    src/QML/Utilities/Sidebar.qml \
    src/QML/Utilities/VerticalLine.qml \
    src/QML/main.qml \
    src/QML/Utilities/Classes.qml \
    src/QML/Apps/Music/MusicArtistComponent.qml \
    src/QML/Apps/Music/MusicAlbumComponent.qml \
    src/QML/Apps/Music/MusicSongComponent.qml

HEADERS += \
    src/CPP/Music/MusicAlbum.h \
    src/CPP/Music/Music.h \
    src/CPP/Music/MusicArtist.h \
    src/CPP/Music/Player.h \
    src/CPP/SystemVolume/SystemVolume.h \
    src/CPP/Music/MusicSong.h

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += alsa
unix: PKGCONFIG += libvlc
