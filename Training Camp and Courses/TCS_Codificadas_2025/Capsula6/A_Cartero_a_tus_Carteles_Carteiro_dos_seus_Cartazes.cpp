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

// ll floorBinarySearch(const vi& arr, ll x) {
//     auto it = upper_bound(arr.begin(), arr.end(), x);
//     if (it == arr.begin()) return -1; // no hay ningún elemento <= x
//     --it;
//     return *it;
// } 

// ll floorBinarySearchIndex(const vi& arr, ll x) {
//     auto it = upper_bound(arr.begin(), arr.end(), x);
//     if (it == arr.begin()) return -1; // no hay ningún elemento <= x
//     --it; // retrocedemos al último <= x
//     return (it - arr.begin()) + 1; // posición empezando en 1
// }

void solve(){
    ll n; cin>>n;
    ll m; cin>>m; 
    vi a(n+1); fore(i, 0, n)cin>>a[i]; 
    vi b(m+1); fore(i, 0, m)cin>>b[i];
   
    vi pref(n); 
    pref[0] = a[0];
    fore(i, 1, n) pref[i] = pref[i-1] + a[i];

    fore(i, 0, m){
        //ll piso = floorBinarySearchIndex(pref, b[i] - 1);
        ll piso = lower_bound(all(pref), b[i]) - pref.begin(); // para saber la posicion en la que esta 
        ll dif = 0; 
        if(piso >0){
            dif = pref[piso - 1];
        }
        ll depto = b[i] - dif;
        cout<<piso + 1<<" "<<depto<<"\n";
    }
    // output: num de piso, num de depto 

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
