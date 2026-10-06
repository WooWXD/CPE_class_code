//10931 - Parity
#include <bits/stdc++.h>
#include <bitset>
using namespace std;

string tobinary(int n){
    string s = "";
    while (n > 0){
        s += to_string(n%2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int N;
    while (cin >> N){
        if (N == 0) break;
        string s = tobinary(N);
        bitset <32> m(N);
        int ans_b = m.count();
        string b = m.to_string();
        // int ans = count(s.begin(), s.end(), '1');
        //printf("The parity of %s is %d (mod 2).\n", s, ans);
        // cout << "The parity of " << s << " is " << ans << " (mod 2).\n";
        cout << "The parity of " << b.substr(b.find('1')) << " is " << ans_b << " (mod 2).\n";
        //cout << s << ' ' << ans << '\n';
    }
}