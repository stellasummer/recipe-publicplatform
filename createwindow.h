#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QMainWindow>

namespace Ui {
class createwindow;
}

class createwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit createwindow(QWidget *parent = nullptr);
    ~createwindow();

private:
    Ui::createwindow *ui;
};

#endif // CREATEWINDOW_H
