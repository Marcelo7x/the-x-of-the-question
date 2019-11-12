#include "Polinomio.h"
#include <iostream>
using namespace std;

//Construtor padrão. Representa numero 0
Polinomio::Polinomio() {
    x = new double[1];
    x = 0;
}

//Cria um polinomio a partir de um numero inteiro (positivo ou negativo)
Polinomio::Polinomio(const int n) {
    x = new double[1];
    *x = n;
}

//Cria um polinomio a partir de um vetor de coeficientes. Os coeficientes deverão ser o do polinomio (Posicao 0 sera a_0, posicao 1 sera a_1, ...). O primeiro parametro representa o grau do polinomio.
Polinomio::Polinomio(unsigned int n, double *a) {
    x = new double[1];
    for (int i = 0; i < n; i++)
    {
        x[i] = i;
    }
}

//Construtor de cópia
Polinomio::Polinomio(const Polinomio &poli) {

}

//Destrutor
Polinomio::~Polinomio() {
    delete[] x;
}

//OPERADORES

