#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QMessageBox>

void MainWindow::on_do_sprite_clicked(bool checked)
{
    spr = checked;
}

void MainWindow::on_start_clicked()
{
    if((ui->size->value() != 2) && (ui->size->value() != 3))
    {
        m_display=m_display.create(ui->size->value(), spr);
        m_display->print();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Нет решений для этого поля");
        msg.exec();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_Enter :
        on_start_clicked();
        break;
    case Qt::Key_Return :
        on_start_clicked();
        break;
    }
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
