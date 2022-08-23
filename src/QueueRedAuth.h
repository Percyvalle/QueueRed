#ifndef QUEUEREDAUTH_H
#define QUEUEREDAUTH_H

#include <QDialog>
#include "QueueRedDatabaseManager.h"

namespace Ui {
class QueueRedAuth;
}

class QueueRedAuth : public QDialog
{
    Q_OBJECT

public:
    explicit QueueRedAuth(QWidget *parent = nullptr);
    ~QueueRedAuth();

    void connectionUI();

signals:
    void auth_done(QString, QString);

private slots:
    void button_auth_clicked();

private:
    Ui::QueueRedAuth *ui;
};

#endif // QUEUEREDAUTH_H
