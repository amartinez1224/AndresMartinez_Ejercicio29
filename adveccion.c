#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include<omp.h>


double cuerda(double n){
    double l = 64;
    double dx = 0.5;
    int tam = (int)(l/dx);
    int evoluciones = 1000000;
    double dt = n/evoluciones;
    double ini[tam+1];
    double ini1[tam+1];
    double ini2[tam+1];
    double pos[tam+1];
    double c = 250;
    double con = (c*c*dt*dt)/(dx*dx);
    double T;
    int r = 0;
    
    for(int i=0; i<tam+1; i++){
        pos[i]=0;
        ini[i]=0;
    }
    
    for(int i=1; i<tam; i++){
        ini1[i]=ini[i]+((con/2)*(ini[i+1]-(2*ini[i])+ini[i-1]));
    }
    
    ini[0]=0;
    ini[tam]=0;
    ini1[0]=0;
    ini1[tam]=0;
    ini2[0]=0;
    ini2[tam]=0;
    
    
    for(int k=0; k<evoluciones-2; k++){
        for(int i=1; i<tam; i++){
            ini2[i]=(con*(ini1[i+1]-(2*ini1[i])+ini1[i-1]))+(2*ini1[i]-ini[i]);
        }
        for(int i=1; i<tam; i++){
            ini[i]=ini1[i];
            ini1[i]=ini2[i];
            if(r<1&&ini[i]<0.0001&&ini[i]>-0.0001){
                T=i*dt;
                r=2;
            }
        }
    }
    return T;
}
int main(int argc, char ** argv)
{
    #pragma omp parallel
    {
    cuerda(5);
    }
    return 0;
}
