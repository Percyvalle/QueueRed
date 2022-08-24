#ifndef QUEUEREDPROFILEMEMBER_H
#define QUEUEREDPROFILEMEMBER_H

#include "QueueRedProfile.h"


/*!
    \brief Класс наследник от QueueRedProfile

    Представление профилей для сотрудников
*/
class QueueRedProfileMember : public QueueRedProfile
{
public:
    QueueRedProfileMember(int _id,
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

    const QString &name() const;
    const QString &birthday() const;
    const QString &addinfo() const;
    const QString &position() const;
    const QString &subdivision() const;
    const QString &status() const;
    int workphone() const;
    int workplace() const;
    int busyness() const;
    int id() const;
};

#endif // QUEUEREDPROFILEMEMBER_H
