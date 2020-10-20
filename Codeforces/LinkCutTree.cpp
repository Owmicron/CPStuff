#include<bits/stdc++.h>
using namespace std;
    long long l,r,k,x,f;
int main(){

    cin>>l>>r>>k;
    x=1;

    while(x<=r){
            //cout << x << endl;
        if(x>=l && x<=r){
            cout<<x;
            f++;
            cout<<" ";
        }
        if(x==1000000000000000000){break;}
        if (x * k / k != x) break;
        x*=k;
        if (x==1){break;}


    }
    if (f==0){cout<<-1;}
}
