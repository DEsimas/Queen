#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "display.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QSharedPointer<display> m_display;
    Ui::MainWindow *ui;
    bool spr = true;

private slots:
    void on_do_sprite_clicked(bool checked);
    void on_start_clicked();

protected:
    void keyPressEvent(QKeyEvent *e);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
