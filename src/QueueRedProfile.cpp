#include "QueueRedProfile.h"

QueueRedProfile::QueueRedProfile(QString _name)
{
    this->name = _name;
}

const QString &QueueRedProfile::getName() const
{
    return name;
}

void QueueRedProfile::setName(const QString &newName)
{
    name = newName;
}
