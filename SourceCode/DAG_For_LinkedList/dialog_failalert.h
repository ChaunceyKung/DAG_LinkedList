#ifndef DIALOG_FAILALERT_H
#define DIALOG_FAILALERT_H

#include <QDialog>

namespace Ui {
class Dialog_FailAlert;
}

class Dialog_FailAlert : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_FailAlert(QWidget *parent = nullptr);
    ~Dialog_FailAlert();

private:
    Ui::Dialog_FailAlert *ui;
};

#endif // DIALOG_FAILALERT_H
