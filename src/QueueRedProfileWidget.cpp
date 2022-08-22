#include "QueueRedProfileWidget.h"

QueueRedProfileWidget::QueueRedProfileWidget(QObject *_parent) : QObject(_parent)
{
}


QFrame* QueueRedProfileWidget::create_widget(QueueRedProfile* _profile){

    m_status_label = new QLabel();
    m_status_label->setMaximumSize(QSize(60, 90));
    m_status_label->setStyleSheet("background-color: #ccc;");

    m_photo_label = new QLabel();
    m_photo_label->setMaximumSize(QSize(60, 60));
    m_photo_label->setStyleSheet("background: rgba(245, 245, 245,100%); border-radius: 30;");

    m_button_profile = new QPushButton();
    m_button_profile->setStyleSheet("background: rgba(245, 245, 245,0%); border: 0;");
    m_button_profile->setMinimumSize(QSize(60,90));
    m_button_profile->setText(_profile->getName());

    m_layout_profile = new QHBoxLayout();
    m_layout_profile->setSizeConstraint(QLayout::SetMinimumSize);
    m_layout_profile->setMargin(0);
    m_layout_profile->addWidget(m_status_label);
    m_layout_profile->addWidget(m_photo_label);
    m_layout_profile->addWidget(m_button_profile);

    m_frame_profile = new QFrame();
    m_frame_profile->setMaximumSize(QSize(420, 85));
    m_frame_profile->setStyleSheet("QFrame{background: rgba(245, 245, 245,50%); border: 0;}"
                                   "QFrame::hover{background: #ccc; border: 0;}");
    m_frame_profile->setLayout(m_layout_profile);

    emit create_signal(m_button_profile);
    return m_frame_profile;
}

QueueRedProfileWidget::~QueueRedProfileWidget(){
    delete m_frame_profile;
    delete m_layout_profile;
    delete m_button_profile;
    delete m_status_label;
    delete m_photo_label;
}
