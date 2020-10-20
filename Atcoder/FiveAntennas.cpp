#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a[6],mx,mn,k;
int main(){
    mx = -1;
    mn = 1000;
    for(int i=0;i<5;i++){
        cin>>a[i];
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    cin>>k;
    if(mx-mn>k)cout<<":(\n";
    else cout<<"Yay!\n";

}
