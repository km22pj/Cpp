#include <iostream>
#include <string>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string n;
        bool ans[] = { 0,0,0,0,0 };  // ���� / �� / �Ҽ� / ����e / ��
        cin >> n;
        const char* ps = n.c_str();
        int cnt = 0;
        for (int i = 0; i < n.length(); i++) {
            if (*(ps + i) >= '0' && *(ps + i) <= '9') {
                if (*(ps+i-1) == '.') ans[2] = 1;
                cnt++;
            }

            else if (*(ps + i) == '.') {
                if (ans[1] == 1 || ans[3] == 1) { // �̹� ��, ������ ������
                    ans[4] = 1;
                    break;
                }
                else {
                    if (cnt != 0) ans[0] = 1, ans[1] = 1;  //���� �κ�, ��  1
                    else ans[1] = 1;
                    cnt = 0;
                }
            }

            else if (*(ps + i) == 'e' || *(ps + i) == 'E') {
                if (ans[3] == 1 || (ans[0] == 0 && cnt == 0) || i == n.length()-1) {
                    ans[4] = 1;
                    break;
                }
                else {
                    if (ans[1] == 1) {
                        if (cnt == 0) ans[3] = 1;
                        else ans[2] = 1, ans[3] = 1;        //�Ҽ��κ�, ����  1
                        cnt = 0;
                    }
                    else {
                        if (cnt == 0) {
                            ans[4] = 1;
                            break;
                        }
                        else ans[0] = 1, ans[3] = 1, cnt = 0;
                    }
                }
            }

            else if (*(ps + i) == '-' || *(ps + i) == '+') {
                if(i==0 && (*(ps+i+1)>='0' && *(ps+i+1)<='9'));
                else if ((*(ps + i + 1) >='0' && *(ps+i+1)<='9') && (*(ps + i - 1) == 'e' || *(ps + i - 1) == 'E'));
                else {
                    ans[4] = 1;
                    break;
                }
            }
        }

        if(ans[4]==1) cout << 0 << endl;
        else {
            if ((ans[0] == 1 || ans[2] == 1) && (ans[1] == 1 || ans[3] == 1)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}