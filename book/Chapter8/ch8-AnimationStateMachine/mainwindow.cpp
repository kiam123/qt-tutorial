#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>
#include <QState>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton("Button", this);
    button->setGeometry(10,10,100,30);

    QStateMachine *machine = new QStateMachine(this);

    QState *state1 = new QState(machine);
    state1->assignProperty(button, "geometry", QRect(10,10,100,30));

    QState *state2 = new QState(machine);
    state2->assignProperty(button, "geometry", QRect(250,250,100,30));

    QSignalTransition *transition1 = state1->addTransition(button, SIGNAL(clicked()), state2);
    transition1->addAnimation(new QPropertyAnimation(button, "geometry"));
    state1->addTransition(transition1);

    QSignalTransition *transition2 = state2->addTransition(button, SIGNAL(clicked()), state1);
    transition2->addAnimation(new QPropertyAnimation(button, "geometry"));
    state2->addTransition(transition2);

    machine->setInitialState(state1);
    machine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

