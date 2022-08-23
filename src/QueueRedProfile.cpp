#include "QueueRedProfile.h"

QueueRedProfile::QueueRedProfile(int _id,
                                 int _workplace,
                                 int _workphone,
                                 int _phone,
                                 QString _login,
                                 QString _birthday,
                                 QString _addinfo,
                                 QString _name,
                                 QString _position,
                                 QString _subdivision,
                                 QString _status)
{
    this->m_name = _name;
}

const QString &QueueRedProfile::getName() const
{
    return m_name;
}

void QueueRedProfile::setName(const QString &newName)
{
    m_name = newName;
}
