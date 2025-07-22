#include <iostream>
using namespace std;


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n1, n2, distance = 0, w1 = 0, w2 = 0;
        cin >> n1 >> n2;
        while (n1 != 0 || n2 != 0) {
            if (n1 % 2 != n2 % 2) distance++;
            if (n1 % 2 == 1)w1++;
            if (n2 % 2 == 1)w2++;
            n1 /= 2;
            n2 /= 2;
        }
        cout << w1 << ' ' << w2 << ' ' << distance << endl;
    }
    return 0;
}