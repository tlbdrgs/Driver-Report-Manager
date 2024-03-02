#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_examenOOP.h"

class examenOOP : public QMainWindow
{
    Q_OBJECT

public:
    examenOOP(QWidget *parent = nullptr);
    ~examenOOP();

private:
    Ui::examenOOPClass ui;
};
