#include <iostream>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int t, n, last_num, zero_count, two_count = 0, five_count=0;
        cin >> t;
        int multple = 1;
        while (t--) {
            cin >> n;
            while (n % 2 == 0) {
                two_count++;
                n /= 2;
            }
            while (n % 5 == 0) {
                five_count++;
                n /= 5;
            }
            multple *= (n%10);
            multple %= 10;
        }
        int ad;
        if (two_count > five_count) {
            zero_count = five_count;
            ad = two_count - five_count;
            int arr[4] = { 6,2,4,8 };
            multple *= arr[ad % 4];
        }
        else if (two_count < five_count) {
            zero_count = two_count;
            ad = five_count - two_count;
            multple *= 5;
        }
        else zero_count = two_count;
        last_num = multple % 10;
        cout << last_num << " " << zero_count << endl;
    }
    return 0;
}