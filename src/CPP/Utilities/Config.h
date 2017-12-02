#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>

class Config : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString bgColor READ bgColor WRITE setBgColor NOTIFY bgColorChanged)
    Q_PROPERTY(QString mapPlaceholderSearchText READ mapPlaceholderSearchText NOTIFY mapPlaceholderSearchTextChanged)
  public:
    explicit Config(QObject *parent = nullptr);
    QString bgColor() { return _bgColor; }
    QString mapPlaceholderSearchText() { return _mapPlaceholderSearchText; }
    void setBgColor(QString bgColor) { _bgColor = bgColor; return; }

  protected:
    QString _bgColor;
    QString _mapPlaceholderSearchText;

  signals:
    void bgColorChanged();
    void mapPlaceholderSearchTextChanged();

  public slots:
};

#endif // CONFIG_H
