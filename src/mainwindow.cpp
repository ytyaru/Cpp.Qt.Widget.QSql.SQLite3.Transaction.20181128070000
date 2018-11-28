#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "memodb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MemoDb memoDb(QApplication::applicationDirPath());
    qDebug() << QApplication::applicationDirPath();
    if ("/home/pi" == QApplication::applicationDirPath()) { memoDb.Open("/tmp/work"); }
    else { memoDb.Open(QApplication::applicationDirPath()); }
    QStringList record;
    record.append("ABCDEFG");
    record.append("2000-01-01 00:00:00.000");
    memoDb.Write(record);
    memoDb.Close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
