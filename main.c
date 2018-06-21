//
// Created by touho on 2018/06/15.
//

#include <stdio.h>
#include <tgmath.h>
# include<assert.h>
double func(double x){
    return (double) sin(x);
}
double daikei(double start , double h){
    double sum=0;
    for(int i=0;i<12;i++){
        double y1=0,y2=0;
        y1=func(start+h*i);
        y2=func(start+h*(i+1));
        sum=sum+(y1+y2)*h/2;
    }
    return sum;

}

double sinpusonn(double start, double h){
    double sum = 0;
    for(int i=0;i<6;i++){
        double y1=0,y2=0,y3=0;
        y1=func(start+(2*i)*h);
        y2=func(start+(2*i+1)*h);
        y3=func(start+(2*i+2)*h);
        sum=sum+(y1+y2*4+y3)/3;
    }
    return sum*h;
}
double sinpusonn3(double start, double h){
    double sum=0;
    for(int i=0;i<4;i++){
        double y1=0,y2=0,y3=0,y4=0;
        y1=func(start+(3*i)*h);
        y2=func(start+(3*i+1)*h);
        y3=func(start+(3*i+2)*h);
        y4=func(start+(3*i+3)*h);
        sum=sum+(y1+y2*3+y3*3+y4)*3/8;
    }
    return sum*h;
}

double kinji4(double start, double h){
    double sum=0;
    for(int i=0;i<3;i++){
        double y1=0,y2=0,y3=0,y4=0,y5=0;
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
    double start,end;
    int mode=0;
    fgets(buf,256,stdin);
    sscanf(buf,"%d",&mode);

    //fgets(buf,256,stdin);
    //sscanf(buf,"%lf %lf",&start,&end);
    start=0;end=M_PI_2;
    double h=0;
    h=(end-start)/12;
    double answer=0;
    if(mode==1){
        answer=daikei(start,h);
    } else if(mode==2){
        answer=sinpusonn(start,h);
    } else if(mode==3){
        answer=sinpusonn3(start,h);
    } else if(mode==4) {
        answer = kinji4(start, h);
    }
    printf("%16.15lf\n",1-answer);
}