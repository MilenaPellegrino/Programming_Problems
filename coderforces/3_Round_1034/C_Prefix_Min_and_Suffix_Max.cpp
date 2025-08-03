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
    ll n; cin>>n;
    ll mins = 1e9;
    ll maxs = -1;
    ll posmin = -1;
    ll posmax = -1;
    vi a(n);
    fore(i, 0, n)cin>>a[i];
    vi b(n);  // mins
    vi c(n);  // maxs
    fore(i, 0, n){
        mins = min(a[i], mins);
        b[i] = mins;
    }
    for(ll i = n-1; i>=0; i--){
        maxs = max(a[i], maxs);
        c[i] = maxs;
    }
    vi res(n, 0);
    fore(i, 0, n){
        if(a[i] <= b[i] || a[i]>= c[i]){
            res[i] = 1;
        }
    }


    // fore(i, 0, n){
    //     if(a[i]<= mins){
    //         mins = a[i];
    //         posmin = i;
    //     }
    //     if(a[i]>= maxs){
    //         maxs = a[i];
    //         posmax= i;
    //     }
    // }
    
    // // fore(i, 0, n){
    // //     if (a[i] == mins || a[i] == maxs)res[i] = 1;
    // // }
    // //db(posmin); db(posmax);
    // ll l = min(posmin, posmax);
    // ll r = max(posmin, posmax);
    //db(l); db(r);
    // fore(i, 0, l+1){
    //     res[i] = 1;
    // }
    // fore(i, r, n)res[i]=1;

    fore(i, 0, n)cout<<res[i];
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
