#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        bool flag1 = 1;
        bool flag2 = 1;
        bool flag3 = 1;


        vector<vector<int>>arr(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 9; i++) {
            bool ar[10] = { 0,0,0,0,0,0,0,0,0,0 };
            //  1 2 3 4 5 6 7 8 9

            for (int j = 0; j < 9; j++) {
                if (ar[arr[i][j]] == 0) {
                    ar[arr[i][j]] = 1;
                }
                else {
                    flag1 = 0;
                    break;
                }
            }
            if (flag1 == 0) {
                break;
            }
        }


        for (int i = 0; i < 9; i++) {
            bool ar[10] = { 0,0,0,0,0,0,0,0,0,0 };
            //  1 2 3 4 5 6 7 8 9
            for (int j = 0; j < 9; j++) {
                if (ar[arr[j][i]] == 0) {
                    ar[arr[j][i]] = 1;
                }
                else {
                    flag2 = 0;
                    break;
                }
            }
            if (flag2 == 0) {
                break;
            }
        }


        // for(int i =0; i<9;i+=3){
        //     for(int j=0; j<9; i+=3){

        //     }
        // }

        if (flag1 == 1 || flag2 == 1 || flag3 == 1) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }


    }
    return 0;
}