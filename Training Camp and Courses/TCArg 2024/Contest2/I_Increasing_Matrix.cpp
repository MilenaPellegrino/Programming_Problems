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
const ll MAXN = 500;
ll ma[MAXN][MAXN];
void solve(){
    ll n,m; cin>>n>>m;
    ll ma[n+1][m+1];
    fore(i, 0, n){
        fore(j, 0, m){
            cin>>ma[i][j];
        }
    }
    for(ll i=n-1;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(ma[i][j]==0)
                ma[i][j]=min(ma[i][j+1]-1,ma[i+1][j]-1);
        }
    }
    ll sum =0;
    fore(i, 0, n){
        fore(j, 0, m){
            if(i<n-1){
                if(ma[i+1][j]<=ma[i][j]){
                    pri(-1);
                    return;
                }
            }
            if(j<m-1){
                if(ma[i][j+1]<=ma[i][j]){
                    pri(-1);
                    return;
                }
            }
            sum+=ma[i][j];
        }
    }
    pri(sum);
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
