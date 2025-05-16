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
    ll n, x; cin>>n>>x ;
    vii a(n);
    fore(i, 0, n){
        ll ai; cin>>ai;
        a[i].fst = ai;
        a[i].snd = i+1;
    }
    if(n<3){
        cout<<-1;
        return;
    }
    sort(all(a));
    ll sumact = a[0].fst + a[1].fst + a[2].fst;
    vi res(3);
    res[0] = a[0].snd;
    res[1] = a[1].snd;
    res[2] = a[2].snd;
    bool flag = true;
    ll l = 0, r = 2;
    ll i =0;
    while(r<n && l <r && i <n){
        if(sumact == x)break;
        if(sumact<x){
            sumact -=a[l].fst;
            l++;
            sumact += a[l].fst;
            res[l] = a[l].snd;
            r++;
            sumact += a[r].fst;
        }
        if(sumact>x){
            flag= false;
            break;
        }
        i++;
    }
    sort(all(res));
    if(flag){
        cout<<res[0]<<" "<<res[1]<<" "<<res[2];
    } else {
        cout<<-1;
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
