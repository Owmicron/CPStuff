#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,a[1000],ans;
bool used[1000];
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!used[a[i]]){used[a[i]]=true;v.push_back(a[i]);}
    }
    sort(v.begin(),v.end());
    if(v.size()>3){ans=-1;}
    if(v.size()==2){
        if((v[0]+v[1])%2==0){ans=(v[0]+v[1])/2;ans=v[1]-ans;}
        else{ans=v[1]-v[0];}
    }
    else if(v.size()==3){
        if((v[1]-v[0])==(v[2]-v[1])){ans=v[2]-v[1];}
        else{ans=-1;}
    }
    printf("%d\n",ans);
}

