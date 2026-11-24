#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s[m];
        
        for (int i = 0; i < m; i++) cin >> s[i];

        int ans = n;

        for (int i = 1; i < m; i++){
            int j;
            for (j = 0; j <= n; j++){
                string x = s[i].substr(0, j);
                string y = s[i-1].substr(n-j);
                if (x != y) break;
            }
            ans += j;
        }
        cout << ans << '\n';
    }
}