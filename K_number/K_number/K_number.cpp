#include <iostream>
#include <string>
using namespace std;


int main() {

    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        int n;
        cin >> n;
        int number = 0;             // 숫자 0부터 시작
        int cnt = 0;                // 셀 수 있는 숫자의 총 자리수 카운터
        int tmp = 0;
        while (cnt < n) {
            number++;                           // 1부터 숫자 카운트 시작
            tmp = to_string(number).length();   // 숫자의 자릿수
            cnt += tmp;
        }

        if (n < cnt) {
            cnt -= tmp;                 //총 자리수를 낮춰줌
            for (int i = 0; i < tmp; i++) {
                cnt++;
                char c = to_string(number)[i];
                if (cnt == n) {
                    int k = int(c);
                    cout << c - '0' << endl;  //문자를 정수로 바꿔줌, 아스키코드 문자 '0'값을 빼면됨
                    break;
                }
            }

        }
        else if (n == cnt) {
            int ans = number % 10;
            cout << ans << endl;
        }
    }
    return 0;
}