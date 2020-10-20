#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
vector < pair <pii,pii> > ans;
int h,w,cell[600][600];
int main(){
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>cell[i][j];
        }
    }

    for(int i=1;i<=h;i++){
        if(i%2==1){
            for(int j=1;j<=w;j++){
                if(cell[i][j]%2==1){
                    if(j<w){ans.pb(mp(mp(i,j),mp(i,j+1)));cell[i][j]--;cell[i][j+1]++; }
                    else{
                        if(i<h){
                            ans.pb(mp(mp(i,j),mp(i+1,j)));cell[i][j]--;cell[i+1][j]++;
                        }
                    }
                }
            }
        }
        else{
            for(int j=w;j>=1;j--){
                if(cell[i][j]%2==1){
                    if(j>1){ans.pb(mp(mp(i,j),mp(i,j-1)));cell[i][j]--;cell[i][j-1]++; }
                    else{
                        if(i<h){
                            ans.pb(mp(mp(i,j),mp(i+1,j)));cell[i][j]--;cell[i+1][j]++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        printf("%d %d %d %d\n",ans[i].ff,ans[i].fs,ans[i].sf,ans[i].ss);
    }


}
