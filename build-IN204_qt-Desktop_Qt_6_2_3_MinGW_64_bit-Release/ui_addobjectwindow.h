/********************************************************************************
** Form generated from reading UI file 'addobjectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOBJECTWINDOW_H
#define UI_ADDOBJECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddObjectWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFormLayout *formLayout;
    QLabel *labelPosition;
    QHBoxLayout *horizontalLayout;
    QLineEdit *linePositionX;
    QLineEdit *linePositionY;
    QLineEdit *linePositionZ;
    QLabel *labelMaterial;
    QComboBox *comboBox;
    QGroupBox *groupGlass;
    QFormLayout *formLayout_2;
    QLabel *labelIoR_2;
    QLineEdit *lineIoR;
    QLineEdit *lineReflectivity;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineAbsorptionR;
    QLineEdit *lineAbsorptionG;
    QLineEdit *lineAbsorptionB;
    QLabel *labelReflectivity;
    QLabel *labelAbsorption;
    QGroupBox *groupMetal;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineFuzziness;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineMetalAlbedoR;
    QLineEdit *lineMetalAlbedoG;
    QLineEdit *lineMetalAlbedoB;
    QGroupBox *groupDiffuse;
    QFormLayout *formLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineDiffuseR;
    QLineEdit *lineDiffuseG;
    QLineEdit *lineDiffuseB;
    QGroupBox *groupLightSource;
    QFormLayout *formLayout_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineLightR;
    QLineEdit *lineLightG;
    QLineEdit *lineLightB;
    QPushButton *buttonAddObject;
    QLabel *label_3;
    QLineEdit *lineSphereLabel;
    QLabel *label_4;
    QLineEdit *lineRadius;
    QWidget *tab_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddObjectWindow)
    {
        if (AddObjectWindow->objectName().isEmpty())
            AddObjectWindow->setObjectName(QString::fromUtf8("AddObjectWindow"));
        AddObjectWindow->resize(800, 600);
        centralwidget = new QWidget(AddObjectWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        formLayout = new QFormLayout(tab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelPosition = new QLabel(tab);
        labelPosition->setObjectName(QString::fromUtf8("labelPosition"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPosition);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        linePositionX = new QLineEdit(tab);
        linePositionX->setObjectName(QString::fromUtf8("linePositionX"));

        horizontalLayout->addWidget(linePositionX);

        linePositionY = new QLineEdit(tab);
        linePositionY->setObjectName(QString::fromUtf8("linePositionY"));

        horizontalLayout->addWidget(linePositionY);

        linePositionZ = new QLineEdit(tab);
        linePositionZ->setObjectName(QString::fromUtf8("linePositionZ"));

        horizontalLayout->addWidget(linePositionZ);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        labelMaterial = new QLabel(tab);
        labelMaterial->setObjectName(QString::fromUtf8("labelMaterial"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelMaterial);

        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox);

        groupGlass = new QGroupBox(tab);
        groupGlass->setObjectName(QString::fromUtf8("groupGlass"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupGlass->sizePolicy().hasHeightForWidth());
        groupGlass->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(groupGlass);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelIoR_2 = new QLabel(groupGlass);
        labelIoR_2->setObjectName(QString::fromUtf8("labelIoR_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelIoR_2);

        lineIoR = new QLineEdit(groupGlass);
        lineIoR->setObjectName(QString::fromUtf8("lineIoR"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineIoR);

        lineReflectivity = new QLineEdit(groupGlass);
        lineReflectivity->setObjectName(QString::fromUtf8("lineReflectivity"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineReflectivity);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineAbsorptionR = new QLineEdit(groupGlass);
        lineAbsorptionR->setObjectName(QString::fromUtf8("lineAbsorptionR"));

        horizontalLayout_2->addWidget(lineAbsorptionR);

        lineAbsorptionG = new QLineEdit(groupGlass);
        lineAbsorptionG->setObjectName(QString::fromUtf8("lineAbsorptionG"));

        horizontalLayout_2->addWidget(lineAbsorptionG);

        lineAbsorptionB = new QLineEdit(groupGlass);
        lineAbsorptionB->setObjectName(QString::fromUtf8("lineAbsorptionB"));

        horizontalLayout_2->addWidget(lineAbsorptionB);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        labelReflectivity = new QLabel(groupGlass);
        labelReflectivity->setObjectName(QString::fromUtf8("labelReflectivity"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelReflectivity);

        labelAbsorption = new QLabel(groupGlass);
        labelAbsorption->setObjectName(QString::fromUtf8("labelAbsorption"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelAbsorption);


        formLayout->setWidget(4, QFormLayout::FieldRole, groupGlass);

        groupMetal = new QGroupBox(tab);
        groupMetal->setObjectName(QString::fromUtf8("groupMetal"));
        sizePolicy.setHeightForWidth(groupMetal->sizePolicy().hasHeightForWidth());
        groupMetal->setSizePolicy(sizePolicy);
        formLayout_3 = new QFormLayout(groupMetal);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_7 = new QLabel(groupMetal);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(groupMetal);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_8);

        lineFuzziness = new QLineEdit(groupMetal);
        lineFuzziness->setObjectName(QString::fromUtf8("lineFuzziness"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineFuzziness);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineMetalAlbedoR = new QLineEdit(groupMetal);
        lineMetalAlbedoR->setObjectName(QString::fromUtf8("lineMetalAlbedoR"));

        horizontalLayout_3->addWidget(lineMetalAlbedoR);

        lineMetalAlbedoG = new QLineEdit(groupMetal);
        lineMetalAlbedoG->setObjectName(QString::fromUtf8("lineMetalAlbedoG"));

        horizontalLayout_3->addWidget(lineMetalAlbedoG);

        lineMetalAlbedoB = new QLineEdit(groupMetal);
        lineMetalAlbedoB->setObjectName(QString::fromUtf8("lineMetalAlbedoB"));

        horizontalLayout_3->addWidget(lineMetalAlbedoB);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout_3);


        formLayout->setWidget(5, QFormLayout::FieldRole, groupMetal);

        groupDiffuse = new QGroupBox(tab);
        groupDiffuse->setObjectName(QString::fromUtf8("groupDiffuse"));
        sizePolicy.setHeightForWidth(groupDiffuse->sizePolicy().hasHeightForWidth());
        groupDiffuse->setSizePolicy(sizePolicy);
        formLayout_4 = new QFormLayout(groupDiffuse);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label = new QLabel(groupDiffuse);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineDiffuseR = new QLineEdit(groupDiffuse);
        lineDiffuseR->setObjectName(QString::fromUtf8("lineDiffuseR"));

        horizontalLayout_4->addWidget(lineDiffuseR);

        lineDiffuseG = new QLineEdit(groupDiffuse);
        lineDiffuseG->setObjectName(QString::fromUtf8("lineDiffuseG"));

        horizontalLayout_4->addWidget(lineDiffuseG);

        lineDiffuseB = new QLineEdit(groupDiffuse);
        lineDiffuseB->setObjectName(QString::fromUtf8("lineDiffuseB"));

        horizontalLayout_4->addWidget(lineDiffuseB);


        formLayout_4->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);


        formLayout->setWidget(6, QFormLayout::FieldRole, groupDiffuse);

        groupLightSource = new QGroupBox(tab);
        groupLightSource->setObjectName(QString::fromUtf8("groupLightSource"));
        formLayout_5 = new QFormLayout(groupLightSource);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_2 = new QLabel(groupLightSource);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineLightR = new QLineEdit(groupLightSource);
        lineLightR->setObjectName(QString::fromUtf8("lineLightR"));

        horizontalLayout_5->addWidget(lineLightR);

        lineLightG = new QLineEdit(groupLightSource);
        lineLightG->setObjectName(QString::fromUtf8("lineLightG"));

        horizontalLayout_5->addWidget(lineLightG);

        lineLightB = new QLineEdit(groupLightSource);
        lineLightB->setObjectName(QString::fromUtf8("lineLightB"));

        horizontalLayout_5->addWidget(lineLightB);


        formLayout_5->setLayout(0, QFormLayout::FieldRole, horizontalLayout_5);


        formLayout->setWidget(7, QFormLayout::FieldRole, groupLightSource);

        buttonAddObject = new QPushButton(tab);
        buttonAddObject->setObjectName(QString::fromUtf8("buttonAddObject"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonAddObject->sizePolicy().hasHeightForWidth());
        buttonAddObject->setSizePolicy(sizePolicy1);

        formLayout->setWidget(8, QFormLayout::FieldRole, buttonAddObject);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lineSphereLabel = new QLineEdit(tab);
        lineSphereLabel->setObjectName(QString::fromUtf8("lineSphereLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineSphereLabel);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineRadius = new QLineEdit(tab);
        lineRadius->setObjectName(QString::fromUtf8("lineRadius"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineRadius);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        AddObjectWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AddObjectWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddObjectWindow->setStatusBar(statusbar);

        retranslateUi(AddObjectWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddObjectWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddObjectWindow)
    {
        AddObjectWindow->setWindowTitle(QCoreApplication::translate("AddObjectWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        labelPosition->setToolTip(QCoreApplication::translate("AddObjectWindow", "Position in 3D space of the center of the sphere", nullptr));
#endif // QT_CONFIG(tooltip)
        labelPosition->setText(QCoreApplication::translate("AddObjectWindow", "Position ", nullptr));
        linePositionX->setText(QString());
        linePositionX->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Enter x coordinate", nullptr));
        linePositionY->setText(QString());
        linePositionY->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Enter y coordinate", nullptr));
        linePositionZ->setText(QString());
        linePositionZ->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Enter z coordinate", nullptr));
#if QT_CONFIG(tooltip)
        labelMaterial->setToolTip(QCoreApplication::translate("AddObjectWindow", "Material that the sphere will be made of", nullptr));
#endif // QT_CONFIG(tooltip)
        labelMaterial->setText(QCoreApplication::translate("AddObjectWindow", "Material", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AddObjectWindow", "Glass", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AddObjectWindow", "Diffuse material", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("AddObjectWindow", "Metal", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("AddObjectWindow", "Light source", nullptr));

        groupGlass->setTitle(QCoreApplication::translate("AddObjectWindow", "Glass properties", nullptr));
#if QT_CONFIG(tooltip)
        labelIoR_2->setToolTip(QCoreApplication::translate("AddObjectWindow", "Index of refraction (at least 1.0)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelIoR_2->setText(QCoreApplication::translate("AddObjectWindow", "Index of refraction", nullptr));
        lineIoR->setText(QString());
        lineIoR->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Index of refraction of the glass (at least 1.0)", nullptr));
        lineReflectivity->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Reflectivity of the glass (between 0.0 and 1.0)", nullptr));
        lineAbsorptionR->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Absorption of red color (at least 0.0)", nullptr));
        lineAbsorptionG->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Absorption of green color (at least 0.0)", nullptr));
        lineAbsorptionB->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Absorption of blue color (at least 0.0)", nullptr));
#if QT_CONFIG(tooltip)
        labelReflectivity->setToolTip(QCoreApplication::translate("AddObjectWindow", "How much the glass reflects (betwen 0.0 and 1.0)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelReflectivity->setText(QCoreApplication::translate("AddObjectWindow", "Reflectivity", nullptr));
#if QT_CONFIG(tooltip)
        labelAbsorption->setToolTip(QCoreApplication::translate("AddObjectWindow", "How much of each color channel the glass absorb", nullptr));
#endif // QT_CONFIG(tooltip)
        labelAbsorption->setText(QCoreApplication::translate("AddObjectWindow", "Absorption", nullptr));
        groupMetal->setTitle(QCoreApplication::translate("AddObjectWindow", "Metal properties", nullptr));
#if QT_CONFIG(tooltip)
        label_7->setToolTip(QCoreApplication::translate("AddObjectWindow", "Color of the metal it were not reflecting part of the light", nullptr));
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("AddObjectWindow", "Albedo", nullptr));
#if QT_CONFIG(tooltip)
        label_8->setToolTip(QCoreApplication::translate("AddObjectWindow", "To what extent the metal doesn't reflect like a mirror, how shady it is", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("AddObjectWindow", "Fuzziness", nullptr));
        lineFuzziness->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "How much it reflects not like a mirror (between 0.0 and 1.0)", nullptr));
        lineMetalAlbedoR->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Red part of the metal's color (>0.0)", nullptr));
        lineMetalAlbedoG->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Green part of the metal's color (>0.0)", nullptr));
        lineMetalAlbedoB->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Blue part of the metal's color (>0.0)", nullptr));
        groupDiffuse->setTitle(QCoreApplication::translate("AddObjectWindow", "Diffuse material properties", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("AddObjectWindow", "Color of the diffuse material", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("AddObjectWindow", "Albedo", nullptr));
        lineDiffuseR->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Red part of the color (>0.0)", nullptr));
        lineDiffuseG->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Green part of the color (>0.0)", nullptr));
        lineDiffuseB->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Blue part of the color (>0.0)", nullptr));
        groupLightSource->setTitle(QCoreApplication::translate("AddObjectWindow", "Light source properties", nullptr));
#if QT_CONFIG(tooltip)
        label_2->setToolTip(QCoreApplication::translate("AddObjectWindow", "Color of the light. Best to chose a higher than one value (the higher, the brighter)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("AddObjectWindow", "Color", nullptr));
        lineLightR->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Red part of the color (>0.0)", nullptr));
        lineLightG->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Green part of the color (>0.0)", nullptr));
        lineLightB->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Blue part of the color (>0.0)", nullptr));
        buttonAddObject->setText(QCoreApplication::translate("AddObjectWindow", "Add Sphere", nullptr));
        label_3->setText(QCoreApplication::translate("AddObjectWindow", "Label", nullptr));
#if QT_CONFIG(tooltip)
        lineSphereLabel->setToolTip(QCoreApplication::translate("AddObjectWindow", "Label of the sphere, must be unique", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("AddObjectWindow", "Radius", nullptr));
#if QT_CONFIG(tooltip)
        lineRadius->setToolTip(QCoreApplication::translate("AddObjectWindow", "Radius of the sphere", nullptr));
#endif // QT_CONFIG(tooltip)
        lineRadius->setText(QString());
        lineRadius->setPlaceholderText(QCoreApplication::translate("AddObjectWindow", "Radius of the sphere", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AddObjectWindow", "Sphere", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AddObjectWindow", "Plane", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddObjectWindow: public Ui_AddObjectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOBJECTWINDOW_H
