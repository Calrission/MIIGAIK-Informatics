#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void handleNewNumber(const QString &num);
    void handleNewOperator(const QString &oper);
    QList<QPushButton*> numButtons;
    QList<QPushButton*> operatorButtons;
    void connectHandlersToButtons();
    QString calculateExpression(const QString &expression);


private slots:

    void on_exec_btn_c_clicked();

    void on_exec_btn_ce_clicked();

    void on_exec_btn_backspace_clicked();

    void on_exec_btn_so_clicked();

    void on_exec_change_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
