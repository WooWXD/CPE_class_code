// 392 Polynomial Showdown
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> coe(9, 0);
    while (cin >> coe[8]) {
        for (int i = 7; i >= 0; i--) {
            cin >> coe[i];
        }

        // 檢查是否全為 0
        bool allZero = true;
        for (int i = 0; i <= 8; i++) {
            if (coe[i] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            cout << 0 << '\n';
            continue;
        }

        bool isFirst = true; // 紀錄是否為印出的第一項

        for (int i = 8; i >= 0; i--) {
            if (coe[i] == 0) continue;

            if (isFirst) {
                // 第一項：如果是負的，印出 "-"；如果是正的，不印正號
                if (coe[i] < 0) {
                    cout << "-";
                    if (abs(coe[i]) != 1 || i == 0) cout << -coe[i];
                } else {
                    if (coe[i] != 1 || i == 0) cout << coe[i];
                }
                isFirst = false;
            } else {
                // 後續項：需要印出 " + " 或 " - "
                if (coe[i] < 0) {
                    cout << " - ";
                    if (abs(coe[i]) != 1 || i == 0) cout << -coe[i];
                } else {
                    cout << " + ";
                    if (coe[i] != 1 || i == 0) cout << coe[i];
                }
            }

            // 印出變數部分
            if (i > 1) {
                cout << "x^" << i;
            } else if (i == 1) {
                cout << "x";
            }
        }
        cout << '\n';
    }
    return 0;
}