#include "QueueRedProfileMember.h"

QueueRedProfileMember::QueueRedProfileMember(int _id,
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
                                             QString _status) :
                             QueueRedProfile(_id,
                                             _workplace,
                                             _workphone,
                                             _busyness,
                                             _phone,
                                             _login,
                                             _birthday,
                                             _addinfo,
                                             _name,
                                             _position,
                                             _subdivision,
                                             _status)
{

}

const QString &QueueRedProfileMember::name() const
{
    return m_name;
}

const QString &QueueRedProfileMember::birthday() const
{
    return m_birthday;
}

const QString &QueueRedProfileMember::addinfo() const
{
    return m_addinfo;
}

const QString &QueueRedProfileMember::position() const
{
    return m_position;
}

const QString &QueueRedProfileMember::subdivision() const
{
    return m_subdivision;
}

const QString &QueueRedProfileMember::status() const
{
    return m_status;
}

int QueueRedProfileMember::workphone() const
{
    return m_workphone;
}

int QueueRedProfileMember::workplace() const
{
    return m_workplace;
}

int QueueRedProfileMember::id() const
{
    return m_id;
}

int QueueRedProfileMember::busyness() const
{
    return m_busyness;
}
