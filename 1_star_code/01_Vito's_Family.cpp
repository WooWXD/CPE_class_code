//10041 - Vito's Family
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int r, ans = 1e9;
        cin >> r;
        int house[r];
        for (int i = 0; i < r; i++){
            cin >> house[i];
        }
        sort(house, house+r);
        for (int i = house[0]; i < house[r-1]; i++){
            int tot = 0;
            for (auto j : house){
                tot += abs(i - j);
            }
            ans = min(ans, tot);
        }
        cout << ans << '\n';
    }
}
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=982&mosmsg=Submission+received+with+ID+30741966

// 中位數解法
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;  //Testcases
    cin>>T;
    while(T--) {
        int r;  //親戚的數目
        cin>>r;

        int v[501]={};  //用來裝親戚住的街址
        int res=0;  //results

        for(int i=0;i<r;i++) {
            cin>>v[i]; 
        }

        sort(v,v+r);  //升序排列
        int mid=v[r/2];  //主角要住在中位數的地方

        for(int i=0; i<r; i++) {
            res+=abs(mid-v[i]);
        }
        cout<<res<<"\n";
    }
    return 0;
}
