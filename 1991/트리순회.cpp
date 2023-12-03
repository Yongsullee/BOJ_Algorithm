/*
 *   [1번 답안] : 배열로 구현한 트리를 활용
 *   [2번 답안] : 구조체 및 연결 리스트를 활용
 */

// #1. 배열을 활용해 구현한 트리를 활용
#include <iostream>
#include <vector>
using namespace std;

// #1. 전위 순회(루트 -> 왼쪽 -> 오른쪽)
void PreOrder(vector<char> &v, int Idx)
{

    if (v[Idx] == '.')
        return;

    cout << v[Idx];
    PreOrder(v, Idx * 2);
    PreOrder(v, Idx * 2 + 1);
}

// #2. 중위 순회(왼쪽 -> 루트 -> 오른쪽)
void InOrder(vector<char> &v, int Idx)
{

    if (v[Idx] == '.')
        return;

    InOrder(v, Idx * 2);
    cout << v[Idx];
    InOrder(v, Idx * 2 + 1);
}

// #3. 후위 순회(왼쪽 -> 오른쪽 -> 루트)
void PostOrder(vector<char> &v, int Idx)
{

    if (v[Idx] == '.')
        return;

    PostOrder(v, Idx * 2);
    PostOrder(v, Idx * 2 + 1);
    cout << v[Idx];
}

{
    int main()
        ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<char> v(26 * 2 + 1, '.');

    for (int i = 0; i < N; i++)
    {
        char Parent;
        char LeftChild;
        char RightChild;

        cin >> Parent >> LeftChild >> RightChild;

        int Idx = Parent - 'A';

        v[Idx] = Parent;
        if (LeftChild != '.')
            v[2 * Idx] = LeftChild;
        if (RightChild != '.')
            v[2 * Idx + 1] = RightChild;
    }

    // #1. 전위 순회(루트 -> 왼쪽 -> 오른쪽)
    PreOrder(v, 0);
    cout << '\n';
    // #2. 중위 순회(왼쪽 -> 루트 -> 오른쪽)
    InOrder(v, 0);
    cout << '\n';
    // #3. 후위 순회(왼쪽 -> 오른쪽 -> 루트)
    PostOrder(v, 0);
}

// #2. 구조체 및 연결 리스트로 구현한 트리를 활용
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    char Val;
    Node *Left = nullptr;
    Node *Right = nullptr;
};

void PreOrder(Node *cur)
{
    if (cur == nullptr)
        return;

    cout << cur->Val;

    if (cur->Left != nullptr)
        PreOrder(cur->Left);

    if (cur->Right != nullptr)
        PreOrder(cur->Right);
}

void InOrder(Node *cur)
{
    if (cur == nullptr)
        return;

    if (cur->Left != nullptr)
        InOrder(cur->Left);

    cout << cur->Val;

    if (cur->Right != nullptr)
        InOrder(cur->Right);
}

void PostOrder(Node *cur)
{
    if (cur == nullptr)
        return;

    if (cur->Left != nullptr)
        PostOrder(cur->Left);

    if (cur->Right != nullptr)
        PostOrder(cur->Right);

    cout << cur->Val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<Node> Tree(26);

    while (N--)
    {
        char Parent, Left, Right;
        cin >> Parent >> Left >> Right;

        int Idx = Parent - 'A';

        Tree[Idx].Val = Parent;
        if (Left != '.')
            Tree[Idx].Left = &Tree[Left - 'A'];
        if (Right != '.')
            Tree[Idx].Right = &Tree[Right - 'A'];
    }

    PreOrder(&Tree[0]);
    cout << '\n';
    InOrder(&Tree[0]);
    cout << '\n';
    PostOrder(&Tree[0]);

    return 0;
}