#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "oauthvk.h"
#include "vksortmodel.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    OAuthVk *o = new OAuthVk();
    //VkSortModel *s = new VkSortModel();
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("oauth", o);
    //ctx->setContextProperty("vksort", s);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
