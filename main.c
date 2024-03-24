#include<stdio.h>
#include<math.h	>
#pragma warning(disable:4996)
#include "runge_kutta.h"

double T[101];
double Z[101];//�������� 

double find_T(double z) {
	
	
	for (int i = 0; i <= 100;) {
		if (i == 0) {
			T[i] = 40;
			Z[i] = z;// �� ���� �츮�� ���ؾ� �� ���� �߿��� ���̴�...
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
//	//�� for �� ��ü�� �Լ��� ������ �ڴ�. 
//	for (int i = 0; i <= 100;) {
//		if (i == 0) {
//			T[i] = 40;
//			Z[i] = 12.69046;// �� ��(100)�� �츮�� ���ؾ� �� ���� �߿��� ���̴�...
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
//}//���� main �Լ� �� �ȵǸ� �̰� �ٽ� ��������.

int main() {
	double a=100;//z���� ������ �����Ѵ�.
	
	
	//bisection�������
	
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