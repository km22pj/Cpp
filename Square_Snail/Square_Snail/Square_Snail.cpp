#include <iostream>
using namespace std;


int main() {

    int TestCase;
    cin >> TestCase;
    while(TestCase--) {
        int size;
        int start;
        int end;

        cin >> size;
        cin >> start;
        cin >> end;

        int idx = 0;                                    // �� ���� �ε���
        int a1 = 1;                                     //a�� ���Ѽ�    
        int b1 = 1;                                     //b�� ���Ѽ� 
        int a2 = size;                                  //a�� ���Ѽ� 
        int b2 = size;                                  //b�� ���Ѽ� 
        int cnt = 0;

        for (int j = 1; j <= size; j++) {                                   //size�� 5��� idx��5, ù��° ���� �׳� ���
            idx++;
            if (idx >= start && idx <= end) {
                cout << (a1 - 1) * size + j << " ";
            }
        }

        while (idx < end) {
            for (int j = ++a1; j <= a2; j++) {                              //a1 ���Ѽ� 1���� 
                idx++;
                if (idx >= start && idx <= end) {
                    cout << (j - 1) * size + b2 << " ";
                }
                if (idx >= end) {
                    break;
                }
            }
            for (int j = --b2; j >= b1; j--) {
                idx++;
                if (idx >= start && idx <= end) {
                    cout << (a2 - 1) * size + j << " ";                    //b2 ���Ѽ� 1���� 
                }
                if (idx >= end) {
                    break;
                }
            }
            for (int j = --a2; j >= a1; j--) {                              //a2 ���Ѽ� 1����
                idx++;
                if (idx >= start && idx <= end) {
                    cout << (j - 1) * size + b1 << " ";
                }
                if (idx >= end) {
                    break;
                }

            }
            for (int j = ++b1; j <= b2; j++) {                               //b1 ���Ѽ� 1����
                idx++;
                if (idx >= start && idx <= end) {
                    cout << (a1 - 1) * size + j << " ";
                }
                if (idx >= end) {
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}