#include<stdio.h>
#include<math.h>
#define h 0.001
#define SIZE 200
#define n SIZE*SIZE

double *diff(void) {
    static double diff_data[n];
    double x,y,a,b,c,e,e1,e2,f,f1;
    double p=4.0/SIZE;
	int i,j,k=0;

    for(y=-2.0,i=0; i<SIZE; y+=p,i++){
        for(x=-2.0,j=0; j<SIZE; x+=p,j++){
				//analytic derivative
			a=(exp(-x*x - y*y))*(-2*x-2*y);
			
				//two-point derivative
			b= (exp(-(x+h)*(x+h) - y*y)- exp(-x*x - y*y))/h + (exp(-(y+h)*(y+h) - x*x)- exp(-x*x - y*y))/h;

                //three-point derivative
            c= (exp(-(x+h)*(x+h) - y*y)- exp(-(x-h)*(x-h) - y*y) + exp(-(y+h)*(y+h) - x*x)- exp(-(y-h)*(y-h) - x*x))/(2*h);

				//five-point derivative
			e1= (-exp(-(x+2*h)*(x+2*h) - y*y) + 8*(exp(-(x+h)*(x+h) - y*y)) - 8*(exp(-(x-h)*(x-h) - y*y))+ exp(-(x-2*h)*(x-2*h) - y*y))/(12*h);
			e2= (-exp(-(y+2*h)*(y+2*h) - x*x) + 8*(exp(-(y+h)*(y+h) - x*x)) - 8*(exp(-(y-h)*(y-h) - x*x))+ exp(-(y-2*h)*(y-2*h) - x*x))/(12*h);
			e=e2+e1;


            //f=fabs(c-a);
			//f1=fabs(e-a);

			diff_data[k]=fabs(a-b);

            //printf("%lf\n",a);
            k++;
        }
        //printf("\n");
    }
    // Populate diff_data
    return diff_data;
}
