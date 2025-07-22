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
        int* arr = new int[n];                      // int arr []는 정적할당 지정이므로 안됨, 동적할당하려면 포인터사용해야함
        //vector <int> arr(n);                      // vector로 동적할당해도됨
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }
        int dix = 0;                             // 배열 시작인덱스
        while (dix <= n - k) {
            int temp = 0;                        // 임시 합계 저장
            for (int i = dix; i < dix+k; i++) {
                temp += arr[i];
            }
            if (temp/k >= total/n) { answer++; }   // 연속적인 k개의 평균이 전체 평균보다 큰경우 +1
            dix++;
        }
        cout << answer << endl;
    }
    return 0;
}