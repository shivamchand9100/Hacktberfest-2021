#include <iostream>
using namespace std;

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int x = 11, y = 15;
 
    int m = max(x,y);
 
    cout << "Max of x and y is = " << m;
    return 0;
}
xen-qqss-ocp
