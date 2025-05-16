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
    string s; cin>>s;
    ll cont = 0;
    fore(i, 0, sz(s)){
        if(s[i] == 'R'){
            cont++;
        }
    }
   // db(cont);
    // vi dis(cont+2);
    // dis[0] = 0;
    // ll j = 0;
    // fore(i, 0, sz(s)){
    //     if(s[i] == 'R'){
    //         dis[j] = i+1;
    //         j++;
    //     }
    // }
    // dis.pb(sz(s)+1);  // ult dis;
    // ll maxdif = 0;
    // sort(all(dis));
    // fore(i, 0, sz(dis)){
    //       cout<<dis[i]<<" ";
    //   }
    vi dis; 
    dis.pb(0);
    fore(i, 0, sz(s)){
        if(s[i] == 'R'){
            dis.pb(i+1);
        }
    }
    dis.pb(sz(s) + 1);
    ll maxdif = 0;
    // fore(i, 0, sz(dis)){
    //     cout<<dis[i]<<" ";
    // }
    fore(i, 0, sz(dis)-1){
        ll ai = dis[i];
        ll bi = dis[i+1];
        maxdif = max(maxdif, abs(ai - bi));
    }
    pri(maxdif);
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
