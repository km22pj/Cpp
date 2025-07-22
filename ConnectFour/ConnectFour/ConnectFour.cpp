#include <iostream>
#include <vector>

using namespace std;

bool four(vector<vector<int>> ar, int row, int col, int player) {
    if (row < 3 && ar[row][col] == player && 
        ar[row+1][col] == player && ar[row+2][col] == player && ar[row+3][col] == player) {
        return 1;
    }
    else if (col < 4 && ar[row][col] == player && ar[row][col+1] == player && 
        ar[row][col + 2] == player && ar[row][col + 3] == player) {
        return 1;
    }
    else if (row < 3 && col < 4 && ar[row][col] == player && ar[row+1][col + 1] == player &&
        ar[row + 2][col + 2] == player && ar[row + 3][col + 3] == player) {
        return 1;
    }
    else if (row > 2 && col < 4 && ar[row][col] == player && ar[row - 1][col + 1] == player &&
        ar[row - 2][col + 2] == player && ar[row - 3][col + 3] == player) {
        return 1;
    }
    else return 0;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(6, vector<int>(7, 0));
        int player1 = 1;
        bool flag = 0;

        for (int i = 0; i < n; i++) {
            int chip;
            cin >> chip;
            chip--;
            for (int j = 0; j < 6; j++) {       // 칩 집어넣기
                if (arr[j][chip] == 0 && player1 == 1) {
                    arr[j][chip] = 1;
                    break;
                }
                if (arr[j][chip] == 0 && player1 == 2) {
                    arr[j][chip] = 2;
                    break;
                }
            }

            if (player1 == 1) player1++;        // 턴 교체
            else player1--;
        }

        if (player1 == 1) player1++;
        else player1--;

        for (int i = 0; i < 6; i++) {       // 이긴 플레이어 찾기
            for (int j = 0; j < 7; j++) {
                if (arr[i][j] == player1) {
                    if (four(arr, i, j, player1) == 1) {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 1) cout << player1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}