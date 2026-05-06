#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 

string NO = "NO";
string YES = "YES";


int main(){
    FIN;
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n; 
        vi a(n); 
        fore(i, 0,n)cin>>a[i]; 
        ll m; cin>>m; 
        vector<string> res;
        fore(i, 0, m){
            string s; cin>>s;
            if(sz(s)!=n){
                res.pb(NO);
                continue;
            }
            vector<bool> vis(30, false);
            map<char, ll> mp;
            set<ll> st;
            bool flag = true;
            fore(j, 0, n){
                char c = s[j];
                ll pos = c- 'a';
                ll num = a[j];
                if(vis[pos]){
                    if(mp[s[j]] != num){
                        res.pb(NO);
                        flag = false;
                        break;
                    }
                }else{
                    vis[pos] = true;
                    if(st.count(num)){res.pb(NO);flag = false;break;}
                    mp[s[j]] = num;
                    st.insert(num);
                }
            }
            if(flag){
                res.pb(YES);
            }
        }
        fore(i, 0, sz(res)){
            cout<<res[i]<<"\n";
        }
    }
    return 0;
}