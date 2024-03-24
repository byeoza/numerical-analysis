/*runge kutta.h 설명


RK함수는 t랑 z의 i+1만을 구해주는 함수이다.
s=1을 넣게되면 t(i+1)을 출력하고
s=2을 넣게되면 z(i+1)을 출력한다.

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