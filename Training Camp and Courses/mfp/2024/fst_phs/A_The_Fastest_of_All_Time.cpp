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

bool can(ll mid, vi &a, ll ent){
    // la idea es entregar todos los que pueda con el numero minimo 
    ll total = 0;
    fore(i, 0, sz(a)){
        ll cant = mid / a[i];
        total += cant;
    }
    return total >= ent;

}

void solve(){
    ll n; cin>>n;
    ll p; cin>>p; 
    vi a(n); fore(i, 0, n)cin>>a[i];
    sort(all(a));
    ll mins = a[0];
    fore(i, 0, n){
        mins = min(mins, a[i]);
    }
    // binary search 
    ll low = 0, high = mins * p;
    ll ans = -1;

    while(low<= high){
        ll mid = (low + high) / 2; 
        if(can(mid, a, p)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout<<ans<<"\n";
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