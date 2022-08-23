#include "QueueRedDatabaseManager.h"

QueueRedDatabaseManager::QueueRedDatabaseManager()
{

}

void QueueRedDatabaseManager::connection_db()
{
    m_database.setHostName("localhost");
    m_database.setPort(5432);
    m_database.setDatabaseName("queuered");
    m_database.setUserName("percy");
    m_database.setPassword("gkpf2ci");

    if(!m_database.open()){
        QMessageBox::warning(0, "Ошибка БД", m_database.lastError().text());
    } else {
        QMessageBox::information(0, "Успешно", "Соединение с БД установлено!");
    }

}

bool QueueRedDatabaseManager::auth_check(QString _login, QString _pass)
{
    m_query->exec("SELECT * FROM profile_auth");
    while(m_query->next()){
        if(m_query->value("login").toString() == _login &&
           m_query->value("password").toString() == _pass){
            return true;
        }
    }

    return false;
}

QSqlDatabase QueueRedDatabaseManager::m_database = QSqlDatabase::addDatabase("QPSQL");
QSqlQuery *QueueRedDatabaseManager::m_query = new QSqlQuery(m_database);
