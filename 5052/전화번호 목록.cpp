#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr int NUM_DIGITS = 10;

// Trie 자료구조의 노드 구조체
struct TrieNode
{
     // #1. 자식 노드 목록
    vector<TrieNode*> children;
    // #2. 리프 노드 여부
    bool terminal;

    TrieNode() : terminal(false){
        children.resize(NUM_DIGITS, nullptr);
    }

    ~TrieNode()
    {
        for(auto child : children)
            if(child)
                delete child;
    }

    // 재귀 호출 수행
    void Insert(const char* key)
    {
        if(*key == '\0')
        {
            terminal = true;
        }
        else
        {
            int next = *key - '0';
            if(children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->Insert(key+1);
        }
    }

    bool find(const char* key)
    {
        // #1.  찾고자 하는 문자열의 마지막 문자의 노드에 도착하면, false를 리턴한다.
        //      찾고자 하는 문자열이 Trie 자료구조에 저장되어, 더 이상의 자식 노드가 붙어 있지 않은 온전한 문자열을 의미한다.
        if(*key == '\0') return false;

        // #2.  찾고자 하는 문자열의 현재 문자가 마지막 노드가 아님에도 불구하고, terminal이 true일 경우, true를 리턴한다.
        //      찾고자 하는 문자열이 Trie 자료구조에 이미 저장되어 있던 문자열에 이어붙여 문자열을 완성했을 경우,
        //      찾고자 하는 문자열의 접두어(앞쪽에 위치한 부분 문자열)가 이전에 저장되었던 온전한 문자열일 경우,
        //      찾고자 하는 문자열을 찾을 때, 마지막 노드에 도착하기 이전에 terminal 여부가 true로 밝혀질 경우, 일관성이 없는 전화번호부 목록이다!
        if(terminal) return true;

        int next = *key - '0';
        return children[next]->find(key+1);
    }
};

int T, N;
char phoneNum[10000][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while(T--)
    {
        cin >> N;

        TrieNode* root = new TrieNode();
        for(int i=0; i<N; ++i)
        {
            cin >> phoneNum[i];
            root->Insert(phoneNum[i]);
        }

        bool consistent = true;
        for(int i=0; i<N; ++i)
        {
            if(root->find(phoneNum[i]))
            {
                consistent = false;
                break; 
            }
        }

        consistent ? cout << "YES\n" : cout << "NO\n";

        delete root;
    }

    return 0;
}