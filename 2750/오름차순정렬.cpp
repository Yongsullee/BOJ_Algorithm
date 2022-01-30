#include <iostream>
// sort 함수 사용을 위해 algorithm 헤더 추가
#include <algorithm>
using namespace std;

int main (){
    int N;
    int arr[1000] = {};
    cin >> N;
    
    for(int i =0; i<N; i++){
        cin >> arr[i];
    }
    
    // 정렬할 배열 원소의 시작 주소, 그리고 마지막 주소+1이 필요
    sort(arr, arr+N);
    
    for(int i =0; i<N; i++){
        cout << arr[i] << '\n';
    }
}
