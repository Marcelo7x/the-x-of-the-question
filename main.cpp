#include "Polinomio.h"
#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

void soma(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar)
{
    cout << '(' << base << ')' << " + " << '(' << auxiliar << ')' << endl;
    resultado = base + auxiliar;
    cout << "= " << resultado << endl
         << endl;
    copia += auxiliar;
    cout << "+= " << copia << endl
         << endl;
}

void subtracao(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar)
{
    cout << '(' << base << ')' << " - " << '(' << auxiliar << ')' << endl;
    resultado = base - auxiliar;
    cout << "= " << resultado << endl
         << endl;
    copia = base;
    copia -= auxiliar;
    cout << "-= " << copia << endl
         << endl;
}

void multiplicacao(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar)
{
    cout << '(' << base << ')' << " * " << '(' << auxiliar << ')' << endl;
    resultado = base * auxiliar;
    cout << "= " << resultado << endl
         << endl;
    copia = base;
    copia *= auxiliar;
    cout << "*= " << copia << endl
         << endl;
}

void divisao(Polinomio &base, Polinomio &copia, Polinomio &resultado, Polinomio &auxiliar, Polinomio &auxiliarDivisao)
{   try{
    cout << '(' << base << ')' << " / " << '(' << auxiliarDivisao << ')' << endl;
    resultado = base / auxiliarDivisao;
    cout << "= " << resultado << endl
         << endl;
    copia = base;
    copia /= auxiliarDivisao;
    cout << "/= " << copia << endl
         << endl;

    cout << '(' << base << ')' << " % " << '(' << auxiliarDivisao << ')' << endl;
    resultado = base % auxiliarDivisao;
    cout << "= " << resultado << endl
         << endl;
    copia = base;
    copia %= auxiliarDivisao;
    cout << "%= " << copia << endl
         << endl;
    }catch(...){
        cout << "Nao e possivel dividir um polinomio dessa ordem ou houve divisao por 0" << endl;
    }
}

void derivada(Polinomio &auxiliar)
{
    cout << "Derivada(" << auxiliar << ")\n";
    cout << "= " << auxiliar.derivada() << endl
         << endl;
}

void avalia(Polinomio &auxiliar)
{
    double x = (rand() % 11 + 1);
    cout << "Avalia(" << auxiliar << ") p/ x = " << x << endl;
    cout << "= " << auxiliar.avalia(x) << endl
         << endl;
}

void resolve(Polinomio &auxiliar)
{
    cout << "Resolve(" << auxiliar << ")\n";
    int numRaizes;
    double *raizes = auxiliar.resolve(numRaizes);
    cout << numRaizes << " raizes\n";
    if (numRaizes > 0)
    {
        cout << "Raizes{";
        for (int i = 0; i < numRaizes; i++)
        {
            if (i == numRaizes - 1)
            {
                cout << raizes[i];
                break;
            }

            cout << raizes[i] << ", ";
        }
        cout << "}\n\n";
        free(raizes);
    }
}

