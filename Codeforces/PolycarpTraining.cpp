#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,idx,a[300000],f;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    idx = 1;
    for(int i=1;i<=n;i++){
        if(idx<=a[i]){idx++;f++;}
    }
    cout<<f<<endl;
}
