#include <iostream>
using namespace std;
                                                                            // 1582년 1월 1일 이후 ~ 주어진 해당 연도의 전 달까지의 모든 시간을 총일수를 계산함. 
int main() {                                                                //그리고 총 일수를 7로 나눈 나머지 값으로 해당월의 시작요일 결정.
                                                                            // 일주일, 7일(일요일 ~ 토요일)씩 출력후 줄을 바꿔야함.
                                                                            
    int TestCase;
    cin >> TestCase;
    while(TestCase--) {
        int y; int m;
        cin >> y; cin >> m;
        cout << y << " " << m << endl;
                                                                            // 처음 금요일 인덱스 0, 토요일 인덱스 1, 일요일 인덱스 2 
        int day = 5;                                                        //출력할때 요일번호와 인덱스를 맞춰주기 위해서 5를 더해줌. 0이아닌 5로 초기화 해줌
        int idx;                                                            // 0 0 0 0 0 1 2  따라서 인덱스값에 맞추어 요일이 일월화수목금토일 순으로 정해지게 만듦.
        day += (y - 1582) * 365;                                            
        for (int j = 1582; j <= y; j++) {
            if (j % 400 == 0 || (j % 4 == 0 && j % 100 != 0)) {             //윤년을 고려해야함. 윤년은 366일이기떄문에 윤년이 있는만큼 1을 더해주어야함
                day++;
            }
        }                                                                  

        for (int j = 1; j < m; j++) {
            if (j == 2) {
                if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
                    day += 29;                                              // 마찬가지로 윤년을 고려하여 윤년이면 2월에 29일 추가, 아니면 28일 추가
                }
                else {
                    day += 28;
                }
            }
            else if (j == 4 || j == 6 || j == 9 || j == 11) {
                day += 30;
            }
            else {      // 1,3,5,7,8,10,12월
                day += 31;
            }
        }


                                                                            //구할 연도의 월에따라 출력할 일수를 결정
        if (m == 2) {
            if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
                idx = 29;
            }
            else {
                idx = 28;
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            idx = 30;
        }
        else {
            idx = 31;
        }

        day %= 7;                                                         // 주어진 달의 시작요일을 구해줌, 5이면 금요일 6이면 토요일, 0이면 일요일
        for (int j = 0; j < day; j++) {
            cout << 0 << " ";
        }

        int strt = 1;                                                     // 1일 부터 출력
        while (strt <= idx) {                                             // 주어진 달의 총 일 수만큼 반복, 그 사이에 7일마다 줄바꿈
            for (int j = day; j < 7; j++) {                               // 해당 요일 전까지 0을 출력했으므로 day부터 1 출력
                if (strt > idx) {                                         // 마지막 일 수 까지 갔다면 반복문 멈춤 
                    for (; j < 7; j++) {
                        cout << 0 << " ";                                 //후반 요일도 0으로
                    }
                    break;
                }
                cout << strt << " ";
                strt++;

            }
            day = 0;
            cout << endl;
        }
    }
    return 0;
}