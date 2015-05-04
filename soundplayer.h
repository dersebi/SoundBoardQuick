#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QObject>
#include <QMap>

class QMediaPlayer;

class SoundPlayer : public QObject
{
    Q_OBJECT

public:
    explicit SoundPlayer(QObject *parent = 0);
    ~SoundPlayer();

    void loadSamples(const QString &baseDir);

signals:
    void deactivateButton(int number);
    void buttonPlaying(int number, bool playing);
    void buttonSetText(int number, QString text);

public slots:
    void startSample(int number);
    void toggleLoop();

private:
    QMap<int,QMediaPlayer*> _samples;
    bool                    _loop;
};

#endif // SOUNDPLAYER_H
