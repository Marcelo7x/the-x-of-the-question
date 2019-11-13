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
    double *vertorDeNumeros = new double[num]{0,1,0,0};
    Polinomio obj3(num, vertorDeNumeros);
    obj3.imprime();
    cout << endl;
    Polinomio obj4(obj3);
    obj4.imprime();
    obj4 = obj2;
    obj4.imprime();
    funcaoParaTestarConstrutorDeCopia(obj4);


    delete[] vertorDeNumeros;
    return 0;
}