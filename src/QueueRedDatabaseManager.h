#ifndef QUEUEREDDATABASEMANAGER_H
#define QUEUEREDDATABASEMANAGER_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

class QueueRedDatabaseManager
{
public:
    explicit QueueRedDatabaseManager();

    void connection_db();

private:

    QSqlDatabase m_database = QSqlDatabase::addDatabase("QPSQL");
    QSqlQuery *m_query = new QSqlQuery(m_database);
};

#endif // QUEUEREDDATABASEMANAGER_H
