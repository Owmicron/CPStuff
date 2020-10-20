#include<bits/stdc++.h>
using namespace std;
int n,a[101],used[101];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n/2;i++){
        int mn=101;
        int mx=-1;

        int in=0,ix=0;
        for(int j=1;j<=n;j++){
            if(not used[j]){
                if(a[j]>mx){mx=a[j];ix=j;}
            }
        }
        used[ix]=true;
        for(int j=1;j<=n;j++){
            if(not used[j]){
                if(a[j]<mn){mn=a[j];in=j;}
            }
        }
        used[in]=true;

        cout<<in<<" "<<ix<<"\n";

    }

}
