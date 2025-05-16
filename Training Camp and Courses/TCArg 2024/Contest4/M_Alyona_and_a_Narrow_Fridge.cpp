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

const ll INF = 1e18+10;

ll n, h; 
vi a,v;
bool can(ll x){
    v.clear();
    fore(i, 0, x){
        v.pb(a[i]);
    }
    sort(all(v));
    ll sum=0;
    for(ll i=x-1;i>=0;i-=2){
        sum+=v[i];
    }
    if(sum>h) return true;
    return false;
}

// t t t t t f f f f f 
//  /      /    /

// 5 10
// 3 1 4 2 4

void solve(){
	cin>>n>>h;
    fore(i, 0, n){
        ll ai; cin>>ai;
        a.pb(ai);
    }
    ll l = 0, r = n+1;
    while(l + 1< r){
        ll mid = (l+r)/2;
        if(can(mid)){
            r = mid;
        } else {
            l = mid;
        }
    }
    pri(l);
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
