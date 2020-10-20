#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
double sum;
double x[20];
str u[20];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>u[i];
        if(u[i]=="JPY"){sum+=x[i];}
        else{sum+=x[i]*380000;}
    }
    printf("%.4lf\n",sum);
}
