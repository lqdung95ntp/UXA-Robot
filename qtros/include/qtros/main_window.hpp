/**
 * @file /include/qtros/main_window.hpp
 *
 * @brief Qt based gui for qtros.
 *
 * @date August 2017
 **/
#ifndef qtros_MAIN_WINDOW_H
#define qtros_MAIN_WINDOW_H


#ifndef Q_MOC_RUN
#include "/home/lqdung/catkin_ws//build/qtros/ui_main_window.h"
#include "qnode.hpp"
#endif
#include <QtGui/QMainWindow>
#include <QThread>
#include <QStringListModel>

namespace qtros {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QNode *node, QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:

    void on_connect_btn_clicked(bool check);
    void on_right_wheel_slider_actionTriggered(void);
    void on_left_wheel_slider_actionTriggered(void);

private:
    Ui::MainWindowDesign ui;
    QNode *qnode;
};

}  // namespace qtros


#endif // qtros_MAIN_WINDOW_H
