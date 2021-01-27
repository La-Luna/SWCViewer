#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include"rwidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);   //键盘按下事件
    //void keyReleaseEvent(QKeyEvent *event);  //键盘释放事件
private:
    Ui::MainWindow *ui;
    RenderWindow *renderwindow;
};
#endif // MAINWINDOW_H
