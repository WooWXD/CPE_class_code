//10170 The Hotel with Infinite Rooms
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    // S 是初始團體大小，D 是目標天數
    long long S, D;

    // 持續讀取輸入，直到沒有輸入為止 (EOF)
    while (cin >> S >> D) {
        
        // 步驟 1: 計算一個偏移量 C
        // C 代表從 1 人團體到 (S-1) 人團體總共會花費的天數
        // C = 1 + 2 + ... + (S-1)
        // 根據等差數列公式，C = (S-1) * S / 2
        long long C = S * (S - 1) / 2;

        // 步驟 2: 計算調整後的目標天數 D'
        // 
        // 我們的問題是：第 D 天是哪個團體？
        // 團體 S 結束於第 S 天 (總天數 S)
        // 團體 S+1 結束於第 S + (S+1) 天
        // 團體 N 結束於第 S + (S+1) + ... + N 天
        // 
        // 設 T(N) = 1 + 2 + ... + N = N*(N+1)/2
        // 團體 N 結束的總天數 = T(N) - T(S-1) = N*(N+1)/2 - C
        //
        // 我們要找最小的 N (N >= S)，使得 D <= N*(N+1)/2 - C
        // 
        // 將不等式移項： D + C <= N*(N+1)/2
        // 
        // 我們令 D' = D + C。
        // 問題簡化為：找到最小的 N (N >= S)，使得 N*(N+1)/2 >= D'
        long long D_prime = D + C;

        // 步驟 3: 使用二元搜尋法 (Binary Search) 尋找 N
        
        // 搜索範圍的左邊界。團體大小至少是 S
        long long L = S;
        
        long long R = 2000000000LL; // 加上 LL 確保是 long long 型別

        // ans 用來儲存找到的最小的 N (即我們的答案)
        long long ans = R; 

        // 開始二元搜尋
        while (L <= R) {
            
            // 計算中間值。使用 L + (R - L) / 2 可避免 L+R 直接相加時溢位
            long long mid = L + (R - L) / 2;

            // 計算 T(mid) = 1 + 2 + ... + mid 的總和
            // 檢查：mid 最大為 2e9，mid * (mid + 1) 約為 4e18，除以 2 為 2e18。
            // 這些計算都在 long long 的範圍內，是安全的。
            long long val = mid * (mid + 1) / 2;

            if (val >= D_prime) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        cout << ans << endl;
    }

    return 0; // 程式正常結束
}
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1111

//短解
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long S, D;
    while (cin >> S >> D) {
        // 從 S 開始找右邊界 算梯形公式
        long long L = S;
        long long R = 2000000000LL;
        long long ans = R;
        while (L <= R) {
            long long mid = L + (R - L) / 2;
            long long val = (mid+S) * (mid-S+1) / 2;
            if (val >= D) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
