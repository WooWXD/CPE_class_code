#include <iostream>
#include <map>

using namespace std;

int main(){
    string s;
    map <char, char> m;
    int count = 0;
    char k = '2';
    for (char c = 'A'; c <= 'O'; c++){
        m[c] = k;
        count++;
        if (count == 3){
            k++;
            count = 0;
        }
    }
    for (char c = 'P'; c <= 'S'; c++) m[c] = '7';
    for (char c = 'T'; c <= 'V'; c++) m[c] = '8';
    for (char c = 'W'; c <= 'Z'; c++) m[c] = '9';
    while (cin >> s){
        string ans = "";
        for (auto& i : s){
            if (i == ' ') break;
            else if (i == '-') ans += '-';
            else if (i == '1') ans += '1';
            else if (i == '0') ans += '0';
            else ans += m[i];
        }
        cout << ans << endl;
    }
}