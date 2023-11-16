#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int x, y;
    cin >> x >> y;
    
    vector<string> str = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int totalDays = y;
    
    for(int i=1; i<x; i++)
    {
        totalDays += days[i-1];
    }
    
    cout << str[(totalDays-1)%7];
    
    return 0;
}