#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include <map>

using namespace std;

class queen
{
private:
    map<int, vector<int>> ans;
    vector<int> x_current;
    vector<bool> col;
    vector<bool> d1;
    vector<bool> d2;
    int counter = 0;
    int size;

public:
    queen(int n);
    void rec_solve(int y = 0);
    int get_count() { return counter; }
    map<int, vector<int>> get_ans(){return ans;}

};

#endif // QUEEN_H
