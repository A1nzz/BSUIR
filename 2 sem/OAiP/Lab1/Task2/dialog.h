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
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    double getWidth();
    double getHeight();
    bool isCl();

private slots:
    void on_pushButton_clicked();
private:
    double d_width;
    double d_height;
    bool isClicked = false;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
