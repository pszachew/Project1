/*Piotr Szachewicz 300272  Wiktor Kusmirek Projekt1*/
#include "functions.h"
#include <vector>
typedef unsigned int uint;
using namespace std;
void changeValue(set<int> *container, int k)
{
    vector<int> tmp;
    for (set<int>::iterator i=(*container).begin(); i!=(*container).end(); ++i)
    {
        tmp.push_back(*i);
    }
    for (uint i=0; i<tmp.size(); ++i)
    {
        (*container).erase(tmp[i]);
    }
    for (uint i=0; i<tmp.size(); ++i)
    {
        (*container).insert(tmp[i]+k);
    }
}
void menu()
{
    Subset subA,subB;
    while(1)
    {
        int choice;
        cout<<"Which subset do you want to modify?\n1.A\n2.B\n3.Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"/**********You are modifying subset A**********/\n";
            submenu(&subA,&subB);
            break;
        case 2:
            cout<<"/**********You are modifying subset B**********/\n";
            submenu(&subB,&subA);
            break;
        case 3:
            return;
        default:
            cout<<"unknown command\n";
        }
    }
}
void submenu(Subset *sub, Subset *second)
{
    int number;
    while(1)
    {
       int choice;
       cout<<"1.Add number to subset\n2.Increase all numbers\n3.Decrease all numbers\n4.Delete number from subset\n5.Add second subset to current subset\n6.Substract second subset from current subset\n7.Display subset\n8.Add all integer numbers from <a,b>\n9.Back\n";

       cin>>choice;
       switch(choice)
       {
       case 1:
            cout<<"Give number: ";
            cin>>number;
            (*sub).setNumber(number);
            break;
       case 2:
            (*sub).increase();
            break;
       case 3:
            (*sub).decrease();
            break;
       case 4:
            cout<<"Which number do you want to delete: ";
            cin>>number;
            (*sub).removeNumber(number);
            break;
       case 5:
            (*sub)=(*sub)+(*second);
            break;
       case 6:
            (*sub)=(*sub)-(*second);
            break;
       case 7:
            (*sub).displaySubset();
            break;
       case 8:
            int a, b;
            cout<<"Give a:\n";
            cin>>a;
            cout<<"Give b:\n";
            cin>>b;
            (*sub).setNumber(a,b);
            break;
       case 9:
            return ;
       default:
            cout<<"unkown command";
            break;
       }
    }
}
