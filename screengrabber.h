#ifndef SCREENGRABBER_H
#define SCREENGRABBER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsView>
#include <QDir>
#include <QTime>
#include <QProcess>
#include <QWidget>
#include <QScreen>
#include <QFileDialog>


#include "View.h"
#include "ofxFFMPEGVideoWriter.h"


class ScreenGrabber : public QWidget
{
    Q_OBJECT

public:

    explicit ScreenGrabber(QWidget *parent = 0);
    void setup(QString fileName, int width, int height);
    void setup(int width, int height);

    int getFrameNumber();
    int getWidth();
    int getHeight();
    bool isRecording;

    QImage getImage();

    void setPixmapSourceWidget(QWidget *widget);
    void setPixmap();

private:

    QWidget *pixmapSourceWidget;

    QString fileName;
    int width;
    int height;

    QPixmap originalPixmap;
    QImage originalImage;

    ofxFFMPEGVideoWriter videoWriter;


    int frameNumber;

    QTimer *timer;
    QTimer *mTimer;

    void showFileDialog();
    void pixmapToImage();


signals:

public slots:
    void startRecording();
    void startRecording(int seconds);
    void saveScreen();
    void stopRecording();

};

#endif // SCREENGRABBER_H
