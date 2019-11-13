#include "Polinomio.h"
#include <iostream>
using namespace std;

//Construtor padrão. Representa numero 0
Polinomio::Polinomio() {
    n = 1;
    x = new double[n];
    x[0] = 0;
}

//Cria um polinomio a partir de um numero inteiro (positivo ou negativo)
Polinomio::Polinomio(const int num) {
    this->n = 1;
    x = new double[n];
    x[0] = num;
}

//Cria um polinomio a partir de um vetor de coeficientes. Os coeficientes deverão ser o do polinomio (Posicao 0 sera a_0, posicao 1 sera a_1, ...). O primeiro parametro representa o grau do polinomio.
Polinomio::Polinomio(unsigned int num, double *a) {
    x = new double[num];
    for (int i = 0; i < num; i++)
    {
        x[i] = a[i];
    }
    this->n = num;
}

//Construtor de cópia
Polinomio::Polinomio(const Polinomio &poli) { 
    x = new double[poli.n];
    
    for (int i = 0; i < poli.n; i++)
    {
        x[i] = poli.x[i];
    }

    n = poli.n;
}

//Destrutor
Polinomio::~Polinomio() {
    delete[] x;
}

//OPERADORES
//atribuição
Polinomio & Polinomio::operator=(const Polinomio &obj) {
    if(this == &obj)
        return *this;
    
    n = obj.n;
    delete[] x;
    x = new double[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = obj.x[i];
    }
    
    return *this;
}

//soma
Polinomio Polinomio::operator+(const Polinomio &obj) const {
    Polinomio const *menor;
    Polinomio const *maior;
    if (n <= obj.n)
    {
        menor = this;
        maior = &obj;
        //Polinomio objSoma(objSoma);
    }
    else
    {
        maior = this;
        menor = &obj;
        //Polinomio objSoma(*this);
    }
    Polinomio objSoma(*maior);

    for (int i = 0; i < menor->n; i++)
    {
        objSoma.x[i] = x[i] + obj.x[i];
    }
    
    return objSoma;
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
Polinomio Polinomio::derivada() const {

}

//Avalia
double Polinomio::avalia(double) const {

}

//Resolve P(x)=0. Encontra raízes reais do polinomio
double* Polinomio::resolve(int &) const {

}

void Polinomio::imprime(){
    for (int i = 0; i < n; i++)
    { 
        cout << x[i] << " ";
    }
    cout << endl;
    
}

