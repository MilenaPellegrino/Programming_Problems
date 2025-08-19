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

void solve(){
    ll x,y,z,k; cin>>x>>y>>z>>k;
    vi divs;
    for(ll i = 1; i * i <= k; ++i) {
        if(k % i == 0) {
            divs.pb(i);
            if(i != k / i) divs.push_back(k / i);
        }
    }
    // o(raiz k )
    ll res = 0;
    // Probamos todas las combinaciones (a, b, c)
    for(auto a : divs) {
        for(auto b : divs) {
            if(a * b > k) continue;
            if(k % (a * b) != 0) continue;
            
            ll c = k / (a * b);
            array<ll,3> dims = {a, b, c};
            sort(all(dims)); 

            do {
                ll dx = x - dims[0] + 1;
                ll dy = y - dims[1] + 1;
                ll dz = z - dims[2] + 1;
                if (dx > 0 && dy > 0 && dz > 0) {
                    res = max(res, dx * dy * dz);
                }
            } while(next_permutation(all(dims)));
        }
    }

    // if(sz(comb)<=0){
    //     pri(0);
    //     return;
    // }
    
    pri(res);
    //  pri(sz(comb));
    //  for(auto t : comb) {
    //      cout << get<0>(t) << " * " << get<1>(t) << " * " << get<2>(t) << " = " << k << endl;
    //  }
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
