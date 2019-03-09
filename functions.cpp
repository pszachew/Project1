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
