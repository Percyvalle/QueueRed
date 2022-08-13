#ifndef QUEUEREDCLIENTSOCKET_H
#define QUEUEREDCLIENTSOCKET_H

#include <QNetworkAccessManager>

class QueueRedClientSocket : public QNetworkAccessManager
{
public:
    explicit QueueRedClientSocket(QObject *parent = nullptr);
};

#endif // QUEUEREDCLIENTSOCKET_H
