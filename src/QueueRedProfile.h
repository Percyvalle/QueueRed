#ifndef QUEUEREDPROFILE_H
#define QUEUEREDPROFILE_H

#include <QString>


/*!
    \brief Родительский класс, для представления профиля

    Данный класс имеет только одну простую цель:
    хранение и работа с данными профиля
*/
class QueueRedProfile
{
public:
    explicit QueueRedProfile(QString _name);

    const QString &getName() const;
    void setName(const QString &newName);

private:
    QString m_name;
};

#endif // QUEUEREDPROFILE_H
