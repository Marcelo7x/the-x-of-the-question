#include "Polinomio.h"
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

void soma(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar){
    cout << '(' << base << ')' << " + " << '(' << auxiliar << ')' << endl;
    resultado = base + auxiliar;
    cout << "= " << resultado << endl << endl;
    copia += auxiliar;
    cout << "+= " << copia << endl << endl;
}

void subtracao(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar){
    cout << '(' << base << ')' << " - " << '(' << auxiliar << ')' << endl;
    resultado = base - auxiliar;
    cout << "= " << resultado << endl << endl;
    copia = base;
    copia -= auxiliar;
    cout << "-= " << copia << endl << endl;
}

void multiplicacao(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar){
    cout << '(' << base << ')' << " * " << '(' << auxiliar << ')' << endl;
    resultado = base * auxiliar;
    cout << "= " << resultado << endl << endl;
    copia = base;
    copia *= auxiliar;
    cout << "*= " << copia << endl << endl;
}

void divisao(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar, Polinomio &auxiliarDivisao){
    cout << '(' << base << ')' << " / " << '(' << auxiliarDivisao << ')' << endl;
    resultado = base / auxiliarDivisao;
    cout << "= " << resultado << endl << endl;
    copia = base;
    copia /= auxiliarDivisao;
    cout << "/= " << copia << endl << endl;

    cout << '(' << base << ')' << " % " << '(' << auxiliarDivisao << ')' << endl;
    resultado = base % auxiliarDivisao;
    cout << "= " << resultado << endl << endl;
    copia = base;
    copia %= auxiliarDivisao;
    cout << "%= " << copia << endl << endl;
}

void derivada(Polinomio &auxiliar){
    cout << "Derivada(" << auxiliar <<")\n";
    cout << "= " << auxiliar.derivada() << endl << endl;
}

void avalia(Polinomio &auxiliar){
    double x = (rand()%11);
    cout << "Avalia(" << auxiliar << ") p/ x = " << x << endl;
    cout << "= " << auxiliar.avalia(x) << endl << endl;
}

void resolve(Polinomio &auxiliar){
    cout << "Resolve(" << auxiliar << ")\n";
    int numRaizes;
    double *raizes = auxiliar.resolve(numRaizes);
    cout << numRaizes << " raizes\n";
    if (numRaizes > 0)
    {
        cout << "Raizes{";
        for (int i = 0; i < numRaizes; i++)
        {
            if (i == numRaizes-1)
            {
                cout << raizes[i];
                break;
            }
            
            cout << raizes[i] <<", ";
        }
        cout << "}\n\n";
    }
}

void exemplo(){
    srand(time(NULL));

    double *vetor1 = new double[6]{0,1,2,3,4,5};
    Polinomio base(6,vetor1);
    delete[] vetor1;

    int numAleatorio = rand() % 11;
    vetor1 = new double[numAleatorio];
    for (int i = 0; i < numAleatorio; i++)
    {
        vetor1[i] = rand() % 101;
    }
    Polinomio auxiliar(numAleatorio, vetor1);
    delete[] vetor1;

    Polinomio copia(base);
    Polinomio resultado;

    cout << "SOMA\n";
    soma(base, copia, resultado, auxiliar);

    cout << "SUBTRACAO\n";
    subtracao(base, copia, resultado, auxiliar);

    cout << "MULTIPLICACAO\n";
    multiplicacao(base, copia, resultado, auxiliar);

    cout << "DIVISAO\n";
    vetor1 = new double[2]{(double)(-rand()%11),1};
    Polinomio auxiliarDivisao(2,vetor1);
    delete[] vetor1;
    divisao(base, copia, resultado, auxiliar, auxiliarDivisao);

    cout << "DERIVADA\n";
    derivada(auxiliar);

    cout << "AVALIA\n";
    avalia(auxiliar);

    cout << "RESOLVE\n";
    resolve(auxiliar);

    double n = (rand()%11);
    cout << "exemplo de calculo: P(" << n <<"){(++(" << base <<") * 2) - (" << auxiliar << ") * 2) / (" 
    << auxiliarDivisao << ")} + " << "P(" << n <<"){(" << "derivada(" <<auxiliar << ")} - " 
    << "((" << auxiliar << ") % (" << auxiliarDivisao << "))\n";
    
    cout << "= " << ((++base*2) - ((auxiliar*2)/auxiliarDivisao)).avalia(n) 
    + (auxiliar.derivada().avalia(n)) - (auxiliar%auxiliarDivisao).avalia(0);
    cout << endl;

}


int main(int argc, char **argv){
    if (strcmp(argv[1], "exemplo") == 0)//mostra um exemplo das fucionalidades presentes neste progama
    {
       exemplo();
    }   
    

    return 0;
}