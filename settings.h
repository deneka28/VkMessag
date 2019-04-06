#ifndef SETTINGS_H
#define SETTINGS_H
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QVariantMap>
#include <QDebug>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString accessToken READ accessToken WRITE setAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)

public:
    explicit Settings(QObject *parent = 0);
    static QString access_token;

    Q_INVOKABLE void loadToken();
    Q_INVOKABLE void saveToken(QString fileName, QString access_token, QString user_id);

    QString fileName() const;
    QString accessToken() const;
    QString userId() const;

signals:

    void fileNameChanged(QString fileName);
    void accessTokenChanged(QString accessToken);
    void userIdChanged(QString userId);

public slots:

    void setFileName(QString fileName);
    void setAccessToken(QString accessToken);
    void setUserId(QString userId);

private:
    QString m_fileName;
    QString m_accessToken;
    QString m_userId;
};

#endif // SETTINGS_H
