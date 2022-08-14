#include "QueueRedMainWindow.h"
#include "ui_QueueRedMainWindow.h"

#include <QDebug>
#include <QLayout>

#include <src/QueueRedClientSocket.h>

QueueRedMainWindow::QueueRedMainWindow(QWidget *_parent)
    : QMainWindow(_parent)
    , ui(new Ui::QueueRedMainWindow)
{
    ui->setupUi(this);
    connectionUI();

    QPixmap icon_search(":/resource/resource/icon_search.png");
    ui->icon_search->setPixmap(icon_search.scaled(20, 20, Qt::KeepAspectRatio));

    QueueRedProfile *profile = new QueueRedProfile("Danya");
    ui->profile_layout->layout()->addWidget(m_profile_widget->create_widget(profile));
    QueueRedProfile *profilek = new QueueRedProfile("Kirill");
    ui->profile_layout->layout()->addWidget(m_profile_widget->create_widget(profilek));
    QueueRedProfile *profilev = new QueueRedProfile("Vlad");
    ui->profile_layout->layout()->addWidget(m_profile_widget->create_widget(profilev));


    QueueRedClientSocket *sock = new QueueRedClientSocket();
    sock->sendData();
}

QueueRedMainWindow::~QueueRedMainWindow()
{
    delete ui;
}

void QueueRedMainWindow::connectionUI(){
    connect(ui->employees_button, SIGNAL(clicked()), this, SLOT(employees_button()));
    connect(ui->profile_button, SIGNAL(clicked()), this, SLOT(profile_button()));
    connect(ui->tasks_button, SIGNAL(clicked()), this, SLOT(tasks_button()));

    connect(m_profile_widget, SIGNAL(create_signal(QPushButton*)),
            this, SLOT(profile_connection(QPushButton*)));
}

void QueueRedMainWindow::employees_button()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void QueueRedMainWindow::profile_button()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void QueueRedMainWindow::tasks_button()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void QueueRedMainWindow::profile_connection(QPushButton *but)
{
    connect(but, SIGNAL(clicked()), this, SLOT(profile_members_button()));
}

void QueueRedMainWindow::profile_members_button()
{
    QPushButton *sender_button = (QPushButton*)sender();
    qDebug() << sender_button->text();
}

// Позже
//void QueueRedMainWindow::sendData() {
//    QNetworkRequest request(QUrl("http://127.0.0.1:2000"));
//    QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
//    connect(mngr, SIGNAL(finished(QNetworkReply*)), SLOT(getResponse(QNetworkReply*)));
//    mngr->get(request);
//}

//void QueueRedMainWindow::getResponse(QNetworkReply *reply)
//{
//    qDebug() << reply->readAll();
//}

