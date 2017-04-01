#include "Cliente.h"

// construtor
// recebe um ID, nome, a data de adesao e o montante de compras
Cliente::Cliente(unsigned int id, string nome, Data cartaoCliente, float volCompras)
{
	this->id = id;
	this->nome = nome;
	this->cartaoCliente = cartaoCliente;
	this->volCompras = volCompras;
}


string Cliente::getNome() const {
	return nome;
}

unsigned int Cliente::getId() const {
	return id;
}

float Cliente::getVolCompras() const {
	return volCompras;
}

string Cliente::getData() const
{
	int y, m, d;

	y = cartaoCliente.getAno();
	m = cartaoCliente.getMes();
	d = cartaoCliente.getDia();

	string y_str, m_str, d_str, data;

	if (d < 10)
		d_str = "0" + to_string(d);
	else d_str = to_string(d);

	if (m < 10)
		m_str = "0" + to_string(m);
	else m_str = to_string(m);

	y_str = to_string(y);

	data = d_str + '/' + m_str + '/' + y_str;

	return data;
}

void  Cliente::setNome(string n)
{
	nome = n;
}

void  Cliente::setData(Data d)
{
	cartaoCliente = d;
}

void Cliente::setVolCompras(float f) {
	volCompras = f;
}


void Cliente::save(ofstream & out) const 
{
	out << getId() << " ; " << getNome() << " ; " << getData() << " ; " << fixed << setprecision(2) << getVolCompras() << endl;

}

ostream& operator<<(ostream& out, const Cliente & cli) {

	out << setw(5) << cli.getId()
		<< setw(25) << cli.getNome()
		<< setw(20) << cli.getData()
		<< setw(21) << fixed << setprecision(2) << cli.getVolCompras() << endl;
	return out;
}

bool operator<(const Cliente &cli1, const Cliente &cli2) 
{
	return cli1.getNome() < cli2.getNome();
}
