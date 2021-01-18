#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&scene);

    auto *t = new QTableWidget(16, 16);

    for(int i = 0; i < 16; ++i) {
        for(int j = 0; j <16; ++j) {
            t->setCellWidget(i, j, new QLabel(QString::number(i) + " : " + QString::number(j)));        // not working
        //    t->setItem(i, j, new QTableWidgetItem(QString::number(i) + " : " + QString::number(j)));    // OK
        }
    }
    scene.addWidget(t);
}

MainWindow::~MainWindow()
{
    delete ui;
}
