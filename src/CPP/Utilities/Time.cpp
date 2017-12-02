#include "Time.h"

Time :: Time(QObject *parent) : QObject(parent) {
  _time = "";
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
  timer->start(5000);
  updateTime();
}

void Time :: updateTime() {
  QTime time = QTime::currentTime();
  QString text = time.toString("h:mm ap");
  if (text != _time) {
    _time = text;
    emit timeChanged();
  }
}
