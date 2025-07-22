#include <iostream>
#include <vector>

using namespace std;

string num10[] = {"", "One", "Two", "Three", "Four", "Five", "Six",
                  "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
                  "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                   "Eighteen", "Nineteen" };
string num100[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                   "Eighty", "Ninety"};
string num1000[] = { "Hundred", "Thousand", "Million", "Billion" };


void numstr(string& s, unsigned int num) {
    if (num == 0) return;

    unsigned int n1 = num / 100; num %= 100;
    unsigned int n2 = num / 10;
    unsigned int r = num % 10;
    
    if (n1 != 0) {
        s += num10[n1];
        s += "_"+num1000[0];
        if (num != 0) {
            if(num < 20) s += "_" + num10[num];
            else {
                s += "_" + num100[n2];
                if (r != 0) s += "_" + num10[r];
            }
        }
    }
    else {
        if (num != 0) {
            if (num < 20) s += num10[num];
            else {
                s += num100[n2];
                if (r != 0) s += "_" + num10[r];
            }
        }
    }   
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        unsigned long long n;
        string s = "";
        cin >> n;
        if (n < 1000) {
            numstr(s, n);
        }
        else if (n < 1000ULL * 1000) {
            unsigned int n1 = n / 1000;
            n %= 1000;
            numstr(s, n1); s += "_";
            s += num1000[1];
            if (n != 0) {
                s += "_";
                numstr(s, n);
            }
        }

        else if (n < 1000ULL * 1000 * 1000) {
            unsigned int n1 = n / (1000ULL * 1000); n %= (1000ULL * 1000);
            unsigned int n2 = n / 1000;
            n %= 1000;
            numstr(s, n1); s += "_";
            s += num1000[2];

            if (n2 != 0) {
                s += "_"; numstr(s, n2);
                s += "_" + num1000[1];
            }
            if (n != 0) {
                s += "_";
                numstr(s, n);
            }
        }

        else {
            unsigned int n0 = n / (1000ULL * 1000 * 1000); n %= (1000ULL * 1000 * 1000);
            unsigned int n1 = n / (1000ULL * 1000); n %= (1000ULL * 1000);
            unsigned int n2 = n / 1000;
            n %= 1000;
            numstr(s, n0); s += "_";
            s += num1000[3];
            if (n1 != 0) {
                s += "_"; numstr(s, n1);
                s += "_" + num1000[2];
            }
            if (n2 != 0) {
                s += "_"; numstr(s, n2);
                s += "_" + num1000[1];
            }
            if (n != 0) {
                s += "_"; numstr(s, n);
            }
           
        }

        cout << s << endl;
    }
    return 0;
}