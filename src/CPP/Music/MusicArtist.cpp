#include "MusicArtist.h"

MusicArtist::MusicArtist(unsigned int id, QString name, QString image, QObject *parent) : QObject(parent) {
    _id = id;
    _name = name;
    _image = "file:"+image;
    return;
}
