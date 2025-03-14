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

const ll NUM_MIN = -1e9 + 10;
const ll NUM_MAX = 1e9 + 10;

ll max_subarray_sum(vi &arr){
    ll max_sum = NUM_MIN;
    ll max_actual = 0;
    for(ll num : arr){
        max_actual += num;
        max_sum = max(max_sum, max_actual);
        if(max_actual < 0){
            max_actual = 0;
        }
    }
    return max_sum;
}

ll min_subarray_sum(vi &arr){
    ll min_sum = NUM_MAX;
    ll min_actual = 0;
    for(ll num : arr){
        min_actual += num;
        min_sum = min(min_sum, min_actual);
        if(min_actual > 0){
            min_actual = 0;
        }
    }
    return min_sum;
}

void solve(){
    ll n; cin>>n;
    vi a(n); 
    fore(i, 0, n)cin>>a[i];
    set<ll> res;
    ll x;
    res.insert(0);
    //vi res; 
    vi sin_x; 
    fore(i, 0, n){
        if(a[i] != 1  && a[i] != -1){
            x = a[i];
        }else{
            sin_x.pb(a[i]);
        }
    }
    ll min_sx = min_subarray_sum(sin_x);
    ll max_sx = max_subarray_sum(sin_x);

    //db(min_sx);
    //db(max_sx);

    fore(i, min_sx, max_sx + 1){
        res.insert(i);
    }

    ll min_cx = min_subarray_sum(a);
    ll max_cx = max_subarray_sum(a);

    //db(min_cx);
    //db(max_cx);

    if (min_cx < x){
        min_cx = min(x, min_cx+x);
    }
    fore(i, min_cx, max_cx + 1){
        res.insert(i);
    }

    vi res_v (all(res));
    sort(all(res_v));

    cout<<sz(res_v)<<"\n";
    fore(i, 0, sz(res_v)){
        cout<<res_v[i]<<" ";
    }
    cout<<"\n";
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