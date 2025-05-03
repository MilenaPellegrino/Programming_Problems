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

// n = 3 
// 1, 2, 3
// ========
// 1, 2, 3 -> 0, 0, 0 = 0
// 1, 3, 2 -> 0, 1, 1 = 2
// 2, 1, 3 -> 1, 1, 0 = 2
// 2, 3, 1 -> 1, 1, 2 = 4 
// 3, 1, 2 -> 2, 1, 1 = 4
// 3, 2, 1 -> 2, 0, 2 = 4
// total = 2 (2, and 4) 

// n = 4
//      1, 2, 3, 4
// ==============
// 1.  [1, 2, 3, 4] -> 0, 0, 0, 0 = 0
// 2.  [1, 2, 4, 3] -> 0, 0, 1, 1 = 2
// 3.  [1, 3, 2, 4] -> 0, 1, 1, 0 = 2 
// 4.  [1, 3, 4, 2] -> 0, 1, 1, 2 = 4
// 5.  [1, 4, 2, 3] -> 0, 2, 1, 1 = 4
// 6.  [1, 4, 3, 2] -> 0, 2, 0, 2 = 4
// 7.  [2, 1, 3, 4] -> 1, 1, 0, 0 = 2
// 8.  [2, 1, 4, 3] -> 1, 1, 1, 1 = 4
// 9.  [2, 3, 1, 4] -> 1, 1, 2, 0 = 4
// 10. [2, 3, 4, 1] -> 1, 1, 1, 3 = 6
// 11. [2, 4, 1, 3] -> 1, 2, 2, 1 = 6
// 12. [2, 4, 3, 1] -> 1, 2, 0, 3 = 6
// 13. [3, 1, 2, 4] -> 2, 1, 1, 0 = 4
// 14. [3, 1, 4, 2] -> 2, 1, 1, 2 = 6
// 15. [3, 2, 1, 4] -> 2, 0, 2, 0 = 4
// 16. [3, 2, 4, 1] -> 2, 0, 1, 3 = 6
// 17. [3, 4, 1, 2] -> 2, 2, 2, 2 = 8
// 18. [3, 4, 2, 1] -> 2, 2, 1, 3 = 8
// 19. [4, 1, 2, 3] -> 3, 1, 1, 1 = 6
// 20. [4, 1, 3, 2] -> 3, 1, 0, 2 = 6
// 21. [4, 2, 1, 3] -> 3, 0, 2, 1 = 6
// 22. [4, 2, 3, 1] -> 3, 0, 0, 3 = 6
// 23. [4, 3, 1, 2] -> 3, 1, 2, 2 = 8
// 24. [4, 3, 2, 1] -> 3, 1, 1, 3 = 8



void solve(){
    ll n; cin>>n;
    vi a(n); 
    vi b(n); 
    fore(i, 1, n+1){
        a[i-1] = i;
    }
    b = a;
    reverse(all(b));
    ll maxsum = 0;
    fore(i, 0, n){
        ll dif = abs(a[i] - b[i]);
        maxsum += dif;
    }
    ll res = maxsum / 2;
    pri(res + 1);
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