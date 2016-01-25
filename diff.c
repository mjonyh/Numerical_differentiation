


/*****************************************************************************************************************************************
 *   FILE: diff.c																														 *
 *   DESCRIPTION:																														 *
 *   This is a code for numerical differetiation .The code that is built for differentiating gaussian surface equation of e^-(x^2        *
 *   +y^2) .Calculation of this code is in c .For running this code please read "How_to".  												 *
 *   Numerical_differentiation - C library code.                                                                                         *
 *   AUTHOR: Shafayet Islam , Sakibul Islam & Md.Enamul Haque                                                                            *
 *   Uploaded in : 01/26/16                                              																 *
 *****************************************************************************************************************************************/ 

/*****************************************************************************************************************************************
 *	                                                  GNU GENERAL PUBLIC LICENSE														 *
 *                                                      Version 3, 29 June 2007															 *
 *																																		 *
 *                                      Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>                              *
 *                                      Everyone is permitted to copy and distribute verbatim copies license							 *
 *                                      document, but changing it is not allowed.														 *
 *****************************************************************************************************************************************/


#include<stdio.h>
#include<math.h>
#define h 0.001
#define SIZE 200
#define n SIZE*SIZE

double *diff(void) {
    static double diff_data[n];
    double x,y,a,b,c,e,e1,e2,f,f1,f2,l2,l3,l5;
    /*This part below is for indexing and resizing.For resizing change value of "SIZE" */
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

			/* ERROR section */

			l2= fabs(-(0.5*h)*4*(exp(-x*x-y*y))*((x+y)*(x+y)-1)); //two-point error

			l3= fabs(-(1/6)*h*h*(-8)*(exp(-x*x-y*y))*((x+y)*(x+y)*(x+y)-3*(x+y))); //three-point error

			l5= fabs(-(1/30)*h*h*h*h*(-32)*(exp(-x*x-y*y))*((x+y)*(x+y)*(x+y)*(x+y)*(x+y)-10*(x+y)*(x+y)*(x+y)+15*(x+y))); //five-point error



/*This part is for evaluating difference graph among two point, three point, analytic and five point derivative error */

            //f=fabs(b-a);
           //f1=fabs(b-a);
		   //f2=fabs(e-a);

			diff_data[k]=fabs(l3);//for finding difference (value can be changeable)

            //printf("%lf\n",a);
            k++;
        }
        //printf("\n");
    }
    // Populate diff_data
    return diff_data;
}
