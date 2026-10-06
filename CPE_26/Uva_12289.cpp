// 12289 One-Two-Three
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string one = "one", two = "two", three = "three";
    while (n--){
        string s;
        cin >> s;
        int len = s.size();
        bool found = false;
        if (len == 3){
            for (int i = 0; i < 3; i++){
                string now = s;
                now[i] = one[i];
                if (now == one){
                    cout << 1 << '\n';
                    found = true;
                    break;
                }
            }
            if (found) continue;
            for (int i = 0; i < 3; i++){
                string now = s;
                now[i] = two[i];
                if (now == two){
                    cout << 2 << '\n';
                    found = true;
                    break;
                }
            }
            if (found) continue;
        }else{
            for (int i = 0; i < 5; i++){
                string now = s;
                now[i] = three[i];
                if (now == three){
                    cout << 3 << '\n';
                    found = true;
                    break;
                }
            }
            if (found) continue;
        }
    }
    return 0;
}