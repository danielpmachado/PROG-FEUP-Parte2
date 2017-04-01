#include <iostream>
#include <string>
#include <vector>

#include "Vende++.h"
#include "Menus.h"
#include "utils.h"


int main() 
{
	string loja, fichClients, fichProdutos, fichTransacoes;

	layout();

	//pede a informacoo sobre o nome da loja e os 3 ficheiros com
	//informacoo de clientes, produtos e transacoes
	if (!infoInicial(loja, fichClients, fichProdutos, fichTransacoes))
	{
		cerr << "Ficheiros invalidos.\n";
		return (-1);	
	}
	
	// cria uma loja
	 VendeMaisMais supermercado(loja, fichClients, fichProdutos, fichTransacoes);
	 
	 
	 cin.get();
	 cout << "\n\nInformacao da loja " << loja << " do supermercado Vende++:" << endl;
	 cin.get();


	 cout << supermercado << endl;  // mostra estatisticas da loja
	 cin.get();

	 opcoesIniciais(supermercado); // menu inicial com as grandes opcoes
								  // que implementam as funcionalidades
								  // disponibilizadas

	return 0;
}