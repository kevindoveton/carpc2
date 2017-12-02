#ifndef TIME_H
#define TIME_H

#include <QObject>
#include <QTimer>
#include <QTime>
class Time : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString time READ time NOTIFY timeChanged)
  public:
    explicit Time(QObject *parent = nullptr);
    QString time() { return _time; }

  protected:
    QString _time;

  signals:
    void timeChanged();

  public slots:
    void updateTime();
};

#endif // TIME_H
