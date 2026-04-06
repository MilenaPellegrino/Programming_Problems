#include<bits/stdc++.h> 
using namespace std;

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second
#define sz(x) ((int)x.size())

//#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using ll = long long; 
typedef vector<ll> vi;

int main(){FIN;
    ll t; cin>>t;
    fore(i,0,t){

        ll b,c,d;
        cin>>b>>c>>d;
        auto bb = bitset<70>(b).to_string();
        auto bc = bitset<70>(c).to_string();
        auto bd = bitset<70>(d).to_string();
        vector<char> a(70, '0');
        bool todobien = true;
        fore(i,0,70){

            if(bb[i]=='0' && bd[i]=='1'){
                if (bc[i]=='1'){
                    todobien = false;
                    break;
                }
                a[i]='1';
            }
            else if(bb[i]=='1' && bd[i]=='0'){
                if (bc[i]=='0'){
                    todobien = false;
                    break;
                }
                a[i]='1';
            }
        }
        if (!todobien){
            cout << "-1\n";
        } else {
            string aa(a.begin(), a.end());
            cout << stoll(aa, nullptr, 2) << "\n";
        }
        
    }

    return 0;
}