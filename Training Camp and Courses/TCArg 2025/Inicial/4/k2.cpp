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


int main(){FIN;

    int n; cin >> n;

    vii va(n);
    vii vb(n);
    vii vc(n);
    string s;
    int aux;

    fore(i,0,n){
        cin >> s;
        cin >> aux;
        if (aux == -1) {
            aux = 1000;
        }
        va[i] = {aux, i};
        cin >> aux;
        if (aux == -1) {
            aux = 1000;
        }
        vb[i] = {aux, i};
        cin >> aux;
        if (aux == -1) {
            aux = 1000;
        }
        vc[i] = {aux, i};
    }

    sort(all(va));
    sort(all(vb));
    sort(all(vc));

    vector<bool> problems(n,false);
    int pcount = 0;
    int tcount = 0;
    int ita=0, itb=0, itc=0;
    while(tcount < 300 && pcount<n){

        if (problems[va[ita].snd]){
            ita++; continue;
        }
        if (problems[vb[itb].snd]){
            itb++; continue;
        }
        if (problems[vc[itc].snd]){
            itc++; continue;
        }
        if (va[ita].fst<=vb[itb].fst && va[ita].fst<=vc[itc].fst) {
            if(tcount + va[ita].fst <= 300){
                tcount += va[ita].fst;
                pcount++;
                problems[va[ita].snd] = true;
                ita++;
                continue;
            } else {
                break;
            }
        }
        if (vb[itb].fst<=va[ita].fst && vb[itb].fst<=vc[itc].fst) {
            if(tcount + vb[itb].fst <= 300){
                tcount += vb[itb].fst;
                pcount++;
                problems[vb[itb].snd] = true;
                itb++;
                continue;
            } else {
                break;
            }
        } else {
            if(tcount + vc[itc].fst <= 300){
                tcount += vc[itc].fst;
                pcount++;
                problems[vc[itc].snd] = true;
                itc++;
                continue;
            } else {
                break;
            }
        }
    }

    cout << pcount << "\n";


    return 0; 
}
