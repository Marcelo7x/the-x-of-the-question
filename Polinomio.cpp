#include "Polinomio.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Construtor padrão. Representa numero 0
Polinomio::Polinomio() {
    n = 1;
    x = (double*) malloc(sizeof(double)*n);
    x[0] = 0;
}

//Cria um polinomio a partir de um numero inteiro (positivo ou negativo)
Polinomio::Polinomio(const int num) {
    this->n = 2;
    x = (double*) malloc(sizeof(double)*n);
    x[0] = 0;
    x[1] = num;
}

//Cria um polinomio a partir de um vetor de coeficientes. Os coeficientes deverão ser o do polinomio (Posicao 0 sera a_0, posicao 1 sera a_1, ...). O primeiro parametro representa o grau do polinomio.
Polinomio::Polinomio(unsigned int num, double *a) {
    x = (double*) malloc(sizeof(double)*num);
    for (int i = 0; i < num; i++)
    {
        x[i] = a[i];
    }
    this->n = num;
}

//Construtor de cópia
Polinomio::Polinomio(const Polinomio &poli) { 
    x = (double*) malloc(sizeof(double)*(poli.n));
    
    for (int i = 0; i < poli.n; i++)
    {
        x[i] = poli.x[i];
    }

    n = poli.n;
}

//Destrutor
Polinomio::~Polinomio() {
    free(x);
}

//OPERADORES
//atribuição
Polinomio & Polinomio::operator=(const Polinomio &obj) {
    if(this == &obj)
        return *this;
    
    n = obj.n;
    free(x);
    x = (double*) malloc(sizeof(double)*n);
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
    }
    else
    {
        maior = this;
        menor = &obj;
    }
    Polinomio objSoma(*maior);

    for (int i = 0; i < menor->n; i++)
    {
        objSoma.x[i] = x[i] + obj.x[i];
    }
    
    return objSoma;
}

//adiciona um polinomio a um numero
Polinomio Polinomio::operator+(const double &num) const {
    Polinomio objSomaConstante(*this);
    objSomaConstante.x[0]+= num;
    
    return objSomaConstante;
}

Polinomio & Polinomio::operator+=(const Polinomio &obj) {
    Polinomio const *menor;
    Polinomio const *maior;
    if (n <= obj.n)
    {
        menor = this;
        maior = &obj;
        x = (double*) realloc(x, sizeof(double)*(maior->n));
    }
    else
    {
        maior = this;
        menor = &obj;
    }

    for (int i = 0; i < menor->n; i++)
    {
        x[i] += obj.x[i];
    }


}
//adiciona um polinomio a um numero
Polinomio & Polinomio::operator+=(const double &num) {
    x[0] += num;
}

//Subtraçao
Polinomio Polinomio::operator-(const Polinomio &obj) const {
    Polinomio const *menor;
    Polinomio const *maior;
    if (n <= obj.n)
    {
        menor = this;
        maior = &obj;
    }
    else
    {
        maior = this;
        menor = &obj;
    }
    Polinomio objSubtracao(*maior);

    for (int i = 0; i < menor->n; i++)
    {
        objSubtracao.x[i] = x[i] - obj.x[i];
    }
    
    return objSubtracao;
}
//subtrai um polinomio a um numero
Polinomio Polinomio::operator-(const double &num) const {
    Polinomio objSubtracaoConstante(*this);
    objSubtracaoConstante.x[0] -= num;
    
    return objSubtracaoConstante;
}

Polinomio & Polinomio::operator-=(const Polinomio &obj) {
    Polinomio const *menor;
    Polinomio const *maior;
    if (n <= obj.n)
    {
        menor = this;
        maior = &obj;
        x = (double*) realloc(x, sizeof(double)*(maior->n));
    }
    else
    {
        maior = this;
        menor = &obj;
    }

    for (int i = 0; i < menor->n; i++)
    {
        x[i] -= obj.x[i];
    }   
}
//subtrai um polinomio a um numero
Polinomio & Polinomio::operator-=(const double &num) {
    x[0] -= num;
}

//Multiplicação
Polinomio Polinomio::operator*(const Polinomio &obj) const {
    double *vetorAux = (double*) calloc((obj.n + this->n),sizeof(double));
    Polinomio objMultiplicacao((obj.n + this->n), vetorAux);
    free(vetorAux);

    for (int i = 0; i < this->n; i++)
    {
       for (int j = 0; j < obj.n ; j++)
       {
           objMultiplicacao.x[i+j] += x[i] * obj.x[j];
       }
    }
    
    return objMultiplicacao;
}
Polinomio Polinomio::operator*(const double &num) const {
    Polinomio objMultiplicacao(*this);

    for (int i = 0; i < n; i++)
    {
        objMultiplicacao.x[i] *= num;
    }

    return objMultiplicacao;
}
Polinomio & Polinomio::operator*=(const Polinomio &obj) {
    double *vetorAux = (double*) calloc((obj.n + this->n),sizeof(double));
    Polinomio objaux((obj.n + this->n), vetorAux);
    free(vetorAux);

    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < obj.n ; j++)
       {
           objaux.x[i+j] += x[i] * (obj.x[j]);
       }
    }
    (*this) = objaux;
}
Polinomio & Polinomio::operator*=(const double &num) {
    for (int i = 0; i < n; i++)
    {
        x[i] *= num;
    }
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
        if (x[i] == 0)
        {
            continue;
        }
        
        cout << x[i] << "x^" << i << " + ";
    }
    cout << endl;
    
}

