#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        while (true) {
            m++;
            if (m == 60) {
                m = 0;
                h = (h + 1) % 24;
            }
            string s = to_string(h * 100 + m);
            string r = s;
            reverse(r.begin(), r.end());
            if (s == r) {
                printf("%02d:%02d\n", h, m);
                break;
            }
        }
    }
}