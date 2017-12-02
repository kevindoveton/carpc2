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

//    Q_PROPERTY(QObject nowPlayingArtist READ nowPlayingArtist WRITE setNowPlayingArtist NOTIFY nowPlayingArtistChanged)



public:
    explicit Music(QObject *parent = nullptr);
    QList<QObject*> artists() { return _artists; }
    QList<QObject*> albums() { return _albums; }
    QList<QObject*> songs() { return _songs; }

    Q_INVOKABLE QObject* getCurrentArtist();
    Q_INVOKABLE QObject* getCurrentAlbum();
    Q_INVOKABLE QObject* getCurrentSong();

    Q_INVOKABLE QObject* getArtistById(unsigned int id);
    Q_INVOKABLE QObject* getAlbumById(unsigned int id);
    Q_INVOKABLE QObject* getSongById(unsigned int id);


    unsigned int currentArtist() { return _currentArtist; }
    unsigned int currentAlbum() { return _currentSong; }
    unsigned int currentSong() { return _currentSong; }

    void setCurrentArtist(unsigned int artistId);
    void setCurrentAlbum(unsigned int albumId);
    void setCurrentSong(unsigned int songId);

//    QObject nowPlayingArtist() { return _nowPlayingArtist; }
//    QObject nowPlayingAlbum() { return _nowPlayingAlbum; }
//    QObject nowPlayingSong() { return _nowPlayingSong; }


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

    QHash<QString, QObject*> _nowPlaying;

    QObject _nowPlayingArtist;

signals:
    void currentArtistChanged();
    void currentAlbumChanged();
    void currentSongChanged();

    void artistsChanged();
    void albumsChanged();
    void songsChanged();

    void nowPlayingChanged();

public slots:
    void updateNowPlaying();
};

#endif // MUSIC_H
