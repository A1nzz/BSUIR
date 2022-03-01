#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

double Dialog::getWidth()
{
    return d_width;
}
double Dialog::getHeight()
{
    return d_height;
}

bool Dialog::isCl()
{
return isClicked;
}

void Dialog::on_pushButton_clicked()
{
    d_width = ui->widthEdit->text().toDouble();
    d_height = ui->heightEdit->text().toDouble();
    isClicked= true;
}

