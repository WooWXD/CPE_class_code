// 272 TEX Quotes
#include <iostream>

using namespace std;

int main(){
    string s;
    bool a = true;
    while (getline(cin, s)){
        
        for (auto i : s){
            if (i == '"'){
                if (a) cout << "``";
                else cout << "''";
                a = !a;
            }
            else cout << i;
        }
        cout << '\n';
    }
}