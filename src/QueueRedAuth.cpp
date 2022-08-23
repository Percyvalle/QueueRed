#include "QueueRedAuth.h"
#include "ui_QueueRedAuth.h"

QueueRedAuth::QueueRedAuth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueueRedAuth)
{
    ui->setupUi(this);
    connectionUI();
    QueueRedDatabaseManager::connection_db();

    ui->line_login->setText("gomanov");
    ui->line_password->setText("gkpf2ci");
}

QueueRedAuth::~QueueRedAuth()
{
    delete ui;
}

void QueueRedAuth::connectionUI()
{
    connect(ui->button_auth, SIGNAL(clicked()), this, SLOT(button_auth_clicked()));
}

void QueueRedAuth::button_auth_clicked()
{
    if (QueueRedDatabaseManager::auth_check(ui->line_login->text(), ui->line_password->text()))
    {
        emit auth_done(ui->line_login->text(),
                       ui->line_password->text());
    } else {

        ui->labe_status->setText("Неправильный пароль или логин");
    }
}
