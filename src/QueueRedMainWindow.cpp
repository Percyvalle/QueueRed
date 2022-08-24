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
}

QueueRedMainWindow::~QueueRedMainWindow()
{
    delete ui;
}

/*-------------------------Авторизация-------------------------*/
void QueueRedMainWindow::connectionAUTH()
{
    connect(m_auth_dialog, SIGNAL(auth_done(QueueRedProfileMain*, QVector<QueueRedProfileMember*>)),
            this, SLOT(auth_done_show(QueueRedProfileMain*, QVector<QueueRedProfileMember*>)));
}

void QueueRedMainWindow::auth_dialog_ready()
{
    m_auth_dialog->setWindowTitle("Авторизация");
    m_auth_dialog->exec();
}

void QueueRedMainWindow::auth_done_show(QueueRedProfileMain* _profile_main, QVector<QueueRedProfileMember*> _members_list)
{
    m_members_list = _members_list;
    m_profile_main = _profile_main;
    m_auth_dialog->close();
    show();

    set_profile_main_ui();
    update_profile_area();
}

/*-------------------------Основное окно-------------------------*/
void QueueRedMainWindow::set_profile_main_ui()
{
    ui->profile_box->setItemText(0, m_profile_main->name().split(" ")[0] + " " + m_profile_main->name().split(" ")[1]);

    ui->profile_main_name->setText(m_profile_main->name());
    ui->profile_main_addinfo->setText(m_profile_main->addinfo());
    ui->profile_main_position->setText(m_profile_main->position());
    ui->profile_main_subdivision->setText(m_profile_main->subdivision());
    ui->profile_main_birthday->setText(m_profile_main->birthday());
    ui->profile_main_phone->setText(m_profile_main->phone());
    ui->profile_main_workphone->setText(QString::number(m_profile_main->workphone()));
    ui->profile_main_workplace->setText(QString::number(m_profile_main->workplace()));
}

void QueueRedMainWindow::update_profile_area()
{
    for(int i = 0; i < ui->profile_layout->layout()->count(); i++)
    {
        while (QLayoutItem* item = ui->profile_layout->layout()->takeAt(0)) {
            delete item->widget();
            delete item;
        }
    }

    m_members_list = QueueRedDatabaseManager::create_members_list(m_profile_main->login());
    for(QueueRedProfileMember *member : qAsConst(m_members_list)){
        ui->profile_layout->layout()->addWidget(m_profile_widget->create_widget(member));
    }
}

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
    update_profile_area();

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
