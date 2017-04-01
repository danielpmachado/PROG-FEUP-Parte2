#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Data.h"
#include "utils.h"

using namespace std;


class Cliente {
private:
	unsigned int id;
	string nome;
	Data cartaoCliente;
	float volCompras;

public:
	Cliente::Cliente(unsigned int id, string nome, Data cartaoCliente, float volCompras); // construtor
	string getNome() const;                 // metodos
	unsigned int getId() const;             //  da
	float getVolCompras() const;            //   classe
	string getData() const;                 //
	void setNome(string n);                 //
	void setData(Data d);                   //
	void setVolCompras(float f);            //
	void save(ofstream & out) const;         // guarda informação de um cliente
	friend ostream& operator<<(ostream& out, const Cliente & cli);  // mostra informacao do cliente no ecra
	friend bool operator<(const Cliente &cli1, const Cliente &cli2); // compara 2 clientes (1 cliente e menor que outro se o seu nome for "alfabeticamente" inferior)
};

