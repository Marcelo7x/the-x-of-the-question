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
        cout << "nao e possivel dividir um polinomio dessa ordem ou houve divisao por 0" << endl;
        exit(0);
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
    resolve(auxiliar);
    
    try{
        double n = (rand() % 11 + 1);
        cout << "\nExemplo de calculo: P(" << n << "){(++(" << base << ") * 2) - (" << auxiliar << ") * 2) / ("
            << auxiliarDivisao << ")} + "
            << "P(" << n << "){("
            << "derivada(" << auxiliar << ")} - "
            << "((" << auxiliar << ") % (" << auxiliarDivisao << "))\n";
        cout << "= " << ((++base * 2) - ((auxiliar * 2) / auxiliarDivisao)).avalia(n) + (auxiliar.derivada().avalia(n)) - (auxiliar % auxiliarDivisao).avalia(0);
        cout << endl << endl;
    }
    catch(...){
        cout << "Nao e possivel dividir por um polinomio dessa ordem ou houve divisao por 0\n";
        exit(0);
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
        cout << "Qual operacao deseja fazer com o polinomio A:\n";
        cout << " 1) +\n 2) -\n 3) *\n 4) /\n 5) %\n 6) ++\n 7) ==\n 8) Derivada\n 9) Avaliar\n 10) Resolver\n-->";
        cin >> user;
        cout << endl;

        if (user == 1 || user == 2 || user == 3 || user == 4 || user == 5 || user == 7)
        {
            cout << "Fazer a oparecao com outro polinomio ou constante?!\n 1) Polinomio\n 2) constante\n-->";
            int polinomioOuConstante;
            cin >> polinomioOuConstante;
            if (polinomioOuConstante == 1)
            {            
                cout << "Digite outro polinomio da forma nx^0, nx^1,...,nx^m para fazer a operacao:\n";
                cout << "Digite 'f' quando acabar o polinomio\n";
            }
            else if (polinomioOuConstante == 2)
            {            
                cout << "Digite uma constante para fazer a operacao:\n";
                cout << "Digite 'f' apos digitar a constante\n";
            }
            
            vetor2PolinomioUsuario = criaPolinomio(tamanhoDoVetor);
            double constante = vetor2PolinomioUsuario[0];
            cout << endl;
            Polinomio B(tamanhoDoVetor, vetor2PolinomioUsuario);
            Bcriado = true;
            copiaB = B;
           
            if (polinomioOuConstante == 1)
            {
                cout << "Polinomio B: " << B << endl << endl;
            }
            if (polinomioOuConstante == 2)
            {
                cout << "Constante : " << constante << endl << endl;
            }
            free(vetor2PolinomioUsuario);

            switch (user)
            {
            case 1:
                cout << " 1) +\n ou\n 2) +=\n-->";
                cin >> user2;
                cout << endl;
                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    Polinomio C = A + B;
                    cout << C << endl << endl;
                }
                else if (user2 == 1 && polinomioOuConstante ==  2)
                {
                    Polinomio C = A + constante;
                    cout << C << endl << endl;
                }
                else if (user2 == 2)
                {
                    A += B;
                    cout << A << endl << endl;
                }
                break;

            case 2:
                cout << " 1) -\n ou\n 2) -=\n--> ";
                cin >> user2;
                cout << endl;
                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    Polinomio C = A - B;
                    cout << C << endl << endl;
                }
                else if (user2 == 1 && polinomioOuConstante ==  2)
                {
                    Polinomio C = A - constante;
                    cout << C << endl << endl;
                }
                else if (user2 == 2)
                {
                    A -= B;
                    cout << A << endl << endl;
                }
                break;

            case 3:
                cout << " 1) *\n ou\n 2) *=\n--> ";
                cin >> user2;
                cout << endl;
                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    Polinomio C = A * B;
                    cout << C << endl << endl;
                }
                else if (user2 == 1 && polinomioOuConstante ==  2)
                {
                    Polinomio C = A * constante;
                    cout << C << endl << endl;
                }
                else if (user2 == 2)
                {
                    A *= B;
                    cout << A << endl << endl;
                }
                break;

            case 4:
                cout << " 1) /\n ou\n 2) /=\n--> ";
                cin >> user2;
                cout << endl;
                if (user2 == 1 && polinomioOuConstante ==  1)
                {
                    try{
                        Polinomio C = A / B;
                        cout << C << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou houve divisao por 0\n";
                        exit(0);
                    }
                }
                if (user2 == 1 && polinomioOuConstante ==  2)
                {   
                    try{
                        Polinomio C = A / polinomioOuConstante;
                        cout << C << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou houve divisao por 0\n";
                        exit(0);
                }
                }
                else if (user2 == 2)
                {   
                    try{
                        A /= B;
                        cout << A << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou houve divisao por 0\n";
                        exit(0);
                    }
                }
                break;

            case 5:
                cout << " 1) %\n ou\n 2) %=\n--> ";
                cin >> user2;
                cout << endl;
                if (user2 == 1)
                {   
                    try{
                        Polinomio C = A % B;
                        cout << C << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou houve divisao por 0\n";
                        exit(0);
                    }
                }
                else if (user2 == 2)
                {
                    try{
                        A %= B;
                        cout << A << endl << endl;
                    }
                    catch(...){
                        cout << "Nao e possivel dividir por um polinomio dessa ordem ou houve divisao por 0\n";
                        exit(0);
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
        else if (user == 6 || user == 8 || user == 9 || user == 10)
        {
            switch (user)
            {
                case 6:
                    cout << ++A << endl;
                    break;

                case 8:
                    cout << A.derivada() << endl;
                    break;

                case 9:
                    cout << "Digite o numero x em que se quer avaliar:\n-->";
                    double x;
                    cin >> x;
                    cout << endl;
                    cout << A.avalia(x) << endl << endl;
                    break;

                case 10:
                    double *raizes;
                    int numRaizes;
                    raizes = A.resolve(numRaizes);
                    cout << "Polinomio A tem " << numRaizes << " raizes:\n";
                    for (int i = 0; i < numRaizes; i++)
                    {
                        cout << raizes[i] << " ";
                    }
                    cout << endl << endl;
                    break;
            
                default:
                    break;
            }
        }
    
        cout << "Deseja fazer outra operacao?! \n 1) Sim\n 2) Nao\n-->";
        cin >> user;
        cout << endl;

        if (user == 1)
        {
            if (Bcriado)
            {
                cout << "Deseja ultizar A ou B?!\n 1) Quero ultilizar A\n 2) Quero ultilizar B\n3) Quero novos polinomios\n-->";
            }
            else if (!Bcriado)
            {
                cout << "Deseja ultizar A ou B?!\n 1) Quero ultilizar A\n 2) Quero ultilizar B (INDISPONIVEL)\n3) Quero novos polinomios\n-->";
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
                cout << "Novo polinomio A(baseado em B): " << A << endl;
            }
            else if (user2 == 2 && !Bcriado)
            {
                cout << "Funcao indisponivel, B nao foi criado anteriomente \nCrie um novo Polinomio\n";
                cout << "\nDigite 1 polinomio da forma nx^0, nx^1,...,nx^m\n(Eh nescessario digitar somente os coeficientes)\n";
                cout << "DIGITE 'f' QUANDO QUISER PARAR\n";
                vetor2PolinomioUsuario = criaPolinomio(tamanhoDoVetor);
                Polinomio aux(tamanhoDoVetor, vetor2PolinomioUsuario);
                free(vetor2PolinomioUsuario);
                A = aux;
                cout << "Polinomio A: " << A << endl << endl;
            }
            else if (user2 == 3)
            {
                cout << "\nDigite 1 polinomio da forma nx^0, nx^1,...,nx^m\n(Eh nescessario digitar somente os coeficientes)\n";
                cout << "DIGITE 'f' QUANDO QUISER PARAR\n";
                vetor2PolinomioUsuario = criaPolinomio(tamanhoDoVetor);
                Polinomio aux(tamanhoDoVetor, vetor2PolinomioUsuario);
                free(vetor2PolinomioUsuario);
                A = aux;
                cout << "Polinomio A: " << A << endl << endl;
            }
        }
        else if (user == 2)
        {
            break;
        }
        
    }
}

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "exemplo") == 0) //mostra um exemplo das fucionalidades presentes neste progama
    {
        exemplo();

        int interacao1;

        while (true)
        {
            cout << "Deseja ver o exemplo novamente com diferentes polinomios?!\n 1) Sim\n 2) Nao \n-->";
            cin >> interacao1;
            cout << endl;
            if (interacao1 == '1')
            {
                exemplo();
            }
            else
            {
                break;
            }
        }
    }

    cout << "Deseja ir para o modo interativo?!\n 1) Sim\n 2) Nao  \n-->>";
    int interacao2;
    cin >> interacao2;
    cout << endl;
    if (interacao2 == 2)
    {
        return 0;
    }
    else if (interacao2 == 1)
    {
        int tamanhoVetor;
        cout << "Digite 1 polinomio da forma nx^0, nx^1,...,nx^m\n(Eh nescessario digitar somente os coeficientes)\n";
        cout << "DIGITE 'f' QUANDO QUISER PARAR\n";
        double *vetorPolinomioUsuario = criaPolinomio(tamanhoVetor);
        cout << endl;
        Polinomio A(tamanhoVetor, vetorPolinomioUsuario);
        free(vetorPolinomioUsuario);
        cout << "Polinomio A: " << A << endl << endl;
        operacao(A);
    }

    return 0;
}
