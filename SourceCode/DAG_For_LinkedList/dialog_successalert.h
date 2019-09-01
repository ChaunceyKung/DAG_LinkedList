#ifndef DIALOG_SUCCESSALERT_H
#define DIALOG_SUCCESSALERT_H

#include <QDialog>

namespace Ui {
class Dialog_SuccessAlert;
}

class Dialog_SuccessAlert : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SuccessAlert(QWidget *parent = nullptr);
    ~Dialog_SuccessAlert();

private:
    Ui::Dialog_SuccessAlert *ui;
};

#endif // DIALOG_SUCCESSALERT_H
