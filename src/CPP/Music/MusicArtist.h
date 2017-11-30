#ifndef MUSICARTIST_H
#define MUSICARTIST_H

#include <QObject>
#include <QUrl>
class MusicArtist : public QObject {
    Q_OBJECT
    Q_PROPERTY(unsigned int id READ getId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QUrl image READ getImage NOTIFY imageChanged)

public:
    explicit MusicArtist(unsigned int id, QString name, QString image, QObject *parent = nullptr);

    unsigned int getId() { return _id; }
    QString getName() { return _name; }
    QUrl getImage() { return _image; }

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
