#include <QApplication>
#include <QPushButton>
#include <QToolBar>
#include <QMainWindow>
#include <QStyle>
#include "StateButton.h"
#include <QStyleFactory> //для светлой темы

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QStyle *fusion = QStyleFactory::create("Fusion");
    app.setStyle(fusion);
    app.setPalette(fusion->standardPalette()); //светлая тема

    QMainWindow mainWindow;
    mainWindow.resize(300, 400);

    QToolBar *toolbar = mainWindow.addToolBar("Main toolbar");
    StateButton *stateButton = new StateButton(&mainWindow);

    ButtonMode lockMode;
    lockMode.title = "Приватность";
    lockMode.onIcon = QIcon(":/icons/lock_off.png");
    lockMode.offIcon = QIcon(":/icons/lock_on.png");
    stateButton->addMode(lockMode);

    ButtonMode soundMode;
    soundMode.title = "Звук";
    soundMode.onIcon = mainWindow.style()->standardIcon(QStyle::SP_MediaVolume);
    soundMode.offIcon = mainWindow.style()->standardIcon(QStyle::SP_MediaVolumeMuted);
    stateButton->addMode(soundMode);

    toolbar->addWidget(stateButton);
    mainWindow.show();

    return app.exec();
}