#include "dialog_failalert.h"
#include "ui_dialog_failalert.h"

Dialog_FailAlert::Dialog_FailAlert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_FailAlert)
{
    ui->setupUi(this);
}

Dialog_FailAlert::~Dialog_FailAlert()
{
    delete ui;
}
