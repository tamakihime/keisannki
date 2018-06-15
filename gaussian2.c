#include<stdio.h>
#include<math.h>

#define N 4

void gaussian(double a[N][N+1]){
	int i, j, k, l, p;
	double x[N], tmp[1][N], L[N][N];
	double pivot, z, lu, det;

 	
 	
 	for(k=0;k<N;k++){
 		for(l=k+1;l<N;l++){
 			a[k][l] = a[k][l]/a[k][k];
 			printf("a%lf\n\n", a[k][l]);
 			for(int m=k+1;m<N;m++){
 				a[m][l] = a[m][l] - a[m][k] * a[k][l];
 				printf("b%lf\n", a[m][l]);
 			}
 		}
 	}
 	
 	
 	printf("l[i][j]\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%f ", a[i][j]);
		}
		printf("\n\n");
	}
	
	det = a[1][1]*a[2][2]*a[3][3];
	printf("detA = %f\n", det);
	
	/**/
	
	printf("answer->\n");
	for(i=0; i<N; i++){
		printf("x[%d] = %f\n", i, x[i]);
	}
}

int main(){
	
    
    double a[N][N+1]={{8.0,2.0,1.0,5.0,0.0},
        {2.0,7.0,3.0,1.0,0.0},
        {1.0,7.0,5.0,1.0,0.0},
       {1.0,1.0,2.0,2.07,0.0}};
	
	
	
	gaussian(a);
	
	return 0;
}