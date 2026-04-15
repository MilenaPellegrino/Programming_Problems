#include<bits/stdc++.h> 

using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst fitst
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long; 

typedef vector<ll> vi; 

int main(){
    FIN;
    ll n; cin>>n; 
    vi a(n); 
    fore(i,0,n)cin>>a[i];
    sort(all(a));
    ll res = 0; 
    ll j = 0;
    fore(i, 0, (n/2)){
        ll suma = abs(a[j] - a[j+1]); 
        res += suma;
        j+=2;
    }
    cout<<res<<"\n";
    return 0;
}