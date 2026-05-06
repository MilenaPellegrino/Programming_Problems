#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 

int main(){
    FIN;

    ll t; cin>>t;
    while(t--){

        ll n,m; cin>>n>>m;
        ll kpos,kneg,aux;
        cin>>kpos;
        kneg=kpos;
        fore(i,1,n){
            cin>>aux;
            if(aux>kpos)kpos=aux;
            if(aux<kneg)kneg=aux;
        }
        ll a,b,c;
        vector<float> minx(m);
        vector<float> miny(m);
        fore(i,0,m){
            cin>>a>>b>>c;
            minx[i] = -b/(2*a);
            miny[i] = a*minx[i]*minx[i] + b*minx[i] + c;
        }
        fore(i,0,m){
            if(minx[i]<0){
                if(miny[i]>kpos*minx[i]){
                    cout<<"YES\n"<<kpos<<"\n";
                }else{
                    cout<<"NO\n";
                }
            } else if(minx[i]>0) {
                if(miny[i]>kneg*minx[i]){
                    cout<<"YES\n"<<kneg<<"\n";
                }else{
                    cout<<"NO\n";
                }
            } else {
                if(miny[i]>0){
                    cout<<"YES\n"<<kneg<<"\n";
                }else{
                    cout<<"NO\n";
                }
            }
        }
        cout<<"\n";

    }

    return 0;
}