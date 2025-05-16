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

void solve(){
    vi a(3); fore(i, 0, 3)cin>>a[i];
    vi b(3); fore(i, 0, 3)cin>>b[i];
	//ll a, b, c; cin>>a>>b>>c;
    //ll x, y, z; cin>>x>>y>>z;
    ll cant = 0;

    fore(i, 0, 3){
        if(a[i] - 2 >= b[i]){
            ll res = a[i] - b[i];
            cant += res/2;
        } else if (a[i] < b[i]){
            ll res2 = b[i] - a[i];
            //if(res2 % 2 !=0) res2 += 1; 
            cant -= res2;
        }
    }

    if(cant >=0 ){
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }
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
