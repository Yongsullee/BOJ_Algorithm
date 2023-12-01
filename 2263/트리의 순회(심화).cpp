#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inorder, postorder, position;

void solve (int in_start, int in_end, int post_start, int post_end) {
    
    if (in_start > in_end || post_start > post_end) 
        return;
    
    // #1. 후위 순회의 마지막 노드는 '루트 노드'
    int root = postorder[post_end];
    cout << root << ' ';
    
    // #2. 왼쪽 서브 트리에 대한 재귀 
    //    -> 'in_start ~ root-1' = 중위순회 내 루트 노드 기준 왼쪽 서브트리
    //    -> 'pos_start ~ pos_start + root-1 - in_start' : 후위순회 내 루트 노드 기준 왼쪽 서브트리
    solve(in_start, position[root]-1, post_start, post_start + (position[root]-1 - in_start));
    // #3. 오른쪽 서브 트리에 대한 재귀
    //    -> 'root+1 ~ in_end' = 중위순회 내 루트 노드 기준 오른쪽 서브트리
    //    -> 'pos_start + root - in_start' = 후위순회 내 루트 노드 기준 오른쪽 서브트리
    solve(position[root]+1, in_end, post_start + (position[root] - in_start), post_end-1);
}

int main() {
    
    int n;
    
    cin >> n;
    
    // 중위 순회
    inorder.resize(n+1);
    // 후위 순회
    postorder.resize(n+1);
    // 중위 순회에서 각 항목의 위치 값
    position.resize(n+1);
    
    // #1.중위 순회 중 본인의 위치를 기억
    for (int i=1; i<=n; i++) {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }
    // #2. 후위 순회
    for (int i=1; i<=n; i++) 
        cin >> postorder[i];
    
    solve(1, n, 1, n);
    
    return 0;
}
