#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cStringVisual.h"
#include "Header.h"
#include <QMessageBox>


class cStringVisual : public QMainWindow
{
    Q_OBJECT

public:
    cStringVisual(QWidget *parent = Q_NULLPTR);

private slots:
    void on_pushButton_clicked();
private:
    Ui::cStringVisualClass ui;

};
