/*Piotr Szachewicz  300272 Wiktor Kusmirek Projekt1*/
#include "functions.h"
using namespace std;
typedef unsigned int uint;
void Subset::setNumber(int value)
{
    container.insert(value);
}
void Subset::removeNumber(int value)
{
    container.erase(value);
}
void Subset::displaySubset()
{
    if(container.size()==0)
    {
        cout<<"Empty subset\n";
    }
    else
    {
        cout<<"{";
        uint it=1;
        for (set<int>::iterator i=container.begin(); i!=container.end(); ++i)
        {
            cout<<*i;
            if(it!=container.size())
            {
                cout<<",";
            }
            ++it;
        }
        cout<<"}\n";
    }
}
void Subset::increase()
{
    changeValue(&container,1);
}
void Subset::decrease()
{
    changeValue(&container,-1);
}
Subset Subset::operator+(Subset subset1)
{
    Subset subset_result;
    subset_result.container.insert(subset1.container.begin(),subset1.container.end());
    subset_result.container.insert(this->container.begin(),this->container.end());
    return subset_result;
}
Subset Subset::operator-(Subset subset1)
{
    Subset subset_result;
    subset_result.container.insert(this->container.begin(),this->container.end());
    for (set<int>::iterator i=subset1.container.begin(); i!=subset1.container.end(); ++i)
    {
        subset_result.container.erase(*i);
    }
    return subset_result;
}
void Subset::setNumber(int value1, int value2)
{
    for(int i=value1; i<=value2; ++i)
    {
        container.insert(i);
    }
}
