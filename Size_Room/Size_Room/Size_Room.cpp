#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int col, row;
        cin >> col >> row;
        vector<vector<char>>arr(row, vector<char>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> arr[i][j];
            }
        }

        vector<int>ro;
        vector<int>siz;

        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                int cnt = 0;
                if (arr[i][j] == '.') {
                    arr[i][j] = '+';
                    ro.push_back(i);
                    ro.push_back(j);
                    while (!ro.empty()) {
                        int c = ro.back(); ro.pop_back();
                        int r = ro.back(); ro.pop_back();
                        cnt++;
                        if (arr[r + 1][c] == '.') arr[r + 1][c] = '+', ro.push_back(r + 1), ro.push_back(c);
                        if (arr[r - 1][c] == '.') arr[r - 1][c] = '+', ro.push_back(r - 1), ro.push_back(c);
                        if (arr[r][c + 1] == '.') arr[r][c + 1] = '+', ro.push_back(r), ro.push_back(c + 1);
                        if (arr[r][c - 1] == '.') arr[r][c - 1] = '+', ro.push_back(r), ro.push_back(c - 1);
                    }
                    siz.push_back(cnt);
                }
            }
        }

        cout << siz.size() << endl;
        if (siz.size() > 1) {
            for (int i = 0; i < siz.size(); i++) {
                for (int j = i+1; j < siz.size(); j++) {
                    if (siz[i] < siz[j]) {
                        int tmp = siz[i];
                        siz[i] = siz[j];
                        siz[j] = tmp;
                    }
                }
            }
            for(int a : siz) cout << a << ' ';
            cout << '\n';
        }
        else cout << siz[0] << endl;
        
    }
    return 0;
}