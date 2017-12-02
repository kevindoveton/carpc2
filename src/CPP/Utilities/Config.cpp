#include "Config.h"

Config::Config(QObject *parent) : QObject(parent) {
  _bgColor = "#285982";
  _mapPlaceholderSearchText = "Search...";
}
