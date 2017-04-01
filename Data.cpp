#include "Data.h"


Data::Data(unsigned int y, unsigned int m, unsigned int d)
{
	dia = d;
	mes = m;
	ano = y;
}

Data::Data(string dataStr) { // data na forma DD/MM/AAAA
	
	dia = stoi(dataStr.substr(0, 2));
	mes = stoi(dataStr.substr(3, 2));
	ano = stoi(dataStr.substr(6, 4));
}


int Data::getDia() const {
	return dia;
}

int Data::getMes() const {
	return mes;
}

int Data::getAno() const {
	return ano;
}

void Data::setDia(int d) {
	dia = d;
}

void Data::setMes(int m) {
	mes = m;
}

void Data::setAno(int a) {
	ano = a;
}


void Data::save(ofstream & out) const 
{
	out << getDia() << '/' << getMes() << '/' << getAno();
}

ostream& operator<<(ostream& out, const Data & data) 
{
	out << data.getDia() << '/' << data.getMes() << '/' << data.getAno();
	
	return out;

}
