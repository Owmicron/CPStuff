#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b;
int time (str x){
    int a,b,c,d;
    d = int(x[4])-48;
    c = int(x[3])-48;
    b = int(x[1])-48;
    a = int(x[0])-48;
    int h,m;
    m = 10*c + d;
    h = 10*a + b;

    return 60*h + m;
}
void clock (int x){
    int h = x/60;
    int m = x%60;
    if(h<10){cout<<"0";}
    cout<<h<<":";
    if(m<10){cout<<"0";}
    cout<<m<<endl;
}
int main(){
    cin>>a;
    cin>>b;
    int c,d;
    c = time(a);
    d = time(b);
    int mid = (c+d)/2;
    clock(mid);
}
