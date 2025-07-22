#include <iostream>
#include <vector>
using namespace std;

bool two(char c) {
    return (c - '0') % 2 == 0 ;
}
bool threenine(const char *p, int i) {
    int sum = 0;
    while (*p) sum += (*p++ - '0');
    return sum % i == 0;
}
bool four(const char* p, int len) {
    char c1, c2;
    if (len >= 2) {
        c1 = p[len - 2];
        c2 = p[len - 1];
    }
    else {
        c1 = '0';
        c2 = p[len - 1];
    }
    return ((c1 - '0') * 10 + (c2 - '0')) % 4 == 0;
}
bool fiveten(char c, int i) {
    if (i == 10) {
        return c == '0';
    }
    return (c == '0' || c == '5');
}
bool seven(const char *p, int len) {
    vector<int>ip(len);
    int j = 0;
    while (*(p+j)) {
        ip[j] = *(p+j) - '0';
        j++;
    }
    for (int i = 0; i < ip.size() - 1; i++) {
        int m = 3 * ip[i] + ip[i + 1];
        ip[i] = m / 10;
        ip[i + 1] = m % 10;
        if (ip[i] != 0) i--;
    }
    return ip[len - 1] % 7 == 0;
}
bool eight(const char*p, int len) {
    char c1, c2, c3;
    if (len >= 3) {
        c1 = p[len - 3];
        c2 = p[len - 2];
        c3 = p[len - 1];
    }
    else if (len == 2) {
        c1 = '0';
        c2 = p[len - 2];
        c3 = p[len - 1];
    }
    else {
        c1 = '0';
        c2 = '0';
        c3 = p[len - 1];
    }
    return ((c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0')) % 8 == 0;
}
bool eleven(const char* p, int len) {
    int odd = 0;
    int even = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) odd += (p[i]-'0');
        else even += (p[i]-'0');
    }
    return abs(odd - even) % 11 == 0;
}
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        bool arr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        string s;
        cin >> s;
        int len = s.length();
        const char* p = s.c_str();
        char last = p[len - 1];
        if (two(last))arr[0] = 1;
        if (threenine(p, 3)) arr[1] = 1;
        if (four(p, len)) arr[2] = 1;
        if (fiveten(last, 5)) arr[3] = 1;
        if (arr[0] == 1 && arr[1] == 1) arr[4] = 1;
        if (seven(p, len)) arr[5] = 1;
        if (eight(p, len)) arr[6] = 1;
        if (threenine(p, 9)) arr[7] = 1;
        if (fiveten(last, 10))arr[8] = 1;
        if (eleven(p, len))arr[9] = 1;
        for (int i : arr) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}