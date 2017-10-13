#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   double A[7];  //Arrays where the value of x and y is stored
   double B[7];

private:
    Ui::MainWindow *ui;
public slots:
    void metodo();   //Statement of functions used in the program
    void borrar();
};

#endif // MAINWINDOW_H
