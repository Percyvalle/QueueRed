#ifndef QUEUEREDAUTHENTICATION_H
#define QUEUEREDAUTHENTICATION_H

#include <QDialog>

namespace Ui {
class QueueRedAuthentication;
}

class QueueRedAuthentication : public QDialog
{
    Q_OBJECT

public:
    explicit QueueRedAuthentication(QWidget *parent = nullptr);
    ~QueueRedAuthentication();

private:
    Ui::QueueRedAuthentication *ui;
};

#endif // QUEUEREDAUTHENTICATION_H
