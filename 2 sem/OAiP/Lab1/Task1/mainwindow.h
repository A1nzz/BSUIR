#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rect.h"
#include "car.h"
#include "lights.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>
#include <QTimer>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QGraphicsScene *scn;
    Rect *rect = new Rect(100, 40);
    Car *car = new Car();
    lights *lt = new lights();
    QTimer *tmr;

public:
    MainWindow(QWidget *parent = nullptr);



public slots:
    void move();
    void turnOnLights();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
