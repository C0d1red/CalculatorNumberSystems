#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_calculate_clicked();

private:
    Ui::MainWindow *ui;
    bool CheckSourceSys(const char* num, int ss, int num_of_char);
    bool CheckSourceNum(const char* num, int num_of_char);
    bool CheckVoid(const char* source, int sourceSS, int finalSS);
    int NumOfChar(const char* source);
};

#endif // MAINWINDOW_H
