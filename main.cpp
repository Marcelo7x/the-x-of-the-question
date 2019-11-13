#include "Polinomio.h"
#include <iostream>
using namespace std;

void funcaoParaTestarConstrutorDeCopia(Polinomio obj){

}

int main(){
    Polinomio obj1;
    obj1.imprime();

    Polinomio obj2(3);
    obj2.imprime();

    unsigned int num = 4;
    double *vertorDeNumeros = new double[4]{0,1,0,0};
    Polinomio obj3(num, vertorDeNumeros);
    obj3.imprime();
    delete[] vertorDeNumeros;

    Polinomio obj4(obj3);
    obj4.imprime();

    obj4 = obj2;
    obj4.imprime();
    funcaoParaTestarConstrutorDeCopia(obj4);

    double *vertorDeNumeros2 = new double[4]{1,2,3,4};
    double *vertorDeNumeros3 = new double[5]{9,8,7,6,5};
    num = 4; Polinomio obj5(num, vertorDeNumeros2);
    num = 5; Polinomio obj6(num, vertorDeNumeros3);
    obj5 = obj5 + obj6;
    obj5.imprime();
    obj5 = obj5 - obj6;
    obj5.imprime();
    delete[] vertorDeNumeros2; delete[] vertorDeNumeros3;

    obj5 = obj5+2.0;
    obj5.imprime();
    
    obj5+= obj6;
    obj5.imprime();

    obj5 = obj5-2.0;
    obj5.imprime();
    
    obj5-= obj6;
    obj5.imprime();
    
    return 0;
}