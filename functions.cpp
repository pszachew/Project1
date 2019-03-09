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
    if(container.size()==0)
    {
        cout<<"Empty subset";
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
        cout<<"}";
    }
}
void change_value(set<int> &container, int k)
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
        container.insert(tmp[i]+k);
    }
}
void subset::increase()
{
    change_value(this->container,1);
}
void subset::decrease()
{
    change_value(this->container,-1);
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
void subset::push(int value1, int value2)
{
    for(int i=value1; i<=value2; ++i)
    {
        container.insert(i);
    }
}
void menu()
{
    subset sub1,sub2,sub3;
    int number;
    while(1)
    {
        int choice;
       cout<<"\n/****MENU****/"<<endl<<"1.Add number to subset\n2.Increase all numbers\n3.Decrease all numbers\n4.Delete number from subset\n5.Display subset\n6.exit\n";
       cin>>choice;
       switch(choice)
       {
       case 1:
        cout<<"Give number: ";
        cin>>number;
        sub1.push(number);
        break;
       case 2:
        sub1.increase();
        break;
       case 3:
        sub1.decrease();
        break;
       case 4:
        cout<<"Which number do you want to delete: ";
        cin>>number;
        sub1.pop(number);
        break;
       case 5:
        sub1.displaySubset();
       case 6:
        return ;
       default:
        cout<<"unkown command";
        break;

       }
    }
}
