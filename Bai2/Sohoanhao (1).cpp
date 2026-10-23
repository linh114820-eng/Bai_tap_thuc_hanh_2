#include<stdio.h>
int ktra(int N){
	if(N <= 0) return 0;
	int S = 0;
	for(int i = 1; i < N/2; i++)
		if(N % i == 0)
		S += i;
	if(S == N) return 1;
	return 0;
}
int main(){
	int N ;
	printf("Nhap N: ");
	scanf("%d", &N);
	if(ktra(N) == 1)
		printf("%d là so hoan hao.\n", N);
	else 
		printf("%d khong la so hoan hao.\n", N);
	
}
