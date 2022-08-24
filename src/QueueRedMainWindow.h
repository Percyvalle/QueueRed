#ifndef QUEUEREDMAINWINDOW_H
#define QUEUEREDMAINWINDOW_H

#include <QMainWindow>
#include "QueueRedProfile.h"
#include "QueueRedProfileWidget.h"
#include "QueueRedAuth.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QueueRedMainWindow; }
QT_END_NAMESPACE

class QueueRedMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QueueRedMainWindow(QWidget *_parent = nullptr);
    ~QueueRedMainWindow();

private slots:
    /***
     * @brief Слот отвечающий за реакцию на нажание кнопки "Сотрудники"
     ***/
    void employees_button();

    /***
     * @brief Слот отвечающий за реакцию на нажание кнопки "Профиль"
     ***/
    void profile_button();

    /***
     * @brief Слот отвечающий за реакцию на нажание кнопки "Задачи"
     ***/
    void tasks_button();

    /***
     * @brief Слот отвечающий на создание профиля
     * @param but Кнопка для коннекта с основным окном
     ***/
    void profile_connection(QPushButton* but);
    void profile_members_button();
    void auth_done_show(QueueRedProfileMain* _profile_main, QVector<QueueRedProfileMember*> _members_list);

private:
    void connectionUI();
    void connectionAUTH();
    void init_icon();
    void auth_dialog_ready();
    void set_profile_main_ui();
    void update_profile_area();

    Ui::QueueRedMainWindow *ui;

    QueueRedProfileWidget *m_profile_widget = new QueueRedProfileWidget();
    QueueRedProfileMain *m_profile_main;
    QVector<QueueRedProfileMember*> m_members_list;
    QueueRedAuth *m_auth_dialog = new QueueRedAuth();
};
#endif // QUEUEREDMAINWINDOW_H
