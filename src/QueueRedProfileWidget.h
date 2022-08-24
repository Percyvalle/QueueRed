#ifndef QUEUEREDPROFILEWIDGET_H
#define QUEUEREDPROFILEWIDGET_H

#include "QueueRedProfileMember.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QRect>
#include <QPushButton>
#include <QWidget>
#include <QGroupBox>

enum busyness{
    ready=0,
    noready=1
};

/*!
 * \brief Класс для представления визиток для пользователей
 */
class QueueRedProfileWidget : public QObject
{
    Q_OBJECT
public:
    explicit  QueueRedProfileWidget(QObject *_parent = NULL);

    ~QueueRedProfileWidget();

    QFrame* create_widget(QueueRedProfileMember* _profile);

    void hide_widget();

    void show_widget();

signals:
    void create_signal(QPushButton*);

private:
    QFrame *m_frame_profile;
    QHBoxLayout *m_layout_profile;
    QPushButton *m_button_profile;
    QLabel *m_status_label;
    QLabel *m_photo_label;
};

#endif // QUEUEREDPROFILEWIDGET_H
