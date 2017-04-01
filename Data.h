# pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


class Data {
private:
	int dia;
	int mes;
	int ano;

public:
	Data(unsigned int y, unsigned int m, unsigned int d);    // construtor
	Data() {};
	Data(string data); // data na forma DD/MM/AAA

	int getDia() const;          // metodos 
	int getMes() const;          // da
	int getAno() const;          // classe
	void setDia(int d);          //
	void setMes(int m);          //
	void setAno(int a);          //

	void save(ofstream & out) const;
	friend ostream& operator<<(ostream& out, const Data & data);
};
