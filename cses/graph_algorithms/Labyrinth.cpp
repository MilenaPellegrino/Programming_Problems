#include<bits/stdc++.h> 
using namespace std; 
#define fore(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define snd second 
#define sz(x) ((int)x.size())
#define db(x) cout<<#x<<" = "<<(x)<<"\n";
 
#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
using ll = long long; 
typedef vector<ll> vi; 
 
void deshacer(char m, ll& row, ll& col){
	if (m == 'U') row += 1; 
    if (m == 'D') row -= 1;
    if (m == 'L') col += 1; 
    if (m == 'R') col -= 1;
}

int main(){
    FIN; 
    ll n, m; cin>>n>>m; 
    vector<string> g(n);
	fore(i,0,n)cin>>g[i];
	ll afil = -1, acol = -1;
	ll bfil = -1, bcol = -1;
	fore(i,0, n){
		fore(j,0,m){
			if(g[i][j] == 'A'){
				afil = i;
				acol = j;
			}
			if(g[i][j] == 'B'){
				bfil = i; 
				bcol = j;
			}
		}
	}
	// cout<<afil<<" "<<acol<<endl; 
	// cout<<bfil<<" "<<bcol<<endl;
	vector<vi> dist(n, vi(m, -1));
	vector<vector<char>> donde(n, vector<char> (m, ' '));
	ll dr[] = {-1, 1, 0, 0};
	ll dc[] = {0, 0, -1, 1};
	char letra[] = {'U', 'D', 'L', 'R'};

	queue<pair<ll, ll>> q; 
	q.push({afil, acol});
	dist[afil][acol] = 0;

	while(!q.empty()){
		auto [fila, col] = q.front();
		q.pop();

		fore(k,0, 4){
			ll nuevaFila = fila + dr[k];
			ll nuevaCol = col + dc[k];
			
			if(nuevaFila < 0 || nuevaFila >= n || nuevaCol <0 || nuevaCol >= m) continue;
			if(g[nuevaFila][nuevaCol] == '#')continue;
			if (dist[nuevaFila][nuevaCol] != -1)continue;

			dist[nuevaFila][nuevaCol] = dist[fila][col] + 1;
			donde[nuevaFila][nuevaCol] = letra[k];
			q.push({nuevaFila, nuevaCol});
		}
	}

	if (dist[bfil][bcol] == -1){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		cout<<dist[bfil][bcol]<<"\n";

		string camino = "";
		ll filaActual = bfil; 
		ll colActual = bcol;
		while(filaActual!= afil || colActual != acol){
			char m = donde[filaActual][colActual];
			camino += m;
			deshacer(m, filaActual, colActual);
		}  
		reverse(all(camino));
		cout<<camino<<"\n";
	}
    return 0;
}