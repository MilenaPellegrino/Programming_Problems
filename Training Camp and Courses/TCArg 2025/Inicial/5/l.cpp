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

pair<int,int> lados[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void algor(ll n, ll m, ll x, ll y, ll left, ll right,
    vector<vector<bool>> &visitados,
    vector<vector<ll>> &a,
    vector<vector<ll>> &vleft,
    vector<vector<ll>> &vright){

    visitados[x][y]=true;
    int p,q;
    for(auto la: lados){
        p=x+la.fst;
        q=y+la.snd;
        if(p>=0 && p<n && q>=0 && q<m && a[p][q]==true && !visitados[p][q]){
            if(la.snd==1 && vright[x][y]<right){
                res++;
                a[p][q]=2;
                vleft[p][q] = vleft[x][y];
                vright[p][q] = vright[x][y] + 1;
                algor(n,m,p,q,left,right,visitados,a,vleft,vright);
            }
            if(la.snd==-1 && vleft[x][y]<left){
                res++;
                a[p][q]=2;
                vright[p][q] = vright[x][y];
                vleft[p][q] = vleft[x][y] + 1;
                algor(n,m,p,q,left,right,visitados,a,vleft,vright);
            }
            if(la.snd==0){
                res++;
                a[p][q]=2;
                vleft[p][q] = vleft[x][y];
                vright[p][q] = vright[x][y];
                algor(n,m,p,q,left,right,visitados,a,vleft,vright);
            }
        }
    }


}

int main(){
    FIN;
    ll n, m; cin>>n>>m; 
    ll r, c; cin>>r>>c; r--;c--;
    ll left, right; cin>>left>>right;
    vector<vector<bool>> visitados(n, vector<bool>(m, false));
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> vleft(n, vector<ll>(m));
    vector<vector<ll>> vright(n, vector<ll>(m));
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
    algor(n,m,r,c,left,right,visitados,a,vleft,vright);

    fore(i,0,n){
        fore(j,0,m){
            cout << a[i][j];
        }
        cout << "\n";
    }


    cout << res << "\n";

    return 0;
}


