#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
#define sz(x) ((int)x.size())
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pp pop_back
#define mp make_pair
#define fst first
#define snd second
#define str string
#define pri(x) cout << (x) << "\n"
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using ll = long long;
using pii = pair<int,int>;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<ll> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void solve(){
    ll n; cin>>n;
    vector<pair<ll, ll>> falt (n); 
    ll sobrceros = 0, sobrunos = 0;
    ll res = 0;
    fore(i, 0, n){
        ll ai, bi, ci, di; cin>>ai>>bi>>ci>>di;
        // ll ceros = bi - ai; 
        // ll unos = di - bi;
        // if (ceros>=0 ){
        //     falt[i].fst = ceros; 
        // } else {
        //     falt[i].fst = 0; 
        // } 
        // if (unos >= 0){
        //     falt[i].snd = unos;
        // }else {
        //     falt[i].snd = 0;
        // }
        // ll ceros = ai - ci; 
        // ll unos = bi - di;

        // if (ceros>= 0){
        //     sobrceros += ceros;
        // }

        // if(unos>= 0){
        //     sobrunos += unos;
        // }

        if(bi > di){
            res += ai + bi - di;
        } else if (ai > ci){
            res += ai - ci;
        }
    }

    // ll res = max(sobrceros, sobrunos); 
    pri(res);

}

int main(){
    FIN; 
    //int t = 1;
    int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0;
}
