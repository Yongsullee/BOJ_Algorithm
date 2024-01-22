#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    sort(arr.begin(), arr.end());

    int start = 0;
    int end = n - 1;
    int cnt = 0;

    while (start < end) {
        int sum = arr[start] + arr[end];
        if (sum == x) {
            cnt++;
            start++;
            end--;
        } else if (sum < x) {
            start++;
        } else {
            end--;
        }
    }

    cout << cnt;

    return 0;
}
