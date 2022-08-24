#ifndef QUEUEREDDATABASEMANAGER_H
#define QUEUEREDDATABASEMANAGER_H

#include "QueueRedProfileMain.h"
#include "src/QueueRedProfileMember.h"

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

class QueueRedDatabaseManager
{
public:
    explicit QueueRedDatabaseManager();

    static void connection_db();
    static void set_offline();
    static bool auth_check(QString _login, QString _pass);
    static QueueRedProfileMain* create_main_profile(QString _login);
    static QVector<QueueRedProfileMember*> create_members_list(QString _login);

private:

    static QSqlDatabase m_database;
    static QSqlQuery *m_query;
    static QString m_main_login;
};

#endif // QUEUEREDDATABASEMANAGER_H
