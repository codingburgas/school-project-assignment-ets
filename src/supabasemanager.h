#ifndef SUPABASEMANAGER_H
#define SUPABASEMANAGER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class SupabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit SupabaseManager(QObject *parent = nullptr);
    void fetchDataFromTable(const QString &tableName);

private slots:
    void onDataReceived(QNetworkReply *reply);

private:
    QString m_baseUrl;
    QString m_apiKey;
    QString m_projectId;
};


#endif // SUPABASEMANAGER_H
