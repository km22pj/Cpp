#include <iostream>
#include <vector>

using namespace std;

int xx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int yy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int fnd(vector<string>& arr, string s, int i, int j) {
    int row = arr.size(), col = arr[0].length();
    for (int dir = 0; dir < 8; dir++) {
        int k, x = i, y = j;
        for (k = 0; k < s.length(); k++) {
            if (x < 0 || y < 0 || x >= row || y >= col)break;
            if (arr[x][y] != s[k])break;
            x += xx[dir];
            y += yy[dir];
        }
        if (k == s.length()) return dir;
    }
    return -1;
}


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int row, col, cnt;
        cin >> row >> col;
        vector<string>arr(row);
        for (int i = 0; i < row; i++) cin >> arr[i];

        cin >> cnt;
        while (cnt--) {
            string s;
            cin >> s;
            int u, v, r=-1;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (arr[i][j] == s[0]) {
                        r = fnd(arr, s, i, j);
                        if (r != -1) {
                            u = i+1; v = j+1;
                            break;
                        }
                    }
                }
                if (r != -1) break;
            }
            if (r == -1) cout << r << endl;
            else cout << u << " " << v << " " << r << endl;
        }
    }
    return 0;
}