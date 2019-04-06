#include "settings.h"

QString Settings::access_token = "no token";
Settings::Settings(QObject *parent) : QObject(parent)
{

}

void Settings::loadToken()
{
    QFile f(m_fileName);
    if(!f.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error load";
            return;
    }
    QDataStream dataStream(&f);
    QVariantMap s;
    dataStream >> s;
    f.close();
    if(s.contains("access_token") | s.contains("user_id"))
    {
        m_accessToken = s.value("access_token").toString();
        m_userId = s.value("user_id").toString();
    }
}

void Settings::saveToken(QString fileName, QString access_token, QString user_id)
{
    QFile f(fileName);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "Error save";
        return;
    }
    QVariantMap param;
    QDataStream dataStream(&f);
    param.insert("access_token", access_token);
    param.insert("user_id", user_id);
    dataStream << param;
    f.close();
}

QString Settings::fileName() const
{
    return m_fileName;
}

QString Settings::accessToken() const
{
    return m_accessToken;
}

QString Settings::userId() const
{
    return m_userId;
}

void Settings::setFileName(QString fileName)
{
    if (m_fileName == fileName)
        return;

    m_fileName = fileName;
    emit fileNameChanged(fileName);
}

void Settings::setAccessToken(QString accessToken)
{
    if (m_accessToken == accessToken)
        return;

    m_accessToken = accessToken;
    emit accessTokenChanged(accessToken);
}

void Settings::setUserId(QString userId)
{
    if (m_userId == userId)
        return;

    m_userId = userId;
    emit userIdChanged(userId);
}


