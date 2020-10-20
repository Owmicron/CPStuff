#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dbl;
bool cross;
dbl n,xa,ya,xb,yb,xc,yc,xd,yd,y,c,x;
dbl INF = 9000000000;
dbl E = 0.0000001;
bool is_equal(dbl a, dbl b){
    if(abs(b-a) < E){return true;}
    else{return false;}
}
bool in_range(dbl z, dbl a, dbl b){
    if((z>=a)&&(z<=b))return true;
    return false;
}
dbl gradient (dbl x1, dbl y1, dbl x2, dbl y2){
    if(is_equal(x2,x1)){return INF;}
    else{
        return (y2-y1)/(x2-x1);
    }
}
void equation(dbl x1, dbl y1, dbl x2, dbl y2){
    dbl m;
    m = gradient (x1,y1,x2,y2);
    if(is_equal(m,INF)){y=0;x=1;c=-x1;}
    else if(is_equal(m,0)){y=1;x=0;c=y1;}
    else{y=1; x=m; c=y*y1-x*x1;}
}
bool cross_up(){
    dbl x1 = min(xc,xd);
    dbl x2 = max(xc,xd);
    dbl y1 = yc;
    if(!in_range(y1, min(ya,yb),max(ya,yb))){return false;}
    if(is_equal(x,0)){
        if(is_equal(c,y1)){
            if(in_range(min(xa,xb),x1,x2) || in_range(max(xa,xb),x1,x2)){return true;}
            else{return false;}
        }
        else{return false;}
    }
    dbl point = (y1*y - c)/x;
    if(in_range(point,x1,x2)){return true;}
    else{return false;}
}
bool cross_down(){
    dbl x1 = min(xc,xd);
    dbl x2 = max(xc,xd);
    dbl y1 = yd;
    if(!in_range(y1, min(ya,yb),max(ya,yb))){return cross_up();}
    if(is_equal(x,0)){
        if(is_equal(c,y1)){
            if(in_range(min(xa,xb),x1,x2) || in_range(max(xa,xb),x1,x2)){return true;}
            else{return cross_up();}
        }
        else{return cross_up();}
    }
    dbl point = (y1*y - c)/x;
    if(in_range(point,x1,x2)){return true;}
    else{return cross_up();}
}
bool cross_left(){
    dbl y1 = min(yc,yd);
    dbl y2 = max(yc,yd);
    dbl x1 = xc;
    if(!in_range(x1, min(xa,xb),max(xa,xb))){return cross_down();}
    dbl point = (x1*x + c);
    if(is_equal(y,0)){
        if(is_equal(-c,x1)){
            if(in_range(min(ya,yb),y1,y2) || in_range(max(ya,yb),y1,y2)){return true;}
            else{return cross_down();}
        }
        else{return cross_down();}
    }
    if(in_range(point,y1,y2)){return true;}
    else{return cross_down();}
}
bool cross_right(){
    dbl y1 = min(yc,yd);
    dbl y2 = max(yc,yd);
    dbl x1 = xd;
    if(!in_range(x1, min(xa,xb),max(xa,xb))){return cross_left();}
    dbl point = (x1*x + c);
    if(is_equal(y,0)){
        if(is_equal(-c,x1)){
            if(in_range(min(ya,yb),y1,y2) || in_range(max(ya,yb),y1,y2)){return true;}
            else{return cross_left();}
        }
        else{return cross_left();}
    }
    if(in_range(point,y1,y2)){return true;}
    else{return cross_left();}
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cross = false;
        scanf ("%lf",&xc);scanf ("%lf",&yc);scanf ("%lf",&xd);scanf ("%lf",&yd);scanf ("%lf",&xa);scanf ("%lf",&ya);scanf ("%lf",&xb);scanf ("%lf",&yb);
        //cout<<xc<<yc<<xd<<yd<<xa<<ya<<xb<<yb<<endl;
        //cin>>xc>>yc>>xd>>yd>>xa>>ya>>xb>>yb;
        equation (xa,ya,xb,yb);
        cross = cross_right();
        if(!cross){printf("TIDAK\n");}
        else{printf("YA\n");}
    }
}
