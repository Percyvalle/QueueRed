#include "QueueRedProfileWidget.h"
#include "qdebug.h"


QueueRedProfileWidget::QueueRedProfileWidget(QObject *_parent) : QObject(_parent)
{
}


QFrame* QueueRedProfileWidget::create_widget(QueueRedProfileMember* _profile){

    m_status_label = new QLabel();
    m_status_label->setMaximumSize(QSize(60, 90));

    if(_profile->status() == "online"){
        m_status_label->setStyleSheet("background-color: #3CB371;");
    }
    else if(_profile->status() == "offline"){
        m_status_label->setStyleSheet("background-color: #ccc;");
    }

    switch (_profile->busyness()) {
        case ready:{
            QPixmap thunder_icon(":/resource/resource/status_icon/thunder_icon.png");
            m_status_label->setPixmap(thunder_icon.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            m_status_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            break;}
        case noready:{
            QPixmap airplane_icon(":/resource/resource/status_icon/airplane_icon.png");
            m_status_label->setPixmap(airplane_icon.scaled(22, 22, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            m_status_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            break;}
    }

    m_photo_label = new QLabel();
    m_photo_label->setMaximumSize(QSize(60, 60));
    m_photo_label->setStyleSheet("background: rgba(245, 245, 245,100%); border-radius: 30;");

    m_button_profile = new QPushButton();
    m_button_profile->setStyleSheet("QPushButton{background: rgba(245, 245, 245,0%); border: 0; font-family: 'Bahnschrift SemiBold'}");
    m_button_profile->setMinimumSize(QSize(60,90));
    m_button_profile->setText(_profile->name());

    m_layout_profile = new QHBoxLayout();
    m_layout_profile->setSizeConstraint(QLayout::SetMinimumSize);
    m_layout_profile->setMargin(0);
    m_layout_profile->addWidget(m_status_label);
    m_layout_profile->addWidget(m_photo_label);
    m_layout_profile->addWidget(m_button_profile);

    m_frame_profile = new QFrame();
    m_frame_profile->setMaximumSize(QSize(420, 85));
    m_frame_profile->setStyleSheet("QFrame{background: rgba(245, 245, 245,50%); border: 0;}"
                                   "QFrame::hover{background: grey; border: 0;}");
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
