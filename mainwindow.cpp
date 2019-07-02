#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transfer.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_calculate_clicked()
{
    Transfer transfert;
    QString source_num = ui->line_sourceNum->text();
    QString source_ss = ui->linesource_SS->text();
    QString finalSS = ui->linefinal_SS->text();

    int sourceSS = source_ss.toInt();
    int final_SS = finalSS.toInt();

    QByteArray ba = source_num.toLatin1();
    const char *one = ba.data();


    if(sourceSS>=2 && final_SS >=2 && final_SS <= 16 && sourceSS <= 16 && CheckSourceSys(one, sourceSS, NumOfChar(one)) && CheckSourceNum(one, NumOfChar(one)) && NumOfChar(one) >=1){
        QString string_final(transfert.changeNumSys(one, sourceSS, final_SS, NumOfChar(one)));
        ui->label_final->setText(string_final);
    } else {
        if (!CheckVoid(one, sourceSS, final_SS)){
            QMessageBox::critical(this, "Ошибка!", "Все поля должны быть заполнены!");
        } else{
            if (sourceSS<2 || final_SS <2 || final_SS > 16 || sourceSS > 16){
                QMessageBox::critical(this, "Ошибка!", "Перевод осуществляется из системы счисления с основанием q(2<=q<=16)  в систему счисления с основанием p(2<=p<=16)");
            } else{
                if(!CheckSourceNum(one, NumOfChar(one))){
                    QMessageBox::critical(this, "Ошибка!", "Некоректный ввод числа-источника");
                } else if(!CheckSourceSys(one, sourceSS, NumOfChar(one))){
                    QMessageBox::critical(this, "Ошибка!", "Число-источник невозможно с заданной системой счисления");
                }
            }
        }
    }

}

bool MainWindow::CheckSourceSys(const char* source, int ss, int num_of_char){
    int num = 0;
    bool check = true;
    for(int i = 0; i<num_of_char; i++){
            switch (source[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                num = (source[i]-'0');
                break;
            case 'A':
                num = 10;
                break;
            case 'B':
                num = 11;
                break;
            case 'C':
                num = 12;
                break;
            case 'D':
                num = 13;
                break;
            case 'E':
                num = 14;
                break;
            case 'F':
                num = 15;
                break;
            default: break;
            }
        if (num >= ss){
            check = false;
       }
    }
    return check;
}

bool MainWindow::CheckSourceNum(const char* source, int num_of_char){
    for(int i = 0; i<num_of_char; i++){
            switch (source[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                break;
            default:
                return false;
            }
    }
    return true;
}

bool MainWindow::CheckVoid(const char* source, int sourceSS, int finalSS){
    if (sourceSS==0 || finalSS==0 || NumOfChar(source)==0){
        return false;
    } else
        return true;
}

int MainWindow::NumOfChar(const char* source){
    int num_of_char = 0;
    while(*source++)
        num_of_char++;
    return num_of_char;
}

