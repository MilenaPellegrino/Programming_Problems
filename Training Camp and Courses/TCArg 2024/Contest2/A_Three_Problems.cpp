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
 
const ll MAXN = 3010;
vii a(MAXN);
vi res(3);
void solve(){
	ll n; cin>>n;
    ii a[MAXN];
    fore(i, 0, n){
        ll ai; cin>>ai;
        pair<ll, ll> par = mp(ai, i);
        a[i] = par;
    }
    sort(a,a+n);
    ll count = 0;
    res[0] = a[0].snd + 1;
    ll pivot = a[0].fst;
    ll j = 1;
   fore(i, 0, n){
        if(pivot < a[i+1].fst){
            count++;
            res[j] = a[i+1].snd + 1;
            //res.pb((a[i+1].snd) + 1);
            j++;
            pivot = a[i+1].fst;
        } 
        if(count == 2){
            break;
        }
   }
   vi res2 = {-1, -1, -1};
   if(count>=2){
        cout<<res[0]<<" " << res[1]<<" "<<res[2]<<"\n";
   } else {
         cout<<res2[0]<<" " << res2[1]<<" "<<res2[2]<<"\n";
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