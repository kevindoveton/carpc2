#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <unistd.h>


#include <vlc/vlc.h>
int main(int argc, char *argv[])
{
	qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);
	qputenv("MAPBOX_ACCESS_TOKEN", "pk.eyJ1Ijoia2V2aW5kb3ZldG9uIiwiYSI6ImNpdGdsYm9zYTAxMmcydG1rMnhuMGkxbHkifQ.pfUpUrZVbxkcj_pDx4Pbeg");
	QQmlApplicationEngine engine;
	engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

	libvlc_instance_t *inst;
	libvlc_media_player_t *mp;
	libvlc_media_t *m;

	// load the vlc engine
//	inst = libvlc_new(0, NULL);

//	// create a new item
//	m = libvlc_media_new_path(inst, "/pieces.m4a");

//	// create a media play playing environment
//	mp = libvlc_media_player_new_from_media(m);

//	// no need to keep the media now
//	libvlc_media_release(m);

//	// play the media_player
//	libvlc_media_player_play(mp);



	// stop playing
//	libvlc_media_player_stop(mp);

	// free the media_player
//	libvlc_media_player_release(mp);
//	libvlc_release(inst);


	return app.exec();
}
