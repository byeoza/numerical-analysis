/*runge kutta.h ����


RK�Լ��� t�� z�� i+1���� �����ִ� �Լ��̴�.
s=1�� �ְԵǸ� t(i+1)�� ����ϰ�
s=2�� �ְԵǸ� z(i+1)�� ����Ѵ�.

*/



double f2(double t) {
	return 0.01 * t - 0.2;
}
double f1(double t){
return t;
 
 }
 
double RK(double t,double z,int s)
{
	double h = 0.1;
	double k11 = f1(z);
	double k12=f2(t);
	double k21 = f1(z+k12/2*h);
	double k22=f2(t+k11*h/2);
	double k31=f1(z+k22/2*h);
	double k32=f2(t+k21/2*h);
	double k41 =f1(z+k32*h);
	double k42=f2(t+k31*h);
 
	if (s == 1)
		return h / 6 * (k11 + 2 * k21 + 2 * k31 + k41);
	if (s == 2)
		return h / 6 * (k12 + 2 * k22 + 2 * k32 + k42);
 
 
 
 
   

 
 
 
 
 
 
 
 
 }