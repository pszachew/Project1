#include "functions.h"
using namespace std;
int main()
{
    subset s1,s2,s3;
    s1.push(5);
    s1.push(10);
    s1.push(12);
    s2.push(1);
    s2.push(5);
    s2.push(10);
    s2.push(12);
    s2.push(18);
    s3=s2-s1;
    s3.displaySubset();
}
