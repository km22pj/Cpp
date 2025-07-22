#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int>arr(n + 2, 0);
        for (int i = 1; i < n + 1; i++) {
            cin >> arr[i];
        }
        while (k--) {
            int tmp = 0;
            for (int i = 1; i < n + 1; i++) {
                if (tmp + arr[i + 1] < 3 && arr[i] > 0) tmp = arr[i]--;
                else if (tmp + arr[i + 1] > 7 && arr[i] > 0) tmp = arr[i]--;
                else {
                    if (tmp + arr[i + 1] > 3 && tmp + arr[i + 1] <= 7 && arr[i] < 9)tmp = arr[i]++;
                    else tmp = arr[i];
                }
            }
        }
        for (int i = 1; i < n + 1; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';        
    }
    return 0;
}