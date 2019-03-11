#include <iostream>
#include <set>
using namespace std;
class subset
{
private:
    set<int> container;
public:
    void push(int);
    void push(int, int);
    void pop(int);
    void displaySubset();
    void decrease();
    void increase();
    subset operator+(subset);
    subset operator-(subset);
};
void change_value(set<int> *, int);
void menu();
void submenu(subset, subset);



