#include "QueueRedMainWindow.h"
#include "ui_QueueRedMainWindow.h"

#include <QDebug>
#include <QLayout>

#include <src/QueueRedDatabaseManager.h>

QueueRedMainWindow::QueueRedMainWindow(QWidget *_parent)
    : QMainWindow(_parent)
    , ui(new Ui::QueueRedMainWindow)
{
    ui->setupUi(this);
    connectionAUTH();
    auth_dialog_ready();

    connectionUI();
    init_icon();

    //QueueRedProfile *profile = new QueueRedProfile("Danya");
    //ui->profile_layout->layout()->addWidget(m_profile_widget->create_widget(profile));
}

QueueRedMainWindow::~QueueRedMainWindow()
{
    delete ui;
}

/*-------------------------Авторизация-------------------------*/
void QueueRedMainWindow::connectionAUTH()
{
    connect(m_auth_dialog, SIGNAL(auth_done(QString, QString)), this, SLOT(auth_done_show(QString, QString)));
}

void QueueRedMainWindow::auth_dialog_ready()
{
    m_auth_dialog->setWindowTitle("Авторизация");
    m_auth_dialog->exec();
}

void QueueRedMainWindow::auth_done_show(QString _login, QString _pass)
{
    m_auth_dialog->close();
    show();
}


/*-------------------------Основное окно-------------------------*/
void QueueRedMainWindow::connectionUI(){
    connect(ui->employees_button, SIGNAL(clicked()), this, SLOT(employees_button()));
    connect(ui->profile_button, SIGNAL(clicked()), this, SLOT(profile_button()));
    connect(ui->tasks_button, SIGNAL(clicked()), this, SLOT(tasks_button()));

    connect(m_profile_widget, SIGNAL(create_signal(QPushButton*)),
            this, SLOT(profile_connection(QPushButton*)));
}

void QueueRedMainWindow::init_icon()
{
    QPixmap icon_search(":/resource/resource/icon_search.png");
    ui->icon_search->setPixmap(icon_search.scaled(20, 20, Qt::KeepAspectRatio));
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
