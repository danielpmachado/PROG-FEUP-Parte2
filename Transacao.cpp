#include "Transacao.h"


Transacao::Transacao(unsigned int idCliente, Data data, vector<string> products)
{
	this->idCliente = idCliente;
	this->data = data;
	//this->produtos = produtos;  // será que funciona??

	for (unsigned int i = 0; i < products.size(); i++)
	{
		string prod;

		prod = products[i];

		produtos.push_back(prod);
	}
}


unsigned int Transacao::getIdCliente() const {
	return idCliente;
}

string Transacao::getDataT() const
{
	int y, m, d;

	y = data.getAno();
	m = data.getMes();
	d = data.getDia();

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

int Transacao::getDiaT() const 
{
	int d;
	d = data.getDia();

	return d;

}

int Transacao::getMesT() const
{
	int m;
	m = data.getMes();

	return m;

}

int Transacao::getAnoT() const
{
	int a;
	a = data.getAno();

	return a;

}

vector<string> Transacao::getProducts() const  {
	return produtos;
}

void Transacao::getListaProds() const
{
	for (unsigned int j = 0; j < produtos.size(); j++) {
		if (j == produtos.size() - 1)
		{
			cout << produtos[j] << endl;
		}
		else { cout << produtos[j] << ", "; }

	}

}


void Transacao::save(ofstream & out) const  // transacao guardada como na forma de  idcliente ; data ; lista produtos
{
	out << getIdCliente() << " ; " << getDataT() << " ; ";

	for (unsigned int j = 0; j < getProducts().size(); j++) 
	{
		if (j == getProducts().size() - 1)
		{
			out << getProducts()[j] << endl;
		}
		else { out << getProducts()[j] << ", "; }
	}
}

ostream& operator<<(ostream& out, const Transacao & trans) 
{
	out << setw(5) << trans.getIdCliente()
		<< setw(20) << trans.getDataT()
		<< setw(7) << "   "; trans.getListaProds();

	return out;
}

bool operator<(const Transacao &trans1, const Transacao &trans2)
{
	string s1 = trans1.getDataT();
	string s2 = trans2.getDataT();
	string day1 = s1.substr(0, 2);
	string month1 = s1.substr(3, 2);
	string year1 = s1.substr(6, 4);
	string day2 = s2.substr(0, 2);
	string month2 = s2.substr(3, 2);
	string year2 = s2.substr(6, 4);
	string date1 = year1 + month1 + day1;
	string date2 = year2 + month2 + day2;
	return (date1 < date2);
}