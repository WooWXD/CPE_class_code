// 11650 Mirror Clock
#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        char s;
        int h, m;
        cin >> h >> s >> m;
        if (m == 0){
            h = 12 - h;
        }else{
            h = 11 - h;
            m = 60 - m;
        }
        if (h <= 0) {
            h += 12;
        }
        if (h < 10) cout << "0";
        cout << h << ":";
        if (m < 10) cout << "0";
        cout << m << '\n';
        
    }
    return 0;
}