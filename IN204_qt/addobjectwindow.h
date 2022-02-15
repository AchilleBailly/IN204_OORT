#ifndef ADDOBJECTWINDOW_H
#define ADDOBJECTWINDOW_H

#include <QMainWindow>
#include "Object3D_list.hpp"
#include "temp.hpp"

namespace Ui {
class AddObjectWindow;
}

class AddObjectWindow : public QMainWindow
{
    Q_OBJECT

public:
    AddObjectWindow(Object3D_list& objs, QWidget *parent = nullptr);
    AddObjectWindow(Object3D_list& objs, shared_ptr<Object3D> to_modify, QWidget *parent = nullptr);
    ~AddObjectWindow();

private slots:
    void on_comboBox_activated(int index);

    void on_buttonAddObject_clicked();

private:
    Ui::AddObjectWindow *ui;
    Object3D_list &list;
    shared_ptr<Object3D> to_modify;
    bool modifying = false;

    void setupOnModify(Sphere& s);
    void setupOnModify(Plane& p);
};

#endif // ADDOBJECTWINDOW_H
