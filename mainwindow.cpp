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

    ui->centralWidget->setLayout(ui->horizontalLayout);

    trip.append(new SubwayTripCounter());
    trip.append(new LandTransportTripCounter("трамвай"));
    trip.append(new LandTransportTripCounter("троллейбус"));
    trip.append(new LandTransportTripCounter("автобус"));

    all();

    foreach(auto t, trip)
        ui->textEdit->append(QString("Total %1 \t %2 %3")
                             .arg(t->name())
                             .arg(t->counter())
                             .arg(t->fullCost()));

    ui->textEdit->append(QString("Total abs \t %1").arg(total));
}

MainWindow::~MainWindow()
{
    delete ui;
    foreach (auto t, trip)
        delete t;

}

void MainWindow::all()
{

    QString  fileName = QFileDialog::getOpenFileName(this,
          tr("Open File"), "E:\\SuperNova", tr(""));
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

         foreach (auto t, trip)
         {
            total += t->fullCost();

         }

}

void MainWindow::process_line(QString line)
{
    QStringList list = line.split(" ");
    foreach(auto word, list)
    {
        foreach(auto counter, trip)
        {
            if (word == counter->name())
                counter->increaseCounter();
            // make it more simple
        }

    }
}
