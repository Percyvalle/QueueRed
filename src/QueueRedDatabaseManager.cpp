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

        QSqlQuery *m_query = new QSqlQuery(m_database);
        m_query->exec("SELECT * FROM profile");
        m_query->next();
        qDebug() << m_query->value("name").toString();
    }

}
