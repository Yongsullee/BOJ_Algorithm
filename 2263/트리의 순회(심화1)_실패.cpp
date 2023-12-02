#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;

void findPreorder(
    vector<int>& inorder, vector<int>& postorder, 
    int inStart, int inEnd, 
    int posStart, int posEnd) 
{
   if(inStart > inEnd || posStart > posEnd)
       return;
    
    // #1. 후위순회의 마지막 노드는 '루트 노드'입니다.
    int root = postorder[posEnd];
    cout << root << ' ';
    
    // #2. 루트 노드를 중위순회에서 찾고, 왼쪽 서브트리와 오른쪽 서브트리를 구분합니다.
    int rootInorder = find(begin(inorder)+inStart, begin(inorder)+inEnd, root) - begin(inorder);
    
    // #3. 루트 노드를 기준으로 왼쪽과 오른쪽으로 분할하고, 재귀 호출 수행
    // #3-1. 왼쪽 서브트리에 대한 재귀
    findPreorder(inorder, postorder, 
                 inStart, rootInorder-1,
                 posStart, posStart + (rootInorder - inStart)-1);
    // #3-2. 오른쪽 서브트리에 대한 재귀
    findPreorder(inorder, postorder,
                rootInorder+1, inEnd,
                posStart + (rootInorder - inStart)-1, posEnd-1);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    vector<int> inorder(n);
    vector<int> postorder(n);
    
    for(int i=0; i<n; i++)
    {
        cin >> inorder[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> postorder[i];
    }
    
    findPreorder(inorder, postorder, 0, n-1, 0, n-1);
    
    return 0;
    
}