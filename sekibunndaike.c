//
// Created by touho on 2018/06/15.
//

#include <stdio.h>
# include<assert.h>
#include <math.h>
long double func(long double x){
    return 1/(sqrtl(x*x+309));
}
long double daikei(long double start , long double h,int n){
    long double sum=0;
    for(int i=0;i<n;i++){
       long  double y1=0,y2=0;
        y1=func(start+h*i);
        y2=func(start+h*(i+1));
        sum=sum+(y1+y2)*h/2;
    }
    return sum;

}

long double sinpusonn(long double start, long double h,int n){
   long  double sum = 0;
    for(int i=0;i<n/3;i++){
        long double y1=0,y2=0,y3=0;
        y1=func(start+(2*i)*h);
        y2=func(start+(2*i+1)*h);
        y3=func(start+(2*i+2)*h);
        sum=sum+(y1+y2*4+y3)/3;
    }
    return sum*h;
}
long double sinpusonn3(long double start, long double h,int n){
    long double sum=0;
    for(int i=0;i<n/3;i++){
        long double y1=0,y2=0,y3=0,y4=0;
        y1=func(start+(3*i)*h);
        y2=func(start+(3*i+1)*h);
        y3=func(start+(3*i+2)*h);
        y4=func(start+(3*i+3)*h);
        sum=sum+(y1+y2*3+y3*3+y4)*3/8;
    }
    return sum*h;
}

long double kinji4(long double start, long double h){
   long  double sum=0;
    for(int i=0;i<3;i++){
       long  double y1=0,y2=0,y3=0,y4=0,y5=0;
        y1=func(start+(4*i)*h);
        y2=func(start+(4*i+1)*h);
        y3=func(start+(4*i+2)*h);
        y4=func(start+(4*i+3)*h);
        y5=func(start+(4*i+4)*h);
        sum=sum+(7*y1+y2*32+y3*12+y4*32+y5*7)*2/45;
    }
    return sum*h;
}
int main (){
    char buf[256];
    long double start,end;
    int mode=0;
    fgets(buf,256,stdin);
    sscanf(buf,"%d",&mode);

    //fgets(buf,256,stdin);
    //sscanf(buf,"%lf %lf",&start,&end);
    start=0;end=1;
    long double h=0;
    for(int i=2000000003;i<2000000300;i=i+3) {
        h = (end - start) / i;
        long double answer = 0;
        if (mode == 1) {
            answer = daikei(start, h, i);
        } else if (mode == 2) {
            answer = sinpusonn(start, h,i);
        } else if (mode == 3) {
            answer = sinpusonn3(start, h,i);
        } else if (mode == 4) {
            answer = kinji4(start, h);
        }
        long double j = logl((1.0 + sqrtl(310.0)) / sqrtl(309.0));
        long double gosa = j - answer;
        if(fabsl(gosa)<1.98e-117) {
            printf("%Lf", j);
            break;
        }
    }
}