#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qwt_plot_curve.h>
#include<qwt_plot.h>
#include <qwt_plot_canvas.h>
#include<QDateTime>
#include<QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void updateScreen();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QwtPlot *plt_hum,*plt_temp;

    QwtPlotCurve *curve_hum,*curve_temp;

    QTimer *timer=new QTimer(this);

    int i;

     QVector<double> xData_hum,yData_hum,xPlotData_hum,yPlotData_hum;

     QVector<double> xData_temp,yData_temp,xPlotData_temp,yPlotData_temp;

};

#endif // MAINWINDOW_H
