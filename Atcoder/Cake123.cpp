#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int x,y,z,k;
ll a[2000],b[2000],c[2000];
priority_queue<pair <ll,ll> > temp;
priority_queue<ll> q;
int main(){
    cin>>x>>y>>z>>k;
    for(int i=1;i<=x;i++)cin>>a[i];
    for(int i=1;i<=y;i++)cin>>b[i];
    for(int i=1;i<=z;i++)cin>>c[i];

    sort(a+1,a+1+x,greater<ll>());
    sort(b+1,b+1+y,greater<ll>());
    sort(c+1,c+1+z,greater<ll>());

    int A,B,C;
    A=1;B=1;C=1;
    while(A*B*C <= 10000000){
        if(A==x && B==y && C==z){
            break;
        }
        else{
            if(A<x){
                temp.push(make_pair(-1*(a[A]-a[A+1]),1));
            }
            if(B<y){
                temp.push(make_pair(-1*(b[B]-b[B+1]),2));
            }
            if(C<z){
                temp.push(make_pair(-1*(c[C]-c[C+1]),3));
            }
        }
        ll top = temp.top().second;
        if(top==1){A++;}
        else if(top==2){B++;}
        else{C++;}
        while(!temp.empty())temp.pop();
    }
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            for(int l=1;l<=C;l++){
                q.push(a[i]+b[j]+c[l]);
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<q.top()<<endl;
        q.pop();
    }
}
