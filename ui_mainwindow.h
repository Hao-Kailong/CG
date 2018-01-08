/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_O;
    QAction *actionSave_S;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonLine;
    QPushButton *ButtonCircle;
    QPushButton *ButtonOval;
    QPushButton *ButtonDoodle;
    QPushButton *Curve;
    QPushButton *Polygon;
    QWidget *widget;
    QRadioButton *Fill;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditReverse;
    QPushButton *Reverse;
    QLineEdit *lineEditMove;
    QPushButton *Move;
    QLineEdit *lineEditZoom;
    QPushButton *Zoom;
    QPushButton *Cut;
    QPushButton *pushButton;
    QPushButton *D3;
    QMenuBar *menuBar;
    QMenu *menu_O;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(900, 700);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/D:/Draw.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_O = new QAction(MainWindow);
        actionOpen_O->setObjectName(QStringLiteral("actionOpen_O"));
        actionSave_S = new QAction(MainWindow);
        actionSave_S->setObjectName(QStringLiteral("actionSave_S"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/D:/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_S->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 511, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ButtonLine = new QPushButton(horizontalLayoutWidget);
        ButtonLine->setObjectName(QStringLiteral("ButtonLine"));

        horizontalLayout->addWidget(ButtonLine);

        ButtonCircle = new QPushButton(horizontalLayoutWidget);
        ButtonCircle->setObjectName(QStringLiteral("ButtonCircle"));

        horizontalLayout->addWidget(ButtonCircle);

        ButtonOval = new QPushButton(horizontalLayoutWidget);
        ButtonOval->setObjectName(QStringLiteral("ButtonOval"));

        horizontalLayout->addWidget(ButtonOval);

        ButtonDoodle = new QPushButton(horizontalLayoutWidget);
        ButtonDoodle->setObjectName(QStringLiteral("ButtonDoodle"));

        horizontalLayout->addWidget(ButtonDoodle);

        Curve = new QPushButton(horizontalLayoutWidget);
        Curve->setObjectName(QStringLiteral("Curve"));

        horizontalLayout->addWidget(Curve);

        Polygon = new QPushButton(horizontalLayoutWidget);
        Polygon->setObjectName(QStringLiteral("Polygon"));

        horizontalLayout->addWidget(Polygon);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 70, 800, 600));
        Fill = new QRadioButton(centralWidget);
        Fill->setObjectName(QStringLiteral("Fill"));
        Fill->setGeometry(QRect(10, 130, 51, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 41, 51));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(520, 0, 374, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEditReverse = new QLineEdit(horizontalLayoutWidget_2);
        lineEditReverse->setObjectName(QStringLiteral("lineEditReverse"));

        horizontalLayout_3->addWidget(lineEditReverse);

        Reverse = new QPushButton(horizontalLayoutWidget_2);
        Reverse->setObjectName(QStringLiteral("Reverse"));

        horizontalLayout_3->addWidget(Reverse);

        lineEditMove = new QLineEdit(horizontalLayoutWidget_2);
        lineEditMove->setObjectName(QStringLiteral("lineEditMove"));

        horizontalLayout_3->addWidget(lineEditMove);

        Move = new QPushButton(horizontalLayoutWidget_2);
        Move->setObjectName(QStringLiteral("Move"));

        horizontalLayout_3->addWidget(Move);

        lineEditZoom = new QLineEdit(horizontalLayoutWidget_2);
        lineEditZoom->setObjectName(QStringLiteral("lineEditZoom"));

        horizontalLayout_3->addWidget(lineEditZoom);

        Zoom = new QPushButton(horizontalLayoutWidget_2);
        Zoom->setObjectName(QStringLiteral("Zoom"));

        horizontalLayout_3->addWidget(Zoom);

        Cut = new QPushButton(centralWidget);
        Cut->setObjectName(QStringLiteral("Cut"));
        Cut->setGeometry(QRect(10, 160, 51, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 190, 51, 23));
        D3 = new QPushButton(centralWidget);
        D3->setObjectName(QStringLiteral("D3"));
        D3->setGeometry(QRect(10, 620, 51, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 23));
        menu_O = new QMenu(menuBar);
        menu_O->setObjectName(QStringLiteral("menu_O"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_O->menuAction());
        menu_O->addAction(actionSave_S);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
        actionOpen_O->setText(QApplication::translate("MainWindow", "Open(O)", Q_NULLPTR));
        actionSave_S->setText(QApplication::translate("MainWindow", "Save(S)", Q_NULLPTR));
        ButtonLine->setText(QApplication::translate("MainWindow", "Line", Q_NULLPTR));
        ButtonCircle->setText(QApplication::translate("MainWindow", "Circle", Q_NULLPTR));
        ButtonOval->setText(QApplication::translate("MainWindow", "Oval", Q_NULLPTR));
        ButtonDoodle->setText(QApplication::translate("MainWindow", "Doodle", Q_NULLPTR));
        Curve->setText(QApplication::translate("MainWindow", "Curve", Q_NULLPTR));
        Polygon->setText(QApplication::translate("MainWindow", "Polygon", Q_NULLPTR));
        Fill->setText(QApplication::translate("MainWindow", "Fill", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Doodle", Q_NULLPTR));
        Reverse->setText(QApplication::translate("MainWindow", "Reverse", Q_NULLPTR));
        Move->setText(QApplication::translate("MainWindow", "Move", Q_NULLPTR));
        Zoom->setText(QApplication::translate("MainWindow", "Zoom", Q_NULLPTR));
        Cut->setText(QApplication::translate("MainWindow", "Cut", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        D3->setText(QApplication::translate("MainWindow", "3D", Q_NULLPTR));
        menu_O->setTitle(QApplication::translate("MainWindow", "File(F)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
