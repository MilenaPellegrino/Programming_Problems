#include<bits/stdc++.h> 
using namespace std;

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second
#define sz(x) ((int)x.size())

#define  FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi;

ll sum(ll idj, ll idi, vi a){
    ll ans = 0;
    fore(i, idi, idj + 1){
        ans+= a[i];
    }
    return ans;
}
int main(){
    FIN;
    ll n; cin>>n; 
    vi a(n);
    fore(i, 0, n)cin>>a[i];
    vi sums;
    sums.pb(0); 
    
    
    ll dif = a[0];
    bool minuso = false, one = false;
    fore(i, 0, n){
        if(a[i] == 1)one =true;
        if(a[i] == -1)minuso = true;
        if(a[i]!= -1 && a[i]!= 1){
            dif = a[i];
            break;
        }
    }
    if(minuso)sums.pb(-1);
    if(one)sums.pb(1);
    sums.pb(dif);
    fore(i, 0, n){
        fore(j, 1, n){
            ll sumss = sum(j, i, a);
            sums.pb(sumss);
        }
    }

    set<ll> adds;
    for(ll elem : sums){
        adds.insert(elem);
    }
    for(ll num : adds){
        cout<<num<<" ";
    }

    cout<<endl;
    return 0;
}