#include<bits/stdc++.h> 
using namespace std;

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second
#define sz(x) ((int)x.size())

//#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using ll = long long; 
typedef vector<ll> vi;

int main(){FIN;

    ll t; cin >> t;
    while(t--){

        ll w, h, a, b; cin>>w>>h>>a>>b;
        ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;

        bool b1 = abs(x1-x2)%a==0;
        bool b2 = abs(y1-y2)%b==0;

        if (b1 || b2){
            if ((b1&&!b2) && x1==x2 ){
                cout<<"No\n";
                continue;
            } if ((!b1&&b2) && y1==y2 ){
                cout<<"No\n";
                continue;
            }
            cout<<"Yes\n";
        } else{
            cout<<"No\n";
        }

    }

    return 0;
}