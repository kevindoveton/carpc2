#ifndef MUSICALBUM_H
#define MUSICALBUM_H

#include <QObject>
#include <QUrl>
class MusicAlbum : public QObject {
    Q_OBJECT
    Q_PROPERTY(unsigned int id READ id NOTIFY idChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QUrl image READ image NOTIFY imageChanged)
  public:
    explicit MusicAlbum(unsigned int id, QString name, QString genre,
                        unsigned int year, QString imagePath,
                        unsigned int artistId, QObject *parent = nullptr);

    unsigned int id() { return _id; }
    QString name() { return _name; }
    QUrl image() { return _imagePath; }

  protected:
    unsigned int _id;
    QString _name;
    QString _genre;
    unsigned int _year;
    QUrl _imagePath;
    unsigned int _artistId;

  signals:
      void nameChanged();
      void imageChanged();
      void idChanged();


  public slots:
};

#endif // MUSICALBUM_H
