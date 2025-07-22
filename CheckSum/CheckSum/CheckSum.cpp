#include <iostream>
using namespace std;


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        unsigned int num;
        int check = 0, sum = 0;
        bool flag = false;
        cin >> num;
        while (num) {
            for (int i = 0; i < 8; i++) {
                int bit = num % 2;
                for (int j = 0; j < i; j++) {
                    bit *= 2;
                }
                sum += bit;
                num /= 2;
            }
            if (flag == false) {
                check = sum;
                sum = 0;
                flag = true;
            }
        }
        sum %= 256;
        sum = 255 - sum;
        if (sum == check) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}