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

ll res = 1;

pair<int,int> lados[4] = {{-1,0},{1,0}, {0,-1},{0,1}};

// dwadwadwa

// la verga esta se queda en espera y no funca dios

int main(){
    FIN;
    ll n, m; cin>>n>>m; 
    ll r, c; cin>>r>>c; r--;c--;
    ll left, right; cin>>left>>right;
    vector<vector<bool>> visitados(n, vector<bool>(m, false));
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> vleft(n, vector<ll>(m));
    vector<vector<ll>> vright(n, vector<ll>(m));
    queue<pair<ll,ll>> qu;
    fore(i, 0, n){
        fore(j, 0, m){
            char c; cin>>c; 
            ll res = 0;
            if(c=='.')res = 1;
            a[i][j] = res;
        }
    }

    vleft[r][c]=0;
    vright[r][c]=0;
    a[r][c]=2;
    qu.push({r,c});
    visitados[r][c]=true;
    
    while(!qu.empty()){
        pair<ll,ll> pv = qu.front();
        ll x = pv.fst;
        ll y = pv.snd;
        qu.pop();

        ll p,q;
        for(auto la: lados){
            p=x+la.fst;
            q=y+la.snd;
            if(p>=0 && p<n && q>=0 && q<m && a[p][q]!=0 && !visitados[p][q]){
                if(la.snd==1 && vright[x][y]<right){
                    res++;
                    a[p][q]=2;
                    vleft[p][q] = vleft[x][y];
                    vright[p][q] = vright[x][y] + 1;
                    visitados[p][q]=true;
                    qu.push({p,q});
                }
                if(la.snd==-1 && vleft[x][y]<left){
                    res++;
                    a[p][q]=2;
                    vright[p][q] = vright[x][y];
                    vleft[p][q] = vleft[x][y] + 1;
                    visitados[p][q]=true;
                    qu.push({p,q});
                }
                if(la.snd==0){
                    ll pp=p;
                    while(pp>=0 && pp<n && a[pp][q]!=0 && !visitados[pp][q]){
                        res++;
                        a[pp][q]=2;
                        vleft[pp][q] = vleft[x][y];
                        vright[pp][q] = vright[x][y];
                        visitados[pp][q]=true;
                        qu.push({pp,q});
                        pp += la.fst;
                    }
                }
            }
        }


    }

    cout << res << "\n";

    return 0;
}