#include "qtcustomtheme_icon.h"

qtcustomtheme_icon::qtcustomtheme_icon(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.pushButtonOK->setIcon( QIcon::fromTheme("check") );
    ui.pushButtonCancel->setIcon( QIcon::fromTheme("cancel") );
}

qtcustomtheme_icon::~qtcustomtheme_icon()
{}
