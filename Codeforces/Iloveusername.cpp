#include<bits/stdc++.h>
using namespace std;
int n,t,a,b,c,ma,mi,f;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(i==1){ma=n;mi=n;}
        else{
            if(n>ma){f++;ma=n;}
            else if(n<mi){f++;mi=n;}
        }

    }
    cout<<f;

}

