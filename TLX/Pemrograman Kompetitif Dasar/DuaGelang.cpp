#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
double xa,ya,ra,xb,yb,rb;
bool inside (double x, double y, double z){
    if((z>x)&&(z<y)){return true;}
    return false;
}
bool intersect(double a, double b, double c, double d){
    //        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    if((c==a)||(c==b)||(d==a)||(d==b))return true;
    else{
        if((inside(a,b,c)) && (inside(a,b,d))){return false;}
        else if ((!inside(a,b,c))&&(!inside(a,b,d))){return false;}
        else{return true;}
    }
}
int main(){
    cin>>xa>>ya>>ra;
    cin>>xb>>yb>>rb;
    if(ra<rb){
        swap(xa,xb);swap(ya,yb);swap(ra,rb);
    }
    double u;
    u = (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb);
    u = sqrt(u);
    //cout<<u<<endl;
    //cout<<-ra<<" "<<ra<<" "<<u-rb<<" "<<u+rb<<"\n";
    bool ans;
//    if (u>ra+rb){ans=false;}
//    else if(u=ra+rb){ans=true;}
//    else{
        if(intersect(-ra,ra,u-rb,u+rb)){ans=true;}
        else{ans=false;}
//    }
    if(ans){cout<<"bersentuhan\n";}
    else{cout<<"tidak bersentuhan\n";}

}
