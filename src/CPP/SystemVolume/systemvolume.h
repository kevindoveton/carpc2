#ifndef SYSTEMVOLUME_H
#define SYSTEMVOLUME_H

#include <QObject>

#include <alsa/asoundlib.h>
#include <alsa/asoundlib.h>
#include <iostream>

class SystemVolume : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned int volume READ getCurrentVolume WRITE setMasterVolume NOTIFY volumeChanged)

public:
    explicit SystemVolume(QObject *parent = nullptr);

    void setMasterVolume(unsigned int volume);
    unsigned int getCurrentVolume();
    Q_INVOKABLE unsigned int increaseVolume();
    Q_INVOKABLE unsigned int decreaseVolume();


protected:
    const float _VOLUMECHANGE = 5;
    void _setMasterVolume(long volume);
    long _getCurrentVolume();
    long _increaseVolume();
    long _decreaseVolume();

signals:
    void volumeChanged();
public slots:
};

#endif // SYSTEMVOLUME_H
