#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "temp.hpp"
#include "QImage"
#include "Error.hpp"
#include "addobjectwindow.h"
#include "QEventLoop"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    result.resize(1,Vector(0));

    objs.load_from_json("test_object.json");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::RenderPixMap(QPixmap pixMap) {
    scene->addPixmap(pixMap);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}


void MainWindow::on_buttonLoad_clicked()
{
    auto fileName = ui->lineEdit->text() + ".ppm";
    QPixmap pixMap = QPixmap(fileName);
    if(pixMap.isNull()){
        Error error("Please enter a valid file name.");
        return;
    }
    RenderPixMap(pixMap);
}


void MainWindow::on_buttonAddObject_clicked()
{
    addWindow = new AddObjectWindow(objs, this);
    addWindow->show();
    addWindow->setAttribute(Qt::WA_DeleteOnClose);
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *)
{
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    auto obj = objs.getObjectByLabel(item->text());
    addWindow = new AddObjectWindow(objs, obj, this);
    addWindow->show();
    addWindow->setAttribute(Qt::WA_DeleteOnClose);
}



void MainWindow::on_listWidget_indexesMoved(const QModelIndexList &)
{
}


void MainWindow::on_buttonUpdateList_clicked()
{
    ui->listWidget->clear();
    auto it = objs.objects.begin();
    auto end = objs.objects.end();
    for(;it != end; it++){
        ui->listWidget->addItem((*it)->label);
    }
}


void MainWindow::on_buttonSaveImage_clicked()
{
    auto fileName = ui->lineEdit->text().toStdString();
    unsigned width = ui->lineWidth->text().toUInt();
    unsigned height = ui->lineHeight->text().toUInt();
    save_vector(fileName, result, width,height);
    Error("Image saved !");
}


void MainWindow::on_buttonRender_clicked()
{
    bool validConversion = true;
    double posx = ui->lineCamX->text().toDouble(&validConversion);
    double posy = ui->lineCamY->text().toDouble(&validConversion);
    double posz = ui->lineCamZ->text().toDouble(&validConversion);
    double orienx = ui->lineLookingX->text().toDouble(&validConversion);
    double orieny = ui->lineLookingY->text().toDouble(&validConversion);
    double orienz = ui->lineLookingZ->text().toDouble(&validConversion);
    double fov = ui->lineFov->text().toDouble(&validConversion);
    unsigned width = ui->lineWidth->text().toUInt(&validConversion);
    unsigned height = ui->lineHeight->text().toUInt(&validConversion);
    unsigned smprate = ui->lineSamplingRate->text().toUInt(&validConversion);
    unsigned depth = ui->lineDepth->text().toUInt(&validConversion);
    if(!validConversion || fov < 1 || fov > 170 || width < 1 || height < 1 || smprate < 1 || depth < 1) {
        Error("Error in the camera's parameters. Please verify they meet the conditions.");
        return;
    }
    Camera test_cam({posx, posy, posz}, {orienx, orieny, orienz}, fov, width, height);
    test_cam.set_number_samples(smprate);

    qDebug() << test_cam;

    Engines engines;
    TimeMeasuring t2;
    t2.setStart();
    result = test_cam.render(engines.ray_trace3, objs, depth);
    t2.setEnd();

    qDebug() << "Temps de calcul " << t2.getAverageDuration().count();
}


void MainWindow::on_buttonSaveJson_clicked()
{
    auto fileName = ui->lineJsonFileName->text().toStdString();
    std::ofstream output(fileName);
    if(!output){
        Error("Please make sure you have entered the right file name.");
        return;
    }

    output << std::setw(4) << objs.to_json() << std::endl;
}


void MainWindow::on_buttonLoadJson_clicked()
{
    auto fileName = ui->lineJsonFileName->text().toStdString();
    std::ifstream in(fileName);
    if(!in){
        Error("Please make sure you have entered the right file name.");
        return;
    }

    json input;
    in >> input;
    try {
        objs.from_json(input);
    }  catch (const json::exception& e) {
        Error("Json file containing the list is corrupted.");
        return;
    }
}


void MainWindow::on_buttonEmpty_clicked()
{
    objs.objects.erase(objs.objects.begin(), objs.objects.end());
    on_buttonUpdateList_clicked();
}

