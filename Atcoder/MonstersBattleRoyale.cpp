#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,g;
int gcd (int a, int b){
    if(a<b)swap(a,b);

    int c = a%b;
    while(c>0){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(i==1){g=temp;}
        else{g=gcd(g,temp);}
    }
    cout<<g<<endl;
}
