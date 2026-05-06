#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (X).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 

int main(){
    FIN; 
    ll n,aa,b;cin>>n>>aa>>b;
    ll a[n];
    ll m=min(aa,b);
    ll ans=0;
    fore(i,0,n){
        cin>>a[i];
    }
    if(n==1){
        if(a[0]==2){
            cout<<m<<"\n";return 0;
        } else{
            cout<<ans<<"\n";return 0;
        }
    }
    fore(i,0,(n/2)){
        if(a[i]==a[n-1-i]){
            if(a[i]==2){
                ans+=m*2;
            }else{continue;}
        }else{
            if(a[i]==2 || a[n-1-i]==2){
                if(a[i]==1 || a[n-1-i]==1){
                    ans+=b;
                }else{
                    ans+=aa;
                }
            }else{
                cout<<-1<<"\n";return 0;
            }
        }
    }
    if(n%2==1){
        if(a[(n/2)]==2){ans+=m;}
    }
    cout<<ans<<"\n";
    return 0; 
}