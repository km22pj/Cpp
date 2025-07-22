#include <iostream>
using namespace std;


int main() {

    int TestCase;
    cin >> TestCase;
    while (TestCase--) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        int area = 0;
        int length = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        area = area + (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);    // 두 사각형의 넓이
        length = length + 2 * (x2 - x1 + y2 - y1 + x4 - x3 + y4 - y3);  // 두 사각형의 둘레

        int tmp1, tmp2;
        if (x3 > x2 || x4 < x1 || y3 > y2 || y4 < y1) {
            ;
        }
        else {
            // x좌표
            if (x3 >= x1) {
                if (x4 >= x2) {
                    tmp1 = x3;
                    tmp2 = x2;
                }
                else if (x4 < x2) {
                    tmp1 = x3;
                    tmp2 = x4;
                }
            }
            else if (x3 < x1) {
                if (x4 <= x2) {
                    tmp1 = x1;
                    tmp2 = x4;
                }
                else if (x4 > x2) {
                    tmp1 = x1;
                    tmp2 = x2;
                }
            }
            // y좌표
            if (y3 >= y1) {
                if (y4 <= y2) {
                    area -= (tmp2 - tmp1) * (y4 - y3);
                    length -= 2 * (tmp2 - tmp1 + y4 - y3);
                }
                else if (y4 > y2) {
                    area -= (tmp2 - tmp1) * (y2 - y3);
                    length -= 2 * (tmp2 - tmp1 + y2 - y3);
                }
            }
            else if (y3 < y1) {
                if (y2 >= y4) {
                    area -= (tmp2 - tmp1) * (y4 - y1);
                    length -= 2 * (tmp2 - tmp1 + y4 - y1);
                }
                else if (y2 < y4) {
                    area -= (tmp2 - tmp1) * (y2 - y1);
                    length -= 2 * (tmp2 - tmp1 + y2 - y1);
                }
            }
        }
        cout << area << " " << length << endl;
    }
    return 0;
}