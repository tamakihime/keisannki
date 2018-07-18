//
// Created by touho on 2018/07/18.
//

#include <math.h>
#include <stdio.h>

double yosikix(double y){
    return y;
}

double yoshikiy(double x){
    return -x;
}

int main(){
    double xfirst=0;
    //xに初期値0を代入したとき得られる解が1
    double yfirst=0;
    //ｙに初期値を代入したとき得られる解が0
     double max=2*M_PI;
     double bunnkatukaisuu=600;
     while(1) {

         double h = max / bunnkatukaisuu;//刻み幅の設定
         double x=1,y=0;
         for (int i = 0; i < bunnkatukaisuu; i++) {
             double x_0 = 0, x_1 = 0, y_0 = 0, y_1 = 0;
             x_0 = x + h * yosikix(y);
             y_0 = y + h * yoshikiy(x);
             x_1 = x + h * yosikix(y_0);
             y_1 = y + h * yoshikiy(x_0);
             x = (x_0 + x_1) / 2;
             y = (y_0 + y_1) / 2;

         }
         if(fabs(x-1)<0.0001 && fabs(y-0)<0.0001){
             printf("%lf",bunnkatukaisuu);
             break;
         }
         bunnkatukaisuu=bunnkatukaisuu+1;
     }
}