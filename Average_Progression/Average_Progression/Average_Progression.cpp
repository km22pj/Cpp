#include <iostream>
#include <string>
//#include <vector>
using namespace std;


int main() {
    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        int n, k, total = 0, answer = 0;
        cin >> n >> k;
        int* arr = new int[n];                      // int arr []�� �����Ҵ� �����̹Ƿ� �ȵ�, �����Ҵ��Ϸ��� �����ͻ���ؾ���
        //vector <int> arr(n);                      // vector�� �����Ҵ��ص���
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }
        int dix = 0;                             // �迭 �����ε���
        while (dix <= n - k) {
            int temp = 0;                        // �ӽ� �հ� ����
            for (int i = dix; i < dix+k; i++) {
                temp += arr[i];
            }
            if (temp/k >= total/n) { answer++; }   // �������� k���� ����� ��ü ��պ��� ū��� +1
            dix++;
        }
        cout << answer << endl;
    }
    return 0;
}