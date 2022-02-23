#include <iostream>
using namespace std;

constexpr int MAX = 15;

int col[MAX];
int N, result=0;

bool check(int colNum)
{
    for(int i=0; i<colNum; i++)
        if(col[i] == col[colNum] || abs(col[colNum] - col[i]) == colNum - i)
            return false;
    return true;
}

void nqueen(int colNum)
{
    if(colNum == N)
        result++;
    else
    {
        for(int i=0; i<N; i++)
        {
            col[colNum] = i;
            if(check(colNum))
                nqueen(colNum+1);
        }   
    }
}

int main () {
    cin >> N;
    nqueen(0);
    cout << result << endl;
}