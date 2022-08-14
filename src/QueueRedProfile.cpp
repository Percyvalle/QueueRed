#include "QueueRedProfile.h"

QueueRedProfile::QueueRedProfile(QString _name)
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
