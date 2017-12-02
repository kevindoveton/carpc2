#include "Music.h"

Music::Music(QObject *parent) : QObject(parent) {

  dbPath = "/home/kdoveton/Desktop/resources/music/musicLibrary.sqlite3";
  _db = QSqlDatabase::addDatabase("QSQLITE");
  _db.setDatabaseName(dbPath);
  if (!_db.open()) {
    qWarning() << "Error: connection with database fail";
  } else {
    qDebug() << "Database: connection ok";
  }

  getAllArtists();

  QObject::connect(this, SIGNAL(currentSongChanged()), this, SLOT(updateNowPlaying()));

  return;
}

void Music :: getAllArtists() {
  QSqlQuery query("SELECT * FROM artists");
  int idName = query.record().indexOf("artistName");
  int idArtistId = query.record().indexOf("artistId");
  int idImagePath = query.record().indexOf("artistImagePath");
  while (query.next()) {
    int id = query.value(idArtistId).toInt();
    QString name = query.value(idName).toString();
    QString imagePath = query.value(idImagePath).toString();
    _artists.append(new MusicArtist(id, name, imagePath));
  }
}

void Music :: setCurrentArtist(unsigned int artistId) {
  if (_currentArtist == artistId) {
    return;
  }

  _currentArtist = artistId;
  qDeleteAll(_albums);
  _albums.clear();

  qDebug() << "Music :: setCurrentArtist()"
           << "Current artist: " << _currentArtist;

  QSqlQuery query;
  query.prepare("SELECT * FROM albums WHERE artistId = (:artistId)");
  query.bindValue(":artistId", artistId);
  if (query.exec()) {
    int idAlbumId = query.record().indexOf("albumId");
    int idName = query.record().indexOf("albumName");
    int idGenre = query.record().indexOf("albumName");
    int idYear = query.record().indexOf("albumName");
    int idImagePath = query.record().indexOf("albumImagePath");
    int idArtistId = query.record().indexOf("artistId");
    while (query.next()) {
      unsigned int id = query.value(idAlbumId).toInt();
      QString name = query.value(idName).toString();
      QString genre = query.value(idGenre).toString();
      unsigned int year = query.value(idYear).toInt();
      QString imagePath = query.value(idImagePath).toString();
      int artistId = query.value(idArtistId).toInt();
      qDebug() << "Music :: setCurrentArtist()"
               << "added album: " << id << "name: " << name;
      _albums.append(new MusicAlbum(id, name, genre, year, imagePath, artistId));
    }
  } else {
    qWarning() << "Music :: setCurrentArtist()"
               << "Failed to exec query, " << query.lastError();
  }

  emit albumsChanged();
  emit currentArtistChanged();
  return;
}

void Music :: setCurrentAlbum(unsigned int albumId) {
  if (_currentAlbum == albumId) {
    return;
  }

  _currentAlbum = albumId;
  qDeleteAll(_songs);
  _songs.clear();

 qDebug() << "Music :: setCurrentAlbum"
          << "Current album: " << _currentAlbum;

  QSqlQuery query;
  query.prepare("SELECT * from songs as s \
                INNER JOIN library as l on s.songId = l.songID \
                where s.albumId = (:albumId)");
  query.bindValue(":albumId", albumId);

  if (query.exec()) {
    int idSongId = query.record().indexOf("songId");;
    int idName = query.record().indexOf("songName");
    int idPath = query.record().indexOf("path");;
    int idAlbumId = query.record().indexOf("albumId");
//    int idArtistId = query.record().indexOf("artistId");
    while (query.next()) {
      unsigned int id = query.value(idSongId).toInt();
      QString name = query.value(idName).toString();
      QString path = query.value(idPath).toString();
      unsigned int albumId = query.value(idAlbumId).toInt();
//      unsigned int artistId = query.value(idArtistId).toInt();
      qDebug() << "Music :: setCurrentAlbum"
               << "added song: " << id << "name: " << name;
      _songs.append(new MusicSong(id, name, path, albumId, 0));
    }
  } else {
    qWarning() << "Music :: setCurrentAlbum()"
               << "Failed to exec query," << query.lastError();
  }

  emit songsChanged();
  emit currentAlbumChanged();
  return;
}

void Music :: setCurrentSong(unsigned int songId){
  _currentSong = songId;
  qDebug() << "Music :: setCurrentSong"
           << "Current song: " << _currentSong;
  emit currentSongChanged();
  return;
}

QObject* Music :: getCurrentArtist() {
  return getArtistById(_currentArtist);
}

QObject* Music :: getCurrentAlbum() {
  return getAlbumById(_currentAlbum);
}

QObject* Music :: getCurrentSong() {
  return getSongById(_currentSong);
}

QObject* Music :: getArtistById(unsigned int id) {
  if (_currentArtist == NULL) {
    qDebug() << "Music :: getArtistById"
             << "unable to return artist, none selected";
    return NULL;
  }

  for (int i = 0; i < _artists.count(); i++) {
    MusicArtist* n = dynamic_cast<MusicArtist*>(_artists[i]);
    if (n->id() == id) return _artists[i];
  }

  return NULL;
}

QObject* Music :: getAlbumById(unsigned int id) {
  if (_currentAlbum == NULL) {
    qDebug() << "Music :: getAlbumById"
             << "unable to return artist, none selected";
    return NULL;
  }

  for (int i = 0; i < _albums.count(); i++) {
    MusicAlbum* n = dynamic_cast<MusicAlbum*>(_albums[i]);
    if (n->id() == id) return _albums[i];
  }

  return NULL;
}

QObject* Music :: getSongById(unsigned int id) {
  if (_currentSong == NULL) {
    qDebug() << "Music :: getSongById"
             << "unable to return artist, none selected";
    return NULL;
  }

  for (int i = 0; i < _songs.count(); i++) {
    MusicSong* n = dynamic_cast<MusicSong*>(_songs[i]);
    if (n->id() == id) return _songs[i];
  }

  return NULL;
}

void Music :: updateNowPlaying() {

  emit nowPlayingChanged();
  return;
}
