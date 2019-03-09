#include <iostream>
#include <set>
using namespace std;
class subset
{
private:
    set<int> container;
public:
    void push(int);
    void pop(int);
    void displaySubset();
    void decrease();
    void increase();
};
