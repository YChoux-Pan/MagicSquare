/********************************************************************************
** Form generated from reading UI file 'Magic_Square.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGIC_SQUARE_H
#define UI_MAGIC_SQUARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qvtkopenglnativewidget.h>

QT_BEGIN_NAMESPACE

class Ui_Magic_SquareClass
{
public:
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QVTKOpenGLNativeWidget *widget_vtk;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cb_unit;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QLineEdit *le_rotation;
    QPushButton *pb_rotation;
    QLabel *label_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pb_rcRound;
    QPushButton *pb_rcExplode;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pb_U;
    QPushButton *pb_U_CW;
    QPushButton *pb_U_CCW;
    QPushButton *pb_D;
    QPushButton *pb_D_CW;
    QPushButton *pb_D_CCW;
    QPushButton *pb_L;
    QPushButton *pb_L_CW;
    QPushButton *pb_L_CCW;
    QPushButton *pb_R;
    QPushButton *pb_L_CW_2;
    QPushButton *pb_L_CCW_2;
    QPushButton *pb_F;
    QPushButton *pb_F_CW;
    QPushButton *pb_F_CCW;
    QPushButton *pb_B;
    QPushButton *pb_B_CW;
    QPushButton *pb_B_CCW;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Magic_SquareClass)
    {
        if (Magic_SquareClass->objectName().isEmpty())
            Magic_SquareClass->setObjectName("Magic_SquareClass");
        Magic_SquareClass->resize(921, 738);
        horizontalLayout_3 = new QHBoxLayout(Magic_SquareClass);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        frame = new QFrame(Magic_SquareClass);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_vtk = new QVTKOpenGLNativeWidget(frame);
        widget_vtk->setObjectName("widget_vtk");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_vtk->sizePolicy().hasHeightForWidth());
        widget_vtk->setSizePolicy(sizePolicy);
        widget_vtk->setMinimumSize(QSize(500, 700));
        widget_vtk->setStyleSheet(QString::fromUtf8("background-color:rgb(175, 175, 175)"));

        horizontalLayout_2->addWidget(widget_vtk);

        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 317, 698));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(frame_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        cb_unit = new QComboBox(frame_2);
        cb_unit->setObjectName("cb_unit");
        sizePolicy1.setHeightForWidth(cb_unit->sizePolicy().hasHeightForWidth());
        cb_unit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(cb_unit);


        verticalLayout_2->addWidget(frame_2);

        frame_3 = new QFrame(scrollAreaWidgetContents);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        le_rotation = new QLineEdit(frame_3);
        le_rotation->setObjectName("le_rotation");

        gridLayout->addWidget(le_rotation, 1, 1, 1, 1);

        pb_rotation = new QPushButton(frame_3);
        pb_rotation->setObjectName("pb_rotation");

        gridLayout->addWidget(pb_rotation, 0, 0, 1, 2);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout_2->addWidget(frame_3);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        pb_rcRound = new QPushButton(widget);
        pb_rcRound->setObjectName("pb_rcRound");

        verticalLayout->addWidget(pb_rcRound);

        pb_rcExplode = new QPushButton(widget);
        pb_rcExplode->setObjectName("pb_rcExplode");

        verticalLayout->addWidget(pb_rcExplode);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        pb_U = new QPushButton(widget_2);
        pb_U->setObjectName("pb_U");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_U->sizePolicy().hasHeightForWidth());
        pb_U->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_U, 0, 0, 1, 1);

        pb_U_CW = new QPushButton(widget_2);
        pb_U_CW->setObjectName("pb_U_CW");
        sizePolicy2.setHeightForWidth(pb_U_CW->sizePolicy().hasHeightForWidth());
        pb_U_CW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_U_CW, 0, 1, 1, 1);

        pb_U_CCW = new QPushButton(widget_2);
        pb_U_CCW->setObjectName("pb_U_CCW");
        sizePolicy2.setHeightForWidth(pb_U_CCW->sizePolicy().hasHeightForWidth());
        pb_U_CCW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_U_CCW, 0, 2, 1, 1);

        pb_D = new QPushButton(widget_2);
        pb_D->setObjectName("pb_D");
        sizePolicy2.setHeightForWidth(pb_D->sizePolicy().hasHeightForWidth());
        pb_D->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_D, 1, 0, 1, 1);

        pb_D_CW = new QPushButton(widget_2);
        pb_D_CW->setObjectName("pb_D_CW");
        sizePolicy2.setHeightForWidth(pb_D_CW->sizePolicy().hasHeightForWidth());
        pb_D_CW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_D_CW, 1, 1, 1, 1);

        pb_D_CCW = new QPushButton(widget_2);
        pb_D_CCW->setObjectName("pb_D_CCW");
        sizePolicy2.setHeightForWidth(pb_D_CCW->sizePolicy().hasHeightForWidth());
        pb_D_CCW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_D_CCW, 1, 2, 1, 1);

        pb_L = new QPushButton(widget_2);
        pb_L->setObjectName("pb_L");
        sizePolicy2.setHeightForWidth(pb_L->sizePolicy().hasHeightForWidth());
        pb_L->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_L, 2, 0, 1, 1);

        pb_L_CW = new QPushButton(widget_2);
        pb_L_CW->setObjectName("pb_L_CW");
        sizePolicy2.setHeightForWidth(pb_L_CW->sizePolicy().hasHeightForWidth());
        pb_L_CW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_L_CW, 2, 1, 1, 1);

        pb_L_CCW = new QPushButton(widget_2);
        pb_L_CCW->setObjectName("pb_L_CCW");
        sizePolicy2.setHeightForWidth(pb_L_CCW->sizePolicy().hasHeightForWidth());
        pb_L_CCW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_L_CCW, 2, 2, 1, 1);

        pb_R = new QPushButton(widget_2);
        pb_R->setObjectName("pb_R");
        sizePolicy2.setHeightForWidth(pb_R->sizePolicy().hasHeightForWidth());
        pb_R->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_R, 3, 0, 1, 1);

        pb_L_CW_2 = new QPushButton(widget_2);
        pb_L_CW_2->setObjectName("pb_L_CW_2");
        sizePolicy2.setHeightForWidth(pb_L_CW_2->sizePolicy().hasHeightForWidth());
        pb_L_CW_2->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_L_CW_2, 3, 1, 1, 1);

        pb_L_CCW_2 = new QPushButton(widget_2);
        pb_L_CCW_2->setObjectName("pb_L_CCW_2");
        sizePolicy2.setHeightForWidth(pb_L_CCW_2->sizePolicy().hasHeightForWidth());
        pb_L_CCW_2->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_L_CCW_2, 3, 2, 1, 1);

        pb_F = new QPushButton(widget_2);
        pb_F->setObjectName("pb_F");
        sizePolicy2.setHeightForWidth(pb_F->sizePolicy().hasHeightForWidth());
        pb_F->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_F, 4, 0, 1, 1);

        pb_F_CW = new QPushButton(widget_2);
        pb_F_CW->setObjectName("pb_F_CW");
        sizePolicy2.setHeightForWidth(pb_F_CW->sizePolicy().hasHeightForWidth());
        pb_F_CW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_F_CW, 4, 1, 1, 1);

        pb_F_CCW = new QPushButton(widget_2);
        pb_F_CCW->setObjectName("pb_F_CCW");
        sizePolicy2.setHeightForWidth(pb_F_CCW->sizePolicy().hasHeightForWidth());
        pb_F_CCW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_F_CCW, 4, 2, 1, 1);

        pb_B = new QPushButton(widget_2);
        pb_B->setObjectName("pb_B");
        sizePolicy2.setHeightForWidth(pb_B->sizePolicy().hasHeightForWidth());
        pb_B->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_B, 5, 0, 1, 1);

        pb_B_CW = new QPushButton(widget_2);
        pb_B_CW->setObjectName("pb_B_CW");
        sizePolicy2.setHeightForWidth(pb_B_CW->sizePolicy().hasHeightForWidth());
        pb_B_CW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_B_CW, 5, 1, 1, 1);

        pb_B_CCW = new QPushButton(widget_2);
        pb_B_CCW->setObjectName("pb_B_CCW");
        sizePolicy2.setHeightForWidth(pb_B_CCW->sizePolicy().hasHeightForWidth());
        pb_B_CCW->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pb_B_CCW, 5, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 3);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);

        verticalLayout_2->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(17, 228, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        horizontalLayout_2->setStretch(0, 7);
        horizontalLayout_2->setStretch(1, 4);

        horizontalLayout_3->addWidget(frame);


        retranslateUi(Magic_SquareClass);

        QMetaObject::connectSlotsByName(Magic_SquareClass);
    } // setupUi

    void retranslateUi(QWidget *Magic_SquareClass)
    {
        Magic_SquareClass->setWindowTitle(QCoreApplication::translate("Magic_SquareClass", "Magic_Square", nullptr));
        label->setText(QCoreApplication::translate("Magic_SquareClass", "\345\215\225\344\275\215\345\257\271\350\261\241\357\274\232", nullptr));
        pb_rotation->setText(QCoreApplication::translate("Magic_SquareClass", "\350\207\252\350\275\254", nullptr));
        label_2->setText(QCoreApplication::translate("Magic_SquareClass", "\350\207\252\350\275\254\351\200\237\345\272\246\357\274\232", nullptr));
        pb_rcRound->setText(QCoreApplication::translate("Magic_SquareClass", "\345\210\233\345\273\272\351\255\224\346\226\271\351\233\206\345\220\210", nullptr));
        pb_rcExplode->setText(QCoreApplication::translate("Magic_SquareClass", "\347\202\270\345\274\200", nullptr));
        pb_U->setText(QCoreApplication::translate("Magic_SquareClass", "U", nullptr));
        pb_U_CW->setText(QCoreApplication::translate("Magic_SquareClass", "+", nullptr));
        pb_U_CCW->setText(QCoreApplication::translate("Magic_SquareClass", "-", nullptr));
        pb_D->setText(QCoreApplication::translate("Magic_SquareClass", "D", nullptr));
        pb_D_CW->setText(QCoreApplication::translate("Magic_SquareClass", "+", nullptr));
        pb_D_CCW->setText(QCoreApplication::translate("Magic_SquareClass", "-", nullptr));
        pb_L->setText(QCoreApplication::translate("Magic_SquareClass", "L", nullptr));
        pb_L_CW->setText(QCoreApplication::translate("Magic_SquareClass", "+", nullptr));
        pb_L_CCW->setText(QCoreApplication::translate("Magic_SquareClass", "-", nullptr));
        pb_R->setText(QCoreApplication::translate("Magic_SquareClass", "R", nullptr));
        pb_L_CW_2->setText(QCoreApplication::translate("Magic_SquareClass", "+", nullptr));
        pb_L_CCW_2->setText(QCoreApplication::translate("Magic_SquareClass", "-", nullptr));
        pb_F->setText(QCoreApplication::translate("Magic_SquareClass", "F", nullptr));
        pb_F_CW->setText(QCoreApplication::translate("Magic_SquareClass", "+", nullptr));
        pb_F_CCW->setText(QCoreApplication::translate("Magic_SquareClass", "-", nullptr));
        pb_B->setText(QCoreApplication::translate("Magic_SquareClass", "B", nullptr));
        pb_B_CW->setText(QCoreApplication::translate("Magic_SquareClass", "+", nullptr));
        pb_B_CCW->setText(QCoreApplication::translate("Magic_SquareClass", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Magic_SquareClass: public Ui_Magic_SquareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGIC_SQUARE_H
