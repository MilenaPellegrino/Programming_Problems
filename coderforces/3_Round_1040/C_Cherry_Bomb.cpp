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

bool sepuede(vi a, vi b, ll k){
    ll sumq = 0; 
    fore(i, 0, sz(a)){
        if(b[i]!= -1){
            sumq = a[i] + b[i];
            break;
        }
    }
    fore(i, 0, sz(a)){
        ll num = 0;
        if(b[i] != -1){
            if(a[i] + b[i] != sumq)return false;
        }else{
            num = sumq - a[i];
            if(num>k || num<0)return false;
        }
    }
    return true;
}

void solve(){
    ll n; cin>>n;
    ll k; cin>>k; 
    vi a(n); 
    fore(i, 0, n)cin>>a[i];
    vi b(n); 
    fore(i, 0, n)cin>>b[i];
    ll cantdif = 0;
    fore(i, 0, n){
        if(b[i]!= -1)cantdif++;
    }
    if(cantdif != 0){
        if(sepuede(a, b, k)){
            pri(1);
        }else{
            pri(0);
        }
    }else{
    //    ll res = k-n + 1;
    //    pri(res+1); 
    ll mini = 0, maxi = 1e18;
    fore(i, 0, n){
        mini = max(mini, a[i]);
        maxi = min(maxi, a[i] + k);
    }
    ll res = max(0LL, maxi - mini + 1);
    pri(res);
    }
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
