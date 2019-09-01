#include "dialog_successalert.h"
#include "ui_dialog_successalert.h"

Dialog_SuccessAlert::Dialog_SuccessAlert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SuccessAlert)
{
    ui->setupUi(this);
}

Dialog_SuccessAlert::~Dialog_SuccessAlert()
{
    delete ui;
}
