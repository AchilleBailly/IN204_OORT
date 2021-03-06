#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(const QString& text, QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_Dialog_accepted();

    void on_label_linkActivated(const QString &link);

    void on_buttonOk_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
