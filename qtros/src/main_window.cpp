/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date August 2017
 **/

#include <QtGui>
#include <QMainWindow>
#include <QMessageBox>
#include <iostream>
#include "../include/qtros/main_window.hpp"
#include <QDebug>

namespace qtros {

using namespace Qt;



MainWindow::MainWindow(QNode *node, QWidget *parent)
    : QMainWindow(parent)
    , qnode(node)
{
    ui.setupUi(this);
    QObject::connect(qnode, SIGNAL(rosShutdown()),this, SLOT(close()));
    qDebug()<<qnode->init();
}

MainWindow::~MainWindow() {}

void MainWindow::on_connect_btn_clicked(bool check){
    QMessageBox msgBox;
    msgBox.setText("Hello World");
    msgBox.exec();
}

void MainWindow::on_right_wheel_slider_actionTriggered(void){
    ui.right_wheel_txt->setText(QString::number(ui.right_wheel_slider->value()));
    qnode->setRightAngle(ui.right_wheel_slider->value()*3.14/180.0);
}
void MainWindow::on_left_wheel_slider_actionTriggered(void){
    ui.left_wheel_txt->setText(QString::number(ui.left_wheel_slider->value()));
    qnode->setLeftAngle(ui.left_wheel_slider->value()*3.14/180.0);
}

}  // namespace qtros

