#include "QueueRedClientSocket.h"

QueueRedClientSocket::QueueRedClientSocket(QObject *parent)
    : QNetworkAccessManager{parent}
{

}

void QueueRedClientSocket::sendData()
{
    QNetworkRequest request(QUrl("http://127.0.0.1:2000"));
    connect(this, SIGNAL(finished(QNetworkReply*)), SLOT(getResponse(QNetworkReply*)));
    get(request);
}

void QueueRedClientSocket::getResponse(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}
