#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QDebug>
#include <QUrl>
#include "Music.h"
#include <vlc/vlc.h>

class Player : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool playing READ playing NOTIFY playingChanged)
    Q_PROPERTY(QString songPath READ songPath WRITE setSongPath NOTIFY songPathChanged)
  public:
    explicit Player(QObject *parent = nullptr);

    Q_INVOKABLE bool play();
    Q_INVOKABLE bool pause();
    Q_INVOKABLE bool playPause(bool play);

    bool playing() { return _playing; }
    QString songPath() { return _songPath; }
    void setSongPath(QString songPath);

  protected:
    bool _playing;
    QString _songPath;
    libvlc_instance_t *_vlcInstance;
    libvlc_media_player_t *_vlcPlayer;
    libvlc_media_t *_vlcMedia;

  signals:
    void playingChanged();
    void songPathChanged();

  public slots:

};

#endif // PLAYER_H
