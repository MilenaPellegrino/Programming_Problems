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

/*
n = 10000
=> 2^10000
*/
const ll MAXN = 1e5 + 10;
vi primes;

bool esPrimo(ll x){
    if(x<2)return false;
    if(x==2)return true;
    for(ll i = 3; i*i <= x; i+=2){
        if(x%i == 0)return false;
    }
    return true;
}

void solve(){
    ll n; cin>>n;
    ll res = 1;
    // cout<<primes[sz(primes) - 1]<<endl;
    // cout<<primes[sz(primes) - 2]<<endl;
    //cout<<sz(primes)<<endl;
    vi a;
    set<ll> aa;
    cout<<primes[0]<<" ";
    a.pb(primes[0]);
    fore(i, 1, n){
        ll num1 = primes[i-1] * primes[i];
        a.pb(num1);
        if(aa.count(num1)){
            cout<<"fallo"<<endl;
            return;
        }else{
            aa.insert(num1); 
        }

        cout<<primes[i-1] * primes[i]<<" ";
    }
    cout<<"\n";

    RAYA; RAYA;
    ll gcdant = gcd(a[0], a[1]);
    cout<<gcdant<<" ";
    fore(i, 1, sz(a)-1){
        
        ll gcdd = gcd(a[i], a[i+1]);
        cout<<gcdd<<" ";
        if(gcdant == gcdd){
            cout<<"GALLO"<<endl;
            return;
        }
        gcdant = gcdd;
    }
    cout<<endl;
}

/*
10009
10007 

100160063 (8)

*/

int main(){
    FIN; 
    ll j = 0;
    fore(i, 2, MAXN){
        if(esPrimo(i)){
         primes.pb(i);
        }
    }
    //int t = 1;
    int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0;
}
