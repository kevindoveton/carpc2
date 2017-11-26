#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>

class Music : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString name READ name WRITE setName)

public:
    explicit Music(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MUSIC_H
