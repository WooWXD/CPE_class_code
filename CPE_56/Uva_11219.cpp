#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int round = 1; round <= T; round++){
        int birth[3], now[3];
        char line;
        cin >> now[2] >> line >> now[1] >> line >> now[0];
        cin >> birth[2] >> line >> birth[1] >> line >> birth[0];
        
        cout << "Case #" << round << ": ";
        if (birth[0] == now[0] && birth[1] == now[1] && birth[2] == now[2]){
            cout << "0\n";
            continue;
        }
        int birthday = birth[1] * 100 + birth[2];
        int nowadays = now[1] * 100 + now[2];
        // cout << birthday << " --- " << nowadays << '\n';
        int ans = 0;
        bool invalid = true;
        if (birth[0] > now[0]){
            invalid = false;
        }else if (birth[0] == now[0]){
            int birthday = birth[1] * 100 + birth[2];
            int nowadays = now[1] * 100 + now[2];
            if (birthday > nowadays){
                invalid = false;
            }else{
                cout << "0\n";
                continue;
            }
        }else{
            ans = now[0] - birth[0];
            if (birthday > nowadays)
                ans -= 1;
        }
        if (invalid){
            if (ans > 130){
                cout << "Check birth date";
            }else{
                cout << ans;
            }
            cout << '\n';
        }else{
            cout << "Invalid birth date\n";
        }
    }
}