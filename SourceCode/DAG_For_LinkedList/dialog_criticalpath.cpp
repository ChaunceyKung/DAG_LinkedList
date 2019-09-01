#include "dialog_criticalpath.h"
#include "ui_dialog_criticalpath.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

Dialog_CriticalPath::Dialog_CriticalPath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CriticalPath)
{
    ui->setupUi(this);

    dialog_failalert = new Dialog_FailAlert(this);
    dialog_successalert = new Dialog_SuccessAlert(this);

    string VE_VL_str, EE_EL_str, cp_str;
    if(CriticalPath(LG_u, VE_VL_str, EE_EL_str, cp_str)){

    ui->plainTextEdit->appendPlainText(QString::fromStdString(VE_VL_str));
    //设为只读，用户不可改写
    ui->plainTextEdit->setReadOnly(true);

    ui->plainTextEdit_2->appendPlainText(QString::fromStdString(EE_EL_str));
    //设为只读，用户不可改写
    ui->plainTextEdit_2->setReadOnly(true);

    ui->plainTextEdit_3->appendPlainText(QString::fromStdString(cp_str));
    //设为只读，用户不可改写
    ui->plainTextEdit_3->setReadOnly(true);

    dialog_successalert->show();

    }else{
        dialog_failalert->show();
    }

}

Dialog_CriticalPath::~Dialog_CriticalPath()
{
    delete ui;
}
