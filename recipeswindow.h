#ifndef RECIPESWINDOW_H
#define RECIPESWINDOW_H

#include <QMainWindow>

namespace Ui {
class recipeswindow;
}

class recipeswindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit recipeswindow(QWidget *parent = nullptr);
    ~recipeswindow();
private:
    Ui::recipeswindow *ui;
};

#endif // RECIPESWINDOW_H
