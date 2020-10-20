#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int one,f[20],ff[200000],other,n,u;
bool valid(){
    vector<int> jlh;
    for(int i=1;i<=10;i++){
        if(f[i]>0){jlh.push_back(f[i]);}
    }
    sort(jlh.begin(),jlh.end());

    int type = 1;
    for(int i=1;i<jlh.size();i++){
        if(jlh[i]!=jlh[i-1]){type++;}
    }
    //for(int i=0;i<jlh.size();i++)cout<<jlh[i]<<" ";cout<<endl;
    if(jlh.size()==1){return true;}
    if(type==1){
        if(jlh[0]==1){return true;}
        else return false;
    }
    else if(type==2){
        if(jlh[0]==1 && jlh[1]!=1) return true;
        if(jlh[jlh.size()-1] == 1 + jlh[jlh.size()-2]){return true;}
        else return false;
    }
    else if(type>2){
        return false;
    }

}
int main(){
    cin>>n;
    int ans;
    for(int i=1;i<=n;i++){
        cin>>u;
        f[u]++;
        if(valid())ans=i;
    }
    cout<<ans<<endl;
}

