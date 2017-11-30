#include "MusicSong.h"

MusicSong::MusicSong(unsigned int id, QString name, QString path,
                     unsigned int albumId, unsigned int artistId,
                     QObject *parent) : QObject(parent) {
  _id = id;
  _name = name;
  _path = path;
  _albumId = albumId;
  _artistId = artistId;
  return;
}
