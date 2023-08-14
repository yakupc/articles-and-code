#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtcustomtheme_icon.h"

class qtcustomtheme_icon : public QMainWindow
{
    Q_OBJECT

public:
    qtcustomtheme_icon(QWidget *parent = nullptr);
    ~qtcustomtheme_icon();

private:
    Ui::qtcustomtheme_iconClass ui;
};
