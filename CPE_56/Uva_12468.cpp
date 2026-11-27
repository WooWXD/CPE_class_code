#include <iostream>

using namespace std;

int main(){
    int Ca, Cb;
    while (cin >> Ca >> Cb){
        if (Ca == -1 && Cb == -1)
            break;
        
        if (Ca > Cb)
            swap(Ca, Cb);
        int pos = Cb - Ca;
        int neg = Ca - Cb + 100;

        cout << min(pos, neg) << '\n';
    }
}