#pragma once

#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include <iomanip>


#include "defs.h"
#include "Data.h"
#include "Cliente.h"
#include "Transacao.h"
#include "Produto.h"
#include "utils.h"


using namespace std;

class VendeMaisMais {
private:
	string nomeLoja; // nome da loja
	string fichClientes, fichProdutos, fichTransacoes; // nome dos
													   // ficheiros de
													   // clientes,
													   // produtos e
													   // transacoes
	bool transacoesAlterdas; // flag que fica a true se for preciso guardar no final as transacoes
	bool clientesAlterados; // flag que fica a true se for preciso guardar no final os clienets
	unsigned int maxClientesId; // variavel que guarda o identificador unico do cliente com o maior identiicador
	vector<Cliente> clientes; // vetor que guarda a informacao dos clientes existentes
	vector<Produto> produtos; // vetor que guarda a informacao dos produtos disponiveis
	vector<Transacao> transacoes; // vetor que guarda a informacao das ttransacoes efetuadas
	map<string, int> clienteIdx;  // map para "traduzir" nome do cliente no indice dele no vetor de clientes
	map<string, int> produtoIdx;  // map para "traduzir" nome do produto no indice dele no vetor de produtos
	multimap<int, int> transacaoIdx; // multima para "traduzir" o identificador do
									 // cliente nos indices das suas
									 // transacoes no vetor de
									 // transacoes

public:
	VendeMaisMais(string loja, string fichClientes, string fichProdutos, string fichTransacoes); // construtor
	void atualizaMaxID(int n);  //atualiza o ID do cliente com maior identificador
	void saveChanges() const;   // guarda toda a informacao da loja (clientes e transacoes)
	unsigned int getNumClientes() const;        // metodos da classe
	unsigned int getNumProdutos() const;        //
	unsigned int getNumTransacoes() const;      //
	friend ostream& operator<<(ostream& out, const VendeMaisMais & supermercado);  // mostra no ecra as informacoes da loja

	//   1  - GESTÃO DE CLIENTES
	void printClients();    // imprime lista de clientes
	void criarCliente();     // cria um cliente
	void alterarCliente();    // modifica um cliente
	void removerCliente();    // remove um cliente
	void printSingleClient();   // imprime um cliente
	void displayClientesABC();   // imprime lista de clientes por ordem alfabetica

	//   2  - PRODUTOS
	void printProducts();     // mostra os produtos por ordem alfabetica crescente

	//   3  - GESTÃO DE TRANSAÇÕES
	void addTransaction();   // adiciona uma transacao
	void printTransactions();  // imprime a lista de transacoes
	void printDayTransaction();  // imprime as transacoes de uma data
	void printTbetweenDates();   // imprime as transacoes entre 2 datas
	void printClientTransaction();  // imprime as transacoes de um cliente
	void printCrono();              // imprime as transacoes de um cliente por ordem cronologica
	void printCronologicamente();   //imprime as transacoes de um cliente por ordem cronologica
	void imprimeEntreDatas();       // imprime as transacoes entre 2 datas
	void imprimeDiaTrans();       // imprime as transacoes de uma data

	//   4  - RECOMENDAÇÕES

	//void Bottom5();
	void printBottom10();  // imprime o bottom10
};