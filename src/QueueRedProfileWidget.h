#ifndef QUEUEREDPROFILEWIDGET_H
#define QUEUEREDPROFILEWIDGET_H

#include "QueueRedProfile.h"

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QRect>
#include <QPushButton>
#include <QWidget>

class QueueRedProfileWidget
{
public:
    QueueRedProfileWidget();

    ~QueueRedProfileWidget();

    QFrame* create_widget(QueueRedProfile* _profile);

    void delete_widget();

    void hide_widget();

    void show_widget();

private:
    QFrame *m_frame_profile = new QFrame();
    QHBoxLayout *m_layout_profile = new QHBoxLayout();
    QPushButton *m_button_profile = new QPushButton();
    QLabel *m_status_label = new QLabel();
    QLabel *m_photo_label = new QLabel();
};

#endif // QUEUEREDPROFILEWIDGET_H
