#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ct;
    cin >> ct;
    while (ct--) {
        int r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        int* s = new int[r1 * r3];
        int* p = new int[r1 * r2];
        vector<vector<int>> vp(r3, vector<int>(r2));

        for (int i = 0; i < r1 * r2; i++) {
            cin >> *(p + i);
        }
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < r3; j++) {
                int input;
                cin >> input;
                vp[j][i] = input;
            }
        }
        for (int k = 0; k < r1; k++) {
            for (int i = 0; i < r3; i++) {
                int sum = 0;
                for (int j = 0; j < r2; j++) {
                    sum += (*(p+ r2*k + j) * vp[i][j]);
                }
                *(s+ r3*k + i) = sum;
            }
        }
        for (int i = 1; i < r1 * r3+1; i++) {
            cout << *(s + i - 1) << " ";
            if (i % r3 == 0) {
                cout << '\n';
            }
        }
        delete[] s;
        delete[] p;
    }
    return 0;
}