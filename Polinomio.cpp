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
//atribuição
Polinomio & Polinomio::operator=(const Polinomio &) {

}

//soma
Polinomio Polinomio::operator+(const Polinomio &) const {

}
//adiciona um polinomio a um numero
Polinomio Polinomio::operator+(const double &) const {

}

Polinomio & Polinomio::operator+=(const Polinomio &) {

}
//adiciona um polinomio a um numero
Polinomio & Polinomio::operator+=(const double &) {

}

//Subtraçao
Polinomio Polinomio::operator-(const Polinomio &) const {

}
//subtrai um polinomio a um numero
Polinomio Polinomio::operator-(const double &) const {

}
Polinomio & Polinomio::operator-=(const Polinomio &) {

}
//subtrai um polinomio a um numero
Polinomio & Polinomio::operator-=(const double &) {

}

//Multiplicação
Polinomio Polinomio::operator*(const Polinomio &) const {

}
Polinomio Polinomio::operator*(const double &) const {

}
Polinomio & Polinomio::operator*=(const Polinomio &) {

}
Polinomio & Polinomio::operator*=(const double &) {

}

//Divisao por polinomio de grau 1 da forma (x-a)
Polinomio Polinomio::operator/(const Polinomio &) const {

}

Polinomio & Polinomio::operator/=(const Polinomio &) {

}
//divide por um numero
Polinomio Polinomio::operator/(const int &) const {

}
Polinomio & Polinomio::operator/=(const int &) {

}

//resto da divisao por um polinomio grau 1 da forma (x-1)
Polinomio Polinomio::operator%(const Polinomio &) const {

}
Polinomio & Polinomio::operator%=(const Polinomio &) {

}

//Retorna o i-esimo coeficiente
double Polinomio::operator[](int) const {

}

//incrementos (adicionar 1) ao termo constante
Polinomio Polinomio::operator++() {

}
Polinomio Polinomio::operator++(int) {

}

//Comparação
//igualdade (verifica se dois polinomios tem  o mesmo grau e coeficientes)
bool Polinomio::operator==(const Polinomio &) const {

}

//Entrada e Saída
istream& operator>>(istream &, Polinomio &) {

}
ostream& operator<<(ostream &, const Polinomio &) {

}
//Retorna derivada
Polinomio::Polinomio derivada() const {

}

//Avalia
double Polinomio::avalia(double) const {

}

//Resolve P(x)=0. Encontra raízes reais do polinomio
double Polinomio::resolve(int &) const {

}

