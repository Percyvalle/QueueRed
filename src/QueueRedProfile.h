#ifndef QUEUEREDPROFILE_H
#define QUEUEREDPROFILE_H

#include <QString>

class QueueRedProfile
{
public:
    QueueRedProfile(QString _name);

    const QString &getName() const;
    void setName(const QString &newName);

private:
    QString name;
};

#endif // QUEUEREDPROFILE_H
