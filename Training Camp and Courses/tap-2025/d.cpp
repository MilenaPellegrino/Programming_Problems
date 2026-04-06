// g++ c.cpp -o z -O2 -std=c++17
#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i =a; i<b; i++)
#define pb push_back
#define ALL(s) s.begin(), s.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define pll pair<ll,ll>
#define fst first
#define snd second
#define vec vector<int>


int distancia(int a, int b, int n){
    if (a>=b){
        return a-b;
    } else {
        return a-b + n;
    }
}

int main(){FIN;

    int n; cin >> n;
    vec v(n);
    fore(i,0,n){
        cin >> v[i];
    }

    vec inver(n);
    for (int i = n; i >= 1; --i)
        inver.pb(i);

    int res;
    fore(i,0,n-1){
        int j = i+1;
        while(j<n){
            if(distancia(v[i], v[j], n) == j-i){
                res += 2;
            }
            j++;
        }
    }

    cout << res << "\n";

    return 0;
}