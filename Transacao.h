#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

#include "Data.h"



using namespace std;


class Transacao {
private:
	unsigned int idCliente;
	Data data; // na forma DD/MM/AAAAA
	vector<string> produtos;

public:
	Transacao(unsigned int idCliente, Data data, vector<string> produtos);   // construtor

	unsigned int getIdCliente() const;         // metodos da classe
	string getDataT() const;                   //
	int getDiaT() const;                       //
	int getMesT() const;                       //
	int getAnoT() const;                       //
	vector<string> getProducts() const;        //
	void getListaProds() const;                //

	void save(ofstream & out) const; // guarda a transacao
	friend ostream& operator<<(ostream& out, const Transacao & trans); // mostra a transacao
	friend bool operator<(const Transacao &trans1, const Transacao &trans2); // compara 2 transacoes. Uma transação é menor se a sua data for anterior à data da outra transação
};
