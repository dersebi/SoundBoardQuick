#include "soundplayer.h"

#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QCoreApplication>
#include <QMimeDatabase>
#include <QMediaPlayer>

SoundPlayer::SoundPlayer(QObject *parent) : QObject(parent),
    _loop(false)
{
}

SoundPlayer::~SoundPlayer()
{
}

void SoundPlayer::startSample(int number)
{
    if(_samples.contains(number))
    {
        QMediaPlayer* smp = _samples.value(number);
        if(smp->state() == QMediaPlayer::PlayingState)
        {
            smp->stop();
        }
        else
        {
            smp->setPosition(0);
            smp->play();
        }
    }
    else
    {
        qDebug() << "sound effect for this button not loaded!";
    }
}

void SoundPlayer::toggleLoop()
{
    _loop = !_loop;
}

void SoundPlayer::loadSamples(const QString& baseDir)
{
    _samples.clear();

    QDir samplesDir(QString("%1sounds").arg(baseDir));
    int counter = 0;
    for(QString entry : samplesDir.entryList(QStringList() << "*.mp3" << "*.wav" << "*.ogg" << "*.m4a", QDir::Files | QDir::Readable, QDir::Name | QDir::IgnoreCase))
    {
        counter++;
        if(counter > 16)
            break;
        QString fileName = samplesDir.filePath(entry);
        QMimeDatabase mdb;
        QMimeType mime = mdb.mimeTypeForFile(fileName);
        if(QMediaPlayer::hasSupport(mime.name()) == QMultimedia::NotSupported)
        {
            counter--;
            continue;
        }
        QMediaPlayer* sample = new QMediaPlayer(this, QMediaPlayer::LowLatency);
        sample->setMedia(QUrl::fromLocalFile(fileName));
        //check if sample is valid
        //FIXME: invalid files are still not detected!
        if(sample->error() != QMediaPlayer::NoError)
        {
            counter--;
            continue;
        }
        sample->setVolume(100);
        connect(sample,&QMediaPlayer::stateChanged, [this,&sample,counter](QMediaPlayer::State state){
            if(state == QMediaPlayer::StoppedState)
            {
                if(this->_loop)
                {
                    //FIXME: This is not working correctly - crashes
                    sample->stop();
                    sample->setPosition(0);
                    sample->play();
                }
                else
                {
                    emit buttonPlaying(counter,false);
                }
            }
            else if(state == QMediaPlayer::PlayingState)
            {
                emit buttonPlaying(counter,true);
            }
        });
        QString buttonLabel = QFileInfo(fileName).baseName();
        if(buttonLabel.size() > 13)
            buttonLabel = buttonLabel.left(10) + "...";
        emit buttonSetText(counter,buttonLabel);
        _samples[counter] = sample;
    }
    for(int i=16;i>_samples.size();i--)
    {
        emit deactivateButton(i);
    }
}

