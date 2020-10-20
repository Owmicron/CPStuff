#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,ans,f[200000],d;
bool small[200000],big[200000];
int main(){
    cin>>n>>k;
    ans = (n-2)*3 + 4;
    for(int i=1;i<=k;i++){
        int temp;
        cin>>temp;
        f[temp]++;
        if(f[temp]==1)d++;
        if(!small[temp]){
            if(f[temp-1]>0){d++;small[temp]=true;}
        }
        if(!big[temp]){
            if(f[temp+1]>0){d++;big[temp]=true;}
        }
    }
    ans-=d;
    if(n==1){ans=0;}
    cout<<ans<<endl;
}
