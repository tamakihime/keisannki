#include <math.h>
#include <stdio.h>


//
// Created by touho on 2018/07/18.
//
double yosikix(double x,double y){
    return y;
}

double yoshikiy(double x, double y){
    return -2*y-2*x;
}
int main(){
    double h=2*M_PI/1000;
    double x=1,y=-1;
    double k_1_x=0,k_2_x=0,k_3_x=0,k_4_x=0;
    double k_1_y=0,k_2_y=0,k_3_y=0,k_4_y=0;
    for(int i=0;i<1000;i++) {
        k_1_x = yosikix(x, y);
        k_1_y = yoshikiy(x, y);
        k_2_x = yosikix(x + h / 2 * k_1_x, y + h / 2 * k_1_y);
        k_2_y = yoshikiy(x + h / 2 * k_1_x, y + h / 2 * k_1_y);
        k_3_x = yosikix(x + h / 2 * k_2_x, y + h / 2 * k_2_y);
        k_3_y = yoshikiy(x + h / 2 * k_2_x, y + h / 2 * k_2_y);
        k_4_x = yosikix(x + h * k_3_x, y + h * k_3_y);
        k_4_y = yoshikiy(x + h * k_3_x, y + h * k_3_y);
        x = x + h * (k_1_x + 2 * k_2_x + 2 * k_3_x + k_4_x) / 6;
        y = y + h * (k_1_y + 2 * k_2_y + 2 * k_3_y + k_4_y) / 6;
    }
    printf("x;%8.9e\ny:%lf\n",x,y);
}
