#include "QueueRedMainWindow.h"
#include "ui_QueueRedMainWindow.h"

#include <QDebug>

QueueRedMainWindow::QueueRedMainWindow(QWidget *_parent)
    : QMainWindow(_parent)
    , ui(new Ui::QueueRedMainWindow)
{
    ui->setupUi(this);
    connectionUI();

    QPixmap icon_search(":/resource/resource/icon_search.png");
    ui->icon_search->setPixmap(icon_search.scaled(20, 20, Qt::KeepAspectRatio));

    QueueRedProfile *profile = new QueueRedProfile("Danya");
    QueueRedProfileWidget *wi = new QueueRedProfileWidget();
    ui->profile_layout->layout()->addWidget(wi->create_widget(profile));
}

QueueRedMainWindow::~QueueRedMainWindow()
{
    delete ui;
}

void QueueRedMainWindow::connectionUI(){
    connect(ui->employees_button, SIGNAL(clicked()), this, SLOT(employees_button()));
    connect(ui->profile_button, SIGNAL(clicked()), this, SLOT(profile_button()));
    connect(ui->tasks_button, SIGNAL(clicked()), this, SLOT(tasks_button()));
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
