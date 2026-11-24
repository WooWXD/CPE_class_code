// 1586 Molar mass
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main(){
    map <char, float> m;
    m['C'] = 12.01;
    m['H'] = 1.008;
    m['O'] = 16.00;
    m['N'] = 14.01;
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        char elements = '\0';
        int num = 1, cnt = 0;
        float ans = 0;
        for (auto i : s){
            if (i >= 'A' && i <= 'Z'){
                // cout << i << ' ' << num << ' ' << cnt << '\n';
                if (elements){
                    if (cnt != 0) num = cnt;
                    ans += m[elements] * num;
                }
                elements = i;
                num = 1;
                cnt = 0;
            }
            if (isdigit(i)){
                cnt = cnt * 10 + (i - '0');
            }
        }
        if (elements){
            if (cnt != 0) num = cnt;
            ans += m[elements] * num;
        }
        cout << fixed << setprecision(3) << ans << '\n';
    }
}