#include <iostream>
using namespace std;


int main() {

    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        int a, b, c, num_, answer = 0;
        cin >> num_;
        num_ -= 3;
        cin >> a; cin >> b; cin >> c;

        int tmp = 0;                    // 크기가 일정할 떄의 값 임시 보관
        if (a < b) {
            if (b > c) {
                answer++;
            }
            else if (b == c) {
                tmp = b;
            }
        }

        while ((num_)--) {
            a = b;
            b = c;
            cin >> c;
            if (a < b) {
                if (b == c) {
                    tmp = b;
                }
                else if (b > c) {
                    answer++;
                    tmp = 0;
                }
            }
            else if (a == b) {
                if (b > c && a == tmp) {
                    answer++;
                    tmp = 0;
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}