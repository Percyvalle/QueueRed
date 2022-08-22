#include "QueueRedAuthentication.h"
#include "ui_QueueRedAuthentication.h"

QueueRedAuthentication::QueueRedAuthentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueueRedAuthentication)
{
    ui->setupUi(this);
}

QueueRedAuthentication::~QueueRedAuthentication()
{
    delete ui;
}
