#include <iostream>
#include <string>
using namespace std;


int main() {
    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        string n;
        cin >> n;

        /*int answer = 0;
        bool in_num = false;

        for (char c : n) {
            if (isdigit(c)) {
                if (!in_num) {
                    answer++;
                    in_num = true;
                }
            }
            else {
                in_num = false;
            }
        }*/

        int answer = 0;
        const char* p = n.c_str();          // string객체 안의 C-style 문자열(const char*)을 반환
        int count = 0;                      // 현재 세고 있는 연속적인 숫자의 개수
        while (*p) {
            if (*p >= '0' && *p <= '9') {   // 숫자일 경우
                if (count == 0) {
                    answer++;
                    count++;
                }

            }
            else {                          // 숫자가 아닐 경우
                if (count != 0) {
                    count = 0;
                }
            }
            p++;
        }
        cout << answer << endl;
    }
    return 0;
}