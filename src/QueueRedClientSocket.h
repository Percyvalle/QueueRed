#ifndef QUEUEREDCLIENTSOCKET_H
#define QUEUEREDCLIENTSOCKET_H

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class QueueRedClientSocket : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit QueueRedClientSocket(QObject *parent = nullptr);

    void sendData();

private slots:
    void getResponse(QNetworkReply *reply);

private:
    const QUrl *m_address_socket = new QUrl("http://127.0.0.1:2000");
};

#endif // QUEUEREDCLIENTSOCKET_H
