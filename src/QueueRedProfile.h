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
                             int _phone,
                             QString _login,
                             QString _birthday,
                             QString _addinfo,
                             QString _name,
                             QString _position,
                             QString _subdivision,
                             QString _status);

    const QString &getName() const;
    void setName(const QString &newName);

private:
    QString m_name;
};

#endif // QUEUEREDPROFILE_H
