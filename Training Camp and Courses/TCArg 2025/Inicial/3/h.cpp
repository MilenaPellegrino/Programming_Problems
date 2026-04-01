#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 
const ll MAXN = 30; // number of letters
vi G[MAXN];
void add_edge(char u, char v){
    ll numu = u - 'a' + 1;
    ll numv = v - 'a' + 1;
    G[numu].pb(numv);
}

ll color[MAXN];

bool hasCycle(ll u){
    color[u] = 1; //gray : (proccess)
    for (ll v : G[u]){
        if(color[v] == 0){
            if(hasCycle(v)){
                return true;
            }
        } else if (color[v] == 1){
            return true;
        }
    }
    color[u] = 2; // black: visited
    return false;
}

bool hasCycleAll(){
    memset(color, 0, sizeof(color));
    fore(i, 0, MAXN){
        if(color[i] == 0){
            if(hasCycle(i)){
                return true;
            }
        }
    }
    return false;
}

vi orden;
bool vis[MAXN];
void dfs(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    orden.push_back(u);
}
int main(){
    FIN;
    ll n; cin>>n; 
    vector<string> vs(n); 
    fore(i, 0, n){
        string s; cin>>s;
        vs[i] = s;
    }

    // Create the graph 
    fore(i, 0, n-1){
        ll j = 0, k = 0;
        string s1 = vs[i];
        string s2 = vs[i+1];
        bool flag = true; // Impossible due to length
        ll len1 = sz(s1); 
        ll len2 = sz(s2);
        while(j<sz(s1) && k<sz(s2)){
            if(s1[j] != s2[k]){
                add_edge(s1[j], s2[k]);
                flag = false; // If they are diff, I   don't care about the length 
                break;
            }
            j++, k++;
        }
        // Special case lenth: 
        // abbb
        // ab
        if(flag){
            if(len1 > len2){
                cout<<"Impossible\n";
                return 0;
            }
        }
    }

    if(hasCycleAll()){
        cout<<"Impossible\n";
        return 0;
    }

    memset(vis, false, sizeof(vis));
    for (int i = 26; i >= 1; i--) { 
        if (!vis[i]) {
            dfs(i);
        }
    }

    reverse(all(orden));

    for (int x : orden) {
        cout << (char)(x + 'a' - 1);
    }
    cout<<"\n";
    
    return 0;
}
