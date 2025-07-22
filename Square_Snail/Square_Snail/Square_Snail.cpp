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

        int idx = 0;                                    // 총 개수 인덱스
        int a1 = 1;                                     //a의 하한선    
        int b1 = 1;                                     //b의 하한선 
        int a2 = size;                                  //a의 상한선 
        int b2 = size;                                  //b의 상한선 
        int cnt = 0;

        for (int j = 1; j <= size; j++) {                                   //size가 5라면 idx는5, 첫번째 줄은 그냥 계산
            idx++;
            if (idx >= start && idx <= end) {
                cout << (a1 - 1) * size + j << " ";
            }
        }

        while (idx < end) {
            for (int j = ++a1; j <= a2; j++) {                              //a1 하한선 1증가 
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
                    cout << (a2 - 1) * size + j << " ";                    //b2 상한선 1감소 
                }
                if (idx >= end) {
                    break;
                }
            }
            for (int j = --a2; j >= a1; j--) {                              //a2 상한선 1감소
                idx++;
                if (idx >= start && idx <= end) {
                    cout << (j - 1) * size + b1 << " ";
                }
                if (idx >= end) {
                    break;
                }

            }
            for (int j = ++b1; j <= b2; j++) {                               //b1 하한선 1증가
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