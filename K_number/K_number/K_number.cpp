#include <iostream>
#include <string>
using namespace std;


int main() {

    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        int n;
        cin >> n;
        int number = 0;             // ���� 0���� ����
        int cnt = 0;                // �� �� �ִ� ������ �� �ڸ��� ī����
        int tmp = 0;
        while (cnt < n) {
            number++;                           // 1���� ���� ī��Ʈ ����
            tmp = to_string(number).length();   // ������ �ڸ���
            cnt += tmp;
        }

        if (n < cnt) {
            cnt -= tmp;                 //�� �ڸ����� ������
            for (int i = 0; i < tmp; i++) {
                cnt++;
                char c = to_string(number)[i];
                if (cnt == n) {
                    int k = int(c);
                    cout << c - '0' << endl;  //���ڸ� ������ �ٲ���, �ƽ�Ű�ڵ� ���� '0'���� �����
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