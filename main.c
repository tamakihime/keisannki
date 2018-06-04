# include<stdio.h>
#include <stdlib.h>
#include <tgmath.h>

double a[4][5];
double answer[4]={};
int input(){
    for(int i= 0;i<4;i++) {
        char  buf[500000]={};
        fgets(buf, 50001, stdin);
        sscanf(buf, "%lf %lf %lf %lf %lf\n", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    }
    return 0;
}
int pipot(int i){
    double temp[5];
    double max = 0;
    int maxpar = 0;
    for(int j=i;j<4;j++){
        if( fabs(max) < fabs(a[j][i])){
            max = a[i][j];
            maxpar = j;
        }
    }

    for(int k=i;k<5;k++){
        temp[k] = a[i][k];
        a[i][k] = a[maxpar][k];
        a[maxpar][k] = temp[k];
    }
}

int syoukyo(int i){
    for(int j=i+1;j<4;j++){

            double temp = a[j][i] / a[i][i];
            for (int k = i; k < 5; k++) {
                a[j][k] = a[j][k] - a[i][k] * temp;
            }

    }
}
int dainyuu(int k){
    double sum=0;
    for(int i=3;i>k;i--){
        sum=sum+a[k][i]*answer[i];
    }
    answer[k]=(a[k][4]-sum)/a[k][k];
}

int main(){
    /*
     *
     *
     *
     *
     */
    input();
    for(int i=0;i<3;i++){
        pipot(i);
        syoukyo(i);
    }
    for(int k=3;k >-1;k--){
        dainyuu(k);
    }
}

