#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderwindow = new RenderWindow();
    this->setCentralWidget(renderwindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    renderwindow->keyPressEvent(event);
}

//void MainWindow::keyReleaseEvent(QKeyEvent *event)
//{
//    renderwindow->keyReleaseEvent(event);
//}