void exemplo()
{
    srand(time(NULL));

    double *vetor1 = new double[6]{0, 1, 2, 3, 4, 5};
    Polinomio base(6, vetor1);
    delete[] vetor1;

    int numAleatorio = rand() % 11 + 1;
    vetor1 = new double[numAleatorio];
    for (int i = 0; i < numAleatorio; i++)
    {
        vetor1[i] = rand() % 101 + 1;
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
    vetor1 = new double[2]{(double)(-(rand() % 11) - 1), 1};
    Polinomio auxiliarDivisao(2, vetor1);
    delete[] vetor1;
    divisao(base, copia, resultado, auxiliar, auxiliarDivisao);

    cout << "DERIVADA\n";
    derivada(auxiliar);

    cout << "AVALIA\n";
    avalia(auxiliar);

    cout << "RESOLVE\n";
    try{
        resolve(auxiliar);
    }
    catch(...){
        cerr << "Nao encotrou raizes\n";
    }
    
    try{
        double n = (rand() % 11 + 1);
        cout << "\nExemplo de calculo: P(" << n << "){(++(" << base << ") * 2 - (" << "-- (" << base << "))) - ((" << auxiliar << ") * 2) / ("
            << auxiliarDivisao << ")) * (" << auxiliarDivisao << ") + (" << auxiliar << ") % (" << auxiliarDivisao << ")} + "
            << "P(" << n << "){("
            << "derivada(" << auxiliar << ") + integral(" << auxiliar << ")} - "
            << "((" << auxiliar << ") % (" << auxiliarDivisao << ") + (" << auxiliar << ") % (" << auxiliarDivisao << "))\n";
        cout << "= " << ((++base * 2 - (++base)) - (((auxiliar * 2) / auxiliarDivisao)* auxiliarDivisao) + auxiliar%auxiliarDivisao).avalia(n)
         + (auxiliar.derivada().avalia(n) + auxiliar.integral().avalia(n)) - (auxiliar % auxiliarDivisao).avalia(0) + (auxiliar % auxiliarDivisao).avalia(0);
        cout << endl << endl;
    }
    catch(...){
        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n\n";
    }
    
}

double *criaPolinomio(int &tamanhoVetor)
{
    tamanhoVetor = 15;
    double *vetorPolinomioUsuario = (double *)calloc(tamanhoVetor, sizeof(double));
    char entrada[10];
    for (int i = 0;; i++)
    {
        if (i == tamanhoVetor - 2)
        {
            tamanhoVetor *= 2;
            vetorPolinomioUsuario = (double *)realloc(vetorPolinomioUsuario, sizeof(double) * tamanhoVetor);
        }
        cin >> entrada;
        if (strcmp(entrada, "f") == 0)
        {
            tamanhoVetor = i;
            vetorPolinomioUsuario = (double *)realloc(vetorPolinomioUsuario, sizeof(double) * tamanhoVetor);
            break;
        }
        vetorPolinomioUsuario[i] = atof(entrada);
    }

    return vetorPolinomioUsuario;
}

void operacao(Polinomio &A)
{
    int user, user2;
    Polinomio copiaA(A), copiaB;
    int tamanhoDoVetor;
    double *vetor2PolinomioUsuario;
    bool Bcriado = false;

    while (true)
    {
        cout << "Digite a operacao que deseja fazer com o polinomio A:\n";
        cout << " 1) +\n 2) -\n 3) *\n 4) /\n 5) %\n 6) ++\n 7) ==\n 8) Derivada\n 9) Avaliar\n 10) Resolver\n 11) Integral\n-->";
        
        do
        {
            cin >> user;
            if (user > 0 && user < 12)
            {
                break;
            }
            cout << "Digite um numero valido\n-->";
        } while (user < 1 || user > 12);
        cout << endl;

        if (user == 1 || user == 2 || user == 3 || user == 4 || user == 5 || user == 7)
        {
            cout << "Deseja fazer a operacao com outro polinomio ou constante?\n 1) Polinomio\n 2) Constante\n-->";
            int polinomioOuConstante;
            do
            {
                cin >> polinomioOuConstante;
                if (polinomioOuConstante > 0 && polinomioOuConstante < 3)
                {
                    break;
                }
                cout << "Digite um numero valido\n-->";
            } while (polinomioOuConstante < 1 || polinomioOuConstante > 2);

            int esquerdaOuDireita;
            double constante;
            Polinomio B;
            cout << endl;
            
            if (polinomioOuConstante == 1)
            {            
                cout << "Digite outro polinomio na forma nx^0, nx^1,...,nx^m para fazer a operacao:\n(Digite apenas os coeficientes)\n";
                cout << "DIGITE 'f' QUANDO FINALIZAR\n";
                vetor2PolinomioUsuario = criaPolinomio(tamanhoDoVetor);
                Polinomio aux(tamanhoDoVetor, vetor2PolinomioUsuario);
                free(vetor2PolinomioUsuario);
                B = aux;
                Bcriado = true;
                copiaB = B;
            }
            else if (polinomioOuConstante == 2)
            {            
                cout << "Fazer operacao com a constante pela esquerda(k_operaçao_polinomio) ou direita(polinomio_operacao_k)\n";
                cout << " 1) Esquerda\n 2) Direita\n-->";
                cin >> esquerdaOuDireita;
                cout << endl;
                cout << "Digite uma constante para fazer a operacao:\n";
                cin >> constante;
                
            }
            cout << endl;
           
            if (polinomioOuConstante == 1)
            {
                cout << "Polinomio B: " << B << endl << endl;
            }
            if (polinomioOuConstante == 2)
            {
                cout << "Constante : " << constante << endl << endl;
            }

            switch (user)
            {
            case 1:
                if(polinomioOuConstante == 1 || (polinomioOuConstante == 2 && esquerdaOuDireita == 2)){
                    cout << " 1) +\n ou\n 2) +=\n-->";
                    do
                    {
                        cin >> user2;
                        if (user2 > 0 && user2 < 3)
                        {
                            break;
                        }
                        cout << "Digite um numero valido\n-->";
                    } while (user2 < 1 || user2 > 2);
                    cout << endl;
                }
                else if(polinomioOuConstante == 2 && esquerdaOuDireita == 1)
                {
                    user2 = 1;
                }

                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    Polinomio C = A + B;
                    cout << C << endl << endl;
                }
                else if (user2 == 1 && polinomioOuConstante ==  2)
                {
                    if(esquerdaOuDireita == 1){
                        Polinomio C = constante + A;
                        cout << C << endl << endl; 
                    }
                    else if(esquerdaOuDireita == 2){
                        Polinomio C = A + constante;
                        cout << C << endl << endl;
                    }
                }
                else if (user2 == 2 && polinomioOuConstante == 1)
                {
                    A += B;
                    cout << A << endl << endl;
                }
                else if (user2 == 2 && polinomioOuConstante == 2)
                {
                    A += constante;
                    cout << A << endl << endl;
                }
                break;

            case 2:
                if(polinomioOuConstante == 1 || (polinomioOuConstante == 2 && esquerdaOuDireita == 2)){
                    cout << " 1) -\n ou\n 2) -=\n-->";
                    do
                    {
                        cin >> user2;
                        if (user2 > 0 && user2 < 3)
                        {
                            break;
                        }
                        cout << "Digite um numero valido\n-->";
                    } while (user2 < 1 || user2 > 2);
                    cout << endl;
                }
                else if(polinomioOuConstante == 2 && esquerdaOuDireita == 1)
                {
                    user2 = 1;
                }

                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    Polinomio C = A - B;
                    cout << C << endl << endl;
                }
                else if (user2 == 1 && polinomioOuConstante ==  2)
                {
                    if(esquerdaOuDireita == 1){
                        Polinomio C = A - constante;
                        cout << C << endl << endl;
                    }
                    else if (esquerdaOuDireita == 2){
                        Polinomio C = constante - A;
                        cout << C << endl << endl;
                    }
                }
                else if (user2 == 2 && polinomioOuConstante == 1)
                {
                    A -= B;
                    cout << A << endl << endl;
                }
                else if (user2 == 2 && polinomioOuConstante == 2)
                {
                    A -= constante;
                    cout << A << endl << endl;
                }
                break;

            case 3:
                if(polinomioOuConstante == 1 || (polinomioOuConstante == 2 && esquerdaOuDireita == 2)){
                    cout << " 1) *\n ou\n 2) *=\n-->";
                    do
                    {
                        cin >> user2;
                        if (user2 > 0 && user2 < 3)
                        {
                            break;
                        }
                        cout << "Digite um numero valido\n-->";
                    } while (user2 < 1 || user2 > 2);
                    cout << endl;
                }
                else if(polinomioOuConstante == 2 && esquerdaOuDireita == 1)
                {
                    user2 = 1;
                }

                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    Polinomio C = A * B;
                    cout << C << endl << endl;
                }
                else if (user2 == 1 && polinomioOuConstante ==  2)
                {
                    if(esquerdaOuDireita == 1){
                        Polinomio C = A * constante;
                        cout << C << endl << endl;
                    }
                    else if (esquerdaOuDireita == 2){
                        Polinomio C = constante * A;
                        cout << C << endl << endl;
                    }
                }
                else if (user2 == 2 && polinomioOuConstante == 1)
                {
                    A *= B;
                    cout << A << endl << endl;
                }
                else if (user2 == 2 && polinomioOuConstante == 2)
                {
                    A *= constante;
                    cout << A << endl << endl;
                }
                break;

            case 4:
                if(polinomioOuConstante == 1 || (polinomioOuConstante == 2 && esquerdaOuDireita == 2)){
                    cout << " 1) /\n ou\n 2) /=\n-->";
                    do
                    {
                        cin >> user2;
                        if (user2 > 0 && user2 < 3)
                        {
                            break;
                        }
                        cout << "Digite um numero valido\n-->";
                    } while (user2 < 1 || user2 > 2);
                    cout << endl;
                }
                else if(polinomioOuConstante == 2 && esquerdaOuDireita == 1)
                {
                    user2 = 1;
                }

                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    try{
                        Polinomio C = A / B;
                        cout << C << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                    }
                }
                else if (user2 == 1 && polinomioOuConstante ==  2)
                {   
                    try{
                        if(esquerdaOuDireita == 1){
                        Polinomio C = A / constante;
                        cout << C << endl << endl;
                    }
                    else if (esquerdaOuDireita == 2){
                        Polinomio C = constante / A;
                        cout << C << endl << endl;
                    }
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                }
                }
                else if (user2 == 2 && polinomioOuConstante == 1)
                {   
                    try{
                        A /= B;
                        cout << A << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                    }
                }
                else if (user2 == 2 && polinomioOuConstante == 2)
                {   
                    try{
                        A /= constante;
                        cout << A << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                    }
                }
                break;

            case 5:
                cout << " 1) %\n ou\n 2) %=\n--> ";
                do
                    {
                        cin >> user2;
                        if (user2 > 0 && user2 < 3)
                        {
                            break;
                        }
                        cout << "Digite um numero valido\n-->";
                    } while (user2 < 1 || user2 > 2);
                cout << endl;
                if (user2 == 1 && polinomioOuConstante == 1)
                {   
                    try{
                        Polinomio C = A % B;
                        cout << C << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                    }
                }
                if (user2 == 1 && polinomioOuConstante == 2)
                {   
                    try{
                        Polinomio C = A % constante;
                        cout << C << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                    }
                }
                else if (user2 == 2 && polinomioOuConstante == 1)
                {
                    try{
                        A %= B;
                        cout << A << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                    }
                }
                else if (user2 == 2 && polinomioOuConstante == 2)
                {
                    try{
                        A %= constante;
                        cout << A << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou por 0\n";
                        break;
                    }
                }
                break;
            
            case 7:
                if (A == B)
                {
                    cout << "A e B sao iguais\n";
                }
                else
                {
                    cout << "A e B sao diferentes\n";
                }
                break;

            default:
                break;
            }
        }
        else if (user == 6 || user == 8 || user == 9 || user == 10 || user == 11)
        {
            switch (user)
            {
                case 6:
                    cout << ++A << endl;
                    break;

                case 8:
                    cout << A.derivada() << endl << endl;
                    break;

                case 9:
                    cout << "Digite o numero x que deseja avaliar:\n-->";
                    double x;
                    cin >> x;
                    cout << endl;
                    cout << A.avalia(x) << endl << endl;
                    break;

                case 10:
                    double *raizes;
                    int numRaizes;
                    try
                    {
                        raizes = A.resolve(numRaizes);
                    }
                    catch(...)
                    {
                        std::cerr << "Nao encotrou raizes" << '\n';
                        break;
                    }
                    
                    
                    cout << "Polinomio A tem " << numRaizes << " raizes:\n";
                    for (int i = 0; i < numRaizes; i++)
                    {
                        cout << raizes[i] << " ";
                    }
                    cout << endl << endl;
                    break;

                case 11:
                    cout << A.integral() << endl << endl;
                    break;
            
                default:
                    break;
            }
        }
    
        cout << "Deseja fazer outra operacao? \n 1) Sim\n 2) Nao\n-->";
        do
            {
                cin >> user;
                if (user > 0 && user < 3)
                {
                    break;
                }
                cout << "Digite um numero valido\n-->";
            } while (user < 1 || user > 2);
        cout << endl;

        if (user == 1)
        {
            if (Bcriado)
            {
                cout << "Deseja utilizar o polinomio A ou B?\n 1) Quero utilizar A\n 2) Quero utilizar B\n 3) Quero novos polinomios\n-->";
            }
            else if (!Bcriado)
            {
                cout << "Deseja utilizar o polinomio A ou B?\n 1) Quero utilizar A\n 2) Quero utilizar B (INDISPONIVEL)\n 3) Quero novos polinomios\n-->";
            }
            
            cin >> user2;
            cout << endl;
            
            if (user2 == 1)
            {
                A = copiaA;
                cout << "Polinomio A: " << A << endl;
            }
            else if (user2 == 2 && Bcriado)
            {
                A = copiaB;
                cout << "Novo polinomio A (baseado em B): " << A << endl;
            }
            else if (user2 == 2 && !Bcriado)
            {
                cout << "Funcao Indisponivel, B nao foi criado anteriomente\nCrie um novo Polinomio\n";
                cout << "\nDigite um polinomio na forma nx^0, nx^1,...,nx^m\n(Digite apenas os coeficientes)\n";
                cout << "DIGITE 'f' QUANDO FINALIZAR\n-->";
                vetor2PolinomioUsuario = criaPolinomio(tamanhoDoVetor);
                Polinomio aux(tamanhoDoVetor, vetor2PolinomioUsuario);
                free(vetor2PolinomioUsuario);
                A = aux;
                cout << "Polinomio A: " << A << endl << endl;
            }
            else if (user2 == 3)
            {
                cout << "\nDigite um polinomio na forma nx^0, nx^1,...,nx^m\n(Digite apenas os coeficientes)\n";
                cout << "DIGITE 'f' QUANDO FINALIZAR\n-->";
                vetor2PolinomioUsuario = criaPolinomio(tamanhoDoVetor);
                Polinomio aux(tamanhoDoVetor, vetor2PolinomioUsuario);
                free(vetor2PolinomioUsuario);
                A = aux;
                cout << "Polinomio A: " << A << endl << endl;
                Bcriado = false;
            }
        }
        else if (user == 2)
        {
            break;
        }
        
    }
}

