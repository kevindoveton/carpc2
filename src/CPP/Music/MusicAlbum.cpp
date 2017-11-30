#include "MusicAlbum.h"

MusicAlbum::MusicAlbum(unsigned int id, QString name, QString genre,
                       unsigned int year, QString imagePath,
                       unsigned int artistId, QObject *parent)
                       : QObject(parent) {
  _id = id;
  _name = name;
  _genre = genre;
  _year = year;
  _imagePath = "file:"+imagePath;
  _artistId = artistId;
  return;
}
