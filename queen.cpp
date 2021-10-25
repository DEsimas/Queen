#include "queen.h"

queen::queen(int n): col(n, false), d1(2 * n - 1 , false), d2(2 * n - 1, false)
{
    this->size = n;
}

void queen::rec_solve(int y)
{
    if (y == this->size)
    {
        this->ans[this->counter++] = this->x_current;
    }
    else
    {
        for (int x = 0; x < this->size; x++)
        {
            if (col[x] == true || d1[x + y] == true || d2[x - y + this->size - 1] == true)
                continue;
            col[x] = true;
            d1[x + y] = true;
            d2[x - y + this->size - 1] = true;
            this->x_current.push_back(x);
            this->rec_solve(y + 1);
            col[x] = false;
            d1[x + y] = false;
            d2[x - y + this->size - 1] = false;
            this->x_current.pop_back();
        }
    }
}
