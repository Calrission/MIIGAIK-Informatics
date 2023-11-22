#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    numButtons = {
        ui->btn_7, ui->btn_8, ui->btn_9,
        ui->btn_4, ui->btn_5, ui->btn_6,
        ui->btn_1, ui->btn_2, ui->btn_3,
        ui->btn_0
    };
    setClickToNumButtons();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setClickToNumButtons(){
    for (QPushButton* btn: numButtons){
        connect(btn, &QPushButton::clicked, this, &MainWindow::clickNumButton);
    }
}

void MainWindow::clickNumButton(){
    QPushButton* btnClicked = qobject_cast<QPushButton*>(sender());
    int num = btnClicked->text().toInt();
    handleNewNumber(num);
}

void MainWindow::handleNewNumber(int num){
    std::cout << num << std::endl;
}

void MainWindow::on_oper_btn_c_clicked(){

}


void MainWindow::on_oper_btn_ce_clicked(){

}


void MainWindow::on_oper_btn_backspace_clicked(){

}


void MainWindow::on_oper_btn_divis_clicked(){

}


void MainWindow::on_oper_btn_multi_clicked(){

}


void MainWindow::on_oper_btn_minus_clicked(){

}


void MainWindow::on_oper_btn_sum_clicked(){

}


void MainWindow::on_oper_btn_so_clicked(){
    std::cout << "So" << std::endl;
}

