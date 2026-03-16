#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define vi vector<ll>
#define fore(i, a, b) for (ll i= a; i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main(){FIN; 

    int n; cin >> n;
    vi rooms(10,0);
    string s;
    cin >> s;
    for (char a:s){
        if(a=='L'){
            fore(i,0,10){
                if (rooms[i]==0){
                    rooms[i]=1;
                    break;
                }
            }
        } else if(a=='R'){
            for (ll i = 9; i>=0; i--){
                if (rooms[i]==0){
                    rooms[i]=1;
                    break;
                }
            }
        } else {
            ll ai = a - '0';
            rooms[ai]=0;
        }
    }

    for(auto a:rooms){
        cout<<a;
    }
    cout<<"\n";

    return 0;
}