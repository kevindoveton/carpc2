#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

#include "MusicArtist.h"
#include "MusicAlbum.h"
#include "MusicSong.h"

class Music : public QObject
{
    Q_OBJECT

    Q_PROPERTY(unsigned int currentArtist READ currentArtist WRITE setCurrentArtist NOTIFY currentArtistChanged)
    Q_PROPERTY(unsigned int currentAlbum READ currentAlbum WRITE setCurrentAlbum NOTIFY currentAlbumChanged)
    Q_PROPERTY(unsigned int currentSong READ currentSong WRITE setCurrentSong NOTIFY currentSongChanged)


    Q_PROPERTY(QList<QObject*> artists READ artists NOTIFY artistsChanged)
    Q_PROPERTY(QList<QObject*> albums READ albums NOTIFY albumsChanged)
    Q_PROPERTY(QList<QObject*> songs READ songs NOTIFY songsChanged)



public:
    explicit Music(QObject *parent = nullptr);
    QList<QObject*> artists() { return _artists; }
    QList<QObject*> albums() { return _albums; }
    QList<QObject*> songs() { return _songs; }

    unsigned int currentArtist() { return _currentArtist; }
    unsigned int currentAlbum() { return _currentSong; }
    unsigned int currentSong() { return _currentSong; }

    void setCurrentArtist(unsigned int artistId);
    void setCurrentAlbum(unsigned int albumId);
    void setCurrentSong(unsigned int songId);


protected:
    void getAllArtists();

    unsigned int _currentArtist;
    unsigned int _currentAlbum;
    unsigned int _currentSong;

    QList<QObject*> _albums;
    QList<QObject*> _artists;
    QList<QObject*> _songs;

    QSqlDatabase _db;
    QString dbPath;

signals:
    void currentArtistChanged();
    void currentAlbumChanged();
    void currentSongChanged();

    void artistsChanged();
    void albumsChanged();
    void songsChanged();

public slots:
};

#endif // MUSIC_H
