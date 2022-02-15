#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(const QString& text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText(text);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_buttonOk_clicked()
{
    qDebug() << "function called";
    this->~Dialog();
}


void Dialog::on_label_linkActivated(const QString &)
{
}


void Dialog::on_Dialog_accepted()
{
}

