#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Connections
    connect(ui->Calcular,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::metodo(){
    QString temp, temp1, temp2, temp3;
    double X1=ui->x1->value(); //we take the value of spingbox and save them in double variables
    double X2=ui->x2->value();
    double X3=ui->x3->value();
    double X4=ui->x4->value();
    double X5=ui->x5->value();
    double X6=ui->x6->value();
    double X7=ui->x7->value();
    double F1=ui->f1->value();
    double F2=ui->f2->value();
    double F3=ui->f3->value();
    double F4=ui->f4->value();
    double F5=ui->f5->value();
    double F6=ui->f6->value();
    double F7=ui->f7->value();
    int i, n=7;                                         //Variables that are dealt with in the program, such as the sum of the x and y
    double sumaX=0, sumaY=0, productoXY=0, suma_cuadrado_X=0, suma_cuadrado_y=0, mediaX=0, mediaY=0, a1=0, a0=0;
    double r=0;     //Variable to show the correlation between the line and the points

    A[0]=X1;A[1]=X2;A[2]=X3;A[3]=X4;A[4]=X5;A[5]=X6;A[6]=X7;   //We store the value of x in a vector
    B[0]=F1;B[1]=F2;B[2]=F3;B[3]=F4;B[4]=F5;B[5]=F6;B[6]=F7;   //We store the value of y in a vector

    for(i=0;i<7;i++){   //In this forum all sums required for formula
        sumaX=sumaX+A[i];
        sumaY=sumaY+B[i];
        productoXY=productoXY+(A[i]*B[i]);
        suma_cuadrado_X=suma_cuadrado_X+(A[i]*A[i]);
        suma_cuadrado_y=suma_cuadrado_y+(B[i]*B[i]);
    }

    mediaX=sumaX/n;   //We obtain the median of x and y
    mediaY=sumaY/n;

    a1=(((n*productoXY)-(sumaX*sumaY))/((n*suma_cuadrado_X)-(sumaX*sumaX)));  //We obtain a1 and a0 In order to obtain the function of our line
    a0=((mediaY)-(a1*mediaX));

    r=((n*productoXY)-(sumaX*sumaY))/((sqrt(n*(suma_cuadrado_X)-(sumaX*sumaX)))*sqrt(n*suma_cuadrado_y-(sumaY*sumaY))); //Obtaining the correlation of points with the line

    temp.append("y=").append(temp1.setNum(a0)).append("+").append(temp2.setNum(a1)).append("x\nr=").append(temp3.setNum(r));//Results are printed
    ui->texto->setText(temp);

}
void MainWindow::borrar(){ //Delete function
    ui->x1->setValue(0.0);
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);
    ui->x7->setValue(0.0);
    ui->f1->setValue(0.0);
    ui->f2->setValue(0.0);
    ui->f3->setValue(0.0);
    ui->f4->setValue(0.0);
    ui->f5->setValue(0.0);
    ui->f6->setValue(0.0);
    ui->f7->setValue(0.0);
    ui->texto->clear();

}
