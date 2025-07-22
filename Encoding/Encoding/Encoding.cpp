#include <iostream>
#include <vector>
using namespace std;

double percent[] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 
                    6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 
                    5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074 };

int main() {         
    int tc;
    cin >> tc;
    
    while (tc--) {
        string s;
        int len = 0;
        cin >> s;
        vector<bool>arr(s.length(), false);
        for (int i = 0; i < s.length(); i++) {        // 대문자화
            if (isalpha(s[i])) len++;                 // 문자의 길이
            if (s[i] >= 'a' && s[i] <= 'z') {
                arr[i] = true;
                s[i] = toupper(s[i]);
            }
        }

        int key = 0;
        vector<int>fre(26);
        while (key < 26) {
            int cnt = 0;
            for (int i = 0; i < s.length(); i++) {
                if (isalpha(s[i])) {
                    if (s[i] == key + 'A') cnt++;
                }
            }
            fre[key] = cnt;
            key++;
        }

        double minvalue = 100000;
        string minstring = "";
        int kkey = 0;
        
        int c = 0;
        for (int i = 0; i < 26; i++) {
            double kai = 0;
            int p = 0;
            int f = c;
            while (p < 26) {
                kai += ((double)fre[f] / (double)len * 100.0) * ((double)fre[f] / (double)len * 100.0) / percent[p];
                p++; f++;
                f %= 26;                                                    // 빈도수만 한칸씩 밀어서 다시 계산
            }
            if (minvalue > kai) minvalue = kai, kkey = c;
            c++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                if (s[i] - kkey < 'A') {             // 범위 넘어가면 Z로 다시 돌아옴
                    char c = s[i] - kkey + 26;
                    minstring.push_back(c);
                }
                else minstring.push_back(s[i] - kkey);
            }
            else minstring.push_back(s[i]);
        }

        for (int i = 0; i < minstring.length(); i++) {                  //소문자화
            if (arr[i] == true) minstring[i] = tolower(minstring[i]);
        }
        cout << minstring << endl;
    }
    return 0;
}
