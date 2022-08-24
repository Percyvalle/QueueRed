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
    explicit QueueRedProfile(int _id,
                             int _workplace,
                             int _workphone,
                             int _busyness,
                             QString _phone,
                             QString _login,
                             QString _birthday,
                             QString _addinfo,
                             QString _name,
                             QString _position,
                             QString _subdivision,
                             QString _status);
protected:
    int m_id;
    int m_workplace;
    int m_workphone;
    int m_busyness;
    QString m_phone;
    QString m_login;
    QString m_birthday;
    QString m_addinfo;
    QString m_name;
    QString m_position;
    QString m_subdivision;
    QString m_status;
};

#endif // QUEUEREDPROFILE_H
