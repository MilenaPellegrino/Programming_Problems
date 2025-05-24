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

//const ll NMIN = -(1e9 + 10);
void solve(){
    ll n; cin>>n; 
    ll k; cin>>k;
    vi a(n); fore(i, 0, n)cin>>a[i];

    // Caso especial subarray = array -> k == 1
    if(k==1){
        vector<bool> vec(n+2, false);
        fore(i, 0, n){
            vec[a[i]] = true;
        }
        fore(i, 0, n+2){
            if(vec[i] == false){
                cout<<i<<"\n";
                return;
            }
        }
    }

    // Caso especial k = n
    if(k == n){
        ll maxn = a[0];
        fore(i, 0, n){
            if (maxn < a[i]){
                maxn = a[i];
            }
        }
        if(maxn == 0){
            cout<<1<<"\n";
        } else {
            cout<<0<<"\n";
        }
        return;
    }
    cout<<"NO HECHO"<<endl;
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