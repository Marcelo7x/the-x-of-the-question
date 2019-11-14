#include "Polinomio.h"
#include <iostream>
using namespace std;

void funcaoParaTestarConstrutorDeCopia(Polinomio obj){

}

int main(){
    Polinomio obj1;
    cout << obj1<< endl;;

    Polinomio obj2(3);
    cout << obj2<< endl;;

    unsigned int num = 4;
    double *vertorDeNumeros = new double[4]{0,1,0,0};
    Polinomio obj3(num, vertorDeNumeros);
    cout << obj3 << endl;
    delete[] vertorDeNumeros;

    Polinomio obj4(obj3);
    cout << obj4<< endl;;

    obj4 = obj2;
    cout << obj4<< endl;;
    funcaoParaTestarConstrutorDeCopia(obj4);

    double *vertorDeNumeros2 = new double[4]{1,2,3,4};
    double *vertorDeNumeros3 = new double[5]{9,8,7,6,5};
    num = 4; Polinomio obj5(num, vertorDeNumeros2);
    num = 5; Polinomio obj6(num, vertorDeNumeros3);
    obj5 = obj5 + obj6;
    cout << obj5<< endl;
    obj5 = obj5 - obj6;
    cout << obj5<< endl;;
    delete[] vertorDeNumeros2; delete[] vertorDeNumeros3;

    obj5 = obj5+2.0;
    cout << obj5<< endl;;
    
    obj5+= obj6;
    cout << obj5<< endl;;

    obj5 = obj5-2.0;
    cout << obj5<< endl;;
    
    obj5-= obj6;
    cout << obj5<< endl;;

    double *vertorDeNumeros4 = new double[2]{1,2,};
    double *vertorDeNumeros5 = new double[3]{3,4,4};
    num = 2; Polinomio obj7(num, vertorDeNumeros4);
    num = 3; Polinomio obj8(num, vertorDeNumeros5);
    Polinomio obj9 = obj7 * obj8;
    cout << obj9<< endl;;
    delete[] vertorDeNumeros4;
    delete[] vertorDeNumeros5;

    obj9 = obj7 * 3;
    cout << obj9<< endl;;
    obj7 *= obj8;
    cout << obj7<< endl;;
    
    obj7 /= 2;
    cout << obj7 << endl;
    obj9 = obj7 / 3;
    cout << obj9;
    
    cout << endl;
    
    return 0;
}