#ifndef QUEUEREDPROFILEMAIN_H
#define QUEUEREDPROFILEMAIN_H

#include "QueueRedProfile.h"

class QueueRedProfileMain : public QueueRedProfile
{
public:
    explicit QueueRedProfileMain(int _id,
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

#endif // QUEUEREDPROFILEMAIN_H
