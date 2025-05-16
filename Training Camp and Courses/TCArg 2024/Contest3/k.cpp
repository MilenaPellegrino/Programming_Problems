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
const ll MAXN = 2e5 + 10;
//vector<ll> a[2*MAXN];
void solve(){
	ll n; cin>>n; 
    ll ans = 0;
    vvi a(2*n + 1);
    fore(i, 0, 2*n){
        ll ai; cin>>ai;
        a[ai].pb(i);
    }
    ans+= a[1][0] + a[1][1];
    fore(i, 2, n+1){
        ans += abs(a[i][0] - a[i-1][0]) + abs(a[i][1] - a[i-1][1]);
    }
    pri(ans);
    // sort(all(a));
    //    fore(i, 0, 2*n){
    //    cout<<a[i].fst<<" "<<a[i].snd<<endl;
    // }
    // cout<<endl<<endl;
    // ll dis = 0;
    // ll s = a[0].snd;
    // ll d = a[1].snd;
    // cout<<"ENtro dal forr"<<endl;
    // fore(i, 2, 2*n-1){ 
    //     db(d);
    //     db(dis);
    //     ll dis1 = abs(s - a[i].snd);
    //     ll dis2 = abs(s-a[i+1].snd);
    //     db(dis1); 
    //     db(dis2);
    //     if(dis1>=dis2){
    //         dis+= dis2;
    //         s = dis2;
    //         d = abs(d - a[i].snd);
    //         db(abs(d - a[i].snd));
    //         dis+= abs(d-a[i].snd);
    //     } else {
    //         s = dis1;
    //         d = abs(d-a[i+1].snd);
    //         db(abs(d - a[i+1].snd));
    //         dis+=abs(d-a[i+1].snd);
    //     }
    // }
    //pri(dis);
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
