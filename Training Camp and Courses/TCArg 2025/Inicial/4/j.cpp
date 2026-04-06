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


int main(){
    FIN; 
    ll n,l,r;cin>>n;
    vector<pair<ll,ll>> vp(n+1); vi start;
    ll s=0;
    fore(i,1,n+1){
        cin>>l>>r;
        if (l==0) {s++;start.pb(i);}
        vp[i].fst=l;
        vp[i].snd=r;
    }
    vector<ll> f;
    if(s==1){
        fore(i,1,n+1){
            cout<<vp[i].fst<<" "<<vp[i].snd<<"\n";
        }
        return 0;
    }
    fore(i,0,s){
        f.pb(start[i]);
        ll act=start[i];
        while(true){
            act=vp[act].snd;
            if(act==0){
                break;
            }
            f.pb(act);
        }
    }
    fore(i,0,sz(f)){
        if(i==0 && sz(f)-1){
            vp[f[i]].snd=f[i+1];continue;
        }
        if(i>0 && i<sz(f)-1){
            vp[f[i]].snd=f[i+1];
            vp[f[i]].fst=f[i-1];
        }
        if(i==sz(f)-1){vp[f[i]].fst=f[i-1];}
        //cout<<f[i]<<"\n";
    }
    fore(i,1,n+1){
        cout<<vp[i].fst<<" "<<vp[i].snd<<"\n";
    }
    return 0; 
}
