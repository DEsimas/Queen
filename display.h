#ifndef DYSPLAY_H
#define DYSPLAY_H

#include "queen.h"

#include <QWidget>
#include <QObject>
#include <QGridLayout>
#include <QSpinBox>
#include <vector>

class display : public QObject
{
    Q_OBJECT

private slots:
    void slot_first();
    void slot_prev();
    void slot_next();
    void slot_last();
    void slot_go();
    void save_val(int);

private:
    const int window_size = 700;
    const float resize_k = 1.25;
    int pos_x = 0;
    int pos_y = 30;
    int counter = 0;
    int new_count = 1;
    int num;
    bool do_sprite;

    QGridLayout *buttons();
    QGridLayout *table();
    QWidget win;
    queen temp;

public:
    display(int, bool);
    void print();
};

#endif // DYSPLAY_H
