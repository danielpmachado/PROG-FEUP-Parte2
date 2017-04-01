#include "Menus.h"


/*
Função que pede ao utilizar para inserir o nome da loja e dos ficheiros (clientes, produtos e transaçoes)
e que verifica se os ficheiros de clientes, produtos e transações abrem corretamente.
*/
bool infoInicial(string & loja, string & fichClientes, string & fichProdutos, string & fichTransacoes) {

	cout << "\nIntroduza o nome da loja: ";
	getline(cin, loja);
	cout << "\nIntroduza o nome do ficheiro de clientes: ";
	cin >> fichClientes;
	cout << "\nIntroduza o nome do ficheiro de produtos: ";
	cin >> fichProdutos;
	cout << "\nIntroduza o nome do ficheiro de transacoes: ";
	cin >> fichTransacoes;


	ifstream clientes, produtos, transacoes;
	clientes.open(fichClientes);
	produtos.open(fichProdutos);
	transacoes.open(fichTransacoes);

	if (clientes.fail())
		return false;

	if (produtos.fail())
	{
		clientes.close();
		return false;
	}

	if (transacoes.fail())
	{
		clientes.close();
		produtos.close();
		return false;
	}

	return true;
}



/******************************************
* Gestao de Clientes
******************************************/

unsigned short int menuGestaoClientes() 
{
	unsigned short int opcao;

	clearScreen();
	layout();
	cout << TAB_BIG << "| MENU GESTAO CLIENTES |" << endl;
	cout << endl;
	cout << TAB << "| 1 |  Listar clientes ordenados alfabeticamente\n" << endl;
	cout << TAB << "| 2 |  Ver informacao de um cliente\n" << endl;
	cout << TAB << "| 3 |  Editar cliente\n" << endl;
	cout << TAB << "| 4 |  Remover cliente\n" << endl;
	cout << TAB << "| 5 |  Adicionar cliente\n" << endl;
	cout << TAB << "| 6 |  Imprime todos os clientes\n" << endl;
	cout << TAB << "| 7 |  Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Opcao: ";
	opcao = leUnsignedShortInt(1, 7);

	if (opcao == 7)
		return 0;

	return opcao;
}

void opcoesGestaoClientes(VendeMaisMais & supermercado) {
	unsigned int opcao;
	string nome;

	while ((opcao = menuGestaoClientes()))
		switch (opcao) {
		case 1: 
			clearScreen();
			layout();
			cout  << endl << TAB_BIG << "| CLIENTES |\n\n";
			supermercado.displayClientesABC();
			cin.get();
			break;
		case 2: 
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| CLIENTE |\n\n";
			supermercado.printSingleClient();
			cin.get();
			break;
		case 3:
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| EDITAR CLIENTE |\n\n";
			supermercado.alterarCliente();
			cin.get();
			break;
		case 4:
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| REMOVER CLIENTE |\n\n";
			supermercado.removerCliente();
			cin.get();
			break;
		case 5:
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| ADICIONAR CLIENTE |\n\n";
			supermercado.criarCliente();
			cin.get();
			break;
		case 6:
			clearScreen();
			layout();
			cout << endl <<  TAB_BIG << "| TODOS OS CLIENTES |\n\n";
			supermercado.printClients();
			cin.get();
		}
}



/******************************************
* Gestao de Transacoes
******************************************/

unsigned short int menuGestaoTransacoes() {

	unsigned short int opcao;

	clearScreen();
	layout();
	cout << TAB_BIG << "| MENU GESTAO TRANSACOES |" << endl;
	cout << endl;
	cout << TAB << "| 1 |  Listar transacoes entre 2 datas\n" << endl;
	cout << TAB << "| 2 |  Listar transacoes de um cliente por ordem cronologica\n" << endl;
	cout << TAB << "| 3 |  Adicionar transacao\n" << endl;
	cout << TAB << "| 4 |  Ver transacoes de um cliente\n" << endl;
	cout << TAB << "| 5 |  Ver todas as transacoes\n" << endl;
	cout << TAB << "| 6 |  Ver transacoes de uma data\n" << endl;
	cout << TAB << "| 7 |  Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Opcao: ";
	opcao = leUnsignedShortInt(1, 7);

	if (opcao == 7)
		return 0;

	return opcao;

}

