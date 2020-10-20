#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,diff,type,f[200000],ff[200000],u,mx;
priority_queue < int > q;
multiset <int> multi;
int main(){
    cin>>n;
    int ans;
    for(int i=1;i<=n;i++){
        cin>>u;
        bool spec=false;
        if(f[u]==0)diff++;
        if(f[u]>0){
            ff[f[u]]--;
            if(ff[f[u]]==0){type--;}
        }
        f[u]++;
        if(f[u]>mx){mx=f[u];}
        ff[f[u]]++;

        if(ff[f[u]]==1){type++;}

        bool valid = false;
        if(diff==1){valid=true;}
        else if(type==1){
            if(f[u]==1){valid=true;}
        }
        else if(type==2){
            if(ff[1]==1){valid=true;}
            else if(ff[mx]==1 && ff[mx-1]>0)valid=true;
        }
        if(valid){ans=i;}
        //cout<<i<<endl<<type<<" "<<diff<<" "<<mx<<" "<<valid<<endl;

    }
    cout<<ans<<endl;
}

