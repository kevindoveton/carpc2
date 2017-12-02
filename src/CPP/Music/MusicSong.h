#ifndef MUSICSONG_H
#define MUSICSONG_H

#include <QObject>
#include <QUrl>
class MusicSong : public QObject {
    Q_OBJECT
    Q_PROPERTY(unsigned int id READ id NOTIFY idChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QUrl path READ path NOTIFY pathChanged)

  public:
    explicit MusicSong(unsigned int id, QString name, QString path,
                       unsigned int albumId, QObject *parent = nullptr);
    unsigned int id() { return _id; }
    QString name() { return _name; }
    QUrl path() { return _path; }

  protected:
    unsigned int _id;
    QString _name;
    QString _path;
    unsigned int _albumId;
    unsigned int _artistId;

  signals:
    void nameChanged();
    void imageChanged();
    void idChanged();
    void pathChanged();

  public slots:
};

#endif // MUSICSONG_H
