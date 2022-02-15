#include "addobjectwindow.h"
#include "ui_addobjectwindow.h"
#include "utils.hpp"
#include <QString>
#include "Error.hpp"
#include "temp.hpp"

AddObjectWindow::AddObjectWindow(Object3D_list& objs, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddObjectWindow),
    list(objs)
{
    ui->setupUi(this);
    this->on_comboBox_activated(0);
}

AddObjectWindow::AddObjectWindow(Object3D_list& objs, shared_ptr<Object3D> _to_modify, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::AddObjectWindow),
    list(objs),
    to_modify(_to_modify)
{
    ui->setupUi(this);
    this->on_comboBox_activated(0);
    modifying = true;
    ui->buttonAddObject->setText("Modify Object");
    try {
        setupOnModify(dynamic_cast<Sphere&>(*(_to_modify.get())));
    }
    catch (const std::bad_cast& e) {
        try{
            setupOnModify(dynamic_cast<Plane&>(*(_to_modify.get())));
        }
        catch (const std::bad_cast& e){}
    }

}

void AddObjectWindow::setupOnModify(Sphere& s) {
    ui->tabWidget->setCurrentIndex(0); // Sphere
    // setting the text of every field
    ui->lineSphereLabel->setText(s.label);
    ui->lineRadius->setText(QString::number(s.radius));
    ui->linePositionX->setText(QString::number(s.position.x));
    ui->linePositionY->setText(QString::number(s.position.y));
    ui->linePositionZ->setText(QString::number(s.position.z));
    try { // transparent material
        Transparent& glass = dynamic_cast<Transparent&>(*(s.material.get()));
        ui->lineIoR->setText(QString::number(glass.ior));
        ui->lineReflectivity->setText(QString::number(glass.reflectivity));
        ui->lineAbsorptionR->setText(QString::number(glass.absorption.x));
        ui->lineAbsorptionG->setText(QString::number(glass.absorption.y));
        ui->lineAbsorptionB->setText(QString::number(glass.absorption.z));
    } catch (const std::bad_cast& e){}

    try { // Metal material
        Metal& m = dynamic_cast<Metal&>(*(s.material.get()));
        ui->lineMetalAlbedoR->setText(QString::number(m.albedo.x));
        ui->lineMetalAlbedoG->setText(QString::number(m.albedo.y));
        ui->lineMetalAlbedoB->setText(QString::number(m.albedo.z));
    }  catch (const std::bad_cast& e) {}

    try { // Diffuse material
        Diffuse& d = dynamic_cast<Diffuse&>(*(s.material.get()));
        ui->lineDiffuseR->setText(QString::number(d.albedo.x));
        ui->lineDiffuseG->setText(QString::number(d.albedo.y));
        ui->lineDiffuseB->setText(QString::number(d.albedo.z));
    }  catch (const std::bad_cast& e) {}

    try { // Light Source
        LightSource& l = dynamic_cast<LightSource&>(*(s.material.get()));
        ui->lineLightR->setText(QString::number(l.color.x));
        ui->lineLightG->setText(QString::number(l.color.y));
        ui->lineLightB->setText(QString::number(l.color.z));
    } catch(const std::bad_cast& e) {}
    // if no cast possible, dont fill anything
}

void AddObjectWindow::setupOnModify(Plane& p) {}

AddObjectWindow::~AddObjectWindow()
{
    delete ui;
}

void AddObjectWindow::on_comboBox_activated(int index)
{
    ui->groupGlass->setVisible((index == 0) ? true:false);
    ui->groupMetal->setVisible((index == 2) ? true:false);
    ui->groupDiffuse->setVisible((index == 1) ? true:false);
    ui->groupLightSource->setVisible((index == 3) ? true:false);
}


void AddObjectWindow::on_buttonAddObject_clicked()
{
    bool validConversion = true;
    auto sphereLabel = ui->lineSphereLabel->text();
    double r = ui->lineRadius->text().toDouble(&validConversion);
    double x = ui->linePositionX->text().toDouble(&validConversion);
    double y =  ui->linePositionY->text().toDouble(&validConversion);
    double z = ui->linePositionZ->text().toDouble(&validConversion);
    Vector position;
    if(validConversion)
        position = Vector(x, y, z);
    shared_ptr<Material> material;

    if(ui->comboBox->currentText() == "Glass"){
        double ior = ui->lineIoR->text().toDouble(&validConversion);
        double reflectivity = ui->lineReflectivity->text().toDouble(&validConversion);
        double absorptionR = ui->lineAbsorptionR->text().toDouble(&validConversion);
        double absorptionG = ui->lineAbsorptionG->text().toDouble(&validConversion);
        double absorptionB = ui->lineAbsorptionB->text().toDouble(&validConversion);
        if(validConversion && ior >= 1 && absorptionB >=0 && absorptionG >=0 && absorptionR >=0)
            material = make_shared<Transparent>(ior,reflectivity,Vector(absorptionR, absorptionG, absorptionB));
    }
    else if(ui->comboBox->currentText() == "Metal"){
        double r = ui->lineMetalAlbedoR->text().toDouble();
        double g = ui->lineMetalAlbedoG->text().toDouble();
        double b = ui->lineAbsorptionB->text().toDouble();
        double fuzz = ui->lineFuzziness->text().toDouble();
        if(validConversion && r >=0 && g >= 0 && b >= 0)
            material = make_shared<Metal>(Vector(r,g,b), fuzz);
    }
    else if(ui->comboBox->currentText() == "Diffuse material"){
        double r = ui->lineDiffuseR->text().toDouble();
        double g = ui->lineDiffuseG->text().toDouble();
        double b = ui->lineDiffuseB->text().toDouble();
        if(validConversion && r >=0 && g >= 0 && b >= 0)
            material = make_shared<Diffuse>(Vector(r,g,b));
    }
    else {
        double r = ui->lineLightR->text().toDouble();
        double g = ui->lineLightG->text().toDouble();
        double b = ui->lineLightB->text().toDouble();
        if(validConversion && r >=0 && g >= 0 && b >= 0)
            material = make_shared<LightSource>(Vector(r,g,b));
    }

    if(!validConversion){
        Error("Please make sure that your values verify the conditions and are floating point values.");
        return;
    }

    shared_ptr<Sphere> s = make_shared<Sphere>(r,position,material);
    s->setLabel(sphereLabel);
    for(auto it = list.objects.begin(); it != list.objects.end(); it++){
        if((*it)->label == s->label){
            Error("Label not unique ! Please change it.");
            return;
        }
    }
    if(modifying){
        for(auto it = list.objects.begin(); it != list.objects.end(); it++){
            if((*it)->label == to_modify->label)
                *it = s;
        }
    }
    else
        list.add(s);
    this->close();
}

