#include "qtcustomtheme_icon.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QIcon>
#include <QStyleFactory>

void SetDarkPalette()
{
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);

    qApp->setPalette(darkPalette);

}

void SetLightPalette()
{
    qApp->setStyle(QStyleFactory::create("Fusion"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << QIcon::themeSearchPaths();

    bool darkMode = false;

    if ( darkMode )
    {
        SetDarkPalette();
        QIcon::setThemeName("dark");
    }
    else
    {
        SetLightPalette();
        QIcon::setThemeName("light");
    }
    qtcustomtheme_icon w;
    w.show();
    return a.exec();
}
