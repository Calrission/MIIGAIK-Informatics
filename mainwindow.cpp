#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    numButtons = {
        ui->btn_7, ui->btn_8, ui->btn_9,
        ui->btn_4, ui->btn_5, ui->btn_6,
        ui->btn_1, ui->btn_2, ui->btn_3,
        ui->btn_0, ui->btn_dot
    };

    operatorButtons = {
        ui->oper_btn_sum, ui->oper_btn_minus,
        ui->oper_btn_multi, ui->oper_btn_divis
    };
    connectHandlersToButtons();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::connectHandlersToButtons(){
    auto addNumHandler = [this](){
        QPushButton* btnClicked = qobject_cast<QPushButton*>(sender());
        QString text = btnClicked->text();
        handleNewNumber(text);
    };

    auto addOperatorHandler = [this](){
        QPushButton* btnClicked = qobject_cast<QPushButton*>(sender());
        QString oper= btnClicked->text();
        handleNewOperator(oper);
    };

    for (QPushButton* btn: numButtons){
        connect(btn, &QPushButton::clicked, this, addNumHandler);
    }

    for (QPushButton* btn: operatorButtons){
        connect(btn, &QPushButton::clicked, this, addOperatorHandler);
    }
}

void MainWindow::handleNewNumber(const QString& text){
    ui->answer->setText(ui->answer->text() + text);
}

void MainWindow::handleNewOperator(const QString& oper){
    ui->answer->setText(ui->answer->text() + " " + oper + " ");
}

void MainWindow::on_exec_btn_c_clicked(){
    ui->answer->clear();
}


void MainWindow::on_exec_btn_ce_clicked(){
    ui->expression->clear();
    ui->answer->clear();
}


void MainWindow::on_exec_btn_backspace_clicked(){
    QString text = ui->answer->text();
    text.chop(1);
    ui->answer->setText(text);
}

void MainWindow::on_exec_btn_so_clicked(){
    QString expression = ui->answer->text();
    ui->expression->setText(expression);
    QString answer = calculateExpression(expression);
    ui->answer->setText(answer);
}


void MainWindow::on_exec_change_clicked()
{
    QString text = ui->answer->text();
    if (text.isEmpty() || text == "0")
        return;
    if (text.at(0) != "-"){
        text.prepend("-");
    }else{
        text.remove(0, 1);
    }
    ui->answer->setText(text);
}

QString MainWindow::calculateExpression(const QString &expression) {
    // Выводим токены для отладки
    QStringList tokens = expression.split(" ");
    QList<QString> numbers;
    QList<QString> operators;
    for (const QString &token : tokens) {
        if (token != "+" && token != "-" && token != "*" && token != "/") {
            // Если токен не является оператором, добавляем его в список чисел
            numbers.push_back(token);
        } else {
            // Если токен - оператор, добавляем его в список операторов
            operators.push_back(token);
        }
    }
    // Выполняем операции умножения и деления
    for (int i = 0; i < operators.size(); ++i) {
        if (operators.at(i) == "*" || operators.at(i) == "/") {
            // Извлекаем первое число
            double a = numbers.at(i).toDouble();
            // Извлекаем оператор
            QString op = operators.at(i);
            // Извлекаем второе число
            double b = numbers.at(i + 1).toDouble();
            // Выполняем операцию в зависимости от оператора
            if (op == "*") {
                numbers[i] = QString::number(a * b);
            } else if (op == "/") {
                if (b == 0.0) {
                    return "Error: Division by zero";
                }
                numbers[i] = QString::number(a / b);
            }
            // Удаляем использованный оператор и второе число
            operators.removeAt(i);
            numbers.removeAt(i + 1);
            // Уменьшаем индекс, чтобы не пропустить следующий оператор
            --i;
        }
    }
    // Выполняем операции сложения и вычитания
    while (!operators.isEmpty()) {
        // Извлекаем первое число
        double a = numbers.takeFirst().toDouble();
        // Извлекаем оператор
        QString op = operators.takeFirst();
        // Извлекаем второе число
        double b = numbers.takeFirst().toDouble();
        // Выполняем операцию в зависимости от оператора
        if (op == "+") {
            numbers.push_front(QString::number(a + b));
        } else if (op == "-") {
            numbers.push_front(QString::number(a - b));
        }
    }
    // В списке должен остаться один элемент - результат выражения
    if (numbers.size() == 1) {
        QString result = numbers.takeFirst();
        return result;
    } else {
        return "Error";
    }
}

