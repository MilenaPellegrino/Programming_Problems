#include<bits/stdc++.h> 

using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long; 

typedef vector<ll> vi; 

const ll N = 2e5 + 10;
vi BIT(N);

void update ( int idx , int val ) {
    for (; idx <= n ; idx += idx & - idx )
        bit [ idx ] += val ;
}

int query ( int pos ) {
    int res = 0;
    for (; pos > 0; pos -= pos & - pos )
        res += bit [ pos ];
    return res ;
}

int main(){
    FIN;

    ll n; cin>>n; 
    vi a(n);
    fore(i, 0, n)cin>>a[i];

    fore(i, 0, n){
        a[i] = min(a[i], n);
    }
    

    return 0;
}