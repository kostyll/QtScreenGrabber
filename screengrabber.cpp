#include "screengrabber.h"

ScreenGrabber::ScreenGrabber(QWidget *parent) :
    QWidget(parent)
{
    isRecording = false;
    frameNumber = 0;
}

void ScreenGrabber::setup(int w, int h){
    width = w;
    height = h;
    fileName = "";
    frameNumber = 0;
}

void ScreenGrabber::setup(QString fName, int w, int h){
    width = w;
    height = h;
    fileName = fName;
    frameNumber = 0;

    videoWriter.setup(fileName.toLatin1(), width, height);
}

void ScreenGrabber::startRecording(){
    if(fileName.isEmpty())
        showFileDialog();

    if (!fileName.isEmpty()) {
        isRecording = true;

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(saveScreen()));
        timer->start(1000/25);

        qDebug() << "Started recording to "<< fileName;
    }

}


void ScreenGrabber::startRecording(int seconds){
    if(fileName.isEmpty())
        showFileDialog();

    if (!fileName.isEmpty()) {
        isRecording = true;

        timer  = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(saveScreen()));
        timer->start(1000/25);

        mTimer = new QTimer(this);
        mTimer->setSingleShot(true);
        connect(mTimer, SIGNAL(timeout()), SLOT(stopRecording()));
        mTimer->start(seconds*1000);

        qDebug() << "Started recording to "<< fileName;
    }
}

void ScreenGrabber::showFileDialog(){
    QString initialPath = QDir::currentPath();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), initialPath, tr("%1 Files (*.%2);;All Files (*)")
                                                    .arg("mpg")
                                                    .arg("mpg"));
    this->fileName = fileName;
    videoWriter.setup(fileName.toLatin1(), this->width, this->height);
}


int ScreenGrabber::getWidth(){
    return width;
}

int ScreenGrabber::getHeight(){
    return height;
}

int ScreenGrabber::getFrameNumber(){
    return frameNumber;
}

QImage ScreenGrabber::getImage(){
    return originalImage;
}

void ScreenGrabber::setPixmapSourceWidget(QWidget *w ){
    pixmapSourceWidget = w;
}

void ScreenGrabber::saveScreen(){
    frameNumber++;
    //    qDebug() << "Screen saved " << frameNumber;
    setPixmap();
    pixmapToImage();
    if(isRecording && frameNumber>1) {
        videoWriter.addFrame((const uint8_t*) originalImage.bits());
    }
}

void ScreenGrabber::pixmapToImage() {
    QImage img = originalPixmap.toImage();
    originalImage = img.convertToFormat(QImage::Format_RGB888);
}



void ScreenGrabber::stopRecording(){
    frameNumber = 0;
    isRecording= false;
    videoWriter.close();
    timer->stop();
    qDebug() << "Stopped recording, closing the video file.";
}

void ScreenGrabber::setPixmap(){
    originalPixmap = QPixmap();
    originalPixmap = pixmapSourceWidget->grab();
}
