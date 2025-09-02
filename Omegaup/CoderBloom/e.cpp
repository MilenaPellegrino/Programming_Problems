#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
#define RAYA cout<<"=============="<<"\n"
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
string YES = "YES\n"; 
string NO = "NO\n";

ll prodCruz (ll a0, ll a1, ll b0, ll b1){
    ll res = (a0 * b1) - (a1 * b0); 
    return res;
}

bool dentro (ll a0, ll a1, ll b0, ll b1, ll c0, ll c1){
    ll pos = prodCruz(a0, a1, b0, b1); 
    ll ladoI = prodCruz(a0, a1,c0, c1);
    ll ladoD = prodCruz(b0, b1, c0, c1);  
    bool flag = false;
    if (pos<=0){
        flag = ladoI < 0 && ladoD > 0;
    }else {
        flag = ladoI > 0 && ladoD < 0;
    }
    return flag;
}
void solve(){
    ll v0, v1; cin>>v0>>v1; 
    ll w0, w1; cin>>w0>>w1;
    ll n; cin>>n;
    ll res = 0;
    fore(i, 0, n){
        ll ai, bi; cin>>ai>>bi;
        if(dentro(v0, v1, w0, w1, ai, bi))res++;
    }
    pri(res);
}

int main(){
    FIN; 
    int t = 1;
    //int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0;
}