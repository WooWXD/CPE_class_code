//10019 - Funny Encryption Method
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        string M_str;
        cin >> M_str;

        int M_decimal = stoi(M_str);
        
        int b1 = countSetBits(M_decimal);

        int b2 = 0;
        for (char c : M_str) {
            int hex_digit_value = c - '0';
            b2 += countSetBits(hex_digit_value);
        }

        cout << b1 << " " << b2 << "\n";
    }

    return 0;
}

// ------------------------------------ //
// bitset
// 10019 Funny Encryption Method
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        int m;
        cin >> m;
        
        bitset <32> a1(m);
        int k = 1;
        string s = to_string(m);
        long long m1 = 0;
        for (int i = s.size()-1; i >= 0; i--){
            m1 += (s[i] - '0') * k;
            k *= 16;
        }
        
        bitset <32> a2(m1);
        cout << a1.count() << ' ' << a2.count() << '\n';
        
    }
    return 0;
}
