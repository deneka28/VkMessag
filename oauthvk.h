#ifndef OAUTHVK_H
#define OAUTHVK_H

#include <QString>
#include <QDebug>
#include <QUrlQuery>
#include <QUrl>

class OAuthVk : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString accessToken READ accessToken WRITE setAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
public:
    explicit OAuthVk(QObject *parent = 0);
    static QString access_token;

    Q_INVOKABLE void getToken(QUrl url);
   // Q_INVOKABLE void getUserId(QUrl url);

    QUrl url() const;
    QString accessToken() const;
    QString userId() const;

signals:

    void urlChanged(QUrl url);
    void accessTokenChanged(QString accessToken);
    void userIdChanged(QString userId);

public slots:

    void setUrl(QUrl url);
    void setAccessToken(QString accessToken);
    void setUserId(QString userId);

private:
    QUrl m_url;
    QString m_accessToken;
    QString m_userId;
};

#endif // OAUTHVK_H
