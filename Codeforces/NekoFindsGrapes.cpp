#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,odd,even,odd1,even1;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int temp;cin>>temp;
        if(temp%2==1){odd++;}
        else{even++;}
    }
    for(int i=1;i<=m;i++){
        int temp;cin>>temp;
        if(temp%2==1){odd1++;}
        else{even1++;}
    }
    int mx;
    mx = min(odd,even1) + min(even,odd1);
    cout<<mx<<endl;

}
