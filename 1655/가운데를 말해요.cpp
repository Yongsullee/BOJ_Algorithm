#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    while(N--)
    {
        int tmp;
        cin >> tmp;
        
        if(maxHeap.size() > minHeap.size())
            minHeap.push(tmp);
        else
            maxHeap.push(tmp);
        
        if(!minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            int minRoot = minHeap.top();
            int maxRoot = maxHeap.top();
            
            minHeap.pop();
            maxHeap.pop();
            
            minHeap.push(maxRoot);
            maxHeap.push(minRoot);
        }
        
        cout << maxHeap.top() << '\n';
    }
    return 0;
}