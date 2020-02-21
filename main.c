#include <stdio.h>
#include<math.h>


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


double computeErr(double N){
    double err=(computePi(N) - M_PI);
    printf("error for %.0f is %.56f\n\n",N,err);
    return err;
}


int serial(double err){
    int i=1;

    while(computeErr(i)>err) i++;

    printf("Nmin-> err value for %i:  %.56f\n\n", (int)i, err);

    return 0;
}

int logMode(double err, unsigned int initial_min,unsigned int initial_max){
    //I'm not checking overflow for mid, should be added
    unsigned int min=initial_min;
    unsigned int max= initial_max;
    unsigned int mid = 0;
    double solution=0.0;

    do{
        mid = (min + max)>>1;

        if ( (solution=computeErr(mid)) > err) min = mid + 1;
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

    serial(pow(10,-6));
    logMode(pow(10,-6),1,500);
    //computePi(289);
    return 0;
}
