/*Piotr Szachewicz 300272 Wiktor Kusmirek Projekt1*/
#include <set>
class Subset
{
private:
    std::set<int> container;
public:
    void setNumber(int);
    void setNumber(int, int);
    void removeNumber(int);
    void displaySubset();
    void decrease();
    void increase();
    Subset operator+(Subset);
    Subset operator-(Subset);
};
