#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 


bool esPrimo ( ll n ) {
    if ( n <= 1) return false ;
    if ( n == 2) return true ;
    if ( n % 2 == 0) return false ;
    for ( ll i = 3; i * i <= n ; i += 2)
    if ( n % i == 0)
        return false ;
    return true ;
}

ll primerDiv ( ll n ) {
    if ( n == 2) return 0 ;
    if ( n % 2 == 0) return 2 ;
    for ( ll i = 3; i * i <= n ; i += 2){
    if ( n % i == 0)
        return i ;
    }
    return 0;
}

int main(){
    FIN; 

    ll a, b; cin >> a >> b;

    if(a==b){
        if(esPrimo(a)){
            cout << a << "\n";
        } else {
            cout << primerDiv(a) << "\n";
        }
    } else {
        cout << 2 << "\n";
    }

    return 0; 
}