#include <bits/stdc++.h>
using namespace std;

double eps =  1e-4;

typedef struct quad
{
	double A;
	double P;
} quad;

double dist( double xa, double xb, double ya, double yb )
{
	return sqrt((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb));
}

double area( double x1, double x2, double xp, double y1, double y2, double yp )
{
	double ans = fabs(x1*y2 + x2*yp + xp*y1 - x2*y1 - xp*y2 - x1*yp)/2.0;
	return ans; 
}

bool cmp( quad a, quad b )
{	
	if ( fabs(a.A - b.A) > eps )
		return (a.A > b.A);
	return a.P > b.P;
}

int main()
{
	double x[4], y[4];
	quad q[4];
	do {
		int zero = 0;
		for ( int i = 0; i < 4; i++ ) {
			scanf("%lf %lf", &x[i], &y[i]);
			if ( x[i] == 0.0 && y[i] == 0.0 )
				zero++;
		}
		if ( zero == 4 ) break;
		// calcular ponto P
		double m0,m1,n0,n1,xp,yp;
		if ( x[0] != x[2] && x[1] != x[3] ) {
			m0 = (y[0]-y[2])/(x[0]-x[2]);
			m1 = (y[1]-y[3])/(x[1]-x[3]);
			n0 = y[0] - m0*x[0];
			n1 = y[3] - m1*x[3];
			xp = (n0-n1)/(m1-m0);
			yp = m0*xp + n0;
		}
		else if ( x[0] == x[2] ) {
			m1 = (y[1]-y[3])/(x[1]-x[3]);	
			n1 = y[3] - m1*x[3];
			xp = x[0];
			yp = m1*xp + n1;
		}
		else {
			m0 = (y[0]-y[2])/(x[0]-x[2]);
			n0 = y[0] - m0*x[0];
			xp = x[3];
			yp = m0*xp + n0;
		}
		for ( int i = 0; i < 4; i++ ) {
			q[i].P = dist(x[i],x[(i+1)%4],y[i],y[(i+1)%4]);
			q[i].P += dist(x[i],xp,y[i],yp);
			q[i].P += dist(x[(i+1)%4],xp,y[(i+1)%4],yp);
			q[i].A = area(x[i],x[(i+1)%4],xp,y[i],y[(i+1)%4],yp);
		}
		
		sort(q,q+4,cmp); 
		for ( int i = 0; i < 4; i++ ) {
			printf("%.3lf %.3lf", q[i].A, q[i].P);
			if ( i != 3 )
				printf(" ");
		}
		printf("\n");
	} while(1);
	return 0;
}
