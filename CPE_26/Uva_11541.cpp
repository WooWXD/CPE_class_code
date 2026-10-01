// 11541 Decoding
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int rd = 1; rd <= n; rd++){
        string s, ans = "";
        cin >> s;
        char now = '\0';
        int cnt = 0;
        for (auto& i : s){
            if (isdigit(i)){
                cnt = cnt * 10 + (i-'0');
            }else{
                if (now == '\0'){
                    now = i;
                }else{
                    if (cnt == 0){
                        ans += now;
                    }else{
                        for (int j = 0; j < cnt; j++){
                            ans += now;
                        }
                    }
                    now = i;
                }
                cnt = 0;
            }
        }
        for (int j = 0; j < cnt; j++){
            ans += now;
        }
        cout << "Case " << rd << ": " << ans << endl;
    }
    return 0;
}