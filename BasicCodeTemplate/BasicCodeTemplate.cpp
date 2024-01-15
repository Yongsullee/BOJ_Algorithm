#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pair<int,int> p1({1,2});
    pair<int,int> p2({2,3});

    p1 = p2;

    return 0;
}