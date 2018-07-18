//
// Created by touho on 2018/07/07.
//

#include <stdio.h>
#include <math.h>

double kannsuu(double x){
    return 1/(1+x);
}
double oira(double h, double x){
    return x+h*kannsuu(x);
}
double  trueanswer( double t){
    return sqrt(1+2*t)-1;
}
double superioroira(double h, double x){
    double x_2=x+(h/2)*kannsuu(x);
    return x+h*kannsuu(x_2);
}
int main(){
    double h=0.1;//刻み幅
    double ht=0;//tの初期値
    double x=0;//初期値
    double x_2=x;
    int tmax=1;
    printf("syokiti=%lf:%lf trueanswer:%lf\n",ht,x,trueanswer(ht));
    while(1){
        x=oira(h,x);
        x_2=superioroira(h,x_2);
        printf("oirat=%lf:%lf superioroirt=%lf:%lf trueanswer:%lf\n",ht+h,x,ht+h,x_2,trueanswer(ht+h));
        ht=ht+h;
        if(ht+h>tmax){
            break;
        }
    }
}
