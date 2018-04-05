#include "oauthvk.h"

OAuthVk::OAuthVk(QObject *parent) : QObject(parent)
{

}

void OAuthVk::getToken(QUrl url)
{
    url = url.toString().replace("#", "?");
    QUrlQuery query(url);
    m_accessToken = query.queryItemValue("access_token");
    m_userId = query.queryItemValue("user_id");
    //qDebug() << m_accessToken;
}


QUrl OAuthVk::url() const
{
    return m_url;
}

QString OAuthVk::accessToken() const
{
    return m_accessToken;
}

QString OAuthVk::userId() const
{
    return m_userId;
}

void OAuthVk::setUrl(QUrl url)
{
    if(m_url == url)
        return;

    m_url = url;
    emit urlChanged(url);
}

void OAuthVk::setAccessToken(QString accessToken)
{
    if(m_accessToken == accessToken)
        return;

    m_accessToken = accessToken;
    emit accessTokenChanged(accessToken);
}

void OAuthVk::setUserId(QString userId)
{
    if(m_userId == userId)
        return;

    m_userId = userId;
    emit userIdChanged(userId);
}
