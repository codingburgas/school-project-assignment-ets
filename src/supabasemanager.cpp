#include "supabasemanager.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

SupabaseManager::SupabaseManager(QObject *parent) : QObject(parent) {
    m_baseUrl = "YOUR_SUPABASE_URL";
    m_apiKey = "YOUR_SUPABASE_API_KEY";
    m_projectId = "YOUR_SUPABASE_PROJECT_ID";
}

void SupabaseManager::fetchDataFromTable(const QString &tableName) {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &SupabaseManager::onDataReceived);

    QUrl url(m_baseUrl + "/rest/v1/" + tableName);
    QNetworkRequest request(url);
    request.setRawHeader("apikey", m_apiKey.toUtf8());
    request.setRawHeader("project-id", m_projectId.toUtf8());

    manager->get(request);
}

void SupabaseManager::onDataReceived(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        QJsonObject jsonObj = jsonDoc.object();

        qDebug() << "Received data:" << jsonObj;
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}
