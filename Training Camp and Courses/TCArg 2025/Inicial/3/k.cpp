#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all (x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 
int main(){FIN;

ll t; cin >>t;
while(t--){

    ll n, s; cin >> n>> s;

    if (s==0){
        cout << 0 << "\n";
        continue;
    }
    if (n==1){
        cout << s << "\n";
        continue;
    } else {
        cout << s/(n*n) << "\n";
        continue;
    }
}

    return 0;
}
