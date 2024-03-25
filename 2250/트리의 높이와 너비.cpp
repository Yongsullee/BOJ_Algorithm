/*
    @문제 : 트리의 레벨 중 가장 너비가 큰 레벨을 찾는 문제
    @설명
            1. 트리를 구성한다.
            2. 루트 노드를 찾는다.
            3. 루트 노드를 시작으로 '중위 순회' 하며, 각 레벨의 최소와 최대 너비 값을 업데이트 해준다.
*/

#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

#define MAX 10001

int N;
vector<pair<int,int>> tree;
vector<bool> IsRoot;
int level[MAX], levelMin[MAX], levelMax[MAX];

void InOrder(int root, int depth, int& order)
{
    // #1. 왼쪽 서브트리
    if(tree[root].first != -1)
    {
        InOrder(tree[root].first, depth+1, order);
    }
    // #2. 현재 노드, 현재 레벨의 가장 왼쪽과 오른쪽 구하기
    order += 1;
    levelMin[depth] = min(levelMin[depth], order);
    levelMax[depth] = max(levelMax[depth], order);
    // #3. 오른쪽 서브트리
    if(tree[root].second != -1)
    {
        InOrder(tree[root].second, depth+1, order);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    tree.resize(N+1);
    fill_n(IsRoot, N+1, true);

    while(N--)
    {
        int parent, leftChild, rightChild;

        cin >> parent >> leftChild >> rightChild;

        tree[parent] = {leftChild, rightChild};
        if(leftChild != -1)
            IsRoot[leftChild] = false;
        if(rightChild != -1)
            IsRoot[rightChild] = false;
    }

    // #1. 루트 노드 찾기
    int root = -1;
    for(int i=1; i<=N; ++i)
    {
        if(IsRoot[i])
            root = i;
    }

    // #2. 중위 순회
    int order = 0;
    InOrder(root, 1, order);

    // #3. 최대 너비 값과 해당 값을 갖는 레벨 출력
    int resLevel = -1;
    int resWidth = -1;
    for(int i=1; i<=N; ++i)
    {
        int width = levelMax[i] - levelMin[i] +1;
        if(resWidth < width)
        {
            resWidth = width;
            resLevel = i;
        }
    }

    cout << resLevel << ' ' << resWidth;

    return 0;
}