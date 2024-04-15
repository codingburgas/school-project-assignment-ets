#include "supabasemanager.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

SupabaseManager::SupabaseManager(QObject *parent) : QObject(parent) {
    m_baseUrl = "https://egyfjgomyvvhoyfizfbk.supabase.co";
    m_apiKey = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImVneWZqZ29teXZ2aG95Zml6ZmJrIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MTMyMjAwMTIsImV4cCI6MjAyODc5NjAxMn0.VWJntRRSsB4SbHWhAcSv7fWykdEfWikMYlzYwcG5zMg";
    m_projectId = "egyfjgomyvvhoyfizfbk";
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
