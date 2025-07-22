#include <iostream>
#include <string>
using namespace std;


int main() {
    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        bool arr[10] = {};                          // �� �ڸ��� ���忩�θ� Ȯ���ϴ� �迭
        int answer = 0;
        unsigned int n;                             // 2^31�����̹Ƿ� unsigned int�� ǥ�� 
        cin >> n;
        unsigned int n2 = n;

        while (n2 != 0) {
            int digit = n2 % 10;                    // �� ������ �ڸ������� Ȯ��
            n2 /= 10;                               // �� ������ �ڸ����� ����
            if (arr[digit] == 1 || digit == 0) {    // �̹� ����� �ڸ��� �Ǵ� �������� �ڸ����� 0�̸� �Ѿ
                continue;
            }   
            arr[digit] = 1;                         // ����� �ڸ����� �迭�� ����
            if (n % digit == 0) { answer++; }       // �ڸ��� ���ڷ� ����������� �� +1
        }
        cout << answer << endl;
    }
    return 0;
}