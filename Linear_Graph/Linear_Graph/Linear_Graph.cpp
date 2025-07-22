#include <iostream>
#include <vector>
using namespace std;

int main() {

    /*int TestCase;
    cin >> TestCase;
    for (int cnt = 0; cnt < TestCase; cnt++) {
        int num;
        cin >> num;
        vector<vector<char>> arr(num, vector<char>(num, '.'));
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                if (i == num / 2) {
                    if (j == num / 2) {
                        arr[i][j] = 'O';
                    }
                    else {
                        arr[i][j] = '+';
                    }
                }
                else if (j == num / 2) {
                    arr[i][j] = 'I';
                }
                else if (j == num - 1 - i) {
                    arr[i][j] = '*';
                }
                cout << arr[i][j];
            }
            if (cnt == TestCase - 1 && i == num - 1) {
                continue;
            }
            else {
                cout << endl;
            }

        }
    }*/


    int TestCase;
    cin >> TestCase;
    for (int cnt = 0; cnt < TestCase; cnt++) {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++) {
            if (i == num / 2) {
                for (int k = 0; k < num; k++) {
                    if (k == num / 2) {
                        cout << 'O';
                    }
                    else {
                        cout << '+';
                    }
                }
                cout << endl;
            }
            else {
                for (int j = 0; j < num; j++) {
                    if (j == num / 2) {
                        cout << 'I';
                    }
                    else {
                        if (j == num - 1 - i) {
                            cout << '*';
                        }
                        else {
                            cout << '.';
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}