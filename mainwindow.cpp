#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);

    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_4, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_5, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_6, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_7, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_8, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_9, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_10, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this,SLOT(update_overall(int)));
    ui->spinBox->setMaximum(100);
    ui->horizontalSlider->setMaximum(100);
    ui->spinBox_2->setMaximum(100);
    ui->horizontalSlider_2->setMaximum(100);
    ui->spinBox_3->setMaximum(100);
    ui->horizontalSlider_3->setMaximum(100);
    ui->spinBox_4->setMaximum(100);
    ui->horizontalSlider_4->setMaximum(100);
    ui->spinBox_5->setMaximum(100);
    ui->horizontalSlider_5->setMaximum(100);
    ui->spinBox_6->setMaximum(100);
    ui->horizontalSlider_6->setMaximum(100);
    ui->spinBox_7->setMaximum(100);
    ui->horizontalSlider_7->setMaximum(100);
    ui->spinBox_8->setMaximum(100);
    ui->horizontalSlider_8->setMaximum(100);
    ui->spinBox_9->setMaximum(100);
    ui->horizontalSlider_9->setMaximum(100);
    ui->spinBox_10->setMaximum(100);
    ui->horizontalSlider_10->setMaximum(100);
    ui->spinBox_11->setMaximum(100);
    ui->horizontalSlider_11->setMaximum(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_overall(int unused)
{
    //double score=31.4;
    double result=0;
    double resulthw=0;
    double resultmt1=0;
    double resultmt2=0;
    double resultfinal=0;
    double x1 = ui->spinBox->value();
    double x2 = ui->spinBox_2->value();
    double x3 = ui->spinBox_3->value();
    double x4 = ui->spinBox_4->value();
    double x5 = ui->spinBox_5->value();
    double x6 = ui->spinBox_6->value();
    double x7 = ui->spinBox_7->value();
    double x8 = ui->spinBox_8->value();//8 hws
    double x9 = ui->spinBox_9->value(); //mt1
    double x10 = ui->spinBox_10->value(); //mt2
    double x11 = ui->spinBox_11->value(); //final
    //find the lowest hw score

    QVector<double>hw(8);
    hw[0]=x1;
    hw[1]=x2;
    hw[2]=x3;
    hw[3]=x4;
    hw[4]=x5;
    hw[5]=x6;
    hw[6]=x7;
    hw[7]=x8;

    double min=hw[0];
    int min_index=0;
    for(int i=0;i<8;i++)
    {
        if(hw[i]<min){

            min=hw[i];
         min_index=i;
        }
    }

    hw.remove(min_index);
    for(int i=0;i<7;i++)
    {
        resulthw+=hw[i];
    }
    double hw_average=resulthw/7;

    if(ui->checkBox->isChecked())
    {
    resultmt1=x9*0.2;
    resultmt2=x10*0.2;
    resultfinal=x11*0.35;
    result=hw_average*0.25+resultmt1+resultmt2+resultfinal;
    }
    else if (ui->checkBox_2->isChecked())
    {
        double highermt=0;
        if(x9>=x10)
        {highermt=x9;}
        else if(x10>x9) highermt=x10;
        result=hw_average*0.25+highermt*0.3+x11*0.44;
    }

    //double score=static_cast<double>(unused);

    ui->label_14->setText(QString::number(result));

        return;

}

void MainWindow ::compute_sum() const {

    //double result=0;
    // Wouldn't it be nice if we could get the needed values
    // directly from the spinBoxes???
   // double x1 = ui->spinBox->value();
    //double x2 = ui->spinBox_2->value();
   // result=x1+x2;
   // QString resultString ="";
    //ui->label_14->setText(resultString.setNum(result));

   // QString text( QString::number(x1) + " + " +
                 // QString::number(x2) + " = " +
                //  QString::number( x1 + x2 )
               // );
   // ui->label->setText(text);
}
