#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidget>
#include "addobjectwindow.h"
#include "Object3D_list.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void RenderPixMap(QPixmap pixMap);

private slots:
    void on_pushButton_clicked();

    void on_buttonLoad_clicked();

    void on_buttonAddObject_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_indexesMoved(const QModelIndexList &indexes);

    void on_buttonUpdateList_clicked();

    void on_buttonSaveImage_clicked();

    void on_buttonRender_clicked();

    void on_buttonSaveJson_clicked();

    void on_buttonLoadJson_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    AddObjectWindow* addWindow;
    Object3D_list objs;
    std::vector<Vector> result;
};
#endif // MAINWINDOW_H
