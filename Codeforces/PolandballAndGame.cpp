#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a;
long n,m,x;
string poland[1001],enemy[1001];
int main(){
    cin>>n>>m;
    str temp;
    for(long i=0;i<n;i++){
        cin>>poland[i];
    }
    for(long i=0;i<m;i++){
        cin>>enemy[i];
    }
    for(long i=0;i<n;i++){
        for(long j=0;j<m;j++){
            if(poland[i]==enemy[j]){x++;break;}
        }

    }

//    m-=(x/2);
//    n-=(x/2);
//    if(x%2 == 1)m-=1;
//

    m-=x;
    n-=x;

        if(n>m){cout<<"YES";}
    else if(n==m){
            if(x%2==1){cout<<"YES";}
            else{cout<<"NO";}
    }
    else{cout<<"NO";}



}
