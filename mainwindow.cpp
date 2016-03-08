#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Logic Gate Calculator - Frank Leveque");

    connect(ui->aEdit, SIGNAL(returnPressed()), this, SLOT(processInputs()));
    connect(ui->bEdit, SIGNAL(returnPressed()), this, SLOT(processInputs()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAnd(QByteArray a, QByteArray b){
    ui->andEdit->setText(QString("0b") +
                         QString::number(
                             a.toULong(&isError, 2)  &
                             b.toULong(&isError, 2), 2));
}


void MainWindow::setOr(QByteArray a, QByteArray b){
    ui->orEdit->setText(QString("0b") + QString::number(
                            a.toULong(&isError, 2) |
                            b.toULong(&isError, 2), 2));
}


void MainWindow::setNot(const QByteArray a, const QByteArray b){

    ui->notAEdit->setText(QString("0b") + QString::number(
                              a.toULong(&isError, 2) ^ QByteArray(a.size(),'1').toULong(&isError,2), 2));

    ui->notBEdit->setText(QString("0b") + QString::number(
                              b.toULong(&isError, 2) ^ QByteArray(b.size(),'1').toULong(&isError,2), 2));


}

void MainWindow::setNand(const QByteArray a, const QByteArray b){
    //not both then or
    ui->nandEdit->setText(QString("0b") +
                          QString::number(
                              (a.toULong(&isError, 2) ^ QByteArray(a.size(),'1').toULong(&isError,2)) |
                              (b.toULong(&isError, 2) ^ QByteArray(b.size(),'1').toULong(&isError,2))
                              , 2));

}

void MainWindow::setNor(const QByteArray a, const QByteArray b){
    // or both then not result
    int orLength = (a.size() < b.size())? b.size() : a.size();
    ui->norEdit->setText(QString("0b") +
                         QString::number(
                             (a.toULong(&isError, 2) | b.toULong(&isError, 2)) ^ QByteArray(orLength,'1').toULong(&isError,2)
                             , 2));
}

void MainWindow::setXor(QByteArray a, QByteArray b){
    ui->xorEdit->setText(QString("0b") + QString::number(
                             a.toULong(&isError, 2) ^
                             b.toULong(&isError, 2), 2));
}


void MainWindow::setXnor(QByteArray a, QByteArray b){
    int xnorLength = (a.size() < b.size())? b.size() : a.size();
    ui->xnorEdit->setText(QString("0b") + QString::number(
                              (a.toULong(&isError, 2) ^ b.toULong(&isError, 2)) ^
                              QByteArray(xnorLength,'1').toULong(&isError,2), 2));
}





void MainWindow::processInputs(){
    if(ui->aEdit->text().isEmpty()){
            ui->aBinary->clear();
            ui->andEdit->clear();
            ui->orEdit->clear();
            ui->notAEdit->clear();
            ui->notBEdit->clear();
            ui->nandEdit->clear();
            ui->norEdit->clear();
            ui->xorEdit->clear();
            ui->xnorEdit->clear();
            return;
        } else if(ui->bEdit->text().isEmpty()){
            ui->bBinary->clear();
            ui->andEdit->clear();
            ui->orEdit->clear();
            ui->notAEdit->clear();
            ui->notBEdit->clear();
            ui->nandEdit->clear();
            ui->norEdit->clear();
            ui->xorEdit->clear();
            ui->xnorEdit->clear();
            return;
        }

    long aText = ui->aEdit->text().toLong();
    long bText = ui->bEdit->text().toLong();

    QByteArray *aBits = new QByteArray(QString::number(aText,2).toStdString().c_str());
    QByteArray *bBits = new QByteArray(QString::number(bText,2).toStdString().c_str());

    ui->aBinary->setText(QString("0b") + QString::fromStdString(aBits->toStdString()));
    ui->bBinary->setText(QString("0b") + QString::fromStdString(bBits->toStdString()));

    setAnd(*aBits, *bBits);
    setOr(*aBits, *bBits);
    setNot(*aBits, *bBits);
    setNand(*aBits, *bBits);
    setNor(*aBits, *bBits);
    setXor(*aBits, *bBits);
    setXnor(*aBits, *bBits);
}


