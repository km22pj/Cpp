#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        bool ans = true;
        vector<char>arr;

        const char* ps = s.c_str();

        for (int i = 0; i < s.length(); i++) {
            if (*(ps+i) == '(' || *(ps+i) == '{' || *(ps+i) == '[') arr.push_back(*(ps+i));
            else if (*(ps+i) == ')' || *(ps+i) == '}' || *(ps+i) == ']') {
                if (arr.empty()) {
                    ans = false;
                    break;
                }

                if ((*(ps+i) == ')' && arr.back() == '(') || (*(ps+i) == '}' && arr.back() == '{') || (*(ps+i) == ']' && arr.back() == '[')) {
                    arr.pop_back();
                }
                else {
                    ans = false;
                    break;
                }
            }
        }
        if (!arr.empty()) ans = false;
        cout << ans << endl;
    }
    return 0;
}