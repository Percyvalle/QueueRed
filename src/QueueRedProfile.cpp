#include "QueueRedProfile.h"

QueueRedProfile::QueueRedProfile(int _id,
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
                                 QString _status)
{
    m_id = _id;
    m_busyness = _busyness;
    m_workplace = _workplace;
    m_workphone = _workphone;
    m_phone = _phone;
    m_login = _login;
    m_birthday = _birthday;
    m_addinfo = _addinfo;
    m_name = _name;
    m_position = _position;
    m_subdivision = _subdivision;
    m_status = _status;
}
