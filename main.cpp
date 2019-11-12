#include "Polinomio.h"
#include <iostream>
using namespace std;

int main(){
    Polinomio obj1;
    obj1.imprime();
    Polinomio obj2(3);
    obj2.imprime();
    unsigned int num = 4;
    double *vertorDeNumeros = new double[num]{0,0,0,0};
    Polinomio obj3(num, vertorDeNumeros);
    obj3.imprime();
    delete[] vertorDeNumeros;

    return 0;
}