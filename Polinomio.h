#ifndef __POLINOMIO
#define __POLINOMIO

#include <iostream>

using namespace std;

class Polinomio {
	private:
		// Você deve editar aqui para a sua representação de dados
		int n;
		double *x;

	public:
		/* construtores e destrutores */

// construtor padrão. Deve representar o número 0
		Polinomio();

// Cria um Polinomio a partir de um número inteiro (positivo ou negativo)
		Polinomio(const int);

// Cria um Polinomio a partir de um vetor de coeficientes. Os coeficientes deverão ser os coeficientes do polinômio (Posição 0 será a_0, posição 1 será a_1, ...). 
// O primeiro parâmetro representa o grau do polinômio.
		Polinomio(unsigned int n, double *a);

		// Construtor de cópia
		Polinomio(const Polinomio &);

		// destrutor
		~Polinomio();

		/* Operadores */

		// atribuição
		Polinomio & operator=(const Polinomio &);

		// soma
		// adiciona 2 polinomios
		Polinomio operator+(const Polinomio &) const;
		//adiciona um polinomio a um numero
		Polinomio operator+(const double &) const;
		Polinomio & operator+=(const Polinomio &);
		Polinomio & operator+=(const double &);
		
		// subtração (segue o mesmo padrão da adição)
		Polinomio operator-(const Polinomio &) const;
		Polinomio operator-(const double &) const;
		Polinomio & operator-=(const Polinomio &);
		Polinomio & operator-=(const double &);
		
		// multiplicação
		// TODO: você também deve implementar a multiplicação por um número à esquerda
		Polinomio operator*(const Polinomio &) const;
		Polinomio operator*(const double &) const;
		Polinomio & operator*=(const Polinomio &);
		Polinomio & operator*=(const double &);
		
// divisão por um polinômio de grau 1 da forma (x - a)
// deve lançar 'ArgumentoInvalidoExcept' se o denominador não for da forma especificada acima
// Sugestão: https://pt.wikipedia.org/wiki/Algoritmo_de_Briot-Ruffini
		Polinomio operator/(const Polinomio &) const;
		Polinomio & operator/=(const Polinomio &);

		// divide os coeficiente por um número 
		Polinomio operator/(const int &) const;
		Polinomio & operator/=(const int &);
		
// resto da divisão por um polinômio de grau 1 da forma (x - 1)
// deve lançar 'ArgumentoInvalidoExcept' se o denominador não for da forma especificada acima
// Sugestão: https://pt.wikipedia.org/wiki/Algoritmo_de_Briot-Ruffini
		Polinomio operator%(const Polinomio &) const;
		Polinomio & operator%=(const Polinomio &);

		// Retorna i-ésimo coeficiente
		// Deve lançar 'PosicaoInvalidaExcept' se houver tentativa de acessar um bit não existente
		// Posição 0 indica o coeficiente do termo constante 
		double operator[](int) const;

		// incrementos (adicionar 1) ao termo constante
		Polinomio operator++();
		Polinomio operator++(int);

		/* Comparação */
		
		// igualdade
		// Verificar se dois polinômios tem o mesmo grau e mesmos coeficientes
		bool operator==(const Polinomio &) const;

		/* Entrada Saída */
		
		// lê/imprime de streams de entrada e saída
		friend istream& operator>>(istream &, Polinomio &);
		friend ostream& operator<<(ostream &, const Polinomio &);
		
		/* Operações (sem operadores) */

		// retorna a derivada do polinômio
		Polinomio derivada() const;

		// avalia.
		// Dado um número 'a', calcula P(a)
		// sugestão https://en.wikipedia.org/wiki/Horner%27s_method
		double avalia(double) const;

		// resolve P(x) = 0. Encontra as raízes reais do polinômio
		// o parâmetro inteiro é o número de raízes encontradas
		// Se não encontrar raízes, deve lançar uma exceção
		// sugestão: use o método de Newton para encontrar uma raiz, 
		// use o algoritmo de divisão para simplificar o polinômio...
		double * resolve(int &) const;

		void imprime();

};
/*
class PosicaoInvalidaExcept() {
};
class ArgumentoInvalidoExcept() {
};
class RaizesNaoEncontradas() {
};
*/
#endif
