#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ll = long long;
typedef vector<int> vi; 
typedef vector<pair<int, int>> vii; 


int main(){
    FIN; 

    int n; cin >> n;

    vii va(n);
    vii vb(n);
    vii vc(n);
    string s;
    int aux;

    fore(i,0,n){
        cin >> s;
        cin >> aux;
        va[i] = {aux, i};
        cin >> aux;
        vb[i] = {aux, i};
        cin >> aux;
        vc[i] = {aux, i};
    }

    sort(all(va));
    sort(all(vb));
    sort(all(vc));

    int best = 0;
    vi viter(n,0);

    while(true){
        int pcount = 0;
        int tcount = 0;
        int ita=0, itb=0, itc=0;
        vector<bool> problems(n,false);
        fore(iter,0,n){
            fore(i,0,n){
                if(viter[iter]==0){
                    while(!problems[va[ita].snd] && ita<n){
                        ita++;
                    }
                    if (ita!= n){
                        if(va[ita].fst + tcount <= 300){
                            pcount++;
                            tcount += va[ita].fst;
                            problems[va[ita].snd]=true;
                            ita++;
                        }
                    }
                } else if(viter[iter]==1) {
                    while(!problems[vb[itb].snd] && itb<n){
                        itb++;
                    }
                    if (itb!= n){
                        if(vb[itb].fst + tcount <= 300){
                            pcount++;
                            tcount += vb[itb].fst;
                            problems[vb[itb].snd]=true;
                            itb++;
                        }
                    }
                } else if(viter[iter]==2) {
                    while(!problems[vc[itc].snd] && itc<n){
                        itc++;
                    }
                    if (itc!= n){
                        if(vc[itc].fst + tcount <= 300){
                            pcount++;
                            tcount += vc[itc].fst;
                            problems[vc[itc].snd]=true;
                            itc++;
                        }
                    }
                }
            }

            fore(j,0,n){
                int k = n -j -1;
                if (viter[k]==2){
                    viter[k]=0;
                } if (viter[k]!=2) {
                    viter[k]++;
                    break;
                }
            }
        }
        if (pcount > best) {
            best = pcount;
        }
    }

    return 0; 
}
