#include "Produto.h"

Produto::Produto(string nome, float custo)
{
	this->nome = nome;
	this->custo = custo;
}


string Produto::getNome() const {
	return nome;
}

float Produto::getCusto() const {
	return custo;
}


ostream& operator<<(ostream& out, const Produto & prod) {

	out << setw(22) << prod.getNome()
		<< setw(22) << fixed << setprecision(2) << prod.getCusto()
		<< endl;

	return out;
}

bool operator<(const Produto &prod1, const Produto &prod2) 
{
	return prod1.getNome() < prod2.getNome();
}
