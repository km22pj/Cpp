#include <iostream>
#include <string>
using namespace std;

char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int inp, outp;
        string num;
        cin >> inp >> num >> outp;
        int sum = 0;

        if (inp != 10) {            // �Է°��� 10�������� ��ȯ 
            int cnt = num.size();
            while (cnt--) {
                int tmp = (isdigit(num[cnt]) ? num[cnt] - '0' : num[cnt] - 'a' + 10);
                for (int i = 0; i < num.size() - cnt - 1; i++) {
                    tmp *= inp;
                }
                sum += tmp;
            }
        }
        else {
            for (int i = num.size() - 1; i >= 0; i--) {
                int tmp = num[i] - '0';
                int j = num.size() - i;
                while (j - 1) {
                    tmp *= 10;
                    j--;
                }
                sum += tmp;
            }
        }

        string s = "";
        if (outp != 10) {           // ��°� 10�������� ��ȯ
            while (sum > 0) {
                s += arr[sum % outp];
                sum /= outp;
            }
            for (int i = s.size() - 1; i >= 0; i--) {
                cout << s[i];
            }
            cout << '\n';
        }
        else {
            cout << sum << endl;
        }
    }
    return 0;
}