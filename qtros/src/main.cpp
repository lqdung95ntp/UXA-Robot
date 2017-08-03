/**
 * @file /src/main.cpp
 *
 * @brief qtros.
 *
 * @date August 2017
 **/

#include <QtGui>
#include <QApplication>
#include "../include/qtros/main_window.hpp"
#include "../qtalker/talker.hpp"

int main(int argc, char **argv) {

    QApplication app(argc, argv);
    qtros::Talker talker(argc, argv);
    qtros::MainWindow w(&talker);
    w.show();
//    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

	return result;
}
