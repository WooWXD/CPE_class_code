#include <bits/stdc++.h>

using namespace std;

bool is_leap(int x) {
    if (x % 400 == 0) return true;
    if (x % 100 == 0) return false;
    if (x % 4 == 0) return true;
    return false;
}

int get_days_in_month(int month, int year) {
    int day_in_mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap(year)) {
        return 29;
    }
    return day_in_mon[month];
}

int main(){

    map <pair <int, int> , string> date;
    date[{121, 219}] = "aquarius";
    date[{220, 320}] = "pisces";
    date[{321, 420}] = "aries";
    date[{421, 521}] = "taurus";
    date[{522, 621}] = "gemini";
    date[{622, 722}] = "cancer";
    date[{723, 821}] = "leo";
    date[{822, 923}] = "virgo";
    date[{924, 1023}] = "libra";
    date[{1024, 1122}] = "scorpio";
    date[{1123, 1222}] = "sagittarius";
    date[{1223, 1231}] = "capricorn";
    date[{101, 120}] = "capricorn";
    // int day_in_mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n, rd = 1;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int month, day, year;
        month = (s[0] - '0') * 10 + (s[1] - '0');
        day = (s[2] - '0') * 10 + (s[3] - '0');
        year = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
        for (int i = 0; i < 280; i++){
            day++;
            if (day > get_days_in_month(month, year)){
                day = 1;
                month++;
                if (month > 12){
                    year++;
                    month = 1;
                }
            }
        }
        int star = month * 100 + day;
        string ans;
        for (auto i : date){
            int l = i.first.first;
            int r = i.first.second;
            if (l <= star && star <= r){
                ans = i.second;
                break;
            }
        }
        cout << rd++ << ' ';
        if (month < 10) cout << "0";
        cout << month << "/";
        if (day < 10) cout << "0";
        cout << day << "/";
        cout << year << ' ';
        cout << ans << endl;
    }
}