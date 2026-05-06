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

vi divi(ll k){
    vi divs;
    for ( ll i = 1; i * i <= k ; i ++) {
        if ( k % i == 0) {
            divs . push_back ( i );
            if ( i != k / i ) divs . push_back ( k / i );
        }
    }
    return divs;
}


int main(){
    FIN;
    ll t;cin>>t; 
    while(t--){
        ll n; cin>>n; 
        char c; cin>>c; 
        string s; cin>>s; 
        ll res = 0;
        if(n==1){
            if(s[0] == c){
                cout<<0<<"\n";
                continue;
            }
        }
        ll co=0; set<ll> se;
        fore(i, 0, sz(s)){
            if(s[i]!= c){
                co++;
                vi d = divi(i+1);
                fore(j,0,sz(d)){
                    se.insert(d[j]);
                }
            }
        }
        if(co==0){cout<<0<<"\n";}
        bool f=true;
        for(ll i=n-1; i>=0;i--){
            if(s[i]==c && se.count(i+1)==0){
                cout<<"1\n"<<i+1<<"\n"; f=false;break;
            }
        }
        if(f){cout<<2<<"\n"<<n<<" "<<n-1<<"\n";}
    }

    return 0;
}