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
        ll co=0;
        fore(i, 0, sz(s)){
            if(s[i]!= c){
                co++;
            }
        }
        if(co>=2 && s[n-1]!=c && s[n-2]==c){
            cout<<1<<"\n"<<n-1<<"\n";
        }else if (co>=2 && s[n-1]!=c && ){
            cout<<2<<"\n"<<n<<" "<<n-1<<"\n";
        }else if (co>=2){
            cout<<1<<"\n"<<n<<"\n";
        }else if(co==1 && s[n-1]!=c){
            cout<<1<<"\n"<<n-1<<"\n";
        }else if(co==1){
            cout<<1<<"\n"<<n<<"\n";
        }
        else {
            cout<<0<<"\n";
        }

    }

    return 0;
}