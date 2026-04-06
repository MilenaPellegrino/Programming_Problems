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
string s; 
// dp[i][j] = true si el substring [i][j] es palindromo. 
vector<vector<ll>> dp; 
bool f (ll i, ll j, string &s){
    if(i>=j) return true;
    if(dp[i][j] != -1)return dp[i][j]; 
    if(s[i] == s[j])return dp[i][j] = f(i+1, j-1, s);
    return dp[i][j] = false; 
}

vector<vector<ll>> memo; 
ll best(ll i, ll j){
    if(i>j)return 0;
    if(i==j) return 1; 
    if(memo[i][j] != -1)return memo[i][j];
    ll res = max(best(i+1, j), best(i, j-1));
    if(f(i, j, s)){
        res = max(res, j-i+1); 
    }
    return memo[i][j] = res; 
}

void solve(){
    ll n; cin>>n;
    cin>>s;
    ll q; cin>>q;
    // mset(dp, -1);
    // mset(memo, -1);
    dp.assign(n, vector<ll>(n, -1));
    memo.assign(n, vector<ll>(n, -1));
    while(q--){
        ll l, r; cin>>l>>r; 
        l--; r--;
        cout<<best(l, r)<<"\n";
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