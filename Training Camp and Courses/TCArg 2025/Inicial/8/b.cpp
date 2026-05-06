#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 

int main(){
    FIN; 

    ll n,imax;cin>>n;
    vi v(n);
    cin>>v[0];
    imax=0;
    fore(i,1,n){
        cin>>v[i];
        imax = (v[imax]<v[i]) ? i : imax;
    }
    sort(all(v));
    cout << imax+1 << " "<<v[v.size()-2]<<"\n";

    return 0; 
}