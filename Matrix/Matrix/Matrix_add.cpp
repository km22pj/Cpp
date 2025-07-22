//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    //ios::sync_with_stdio(false);
//    //cin.tie(NULL);
//    int ct;
//    cin >> ct;
//    while (ct--) {
//        int row, col;
//        cin >> row >> col;
//        int* p = new int[row*col];
//        for (int i = 0; i < row*col; i++) {
//             cin >> *(p+i);
//        }
//        for (int i = 1; i < row*col+1; i++) {
//            int input;
//            cin >> input;
//            cout << *(p+i-1) + input << " ";
//            if (i % col == 0) {
//                cout << '\n';
//            }
//        }
//        delete[] p;
//    }
//    return 0;
//}