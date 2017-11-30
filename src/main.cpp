#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickWindow>

#include <unistd.h>

#include "CPP/SystemVolume/SystemVolume.h"
#include "CPP/Music/Music.h"
#include "CPP/Music/Player.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQmlEngine engine;
    QQmlContext * context = new QQmlContext(engine.rootContext());
    QObject::connect(&engine, SIGNAL(quit()), QCoreApplication::instance(), SLOT(quit    ()));


    qputenv("MAPBOX_ACCESS_TOKEN", "pk.eyJ1Ijoia2V2aW5kb3ZldG9uIiwiYSI6ImNpdGdsYm9zYTAxMmcydG1rMnhuMGkxbHkifQ.pfUpUrZVbxkcj_pDx4Pbeg");

    context->setContextProperty("systemVolume", new SystemVolume);
    context->setContextProperty("music", new Music);
    context->setContextProperty("player", new Player);

    QQmlComponent component(&engine, "qrc:/qml/main.qml");
    QQuickWindow * topLevel = qobject_cast<QQuickWindow*>(component.create(context));
    topLevel->show();

    int rc = app.exec();

    delete topLevel;
    delete context;
    return rc;

//	return app.exec();
}
