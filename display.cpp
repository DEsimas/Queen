#include "display.h"

#include <QLabel>
#include <QPushButton>
#include <QPixmap>

void display::slot_first()
{
    counter = 0;
    print();
}

void display::slot_prev()
{
    if(counter != 0)
    {
        counter--;
        new_count = counter+1;
        print();
    }
}

void display::slot_next()
{
    if(counter != temp.get_count() - 1)
    {
        counter++;
        new_count = counter+1;
        print();
    }
}

void display::slot_last()
{
    counter = temp.get_count() - 1;
    print();
}

void display::slot_go()
{
    counter = new_count - 1;
    print();
}

void display::save_val(int arg)
{
    new_count = arg;
}

display::display(int num, bool do_sprite): temp(num)
{
    this->num = num;
    this->do_sprite = do_sprite;
    temp.rec_solve();
}

void display::print()
{
    if(!win.isHidden())
    {
        pos_x = win.geometry().x();
        pos_y = win.geometry().y();
    }

    qDeleteAll(win.findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete win.layout();

    QGridLayout *disp = new QGridLayout;
    disp->addLayout(table(), 0, 0);
    disp->addLayout(buttons(), 1,0);

    win.setGeometry(pos_x, pos_y, window_size, window_size);
    win.setLayout(disp);
    win.show();
}

QGridLayout *display::buttons()
{
    QGridLayout *buttons = new QGridLayout;
    QPushButton *first = new QPushButton("<<");
    QPushButton *prev = new QPushButton("<");
    QPushButton *next = new QPushButton(">");
    QPushButton *last = new QPushButton(">>");
    QPushButton *go = new QPushButton("Перейти");
    QSpinBox *p = new QSpinBox;
    QLabel *count = new QLabel;
    QCursor usual = QCursor(Qt::PointingHandCursor);

    count->setText(QString::number(counter + 1) + "/" + QString::number(temp.get_count()));
    p->setMinimum(1);
    p->setMaximum(temp.get_count());
    p->setValue(counter+1);
    first->setCursor(usual);
    prev->setCursor(usual);
    next->setCursor(usual);
    last->setCursor(usual);
    go->setCursor(usual);
    last->setEnabled(true);
    next->setEnabled(true);
    first->setEnabled(true);
    prev->setEnabled(true);

    if(counter == 0)
    {
        first->setEnabled(false);
        prev->setEnabled(false);
    }
    else if(counter == temp.get_count() - 1)
    {
        last->setEnabled(false);
        next->setEnabled(false);
    }

    QObject::connect(first, SIGNAL(clicked()), this, SLOT(slot_first()));
    QObject::connect(last, SIGNAL(clicked()), this, SLOT(slot_last()));
    QObject::connect(next, SIGNAL(clicked()), this, SLOT(slot_next()));
    QObject::connect(prev, SIGNAL(clicked()), this, SLOT(slot_prev()));
    QObject::connect(go, SIGNAL(clicked()), this, SLOT(slot_go()));
    QObject::connect(p, SIGNAL(valueChanged(int)), this, SLOT(save_val(int)));

    buttons->addWidget(first, 0, num + 1);
    buttons->addWidget(prev, 0, num + 2);
    buttons->addWidget(next, 0, num + 3);
    buttons->addWidget(last, 0, num + 4);
    buttons->addWidget(p,0, num + 5);
    buttons->addWidget(go, 0, num + 6);
    buttons->addWidget(count, 0, num + 67);

    return buttons;
}

QGridLayout *display::table()
{
    QGridLayout *layout = new QGridLayout;
    QPixmap queen = QPixmap(":/queen/sprite/queen.png");

    auto x = temp.get_ans()[counter];

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            QLabel * lbl = new QLabel;
            lbl->setAlignment(Qt::AlignCenter);

            if(((j % 2 == 0) && (i % 2 == 0)) || ((j % 2 == 1) && (i % 2 == 1)))
                lbl->setStyleSheet("background-color: #ffffff");
            else
                lbl->setStyleSheet("background-color: #000000");

            if (j == x[i])
            {
                if(do_sprite)
                {
//                    int size = (int) window_size/(num*resize_k);
                    int size = 75;
                    QSize pic_size = QSize(size, size);
                    queen = queen.scaled(pic_size, Qt::KeepAspectRatio);
                    lbl->setPixmap(queen);
                }
                else
                    lbl->setStyleSheet("background-color: #fff000");
            }

            layout->addWidget(lbl, i, j);
        }
    }

    return layout;
}


