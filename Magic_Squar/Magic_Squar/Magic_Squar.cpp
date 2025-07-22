#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int r, cnt = 1;
        cin >> r;
        vector<vector<int>>arr(r, vector<int>(r, 0));

        int row = 0, col = r / 2;
        while (cnt <= r * r) {
            int c = 1;
            while (arr[row][col] != 0) {
                row++;
                if (row > r - 1) row = 0;
                if (c == 1) {
                    col--; c--;
                    if (col < 0) col = r - 1;
                }
            }

            arr[row][col] = cnt;
            row--; col++; cnt++;

            if (row < 0) row = r-1;
            if (col > r - 1) col = 0;

        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < r; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}