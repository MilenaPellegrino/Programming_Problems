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
    if(n%2!=0 || n<=2){
        cout<<"0\n";
        return 0;
    }

    ll k;
    if(n%4!=0){
        k = n/4;
    } else {
        k = n/4 -1;
    }
    cout<<k<<"\n";

    return 0;
}