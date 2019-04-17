#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "settings.h"
#include "oauthvk.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    OAuthVk *o = new OAuthVk();
    Settings *s = new Settings();
    //VkSortModel *sm = new VkSortModel();
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("oauth", o);
    ctx->setContextProperty("settings", s);
    //ctx->setContextProperty("vksortmodel", sm);
    qmlRegisterType<Settings>("SettingsVk", 1, 0, "SettingsVk");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
