# include<stdio.h>
#include <stdlib.h>

double a[4][5];
int input(){
    for(int i= 0;i<4;i++) {
        char  buf[500000]={};
        fgets(buf, 50001, stdin);
        sscanf(buf, "%lf %lf %lf %lf %lf\n", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    }
    return 0;
}
int pipot(){
    double temp[4][5];
    int max[4]={};
    for (int i = 0; i < 4; i++) {
        if (max[0] < a[i][0]) {
            max[0] = i;
        }
    }
    for(int i =0;i<4;i++){
        if(i!=max[0]){
            if (max[1] < a[i][1]) {
                max[1] = i;
            }
        }
    }
    for(int i =0;i<4;i++){
        if(i!=max[0] && i!=max[1]){
            if (max[2] < a[i][2]) {
                max[2] = i;
            }
        }
    }
    for(int i=0;i<4;i++){
        if(i != max[0] && i != max[1] && i != max[2]){
            max[3]=i;
        }
    }
    for(int i=0; i<4;i++){
        int k= max[i];
        for(int j=0;j<5;j++){
            temp[i][j]=a[k][j];
        }
    }
    for(int i=0; i<4;i++){
        for(int j=0;j<5;j++){
            a[i][j]=temp[i][j];
        }
    }
}

int syoukyo(){
    for(int i=0;i<4;i++){
        for(int k=i+1;k<4;k++){
            double tmp;
            tmp=a[k][i]/a[i][i];
            for(int j=i;j<5;j++){
                a[k][j]=a[k][j]-(a[i][j]*tmp);
            }
        }
    }
}

int main(){
    /*
     *
     *
     *
     *
     */
    input();
    pipot();
    syoukyo();
}

