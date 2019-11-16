#include "Polinomio.h"
#include <iostream>
using namespace std;

void funcaoParaTestarConstrutorDeCopia(Polinomio obj){

}

int main(){
    cout << "teste construtor 1" <<endl;
    Polinomio obj1;
    cout << obj1<< endl;;

    cout << "teste construtor 2" <<endl;
    Polinomio obj2(3);
    cout << obj2<< endl;;

    cout << "teste construtor 3" <<endl;
    unsigned int num = 4;
    double *vertorDeNumeros = new double[4]{0,1,0,0};
    Polinomio obj3(num, vertorDeNumeros);
    cout << obj3 << endl;
    delete[] vertorDeNumeros;

    cout << "teste construtor de copia" <<endl;
    Polinomio obj4(obj3);
    cout << obj4<< endl;;

    cout << "teste atribuicao" <<endl;
    obj4 = obj2;
    cout << obj4 << endl;;
   
    cout << "teste construtor de copia" <<endl;
    funcaoParaTestarConstrutorDeCopia(obj4);

    cout << "teste soma e subtracao" <<endl;
    double *vertorDeNumeros2 = new double[4]{1,2,3,4};
    double *vertorDeNumeros3 = new double[5]{9,8,7,6,5};
    num = 4; Polinomio obj5(num, vertorDeNumeros2);
    num = 5; Polinomio obj6(num, vertorDeNumeros3);
    obj5 = obj5 + obj6;
    cout << obj5<< endl;
    obj5 = obj5 - obj6;
    cout << obj5<< endl;;
    delete[] vertorDeNumeros2; delete[] vertorDeNumeros3;

    cout << "teste somar constante" <<endl;
    obj5 = obj5+2.0;
    cout << obj5<< endl;;
    
    cout << "teste +=" <<endl;
    obj5+= obj6;
    cout << obj5<< endl;;

    cout << "teste subtrair constante" <<endl;
    obj5 = obj5-2.0;
    cout << obj5<< endl;;
    
    cout << "teste -=" <<endl;
    obj5-= obj6;
    cout << obj5<< endl;;

    cout << "teste multiplicacao" <<endl;
    double *vertorDeNumeros4 = new double[2]{1,2};
    double *vertorDeNumeros5 = new double[3]{3,4,4};
    num = 2; Polinomio obj7(num, vertorDeNumeros4);
    num = 3; Polinomio obj8(num, vertorDeNumeros5);
    Polinomio obj9 = obj7 * obj8;
    cout << obj9 << endl;;
    delete[] vertorDeNumeros4;
    delete[] vertorDeNumeros5;

    cout << "teste multiplicar constante" <<endl;
    obj9 = obj7 * 3;
    cout << obj9<< endl;;
    
    cout << "teste *=" <<endl;
    obj7 *= obj8;
    cout << obj7<< endl;

    cout << "teste *= constante" <<endl;
    obj7 *= 3;
    cout << obj7<< endl;;
    
    cout << "teste /= constatante" <<endl;
    obj7 /= 2;
    cout << obj7 << endl;
    
    cout << "teste dividir constante" <<endl;
    obj9 = obj9 / 3;
    cout << obj9 << endl;

    cout << "teste ++" <<endl;
    for (int i = 0; i < 2; i++)
    {
        ++obj9;
        cout << i << " , " << obj9 << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << i << " , " << obj9++ << endl;
    }
    cout << obj9 << endl;

    cout << "teste divisao" <<endl;
    vertorDeNumeros4 = new double[2]{-2,1};
    num = 2; Polinomio obj10(num, vertorDeNumeros4);
    cout << obj10 << " obj10\n";
    vertorDeNumeros5 = new double[6]{1,0,3,0,-2,3};
    num = 6; Polinomio obj11(num, vertorDeNumeros5);
    cout << obj11 << " obj11\n";
    obj11 = obj11 / obj10;
    cout << obj11 << " obj11/obj10\n";
    delete[]vertorDeNumeros4; delete[] vertorDeNumeros5;

    cout << "teste divisao" <<endl;
    vertorDeNumeros4 = new double[2]{-2,1};
    num = 2; Polinomio obj12(num, vertorDeNumeros4);
    cout << obj12 << " obj12\n";
    vertorDeNumeros5 = new double[4]{-1,3,-2,5};
    num = 4; Polinomio obj13(num, vertorDeNumeros5);
    cout << obj13 << " obj13\n";
    Polinomio obj14 = obj13 / obj12;
    cout << obj14 << " obj13/obj12\n";
    delete[]vertorDeNumeros4; delete[] vertorDeNumeros5;

    cout << "teste /=" <<endl;
    obj14 = obj13;
    obj14 /= obj12;
    cout << obj14 << endl;

    cout << "teste resto divisao" <<endl;
    cout << obj13 % obj12 << endl;

    cout << "teste %=" <<endl;
    obj14 = obj13;
    obj14 %= obj12;
    cout << obj14 << endl;

    cout << "teste []" <<endl;
    cout << obj13[2] << endl;
    
    cout << endl;

    vertorDeNumeros = new double[6]{1,-3,7,5,-2,3}; num = 6;
    Polinomio obj15(num, vertorDeNumeros);
    cout << obj15 << endl;
    cout << obj15.avalia(4) << endl;


    return 0;
}