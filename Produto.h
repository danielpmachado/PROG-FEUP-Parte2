#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;



class Produto {
private:
	string nome;
	float custo;


public:
	Produto(string nome, float custo);  // construtor

	string getNome() const;        // metodos
	float getCusto() const;        // da classe

	friend ostream& operator<<(ostream& out, const Produto & prod); // mostra um produto
	friend bool operator<(const Produto &prod1, const Produto &prod2); // compara 2 produtos (1 produto e mais pequeno que outro se o seu nome for "alfabeticamente inferior"
};