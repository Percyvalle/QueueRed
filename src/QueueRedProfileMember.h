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
                          int _phone,
                          QString _login,
                          QString _birthday,
                          QString _addinfo,
                          QString _name,
                          QString _position,
                          QString _subdivision,
                          QString _status);
};

#endif // QUEUEREDPROFILEMEMBER_H