void opcoesGestaoTransacoes(VendeMaisMais & supermercado) {
	unsigned int opcao;

	while ((opcao = menuGestaoTransacoes()))
		switch (opcao) {
		case 1:
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| TRANSACOES ENTRE 2 DATAS |\n\n";
			supermercado.imprimeEntreDatas();
			cin.get();
			break;
		case 2:
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| TRANSACOES DE UM CLIENTE |\n\n";
			supermercado.printCronologicamente();
			cin.get();
			break;
		case 3:
			clearScreen();
			layout();
			cout << endl <<  TAB_BIG << "| ADICIONAR TRANSACAO |\n\n";
			supermercado.addTransaction();
			cin.get();
			break;
		case 4:
			clearScreen();
			layout();
			cout  << endl << TAB_BIG << "| TRANSACOES DE UM CLIENTE |\n\n";
			supermercado.printClientTransaction();
			cin.get();
			break;
		case 5:
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| TODAS TRANSACOES |\n\n";
			supermercado.printTransactions();
			cin.get();
			break;
		case 6:
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| TRANSACOES DE UMA DATA |\n\n";
			supermercado.imprimeDiaTrans();
			cin.get();
			break;
		}
}



/******************************************
* Gestao de Recomendacoes
******************************************/

unsigned short int menuRecomendacao() 
{
	unsigned short int opcao;

	clearScreen();
	layout();
	cout << TAB_BIG << "| MENU DE RECOMENDACAO |" << endl;
	cout << endl;
	cout << TAB << "| 1 |  Visualizar Bottom 10\n" << endl;
	cout << TAB << "| 2 |  Publicidade\n" << endl;
	cout << TAB << "| 3 |  Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Opcao: ";
	opcao = leUnsignedShortInt(1, 3);

	if (opcao == 3)
		return 0;

	return opcao;

}

void opcoesRecomendacao(VendeMaisMais & supermercado) {
	unsigned int opcao;

	while ((opcao = menuRecomendacao()))
		switch (opcao) {
		case 1:
			clearScreen();
			layout();
			cout << endl  << TAB_BIG << "| BOTTOM 10 |\n\n";
			supermercado.printBottom10();
			cin.get();
			break;
		case 2:
			cout << "Funcionalidade temporariamente indisponivel";
			cin.get();
			//publicidade
			break;
		}

}



/******************************************
* Menu Inicial
******************************************/

unsigned short int menuInicial() {
	unsigned short int opcao;

	clearScreen();
	layout();
	cout << TAB_BIG << "| MENU INICIAL |" << endl;
	cout << endl;
	cout << TAB << "| 1 |  Gestao de clientes\n" << endl;
	cout << TAB << "| 2 |  Lista produto disponiveis\n" << endl;
	cout << TAB << "| 3 |  Gestao de transacoes\n" << endl;
	cout << TAB << "| 4 |  Recomendacoes\n" << endl;
	cout << TAB << "| 5 |  Sair do programa" << endl << endl;
	cout << TAB << "Opcao: ";
	opcao = leUnsignedShortInt(1, 5);

	if (opcao == 5)
		return 0;

	return opcao;
}

void opcoesIniciais(VendeMaisMais & supermercado) 
{
	unsigned int opcao;

	while ((opcao = menuInicial()))
		switch (opcao) {
		case 1: opcoesGestaoClientes(supermercado);
			break;
		case 2: 
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| PRODUTOS |\n\n";
			supermercado.printProducts();
			cin.get();
			break;
		case 3: opcoesGestaoTransacoes(supermercado);
			break;
		case 4: opcoesRecomendacao(supermercado);
			break;
		}

	supermercado.saveChanges();
}

