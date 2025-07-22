#include <iostream>
#include <string>
using namespace std;


int main() {
    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        bool arr[10] = {};                          // 각 자릿수 등장여부를 확인하는 배열
        int answer = 0;
        unsigned int n;                             // 2^31까지이므로 unsigned int로 표현 
        cin >> n;
        unsigned int n2 = n;

        while (n2 != 0) {
            int digit = n2 % 10;                    // 맨 오른쪽 자릿수부터 확인
            n2 /= 10;                               // 맨 오른쪽 자리수를 없앰
            if (arr[digit] == 1 || digit == 0) {    // 이미 사용한 자리수 또는 나누려는 자릿수가 0이면 넘어감
                continue;
            }   
            arr[digit] = 1;                         // 사용한 자릿수는 배열에 저장
            if (n % digit == 0) { answer++; }       // 자릿수 숫자로 나누어떨어지면 답 +1
        }
        cout << answer << endl;
    }
    return 0;
}