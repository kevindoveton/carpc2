#ifndef MUSICARTIST_H
#define MUSICARTIST_H

#include <QObject>
#include <QUrl>
class MusicArtist : public QObject {
    Q_OBJECT
    Q_PROPERTY(unsigned int id READ id NOTIFY idChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QUrl image READ image NOTIFY imageChanged)

public:
    explicit MusicArtist(unsigned int id, QString name, QString image, QObject *parent = nullptr);

    unsigned int id() { return _id; }
    QString name() { return _name; }
    QUrl image() { return _image; }

signals:
    void nameChanged();
    void imageChanged();
    void idChanged();

protected:
    unsigned int _id;
    QString _name;
    QUrl _image;

public slots:
};

#endif // MUSICARTIST_H
