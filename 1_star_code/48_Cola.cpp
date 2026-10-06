// 11150 - Cola
#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int total = n;    // 總共喝到的數量，初始為買的瓶數
        int empty = n;    // 手上的空瓶數
        
        while (empty >= 3) {
            int new_cola = empty / 3;
            total += new_cola;
            empty = (empty % 3) + new_cola;
        }
        // 換完喝掉後剛好剩 1 個還給朋友，所以總數加 1
        if (empty == 2) {
            total++;
        }
        
        cout << total << '\n';
    }
    return 0;
}

// ------------------------------
// 公式解
#include <iostream>

using namespace std;

int main(){
    int n;
    while (cin >> n){
        cout << n + n/2 << '\n';
    }
    return 0;
}