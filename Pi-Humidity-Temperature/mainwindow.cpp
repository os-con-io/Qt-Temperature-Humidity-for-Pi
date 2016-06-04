#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<read.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
qDebug()<<"test";
    plt_hum=new QwtPlot();
    plt_hum->setAxisScale(QwtPlot::xBottom,0.0,1024,50);
    plt_hum->setAxisScale(QwtPlot::yLeft,0,100,50);
    plt_hum->enableAxis(QwtPlot::xBottom,false);
    plt_hum->enableAxis(QwtPlot::yLeft,false);
    plt_hum->setAutoReplot(true);
    plt_hum->resize(90,50);
    plt_hum->setStyleSheet("background-color: rgb(0, 0, 51);");
    curve_hum=new QwtPlotCurve();
    curve_hum->setPen( QPen( Qt::yellow, 1.0 ) );
    curve_hum->setStyle( QwtPlotCurve::Lines );
    curve_hum->setRenderHint( QwtPlotCurve::RenderAntialiased );
qDebug()<<"test";
    plt_temp=new QwtPlot();
    plt_temp->setAxisScale(QwtPlot::xBottom,0.0,1024,50);
    plt_temp->setAxisScale(QwtPlot::yLeft,0,50,50);
    plt_temp->enableAxis(QwtPlot::xBottom,false);
    plt_temp->enableAxis(QwtPlot::yLeft,false);
    plt_temp->setAutoReplot(true);
    plt_temp->resize(90,50);
    plt_temp->setStyleSheet("background-color: rgb(0, 0, 51);");
    curve_temp=new QwtPlotCurve();
    curve_temp->setPen( QPen( Qt::yellow, 1.0 ) );
    curve_temp->setStyle( QwtPlotCurve::Lines );
    curve_temp->setRenderHint( QwtPlotCurve::RenderAntialiased );

    connect(timer,SIGNAL(timeout()),this,SLOT(updateScreen()));
    timer->start(2000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateScreen(){
    struct sensor reading=test_read();
    int rowCount=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    int rowCount_2=ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(rowCount_2);
//    xData_hum.append(i);
//    yData_hum.append(reading.hum);
//    xPlotData_hum.fill(xData_hum.at(i));
//    xPlotData_hum.append(xData_hum.at(i));
//    yPlotData_hum.append(yData_hum.at(i));
//    curve_hum->setSamples(xPlotData_hum,yPlotData_hum);
//    curve_hum->attach(plt_hum);
    ui->tableWidget->setItem(rowCount,0,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
    ui->tableWidget->setItem(rowCount,1,new QTableWidgetItem(QString::number(reading.hum,'f',2)));


    ui->tableWidget_2->setItem(rowCount_2,0,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
    ui->tableWidget_2->setItem(rowCount_2,1,new QTableWidgetItem(QString::number(reading.temp,'f',2)));
    i++;
}
