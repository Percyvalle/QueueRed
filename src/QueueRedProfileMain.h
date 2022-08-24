#ifndef QUEUEREDPROFILEMAIN_H
#define QUEUEREDPROFILEMAIN_H

#include "QueueRedProfile.h"

class QueueRedProfileMain : public QueueRedProfile
{
public:
    explicit QueueRedProfileMain(int _id,
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

    int id() const;
    void setId(int newId);

    int workplace() const;
    void setWorkplace(int newWorkplace);

    int workphone() const;
    void setWorkphone(int newWorkphone);

    QString phone() const;
    void setPhone(QString newPhone);

    const QString &birthday() const;
    void setBirthday(const QString &newBirthday);

    const QString &addinfo() const;
    void setAddinfo(const QString &newAddinfo);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &position() const;
    void setPosition(const QString &newPosition);

    const QString &subdivision() const;
    void setSubdivision(const QString &newSubdivision);

    const QString &login() const;
    void setLogin(const QString &newLogin);

    int busyness() const;
    void setBusyness(int newBusyness);
};

#endif // QUEUEREDPROFILEMAIN_H
