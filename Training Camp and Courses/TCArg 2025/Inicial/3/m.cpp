#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all (x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 
int main(){FIN;

    ll a,b,m,r0; cin>>a>>b>>m>>r0;
    vi v1(100000,0);
    vi v2(100000,0);
    ll counter = 0;
    v2[r0]=1;
    ll last = r0;

    while(true){
        counter++;
        last = (a*last + b) % m;
        if(v2[last]==1){
            cout<< counter - v1[last] << "\n";
            return 0;
        } else {
            v2[last]=1;
            v1[last]=counter;
        }
    }



    return 0;
}
