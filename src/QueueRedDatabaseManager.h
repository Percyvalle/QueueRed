#ifndef QUEUEREDDATABASEMANAGER_H
#define QUEUEREDDATABASEMANAGER_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

class QueueRedDatabaseManager
{
public:
    explicit QueueRedDatabaseManager();

    static void connection_db();
    static bool auth_check(QString _login, QString _pass);

private:

    static QSqlDatabase m_database;
    static QSqlQuery *m_query;
};

#endif // QUEUEREDDATABASEMANAGER_H
