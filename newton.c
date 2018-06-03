# include<math.h>
#include <stdio.h>
double fx (double x){
    double y;
    y = tan(x)-309;
    return y;
}

double df (double x){
    double y;
    y = 1/(cos(x)*cos(x));
    return y;
}
double  newton(double x){
    for (int i = 0; i < 2000; ++i) {
        double a;
        a = x-(fx(x)/df(x));
        x = a;
    }
    return x;
}
int main(){
    double x;
        x =1.55783849384;
        double t = newton(x);
            printf("%lf\n",t);

    printf("%lf\n",tan(1.56756));

}