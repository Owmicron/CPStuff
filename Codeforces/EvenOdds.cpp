#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,odd,even,p,ans;
int main(){
    cin>>n>>k;
    if(n%2 == 0){even=n;odd=n-1;}
    else{odd=n;even=n-1;}

    p = ((odd - 1)/2)+1;
    if(k>p){ans = 2 + (k-p-1)*2;}
    else{ans = 1 + (k-1)*2;}

    cout<<ans;

}
