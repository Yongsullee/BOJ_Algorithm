#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

// String으로 정의한 Board판, 문자열의 문자에 접근하기위해 board[x][y]를 사용할 수 있다.
// #include <string> 필요. 
string board[50];

int BW_cnt (int x, int y){
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[x+i][y+j] != BW[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int WB_cnt (int x, int y){
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[x+i][y+j] != WB[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main () {
    // STL 라이브러리의 pair 사용, #include <utility> 필요
    pair<int, int> p;
    cin >> p.first >> p.second;
    
    int min_val = p.first * p.second;
    for(int i=0; i<p.first; i++){
        cin >> board[i];
    }
    for(int i=0; i+8<=p.first; i++){
        for(int j=0; j+8<=p.second; j++){
            int tmp = 0;
            // 최소값을 구하기위해 min() 사용, #include <algorithm> 필요
            tmp = min(WB_cnt(i, j), BW_cnt(i, j));
            if(tmp < min_val){
                min_val = tmp;
            }
        }
    }
    cout << min_val << endl;
}