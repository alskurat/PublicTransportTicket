#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    total(0)

{
    ui->setupUi(this);

    counter[SUBWAY] = 0;
    counter[TRAM] = 0;
    counter[TROLLEY] = 0;
    counter[BUS] = 0;

    all();

//    ui->label->setText(QString("%1 %2 %3 %4")
//                       .arg(counter[SUBWAY])
//                       .arg(counter[TRAM])
//                       .arg(counter[TROLLEY])
//                       .arg(counter[BUS]));

    ui->label->setText(QString("%1").arg(total));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::all()
{

    QString  fileName = QFileDialog::getOpenFileName(this,
          tr("Open File"), "E:\SuperNova", tr(""));
        QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

         QTextStream in(&file);
         in.setCodec("UTF-8");

         QString line = in.readLine();
         while (!line.isNull()) {
             process_line(line);
             qDebug()<< line;
//                      in.setCodec("UTF-8");
             line = in.readLine();
         }

            int total_sub = 0;
         if     (counter[SUBWAY] < 11 ) total_sub = 36 * counter[SUBWAY];
         else if(counter[SUBWAY] < 21 ) total_sub = 360 + 35 * counter[SUBWAY];
         else if(counter[SUBWAY] < 31 ) total_sub = 350+360 + 34 * counter[SUBWAY];
         else if(counter[SUBWAY] < 41 ) total_sub = 340+350+360 + 33 * counter[SUBWAY];
         else                           total_sub = 330+340+350+360 + 32 * counter[SUBWAY];


         int total_tr = 0;

         if     (counter[TRAM] < 11 ) total_tr = 31 * counter[TRAM];
         else if(counter[TRAM] < 21 ) total_tr = 310 + 30 * counter[TRAM];
         else if(counter[TRAM] < 31 ) total_tr = 300+310 + 29 * counter[TRAM];
         else if(counter[TRAM] < 41 ) total_tr = 290+300+310 + 28 * counter[TRAM];
         else                         total_tr = 280+290+300+310 + 27 * counter[TRAM];

         int total_b = 0;

         if     (counter[BUS] < 11 ) total_b = 31 * counter[BUS];
         else if(counter[BUS] < 21 ) total_b = 310 + 30 * counter[BUS];
         else if(counter[BUS] < 31 ) total_b = 300+310 + 29 * counter[BUS];
         else if(counter[BUS] < 41 ) total_b = 290+300+310 + 28 * counter[BUS];
         else                         total_b = 280+290+300+310 + 27 * counter[BUS];


        total = total_sub + total_tr+ total_b;

}

void MainWindow::process_line(QString line)
{
    QStringList list = line.split(" ");
    foreach(auto word, list)
    {
        if (word == "метро")
            counter[SUBWAY]++;
        else if (word == "трамвай")
            counter[TRAM]++;
        else if (word == "троллейбус")
            counter[TROLLEY]++;
        else if (word == "автобус")
            counter[BUS]++;
    }
//         in.setCodec("UTF-8");
    qDebug()<< "aaa" << counter[SUBWAY]
               << counter[TRAM]
               <<counter[TROLLEY]
                 <<counter[BUS];


}
