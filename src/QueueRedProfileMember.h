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
    QueueRedProfileMember(QString _name);
};

#endif // QUEUEREDPROFILEMEMBER_H
