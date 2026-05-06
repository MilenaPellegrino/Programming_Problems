#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a);i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((ll)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long; 
typedef vector<ll> vi;
 
int main(){
   FIN;

   ll n,m,a,b; cin>>n>>m;
   vi perm(n);
   fore(i,0,n){
      cin>>perm[i];
      perm[i]--;      
   }
   vector<vector<ll>> adj(n);
   fore(i,0,m){
      cin>>a>>b;
      a-=1;
      b-=1;
      adj[a].pb(b);
      adj[b].pb(a);
   }

   ll s=0; // source vertex

   queue<ll> q;
   vector<bool> used(n);
   vector<ll> d(n), p(n);

   q.push(s);
   used[s] = true;
   p[s] = -1;
   ll index_aux = 0;
   ll id_componente = 0;
   ll comp_conexa = 1;
   vector<vector<ll>> clase(comp_conexa);
   while (!q.empty()) {
      ll v = q.front();
      q.pop();
      clase[id_componente].pb(v);
      for (ll u : adj[v]) {
         if (!used[u]) {
               used[u] = true;
               q.push(u);
               d[u] = d[v] + 1;
               p[u] = v;
         }
      }

      if(q.empty()){
         fore(k,index_aux,n){
            if(!used[k]){
               index_aux=k;
               q.push(index_aux);
               used[index_aux]=true;
               p[index_aux] = -1;
               id_componente++;
               comp_conexa++;
               clase.resize(comp_conexa);
               break;
            }
         }
      }
   }

   fore(i,0,sz(clase)){
      sort(all(clase[i]));
   }

   vi ix_clase(sz(clase));
   vi cual_clase(n);
   fore(i,0,sz(clase)){
      ix_clase[i]=sz(clase[i])-1;
      fore(j,0,sz(clase[i])){
         cual_clase[clase[i][j]]=i;
      }
   }

   fore(k,0,n){
      ll clase_k = cual_clase[perm[k]];
      cout << clase[clase_k][ix_clase[clase_k]] + 1 << " ";
      ix_clase[clase_k]--;
   }
   cout << "\n";
   
   return 0;
}