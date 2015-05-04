#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QScopedPointer>
#include <QDir>

#include "soundplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QScopedPointer<SoundPlayer> player(new SoundPlayer());
    engine.rootContext()->setContextProperty("soundplayer", player.data());
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    component.create();

#ifdef Q_OS_ANDROID
    player->loadSamples("/sdcard/Download/");
#else
    player->loadSamples(qApp->applicationDirPath() + QDir::separator());
#endif

    return app.exec();
}
