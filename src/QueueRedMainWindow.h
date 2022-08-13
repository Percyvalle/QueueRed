#ifndef QUEUEREDMAINWINDOW_H
#define QUEUEREDMAINWINDOW_H

#include <QMainWindow>
#include "QueueRedProfile.h"
#include "QueueRedProfileWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QueueRedMainWindow; }
QT_END_NAMESPACE

class QueueRedMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QueueRedMainWindow(QWidget *_parent = nullptr);
    ~QueueRedMainWindow();

    void connectionUI();

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

    void profile_connection(QPushButton* but);

    void profile_members_button();

private:
    Ui::QueueRedMainWindow *ui;

    QueueRedProfileWidget *profile_widget = new QueueRedProfileWidget();
};
#endif // QUEUEREDMAINWINDOW_H
