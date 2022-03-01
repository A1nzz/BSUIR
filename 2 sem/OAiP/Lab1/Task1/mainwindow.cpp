#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    ui->setupUi(this);
    tmr = new QTimer(this);
    scn = new QGraphicsScene();
    ui->graphicsView->setScene(scn);
    scn->setSceneRect(0, 0, 960, 540);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(move()));
    //connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(turnOnLights()));
    car->setPos(250, 250);
    scn->addItem(car);
    rect->setPos(230,240);
    scn->addItem(rect);
    //lt->setPos(250, 250);
    //scn->addItem(lt);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->scale(2, 2);
}

void MainWindow::move() {
    int x = 100;
    int y = 20;
    rect->setTransform(QTransform().translate(x, y).rotate(30).translate(-x, -y));
}

void MainWindow::turnOnLights()
{
    scn->addItem(lt);
    lt->setPos(250, 250);
    scn->update();
}

void MainWindow::on_pushButton_2_clicked()
{
    connect(tmr,SIGNAL(timeout()),SLOT(turnOnLights()));
    tmr->start(1000/240);
}




