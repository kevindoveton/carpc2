#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <unistd.h>
#include <vlc/vlc.h>

#include "CPP/SystemVolume/systemvolume.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qputenv("MAPBOX_ACCESS_TOKEN", "pk.eyJ1Ijoia2V2aW5kb3ZldG9uIiwiYSI6ImNpdGdsYm9zYTAxMmcydG1rMnhuMGkxbHkifQ.pfUpUrZVbxkcj_pDx4Pbeg");


    qmlRegisterType<SystemVolume>("com.kdoveton.carpc.SystemVolume", 1, 0, "SystemVolume");



    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

	return app.exec();
}