int main()
{
    int interacao0;
    cout << "Deseja ver um exemplo das funcoes implementadas nesse trabalho?\n 1) Sim\n 2) Nao\n-->";
    do
    {
        cin >> interacao0;
        if (interacao0 > 0 && interacao0 < 3)
        {
            break;
        }
        cout << "Digite um numero valido\n-->";
    } while (interacao0 < 1 || interacao0 > 2);

    cout << endl;
    if (interacao0 == 1)    //mostra um exemplo das fucionalidades presentes neste progama
    {
        exemplo();

        int interacao1;

        while (true)
        {
            cout << "Deseja ver o exemplo novamente com diferentes polinomios?\n 1) Sim\n 2) Nao \n-->";
            do
            {
                cin >> interacao1;
                if (interacao1 > 0 && interacao1 < 3)
                {
                    break;
                }
                cout << "Digite um numero valido\n-->";
            } while (interacao1 < 1 || interacao1 > 2);
            cout << endl;
            
            if (interacao1 == 1)
            {
                exemplo();
            }
            else
            {
                break;
            }
        }
    }

    cout << "Deseja ir para o modo interativo?\n 1) Sim\n 2) Nao  \n-->>";
    int interacao2;
    do
    {
        cin >> interacao2;
        if (interacao2 > 0 && interacao2 < 3)
        {
            break;
        }
        cout << "Digite um numero valido\n-->";
    } while (interacao2 < 1 || interacao2 > 2);
    cout << endl;
    
    if (interacao2 == 2)
    {
        return 0;
    }
    else if (interacao2 == 1)
    {
        int tamanhoVetor;
        cout << "Digite um polinomio na forma nx^0, nx^1,...,nx^m\n(Digite apenas os coeficientes)\n";
        cout << "Exemplo: 1 2 3 4 5 == 5x^4 + 4x^3 + 3x^2 + 2x^1 + 1\n";
        cout << "DIGITE 'f' QUANDO FINALIZAR\n-->";
        double *vetorPolinomioUsuario = criaPolinomio(tamanhoVetor);
        cout << endl;
        Polinomio A(tamanhoVetor, vetorPolinomioUsuario);
        free(vetorPolinomioUsuario);
        cout << "Polinomio A: " << A << endl << endl;
        operacao(A);
    }

    return 0;
}
