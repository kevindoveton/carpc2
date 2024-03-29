#include "Player.h"

Player::Player(QObject *parent) : QObject(parent) {
  _playing = false;
  _vlcInstance = libvlc_new(0, NULL);
  _vlcPlayer = NULL;
  _vlcMedia = NULL;
  return;
}

bool Player :: play() {
  return playPause(true);
}

bool Player :: pause() {
  return playPause(false);
}

bool Player :: playPause(bool play) {
  if (_playing == play) {
    return _playing;
  }

  if (_vlcPlayer == NULL) {
    return false;
  }

  if (play == true) {
    libvlc_media_player_play(_vlcPlayer);
  } else {
    if (libvlc_media_player_can_pause(_vlcPlayer)) {
      libvlc_media_player_pause(_vlcPlayer);
    } else {
      libvlc_media_player_stop(_vlcPlayer);
    }
  }

  _playing = play;
  emit playingChanged();
  return _playing;
}

bool Player :: playPause() {
  return playPause(!_playing);
}

void Player :: setSongPath(QString songPath) {
  if (_songPath == songPath) {
    qDebug() << "AHHH";
    play();
    return;
  }

  if (_playing)
    pause();

  _songPath = songPath;
  qDebug() << _songPath;
  std::string path = _songPath.toStdString();

  _vlcMedia = libvlc_media_new_path(_vlcInstance, &path[0]);
  _vlcPlayer = libvlc_media_player_new_from_media(_vlcMedia);

  libvlc_media_release(_vlcMedia);

  play();

  emit songPathChanged();
  return;
}
