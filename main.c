#include <stdio.h>
#include <stdlib.h>
double raguranzyu(int i,double x, double data_x[])
{
    int j;
    double lam = 1.0;

    for(j = 0 ; j < 4 ; j++)
    {
        if(i != j)
        {
            lam *= (x - data_x[j])/(data_x[i] - data_x[j]);
        }
    }

    return lam;
}
int main(){
    double x[4];
    double y[4];
    FILE *output;
    output = fopen("output.dat", "w");
    x[0]=1;
    x[1]=3;
    x[2]=5;
    x[3]=7;

    y[0]=2;
    y[1]=0;
    y[2]=-6;
    y[3]=5;

    for(double i=x[0];i<x[3];i+=0.1){
        double f=0;
        for(int j=0;j<4;j++){
            f=f+y[j]*raguranzyu(j,i,x);
        }
        fprintf(output, "%f %f\n", i, f);;
    }
    fclose(output);
    return 0;
}