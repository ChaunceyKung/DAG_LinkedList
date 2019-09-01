#include "dialog_vexinit.h"
#include "ui_dialog_vexinit.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

Dialog_VexInit::Dialog_VexInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_VexInit)
{
    ui->setupUi(this);
}

Dialog_VexInit::~Dialog_VexInit()
{
    delete ui;
}

void Dialog_VexInit::on_buttonBox_accepted()
{
    dialog_failalert = new Dialog_FailAlert(this);
    dialog_successalert = new Dialog_SuccessAlert(this);


    //初始化时总的顶点数
    int sum_vexNum = ui->lineEdit->text().toInt();

    //因结点个数不符号要求导致错误
    if(sum_vexNum >50 || sum_vexNum <= 0){
        dialog_failalert->show();
        return;
    }


    //采用默认的结点名
    //isChecked()为true，代表radio button被选中
    if(ui->radioButton->isChecked() == true){
        for (int i = 0; i < sum_vexNum; i++){
            //依次默认插入
            //最开始出错是因为Bool的默认返回值为false
            if(false == ListGraph_InsertOneVex(LG_u, DEFAULT_NAME_ARR[i])){
                /*如果失败，提示为false,且继续禁用其他button*/
                dialog_failalert->show();
                //如何继续禁用其他button,如何访问到父类上去？
                return;
            }
        }
        dialog_successalert->show();
        return;
    }

    //不使用中文结点名扩展包
    else{
        for (int i = 0; i < sum_vexNum; i++){
            //依次默认插入
            //最开始出错是因为Bool的默认返回值为false
            if(false == ListGraph_InsertOneVex(LG_u, DEFAULT_NAME_ARR[i + 22])){
                /*如果失败，提示为false,且继续禁用其他button*/
                dialog_failalert->show();
                //如何继续禁用其他button,如何访问到父类上去？
                return;
            }
        }
        dialog_successalert->show();
        return;
    }

}
