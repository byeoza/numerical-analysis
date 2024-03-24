#include<stdio.h>
#include<math.h	>
#pragma warning(disable:4996)
#include "runge_kutta.h"

double T[101];
double Z[101];//전역변수 

double find_T(double z) {
	
	
	for (int i = 0; i <= 100;) {
		if (i == 0) {
			T[i] = 40;
			Z[i] = z;// 이 값이 우리가 구해야 할 아주 중요한 값이다...
		}
		else{
			T[i] = T[i - 1] + RK(T[i - 1], Z[i - 1], 1);
			Z[i] = Z[i - 1] + RK(T[i - 1], Z[i - 1], 2);
		}
		i++;
	}
	
	return T[100];
}


//int main() {
//	double T[101];//
//	double Z[101];
//	//이 for 문 자체를 함수로 만들어야 겠다. 
//	for (int i = 0; i <= 100;) {
//		if (i == 0) {
//			T[i] = 40;
//			Z[i] = 12.69046;// 이 값(100)이 우리가 구해야 할 아주 중요한 값이다...
//		}
//		else{
//			T[i] = T[i - 1] + RK(T[i - 1], Z[i - 1], 1);
//			Z[i] = Z[i - 1] + RK(T[i - 1], Z[i - 1], 2);
//		}
//		i++;
//	}
//	for (int i=0;i<=100;i++){
//	printf("T%d :%lf\n",i, T[i]);
//	//printf("Z%d :%lf\n",i, Z[i]);
//	}
//	return 0;
//
//}//이전 main 함수 잘 안되면 이거 다시 복구하자.

int main() {
	double a=100;//z값의 범위를 설정한다.
	
	
	//bisection만드는중
	
	for (int i = 1; i < 100; i++) {
		if (find_T(a) > 200)
			a -= 100/pow(2, i) ;
		else 
			a += 100/pow(2, i);
		
		if (fabs( ((find_T(a) - 200) / 200 )) < 0.001)
			break;
	}
	printf("z(0)=%lf\n", a);

	for (int i = 0; i <= 100; i++)
		printf("T%d :%lf\n", i,T[i]);

	//a=12.695312

	return 0;
}