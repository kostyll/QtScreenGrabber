QtScreenGrabber
================

QtScreenGrabber is a Qt example (tested with 5.3) that enables user to record any QWidget (with it's dynamic content) as a video file. Rather than using an external screen recording software, this can be done through code without major performance decrease.

The example is based on [Animated Tiles](http://qt-project.org/doc/qt-5/qtwidgets-animation-animatedtiles-example.html) example provided with Qt 5.3 examples.

It uses [ofxFFMPEGVideoWriter](http://www.morethantechnical.com/2013/04/11/simplified-ffmpeg-video-writer-also-for-openframework-w-code/) (by Roy Shil) which was initially developed as a screen recording addon for openFrameworks. Since it is not dependent on any openFrameworks core classes it was used as the main FFmpeg interface here.


Setup
------
* Install [Qt 5.3](http://qt-project.org/) and Qt Creator
* Compile and/or install [FFmpeg](https://www.ffmpeg.org/) as described [here](https://trac.ffmpeg.org/wiki/CompilationGuide/MacOSX)
* Open the animatedtiles.pro in Qt Creator, build and run

Issues
-----------
Check the `animatedtiles.pro` file for the `INCLUDEPATH` and `LIBS` variables. They should point to right FFmpeg include and library locations. Might be different depending on the OS.

TODO
-----------
* Add GLWidget support
