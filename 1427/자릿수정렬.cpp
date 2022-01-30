#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    vector<int> count;
    int N;
    cin >> N;

    str = to_string(N);
    for (int i = 0; i < str.length(); i++)
    {
        count.push_back(str[i] - '0');
    }
    sort(count.begin(), count.end());
    for (int i = count.size() - 1; i >= 0; i--)
        cout << count[i];
}