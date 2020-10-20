#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dbl;
int n,x[303],y[303],dif;
dbl ans;
bool valid;
dbl area (dbl x1, dbl y1, dbl x2, dbl y2, dbl x3, dbl y3){
    dbl tmp = x2*y3 + x3*y1 + x1*y2 - (x2*y1 + x3*y2 + x1*y3);
    tmp = abs(tmp);
    tmp/=2;
    return tmp;
}
int main(){
    valid = true;
    scanf("%d",&n);
    ans = 400000000;
    for(int i=1;i<=n;i++){scanf("%d %d",&x[i],&y[i]);}
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<=n;k++){
                dbl t = area(x[i],y[i],x[j],y[j],x[k],y[k]);
                if(ans > t){
                    if(t!=0){ans=t;dif++;valid=true;}
                }
                else if(ans == t){valid=false;}
            }
        }
    }
    if(ans==400000000){ans=-1;}
    if(ans==0){ans=-1;}
    if(dif<=1){ans=-1;}
    if(!valid){ans=-1;}
    printf ("%.2lf\n",ans);
}
