QT += widgets

# FFMPEG INCLUDE PATH
INCLUDEPATH += /usr/local/include

# FFMPEG LIBRARIES INCLUDED
LIBS += /usr/local/lib/libavdevice.dylib
LIBS += /usr/local/lib/libavformat.dylib
LIBS += /usr/local/lib/libavutil.dylib
LIBS += /usr/local/lib/libavcodec.dylib
LIBS += /usr/local/lib/libavfilter.dylib
LIBS += /usr/local/lib/libswscale.dylib


SOURCES = main.cpp \
    screengrabber.cpp \
    ofxFFMPEGVideoWriter.cpp
RESOURCES = animatedtiles.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/animation/animatedtiles
INSTALLS += target

HEADERS += \
    screengrabber.h \
    View.h \
    ofxFFMPEGVideoWriter.h

CONFIG += console
