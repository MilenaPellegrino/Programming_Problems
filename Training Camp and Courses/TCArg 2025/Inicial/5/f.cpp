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

    ll n,m,a,b; cin>>n>>m;
    vi vm(m,0);

    fore(i,0,n){
        cin>>a;
        fore(j,0,a){
            cin>>b;
            vm[b-1]=1;
        }
    }

    fore(i,0,m){
        if(vm[i]==0){
            cout<<"NO\n";
            return 0;
        }
    }

    cout<<"YES\n";

    return 0;
}