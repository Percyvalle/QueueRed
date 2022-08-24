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

void QueueRedDatabaseManager::set_offline()
{
    m_query->exec("UPDATE profile_auth SET status='offline' WHERE login='"+m_main_login+"'");
}

bool QueueRedDatabaseManager::auth_check(QString _login, QString _pass)
{
    m_query->exec("SELECT * FROM profile_auth");
    while(m_query->next()){
        if(m_query->value("login").toString() == _login &&
           m_query->value("password").toString() == _pass){
            m_query->exec("UPDATE profile_auth SET status='online' WHERE login='"+_login+"'");
            m_main_login = _login;
            return true;
        }
    }

    return false;
}

QueueRedProfileMain* QueueRedDatabaseManager::create_main_profile(QString _login)
{
    m_query->exec("SELECT * FROM profile INNER JOIN profile_auth ON profile.id = profile_auth.id_profile WHERE login='"+_login+"'");
    m_query->next();
    QueueRedProfileMain *profile_main = new QueueRedProfileMain(m_query->value("id").toInt(),
                                                                m_query->value("workplace").toInt(),
                                                                m_query->value("workphone").toInt(),
                                                                m_query->value("busyness").toInt(),
                                                                m_query->value("phone").toString(),
                                                                m_query->value("login").toString(),
                                                                m_query->value("birthday").toString(),
                                                                m_query->value("addinfo").toString(),
                                                                m_query->value("name").toString(),
                                                                m_query->value("position").toString(),
                                                                m_query->value("subdivision").toString(),
                                                                m_query->value("status").toString());
    return profile_main;
}

QVector<QueueRedProfileMember *> QueueRedDatabaseManager::create_members_list(QString _login)
{
    m_query->exec("SELECT * FROM profile INNER JOIN profile_auth ON profile.id = profile_auth.id_profile WHERE login!='"+_login+"'");

    QVector<QueueRedProfileMember*> members_list;
    while(m_query->next()){
        members_list.append(new QueueRedProfileMember(m_query->value("id").toInt(),
                                                      m_query->value("workplace").toInt(),
                                                      m_query->value("workphone").toInt(),
                                                      m_query->value("busyness").toInt(),
                                                      m_query->value("phone").toString(),
                                                      m_query->value("login").toString(),
                                                      m_query->value("birthday").toString(),
                                                      m_query->value("addinfo").toString(),
                                                      m_query->value("name").toString(),
                                                      m_query->value("position").toString(),
                                                      m_query->value("subdivision").toString(),
                                                      m_query->value("status").toString()));
    }

    return members_list;
}

QSqlDatabase QueueRedDatabaseManager::m_database = QSqlDatabase::addDatabase("QPSQL");
QSqlQuery *QueueRedDatabaseManager::m_query = new QSqlQuery(m_database);
QString QueueRedDatabaseManager::m_main_login = NULL;
