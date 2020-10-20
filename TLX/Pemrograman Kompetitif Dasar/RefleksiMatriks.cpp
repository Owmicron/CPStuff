#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[100][100],b[100][100],c[100][100];
void s(){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            c[i][j]=a[i][j];
        }
    }
}
void h(){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            c[i][j]=a[n+1-i][j];
        }
    }
}
void v(){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            c[i][j]=a[i][n+1-j];
        }
    }
}
void dkab(){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            c[i][j]=a[j][i];
        }
    }
}
void dkib(){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            c[i][j]=a[n+1-j][n+1-i];
        }
    }
}
bool check(){
    bool x=true;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(c[i][j]!=b[i][j]){return false;}
        }
    }
    return x;
}
str ans(){
    s();if(check()){return "identik\n";}
    h();if(check()){return "horisontal\n";}
    v();if(check()){return "vertikal\n";}
    dkab();if(check()){return "diagonal kanan bawah\n";}
    dkib();if(check()){return "diagonal kiri bawah\n";}
    return "tidak identik\n";
}
int main(){
    cin>>n>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cin>>n>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    cout<<ans();

}
