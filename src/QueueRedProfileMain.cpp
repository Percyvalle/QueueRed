#include "QueueRedProfileMain.h"

QueueRedProfileMain::QueueRedProfileMain(int _id,
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

int QueueRedProfileMain::id() const
{
    return m_id;
}

void QueueRedProfileMain::setId(int newId)
{
    m_id = newId;
}

int QueueRedProfileMain::workplace() const
{
    return m_workplace;
}

void QueueRedProfileMain::setWorkplace(int newWorkplace)
{
    m_workplace = newWorkplace;
}

int QueueRedProfileMain::workphone() const
{
    return m_workphone;
}

void QueueRedProfileMain::setWorkphone(int newWorkphone)
{
    m_workphone = newWorkphone;
}

QString QueueRedProfileMain::phone() const
{
    return m_phone;
}

void QueueRedProfileMain::setPhone(QString newPhone)
{
    m_phone = newPhone;
}

const QString &QueueRedProfileMain::birthday() const
{
    return m_birthday;
}

void QueueRedProfileMain::setBirthday(const QString &newBirthday)
{
    m_birthday = newBirthday;
}

const QString &QueueRedProfileMain::addinfo() const
{
    return m_addinfo;
}

void QueueRedProfileMain::setAddinfo(const QString &newAddinfo)
{
    m_addinfo = newAddinfo;
}

const QString &QueueRedProfileMain::name() const
{
    return m_name;
}

void QueueRedProfileMain::setName(const QString &newName)
{
    m_name = newName;
}

const QString &QueueRedProfileMain::position() const
{
    return m_position;
}

void QueueRedProfileMain::setPosition(const QString &newPosition)
{
    m_position = newPosition;
}

const QString &QueueRedProfileMain::subdivision() const
{
    return m_subdivision;
}

void QueueRedProfileMain::setSubdivision(const QString &newSubdivision)
{
    m_subdivision = newSubdivision;
}

const QString &QueueRedProfileMain::login() const
{
    return m_login;
}

void QueueRedProfileMain::setLogin(const QString &newLogin)
{
    m_login = newLogin;
}

int QueueRedProfileMain::busyness() const
{
    return m_busyness;
}

void QueueRedProfileMain::setBusyness(int newBusyness)
{
    m_busyness = newBusyness;
}
