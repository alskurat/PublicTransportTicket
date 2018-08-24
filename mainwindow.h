#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

enum Transport { SUBWAY, TRAM, TROLLEY, BUS };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void all();
    void process_line(QString line);

    int counter[4];

    int total;


};

#endif // MAINWINDOW_H

//Стоимость поездки в метрополитене
//Количество поездок (в течение календарного месяца)
//36 р.
//от 1 до 10
//35 р.
//от 11 до 20
//34 р.
//от 21 до 30
//33 р.
//от 31 до 40
//32 р.
//от 41

//Стоимость поездки в НГПТ*
//Количество поездок (в течение календарного месяца)
//31 р.
//от 1 до 10
//30 р.
//от 11 до 20
//29р.
//от 21 до 30
//28р.
//от 31 до 40
//27р.
//от 41
