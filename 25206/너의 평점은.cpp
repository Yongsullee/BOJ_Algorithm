#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, double> m;
string str1, str2;
double num;
double det;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    m.insert({"A+", 4.5});
    m.insert({"A0", 4.0});
    m.insert({"B+", 3.5});
    m.insert({"B0", 3.0});
    m.insert({"C+", 2.5});
    m.insert({"C0", 2.0});
    m.insert({"D+", 1.5});
    m.insert({"D0", 1.0});
    m.insert({"F", 0});
    
    for(int i=0; i<20; i++)
    {
        double score;
        cin >> str1 >> score >> str2;
        if(str2 == "P") continue;
        num += score * m[str2];
        det += score;
    }
    
    cout << num/det << endl;
    
    return 0;
}