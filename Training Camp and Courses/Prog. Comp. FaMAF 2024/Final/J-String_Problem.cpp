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

const ll INF = 1e18;
const ll MAXN = 1e9;
const ll CH = 26;
string s,t;
ll n;

// Lista de adyacencia para representar el grafo. g[u] contiene pares (v, cost), donde v es un nodo adyacente a u y cost es el costo de la arista de u a v.
vector<pair<ll, ll>> g[CH];  
ll dist[CH][CH];  // dist[i][j] es el costo mínimo de cambiar el carácter 'a'+ i a 'a'+ j

/*
void dijkstra(int x){  // x->nodo origen
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});

	while(!q.empty()){
		x=q.top().snd; ll c=-q.top().fst; q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}
*/

// Modifico el alogritmo que tenia para el nuevo tipo de almacenamiento dist 
void dijkstra(int x) {
    fill(dist[x], dist[x] + CH, INF);  //void fill(ForwardIterator first, ForwardIterator last, const T& value); memset o fill? difs? 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;  // Modifico porque ahora es bidim
    dist[x][x] = 0;
    pq.push({0, x});

    while (!pq.empty()) {
        // Igual
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // trabajo con u | difs
        if (d > dist[x][u]) continue;

        for (auto &edge : g[u]) {  // ver porque me da error hace rel for hasta size
            int y = edge.first;
            ll c = edge.second;
            if (dist[x][u] + c < dist[x][y]) {  // es mas o menos lo mismo 
                dist[x][y] = dist[x][u] + c;
                pq.push({dist[x][y], y});  // No lo hago con el signo negativo porque uso el greater 
            }
        }
    }
}

void solve(){
    // Inicializamos los costos de las aristas 
    fore(i, 0, CH){
        fore(j, 0, CH){
            g[i].pb({j, INF});
        }
    }
    cin>>s>>t;
    cin>>n;
    fore(i, 0, n){
        char ai, bi; cin>>ai>>bi;
        ll wi; cin>>wi;
        
        // Agrego el costo de las aristas 
        g[ai-'a'].pb({bi-'a', wi});
    }
    
    // Ejecutamos dijkstra para cada caracter 
    fore(i, 0, CH){
        dijkstra(i);
    }
    // Si las string tienen tamano diferente no se puede
    if(sz(s)!= sz(t)){
        pri(-1);
        return;
    }
    ll res = 0;
    string sres = s;

    fore(i, 0, sz(s)) {
        if (s[i] != t[i]) {
            ll minc = INF;
            char bchar = s[i];

            // Encontrar el mejor carácter para hacer s[i] y t[i] iguales  y recordar la resp
            fore(j, 0, CH) {
                if (dist[s[i] - 'a'][j] < INF && dist[t[i] - 'a'][j] < INF) {
                    ll actc = dist[s[i] - 'a'][j] + dist[t[i] - 'a'][j];
                    if (actc < minc) {
                        minc = actc;
                        bchar = 'a' + j;
                    }
                }
            }
            if(minc == INF){
                pri(-1);
                return;
            }
            res += minc;
            sres[i] = bchar;
        }
    }
    pri(res);
    pri(sres);
    return;
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
