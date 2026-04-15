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

    ll r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;

    ll a,b;
    a=abs(x1-x2);
    b=abs(y1-y2);
    double h;
    h=sqrt(a*a + b*b);
    cout << (ll) ceil(h/(2*r)) << "\n";

    return 0;
}