// 11356 Dates
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string month[13] = {"", "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
int month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map <string, int> m;

bool is_leap(int x){
    if (x % 100 == 0 && x % 400 != 0) return false;
    else if (x % 100 == 0) return true;
    if (x % 4 == 0) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    for (int i = 1; i < 13; i++){
        m[month[i]] = i;
    }
    for (int rd = 1; rd <= t; rd++){
        string date;
        cin >> date;
        vector <string> s;

        string now = "";
        int year = 0;
        int index = 0;
        for (; index < 4;){
            year *= 10;
            year += (date[index] - '0');
            index++;
            
        }
        index++;
        while (date[index] != '-'){
            now += date[index];
            index++;
        }
        index++;
        int day = (date[index] - '0') * 10 + (date[index+1] - '0');
        // cout << year << ' ' << now << ' ' << day << '\n';
        
        int k;
        cin >> k;
        int now_mon = m[now];
        for (int i = 0; i < k; i++){
            day++;
            if (day > month_day[now_mon]){
                if (is_leap(year) && now_mon == 2){
                    if (i == k-1) break;
                    i++;
                    day++;
                }
                now_mon++;
                day = 1;
            }
            if (now_mon > 12){
                year++;
                now_mon = 1;
            }
        }
        cout << "Case " << rd << ": " << year << "-" << month[now_mon] << "-";
        if (day < 10) cout << "0" << day;
        else cout << day;
        cout << endl;
    }
}