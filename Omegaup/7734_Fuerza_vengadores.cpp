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
    ll n; cin>>n; 
    vi a(n); 
    fore(i, 0, n)cin>>a[i];
    vi b(n);
    fore(i, 0, n)cin>>b[i];
    sort(all(a));
    sort(all(b));
    ll av = 0, th = 0;
    ll j =0, i=0;
    while(i<n && j<n){
        if(a[i] >b[j]){
            av++;
            j++;
        } else if(a[i] < b[j]){
            th++;
            i++;
        } else{
            i++;
            j++;
        }
    }
    db(av); db(th);
    av+= n-j;
    th += n-i;
    db(av); db(th);
    if(av>th){
       pri("Avengers");
       pri(av);
    } else {
        pri("Thanos");
        pri(th - av + 1);
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
