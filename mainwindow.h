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
    void clickNumButton();
    void handleNewNumber(int num);
    QList<QPushButton*> numButtons;
    void setClickToNumButtons();

private slots:

    void on_oper_btn_c_clicked();

    void on_oper_btn_ce_clicked();

    void on_oper_btn_backspace_clicked();

    void on_oper_btn_divis_clicked();

    void on_oper_btn_multi_clicked();

    void on_oper_btn_minus_clicked();

    void on_oper_btn_sum_clicked();

    void on_oper_btn_so_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
