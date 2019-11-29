#include "Polinomio.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

using namespace std;
class erroDivisao{};
class erroPosicaoInvalida{};

//notacao potencia "^" ... exemplo: x^2 (x elevado a 2) 

//Construtor padrão. Representa numero 0
Polinomio::Polinomio() {//Aloca 1 posicao, colooca o valor 0
    n = 1;
    x = (double*) malloc(sizeof(double)*n);
    x[0] = 0;
}

//Cria um polinomio a partir de um numero inteiro (positivo ou negativo)
Polinomio::Polinomio(const int num) {//Aloca um vetor de 2 posicoes, cada o numero da posicao idica o grau
    this->n = 2;                            //do polinomio, exemplo: x[3] = 2 equivale as 2x^3
    x = (double*) malloc(sizeof(double)*n);
    x[0] = 0;
    x[1] = num;     //polinomio formado por 0x^0 (primeira posicao do vetor) e ax^1;
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
Polinomio::Polinomio(const Polinomio &obj) { 
    x = (double*) malloc(sizeof(double)*(obj.n));
    
    for (int i = 0; i < obj.n; i++) // copia os polinomio do objeto
    {
        x[i] = obj.x[i];
    }

    n = obj.n;
}

//Destrutor
Polinomio::~Polinomio() {
    free(x);    //desaloca o vetor "x" dos polinomios que foi alocado dinamicamente 
}

//OPERADORES
//atribuição
Polinomio & Polinomio::operator=(const Polinomio &obj) {
    if(this == &obj)    //verifica se e o mesmo objeto
        return *this;
    
    n = obj.n;  //copia o tamanho do vetor dos coeficientes

    free(x);    //desaloca o vetor dos polinomios do objeto que seja modificado
    x = (double*) malloc(sizeof(double)*n); //aloca o vetor, agora com o novo tamanho
    
    for (int i = 0; i < n; i++) //copia os dados
    {
        x[i] = obj.x[i];
    }
    
    return *this;
}

//soma
Polinomio Polinomio::operator+(const Polinomio &obj) const {
    Polinomio const *menor;
    Polinomio const *maior;
    if (n <= obj.n)         //verifica o tamanho do maior vetor de polinomio
    {
        menor = this;
        maior = &obj;
    }
    else
    {
        maior = this;
        menor = &obj;
    }
    Polinomio objSoma(*maior);  //objeto auxiliar 

    for (int i = 0; i < menor->n; i++)  //soma os polinomios semelhantes
    {
        objSoma.x[i] = x[i] + obj.x[i];
    }
    
    return objSoma;
}

//adiciona um polinomio a um numero
Polinomio Polinomio::operator+(const double &num) const {
    Polinomio objSomaConstante(*this);
    objSomaConstante.x[0]+= num;    //soma o elemento a posicao 0, onde esta o termo independente
    
    return objSomaConstante;
}
Polinomio operator+(double num, const Polinomio &obj){
    return obj+num;
}

Polinomio & Polinomio::operator+=(const Polinomio &obj) {
    Polinomio const *menor;
    Polinomio const *maior;

    if (n <= obj.n) //verifica o tamanho do maior vetor de polinomios
    {
        menor = this;
        maior = &obj;
        x = (double*) realloc(x, sizeof(double)*(maior->n));    //iguala o tamanho do vetor a ser modificado ao outro vetor
        for (int i = menor->n; i < maior->n; i++)//copia os polinomios cujo nao ha termos semelhantes
        {
            x[i] = obj.x[i];
        }
    }                                                           //caso ele for menor
    else
    {
        maior = this;
        menor = &obj;
    }

    for (int i = 0; i < menor->n; i++)//soma os polinomios semelhantes
    {
        x[i] += obj.x[i];
    }

    n = maior->n;

    return *this;
}
//adiciona um polinomio a um numero
Polinomio & Polinomio::operator+=(const double &num) {
    x[0] += num;    //soma a posicao 0 onde esta a constante
    return *this;
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
Polinomio operator-(double num, const Polinomio &obj){
    return obj-num;
}

Polinomio & Polinomio::operator-=(const Polinomio &obj) {
    Polinomio const *menor;
    Polinomio const *maior;
    if (n <= obj.n)
    {
        menor = this;
        maior = &obj;
        x = (double*) realloc(x, sizeof(double)*(maior->n));
        for (int i = menor->n; i < maior->n; i++)//copia os polinomios cujo nao ha termos semelhantes
        {
            x[i] = obj.x[i];
        }
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
    
    n = maior->n;
    
    return *this; 
}
//subtrai um polinomio a um numero
Polinomio & Polinomio::operator-=(const double &num) {
    x[0] -= num;
    
    return *this;
}

//Multiplicação
Polinomio Polinomio::operator*(const Polinomio &obj) const {
    double *vetorAux = (double*) calloc((obj.n + this->n),sizeof(double));  //vetor auxiliar com o tamanho dos vetores
    Polinomio objMultiplicacao((obj.n + this->n), vetorAux);                //dos objetos somados
    free(vetorAux);

    for (int i = 0; i < this->n; i++)   //multiplica os polinomios, distributividade
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

    for (int i = 0; i < n; i++) //multiplica todos polinomios pela constante
    {
        objMultiplicacao.x[i] *= num;
    }

    return objMultiplicacao;
}
Polinomio operator*(double num, const Polinomio &obj){
    return obj*num;
}
Polinomio & Polinomio::operator*=(const Polinomio &obj) {
    double *vetorAux = (double*) calloc((obj.n + this->n),sizeof(double));//vetor auxiliar para criacao do objeto auxiliar
    Polinomio objaux((obj.n + this->n), vetorAux);
    free(vetorAux);

    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < obj.n ; j++)
       {
           objaux.x[i+j] += x[i] * (obj.x[j]);//distributividade
       }
    }
    (*this) = objaux;//copiar os resultados para o objeto a ser modificado

    return *this;
}
Polinomio & Polinomio::operator*=(const double &num) {
    for (int i = 0; i < n; i++)//multiplica todos os polinomios pela constante 
    {
        x[i] *= num;
    }
    return *this;
}

//Divisao por polinomio de grau 1 da forma (x-a) 
Polinomio Polinomio::operator/(const Polinomio &obj) const {///////PRECISA DE UMA EXCESSAO AKI
    if(obj.n!=2 || this->n<2)
        throw erroDivisao();
        
    Polinomio objDivisao(*this);
    free(objDivisao.x);
    objDivisao.x = (double*) calloc(n-1, sizeof(double)); //cria um obj de tamanho n-1 
    objDivisao.n = n-1;
        
    for (int i = objDivisao.n-1; i >= 0; i--)//aplica Briot-Ruffini
    {
        if (i == objDivisao.n-1)
        {
            objDivisao.x[i] = x[n-1];
        }
        else
        {
            objDivisao.x[i] = (-(obj.x[0]) * objDivisao.x[i+1]) + x[i+1];
        } 
    }
    return objDivisao;
}

Polinomio & Polinomio::operator/=(const Polinomio &obj) {//PRECISA DE EXCESSAO
    Polinomio objDivisao(*this);
    free(objDivisao.x);
    objDivisao.x = (double*) calloc(n-1, sizeof(double));
    objDivisao.n = n-1;
    
    if(obj.n!=2 || this->n<2)
        throw erroDivisao();
    
    for (int i = objDivisao.n-1; i >= 0; i--)
    {
        if (i == objDivisao.n-1)
        {
            objDivisao.x[i] = x[n-1];
        }
        else
        {
            objDivisao.x[i] = (-(obj.x[0]) * objDivisao.x[i+1]) + x[i+1];
        } 
    }
    *this = objDivisao;

    return *this;
}
//divide por um numero
Polinomio Polinomio::operator/(const int &num) const {//PRECISA DE EXCESSAO
    Polinomio objDivisao(*this);
    
    if(num==0)
        throw erroDivisao();

    for (int i = 0; i < n; i++)//divide todos polinomios pela constante
    {
        objDivisao.x[i] /= num;
    }

    return objDivisao;
}
Polinomio operator/(double num, const Polinomio &obj){//EXCESSAO
    if (obj.n == 1)
    {
       Polinomio aux(num/obj.x[0]);
        return aux;
    }
    else
    {
        Polinomio aux;
        return aux;
    }
}
Polinomio & Polinomio::operator/=(const int &num) {//PRECISA DE EXCESSAO

    if(num==0)
        throw erroDivisao();
        
    for (int i = 0; i < n; i++)
    {
        x[i] /= num;
    }
    return *this;
}

//resto da divisao por um polinomio grau 1 da forma (x-1)
Polinomio Polinomio::operator%(const Polinomio &obj) const {////////PRECISA DE UM EXCESSAO AKI
    Polinomio objDivisao(*this);
    free(objDivisao.x);
    objDivisao.x = (double*) calloc(n-1, sizeof(double));
    objDivisao.n = n-1;
    
    if(obj.n!=2 || this->n<2)
        throw erroDivisao();
    
    for (int i = objDivisao.n-1; i >= 0; i--)//Briot-Ruffini
    {
        if (i == objDivisao.n-1)
        {
            objDivisao.x[i] = x[n-1];
        }
        else
        {
            objDivisao.x[i] = (-(obj.x[0]) * objDivisao.x[i+1]) + x[i+1];
        } 
    }
    
    objDivisao.x[0] = (-(obj.x[0]) * objDivisao.x[0]) + x[0];//Briot-Ruffini uma vez mais para achar o resto
    objDivisao.x = (double*) realloc(objDivisao.x, sizeof(double));//realoca para o tamanho necessario para uma constante
    objDivisao.n = 1;
    
    return objDivisao;
}

Polinomio & Polinomio::operator%=(const Polinomio &obj) {////////PRECISA DE UMA EXCESSAO AKI
    Polinomio objDivisao(*this);
    free(objDivisao.x);
    objDivisao.x = (double*) calloc(n-1, sizeof(double));
    objDivisao.n = n-1;
    if(obj.n!=2 || this->n<2)
        throw erroDivisao();
        
    for (int i = objDivisao.n-1; i >= 0; i--)
    {
        if (i == objDivisao.n-1)
        {
            objDivisao.x[i] = x[n-1];
        }
        else
        {
            objDivisao.x[i] = (-(obj.x[0]) * objDivisao.x[i+1]) + x[i+1];
        } 
    }
    
    objDivisao.x[0] = (-(obj.x[0]) * objDivisao.x[0]) + x[0];
    objDivisao.x = (double*) realloc(objDivisao.x, sizeof(double));
    objDivisao.n = 1;
    
    *this = objDivisao;
    
    return *this;
}

//Retorna o i-esimo coeficiente
double Polinomio::operator[](int num) const {//////////PRECISA DE UMA EXCECAO AKI
    if(num<0 || num > n-1)
        throw erroPosicaoInvalida();
    return x[num];
}

//incrementos (adicionar 1) ao termo constante
Polinomio Polinomio::operator++() { // ++ prefixado
    x[0] += 1;
    return *this;
}
Polinomio Polinomio::operator++(int) { //++ pos fixado 
    Polinomio obj(*this);
    x[0] += 1;
    
    return obj;
}

//Comparação
//igualdade (verifica se dois polinomios tem  o mesmo grau e coeficientes)
bool Polinomio::operator==(const Polinomio &obj) const {
    if(n != obj.n) return false;
    const double EPSILON = 1e-15;

    for (int i = 0; i < n; i++)
    {
        if ((x[i]-obj.x[i]) <= EPSILON)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

//Entrada e Saída
istream& operator>>(istream &is, Polinomio &obj) {
   for (int i = obj.n-1; i >= 0; i--)
   {
       is >> obj.x[i];
   }
   
   return is;
}

ostream& operator<<(ostream &os, const Polinomio &obj) {
    bool sinal = false;//para verificar se pode imprimir um sinal
    
    for (int i = obj.n-1; i >= 0; i--)
    { 
        if(sinal && obj.x[i] > 0)//verifica se imprimu algum polinomio, em caso afirmativo imprime o sinal 
        {                        //que acompanha o polinomio
            os << " + ";
        }
        if (obj.x[i] < 0)
        {
            os << " - ";
        }
       
        if (i == 0)
        {
            if (obj.x[i] < 0)
            {
                os << obj.x[i] * (-1);//troca o sinal de numeros negativos pois os sinais sao impressos 
            }                         //independentemente
            else if(obj.x[i] > 0)
            {
                os << obj.x[i];
            }
            else
            {
                continue;
            }
        }
        else if (i == obj.n-1)
        {
            if (obj.x[i] < 0)
            {
                os << obj.x[i] * (-1) << "x^" << i;
            }
            else if (obj.x[i] == 0)
            {
                continue;
            }
            else
            {
                os << obj.x[i] << "x^" << i;
            }
        }
        else if (obj.x[i] == 0)
        {
            continue;
        }
        else
        {
            if (obj.x[i] < 0)
            {
                os << obj.x[i] * (-1) << "x^" << i;
            }
            else
            {  
                os << obj.x[i] << "x^" << i;
            }
        }
        sinal = true;
    }
    
    return os;
}
//Retorna derivada
Polinomio Polinomio::derivada() const {
    if (n == 1)//se for uma constante retorna um polinomio 0x^0
    {
        Polinomio obj;
        return obj;
    }
    
    Polinomio obj(*this);
    obj.x = (double*) realloc(obj.x, sizeof(double)* (n-1));
    obj.n--;
    
    for (int i = 0; i < n-1; i++)//derivada
    {
        obj.x[i] = x[i+1] * (i+1);
    }

    return obj;
}

//Avalia
double Polinomio::avalia(double num) const {
    if (n == 1)//se constante retorna a propria constante
    {
        return x[0];
    }
    
    double result = (x[n-1] * num) + (x[n-2]);
    for (int i = n-3; i >= 0; i--)
    {
        result = (result * num) + (x[i]);  
    }
    
    return result;
}

//Resolve P(x)=0. Encontra raízes reais do polinomio
double* Polinomio::resolve(int &numRaizes) const {
    if (n == 2)//do primeiro grau 
    {
        double *raiz = (double*) malloc(sizeof(double));
        raiz[0] = (-x[0]/x[1]);
        numRaizes = 1;
        return raiz;
    }
    if (n == 3)//do segundo grau calculando por Braska
    {
        double *raiz = (double*) malloc(sizeof(double)*2);

        double delta = (x[1] * x[1]) - (4 * x[2] * x[0]);
        if (delta < 0)
        {
            raiz[0] = 0; // deve lancar uma execao fala que nao existe raiz
            raiz = (double*) realloc(raiz, sizeof(double));
            numRaizes = 1;
            return raiz;   
        }
        
        raiz[0] = (-x[1] - sqrt(delta))/(2*x[2]);
        raiz[1] = (-x[1] + sqrt(delta))/(2*x[2]);
        numRaizes = 2;

        return raiz;
    }
    
    //outros polinomios, calculando por metodo de Newton
    double *raiz = (double*) malloc(sizeof(double)*n);//vetor para retonar as raizes
    //auxiliares
    Polinomio auxFuncao(*this);
    Polinomio auxDerivada = (*this).derivada();
    
    Polinomio divide(1);//polinomio para divisao
    
    double x = 1;//chute inicial
    if (auxDerivada.avalia(x) == 0)//verifica se o chute eh valido, pois a derivada nao pode ser zero
    {
        x++;
    }
    
    int j = 0;
    
    double EPSILON = 1e-15;
    
    for (int i = 0; i < 250; i++)//metodo de Newton
    {
        raiz[j] = x - (auxFuncao.avalia(x) / auxDerivada.avalia(x));//calculo do metodo
 
        if (auxFuncao.avalia(raiz[j]) <= EPSILON)//verifica se encontrou uma raiz
        {
            raiz[j] = x;//guarda a raiz no vetor de raizes
            divide.x[0] = -raiz[j];//altera atualiza o polinomio de divisao
            auxFuncao /= divide;
            auxDerivada = auxFuncao.derivada();//calcula a nova derivada
            
            x = 1;//chute
            if (auxDerivada.avalia(x) == 0)//verifica o chute
            {
                x++;
            }

            j++;

            if (j>= n)
            {
                break;
            }
        }
        else//se nao encotra a raiz, atualiza o x
        {
            x = raiz[j];
        } 
    }

    raiz = (double*) realloc(raiz, sizeof(double)*j);
    numRaizes = j;
    
   return raiz; 
}
