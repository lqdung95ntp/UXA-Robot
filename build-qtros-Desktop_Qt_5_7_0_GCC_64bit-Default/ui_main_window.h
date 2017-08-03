/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_2;
    QPushButton *connect_btn;
    QSlider *right_wheel_slider;
    QSlider *left_wheel_slider;
    QLabel *label;
    QLabel *label_2;
    QLabel *right_wheel_txt;
    QLabel *left_wheel_txt;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(264, 158);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        connect_btn = new QPushButton(groupBox_2);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));
        connect_btn->setGeometry(QRect(10, 30, 71, 22));
        right_wheel_slider = new QSlider(groupBox_2);
        right_wheel_slider->setObjectName(QString::fromUtf8("right_wheel_slider"));
        right_wheel_slider->setGeometry(QRect(90, 60, 111, 20));
        right_wheel_slider->setMaximum(360);
        right_wheel_slider->setOrientation(Qt::Horizontal);
        left_wheel_slider = new QSlider(groupBox_2);
        left_wheel_slider->setObjectName(QString::fromUtf8("left_wheel_slider"));
        left_wheel_slider->setGeometry(QRect(90, 90, 111, 20));
        left_wheel_slider->setMaximum(360);
        left_wheel_slider->setOrientation(Qt::Horizontal);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 81, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 71, 16));
        right_wheel_txt = new QLabel(groupBox_2);
        right_wheel_txt->setObjectName(QString::fromUtf8("right_wheel_txt"));
        right_wheel_txt->setGeometry(QRect(210, 60, 59, 14));
        left_wheel_txt = new QLabel(groupBox_2);
        left_wheel_txt->setObjectName(QString::fromUtf8("left_wheel_txt"));
        left_wheel_txt->setGeometry(QRect(210, 90, 59, 14));

        hboxLayout->addWidget(groupBox_2);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 264, 19));
        MainWindowDesign->setMenuBar(menubar);

        retranslateUi(MainWindowDesign);

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindowDesign", "GroupBox", 0, QApplication::UnicodeUTF8));
        connect_btn->setText(QApplication::translate("MainWindowDesign", "connect", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "Right Wheel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowDesign", "Left Wheel", 0, QApplication::UnicodeUTF8));
        right_wheel_txt->setText(QApplication::translate("MainWindowDesign", "0", 0, QApplication::UnicodeUTF8));
        left_wheel_txt->setText(QApplication::translate("MainWindowDesign", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
