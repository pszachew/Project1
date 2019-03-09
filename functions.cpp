#include "functions.h"
#include <vector>
typedef unsigned int uint;
void subset::push(int value)
{
    container.insert(value);
}
void subset::pop(int value)
{
    container.erase(value);
}
void subset::displaySubset()
{
    for (set<int>::iterator i=container.begin(); i!=container.end(); ++i) cout<<*i<<" ";
}
void subset::increase()
{
    vector<int> tmp;
    for (set<int>::iterator i=container.begin(); i!=container.end(); ++i)
    {
        tmp.push_back(*i);
    }
    for (uint i=0; i<tmp.size(); ++i)
    {
        container.erase(tmp[i]);
    }
    for (uint i=0; i<tmp.size(); ++i)
    {
        container.insert(tmp[i]+1);
    }
}
void subset::decrease()
{
    vector<int> tmp;
    for (set<int>::iterator i=container.begin(); i!=container.end(); ++i)
    {
        tmp.push_back(*i);
    }
    for (uint i=0; i<tmp.size(); ++i)
    {
        container.erase(tmp[i]);
    }
    for (uint i=0; i<tmp.size(); ++i)
    {
        container.insert(tmp[i]-1);
    }
}
subset subset::operator+(subset &subset1)
{
    subset subset_result;
    subset_result.container.insert(subset1.container.begin(),subset1.container.end());
    subset_result.container.insert(this->container.begin(),this->container.end());
    return subset_result;
}
subset subset::operator-(subset &subset1)
{
    subset subset_result;
    subset_result.container.insert(this->container.begin(),this->container.end());
    for (set<int>::iterator i=subset1.container.begin(); i!=subset1.container.end(); ++i)
    {
        subset_result.container.erase(*i);
    }
    return subset_result;
}
