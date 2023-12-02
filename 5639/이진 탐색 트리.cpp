#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> tree;
int num;

void findPostorder(int pre_start, int pre_end)
{
    if(pre_start > pre_end)
        return;
    
    // #1. 루트 노드 찾기, 전위순회의 첫 번째 순서
    int root = tree[pre_start];
    
    // #2. 루트 노드 다음으로 큰 수가 오른쪽 자식 노드가 된다.
    int rightChildIdx = pre_start+1;
    while(rightChildIdx <= pre_end && tree[rightChildIdx] <= root)
    {
        rightChildIdx++;
    }
    // #3. 왼쪽 서브트리에 대해 재귀함수 호출
    findPostorder(pre_start+1, rightChildIdx-1);
    
    // #4. 오른쪽 서브트리에 대해 재귀함수 호출
    findPostorder(rightChildIdx, pre_end);
    
    // #5. 루트 노드 출력
    cout << root << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    while(cin >> num)
    {   
        tree.push_back(num);
    }
    
    findPostorder(0, tree.size()-1);
    
    return 0;
}