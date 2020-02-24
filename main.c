#include <stdio.h>
#include<math.h>
/*
 * EX1
The following expansion, shown in image (open the following link in a new tab)
https://events.prace-ri.eu/event/845/images/127-pi-series.png, gives an approximation to the exact value of π.
// For example, it is easy to check by hand that for N=1 the result is as shown in equation mage
// (open the following link in a new tab) https://events.prace-ri.eu/event/845/images/126-pi-example.png .
// It can be shown that the approximation continues to become more accurate as N is increased.
Note that you must use double-precision variables for ALL floating-point numbers.
 Write a program in C, C++, Fortran, Java or Python that computes an approximation
 to π using the above formula for the following values
 of N: 1, 2, 10, 50, 100, 500. For each value of N,
 print out the approximate value π(N) and the error err(N).
 The error is the difference between π(N) and the true value of π,
 ie err(N) = π(N) − π. As N increases the value of the error should decrease.

EX2
 We now want to find out the minimum value of N that is
 required to give a value for π(N) that is accurate to some specified value.
 We will call this value Nmin. By computing π(N) for increasing values of N, calculate Nmin such that err(Nmin) < 10−6

 EX3
This way of computing Nmin is clearly inefficient. For example, if we require err(Nmin) < 10−6. and we calculate err(2) = 0.02,
 it is a waste of time to calculate err(3)
 as it is already obvious that Nmin is very much larger than 2!
 Rewrite your program so that is uses a more efficient way to locate the minimum value of N.
 Your new method must produce exactly the same value for Nmin as before but should be faster. For example, you might try
 and reduce the number of times that you have to evaluate err(N). You should also tell us how much faster your new program is.
 */

double computePi(unsigned int N){

    double temp=0.0;
    unsigned int i=1;

    do{
        temp= temp+ (1.0 / ( (double)(N*N)+ (double)(i-0.5)*(i-0.5) ) );
        i++;
    }while(i<=N);

    temp= (temp *(double)(N<<2));

    printf("approx value for %i:  %.56f\n",(int) N, temp);

    return temp;
}


double computeErr_ex1(double N){
    double err=(computePi(N) - M_PI);
    printf("error for %.0f is %.56f\n\n",N,err);
    return err;
}


int serial_ex2(double err){
    int i=1;

    while(computeErr_ex1(i)>err) i++;

    printf("Nmin-> err value for %i:  %.56f\n\n", (int)i, err);

    return 0;
}

int logMode_ex3(double err, unsigned int initial_min,unsigned int initial_max){
    //I'm not checking overflow for mid, should be added
    unsigned int min=initial_min;
    unsigned int max= initial_max;
    unsigned int mid = 0;
    double solution=0.0;

    do{
        mid = (min + max)>>1;

        if ( (solution=computeErr_ex1(mid)) > err) min = mid + 1;
        else max = mid - 1;

    }while (min <= max);

    if (solution < err){
        printf("Nmin-> err value for %i:  %.56f\n\n", (int)mid, solution);
        return mid;
    }
    else return -1;
    //if we don't reach a solution in the range, change it in the call
}

int main() {

    serial_ex2(pow(10,-6));
    logMode_ex3(pow(10,-6),1,500);
    //computePi(289);
    return 0;
}
