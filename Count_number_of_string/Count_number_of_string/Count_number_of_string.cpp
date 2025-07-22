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
        const char* p = n.c_str();          // string��ü ���� C-style ���ڿ�(const char*)�� ��ȯ
        int count = 0;                      // ���� ���� �ִ� �������� ������ ����
        while (*p) {
            if (*p >= '0' && *p <= '9') {   // ������ ���
                if (count == 0) {
                    answer++;
                    count++;
                }

            }
            else {                          // ���ڰ� �ƴ� ���
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