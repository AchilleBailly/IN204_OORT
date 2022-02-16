/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupCamera;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineFov;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineWidth;
    QLineEdit *lineHeight;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineCamX;
    QLineEdit *lineCamY;
    QLineEdit *lineCamZ;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineLookingX;
    QLineEdit *lineLookingY;
    QLineEdit *lineLookingZ;
    QLineEdit *lineSamplingRate;
    QLabel *label_7;
    QLineEdit *lineDepth;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *buttonAddObject;
    QPushButton *buttonUpdateList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonRender;
    QLineEdit *lineEdit;
    QPushButton *buttonLoad;
    QPushButton *buttonSaveImage;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(843, 595);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        groupCamera = new QGroupBox(centralwidget);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupCamera->sizePolicy().hasHeightForWidth());
        groupCamera->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(groupCamera);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupCamera);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineFov = new QLineEdit(groupCamera);
        lineFov->setObjectName(QString::fromUtf8("lineFov"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineFov);

        label_3 = new QLabel(groupCamera);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupCamera);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupCamera);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupCamera);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineWidth = new QLineEdit(groupCamera);
        lineWidth->setObjectName(QString::fromUtf8("lineWidth"));

        horizontalLayout_4->addWidget(lineWidth);

        lineHeight = new QLineEdit(groupCamera);
        lineHeight->setObjectName(QString::fromUtf8("lineHeight"));

        horizontalLayout_4->addWidget(lineHeight);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineCamX = new QLineEdit(groupCamera);
        lineCamX->setObjectName(QString::fromUtf8("lineCamX"));

        horizontalLayout_5->addWidget(lineCamX);

        lineCamY = new QLineEdit(groupCamera);
        lineCamY->setObjectName(QString::fromUtf8("lineCamY"));

        horizontalLayout_5->addWidget(lineCamY);

        lineCamZ = new QLineEdit(groupCamera);
        lineCamZ->setObjectName(QString::fromUtf8("lineCamZ"));

        horizontalLayout_5->addWidget(lineCamZ);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineLookingX = new QLineEdit(groupCamera);
        lineLookingX->setObjectName(QString::fromUtf8("lineLookingX"));

        horizontalLayout_6->addWidget(lineLookingX);

        lineLookingY = new QLineEdit(groupCamera);
        lineLookingY->setObjectName(QString::fromUtf8("lineLookingY"));

        horizontalLayout_6->addWidget(lineLookingY);

        lineLookingZ = new QLineEdit(groupCamera);
        lineLookingZ->setObjectName(QString::fromUtf8("lineLookingZ"));

        horizontalLayout_6->addWidget(lineLookingZ);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_6);

        lineSamplingRate = new QLineEdit(groupCamera);
        lineSamplingRate->setObjectName(QString::fromUtf8("lineSamplingRate"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineSamplingRate);

        label_7 = new QLabel(groupCamera);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        lineDepth = new QLineEdit(groupCamera);
        lineDepth->setObjectName(QString::fromUtf8("lineDepth"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineDepth);


        verticalLayout->addWidget(groupCamera);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label, 0, Qt::AlignBottom);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);
        listWidget->setMaximumSize(QSize(16777215, 192));
        listWidget->setLayoutDirection(Qt::LeftToRight);
        listWidget->setAutoFillBackground(false);

        verticalLayout->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        buttonAddObject = new QPushButton(centralwidget);
        buttonAddObject->setObjectName(QString::fromUtf8("buttonAddObject"));

        horizontalLayout_3->addWidget(buttonAddObject);

        buttonUpdateList = new QPushButton(centralwidget);
        buttonUpdateList->setObjectName(QString::fromUtf8("buttonUpdateList"));

        horizontalLayout_3->addWidget(buttonUpdateList);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonRender = new QPushButton(centralwidget);
        buttonRender->setObjectName(QString::fromUtf8("buttonRender"));
        sizePolicy1.setHeightForWidth(buttonRender->sizePolicy().hasHeightForWidth());
        buttonRender->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(buttonRender, 0, Qt::AlignBottom);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit, 0, Qt::AlignBottom);

        buttonLoad = new QPushButton(centralwidget);
        buttonLoad->setObjectName(QString::fromUtf8("buttonLoad"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(buttonLoad->sizePolicy().hasHeightForWidth());
        buttonLoad->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(buttonLoad, 0, Qt::AlignBottom);

        buttonSaveImage = new QPushButton(centralwidget);
        buttonSaveImage->setObjectName(QString::fromUtf8("buttonSaveImage"));

        horizontalLayout_2->addWidget(buttonSaveImage, 0, Qt::AlignBottom);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 843, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("MainWindow", "Camera setup", nullptr));
#if QT_CONFIG(tooltip)
        label_2->setToolTip(QCoreApplication::translate("MainWindow", "Horizontal field of view of the final image in degress. Minimum 0, maximum 170.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("MainWindow", "Field of view", nullptr));
        lineFov->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        lineFov->setPlaceholderText(QCoreApplication::translate("MainWindow", "Horizontal FOV", nullptr));
#if QT_CONFIG(tooltip)
        label_3->setToolTip(QCoreApplication::translate("MainWindow", "Size in pixels of the final image. Positive, non-zero integer.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("MainWindow", "Image size", nullptr));
#if QT_CONFIG(tooltip)
        label_4->setToolTip(QCoreApplication::translate("MainWindow", "Position in 3D of the camera, up is (0,1,0). Double.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("MainWindow", "Camera position", nullptr));
#if QT_CONFIG(tooltip)
        label_5->setToolTip(QCoreApplication::translate("MainWindow", "Direction in which the camera is looking, up is (0,1,0). Double.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("MainWindow", "Camera Orientation", nullptr));
#if QT_CONFIG(tooltip)
        label_6->setToolTip(QCoreApplication::translate("MainWindow", "Number of rays thrown per pixels, more rays means accuracy but longer computational time. Positive, non-zero integer.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("MainWindow", "Sampling rate", nullptr));
        lineWidth->setText(QCoreApplication::translate("MainWindow", "600", nullptr));
        lineWidth->setPlaceholderText(QCoreApplication::translate("MainWindow", "Width in pixels", nullptr));
        lineHeight->setText(QCoreApplication::translate("MainWindow", "450", nullptr));
        lineHeight->setPlaceholderText(QCoreApplication::translate("MainWindow", "Height in pixels", nullptr));
        lineCamX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineCamX->setPlaceholderText(QCoreApplication::translate("MainWindow", "x coordinate", nullptr));
        lineCamY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineCamY->setPlaceholderText(QCoreApplication::translate("MainWindow", "y coordinate", nullptr));
        lineCamZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineCamZ->setPlaceholderText(QCoreApplication::translate("MainWindow", "z coordinate", nullptr));
        lineLookingX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineLookingX->setPlaceholderText(QCoreApplication::translate("MainWindow", "x coordinate", nullptr));
        lineLookingY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineLookingY->setPlaceholderText(QCoreApplication::translate("MainWindow", "y coordinate", nullptr));
        lineLookingZ->setText(QCoreApplication::translate("MainWindow", "-1", nullptr));
        lineLookingZ->setPlaceholderText(QCoreApplication::translate("MainWindow", "z coordinate", nullptr));
        lineSamplingRate->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lineSamplingRate->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rays per pixel", nullptr));
#if QT_CONFIG(tooltip)
        label_7->setToolTip(QCoreApplication::translate("MainWindow", "Macimum number of bounces each ray can do, recommended is 5. Positive, non-zero integer.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("MainWindow", "Max bounces", nullptr));
#if QT_CONFIG(tooltip)
        lineDepth->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineDepth->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        lineDepth->setPlaceholderText(QCoreApplication::translate("MainWindow", "Depth of recursion", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "List of the objects in the scene :", nullptr));
        buttonAddObject->setText(QCoreApplication::translate("MainWindow", "Add Object", nullptr));
        buttonUpdateList->setText(QCoreApplication::translate("MainWindow", "Update List", nullptr));
        buttonRender->setText(QCoreApplication::translate("MainWindow", "Render", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter file name for the image.", nullptr));
        buttonLoad->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        buttonSaveImage->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
