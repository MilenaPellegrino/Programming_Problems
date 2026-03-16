#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define vi vector<ll>
#define fore(i, a, b) for (ll i= a; i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){FIN; 

    string s; cin >> s;
    bool b1 = false;
    bool b2 = false;

    for(auto a : s){
        if (a=='0'){
            if(!b1){
                b1 = true;
                cout << "3 4\n";
            } else {
                b1= false;
                cout << "1 4\n";
            }
        }
        else {
            if(!b2){
                b2 = true;
                cout << "1 1\n";
            } else {
                b2= false;
                cout << "1 3\n";
            }
        }
    }

    return 0;
}