//
// Created by touho on 2018/06/15.
//

#include <stdio.h>

double func(double x){
    return x;
}
int main (){
    char buf[256];
    double start,end;
    fgets(buf,256,stdin);
    sscanf(buf,"%lf %lf",&start,&end);
    double h=0;
    h=(end-start)/12;

}