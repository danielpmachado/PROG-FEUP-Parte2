#include "Vende++.h"

/*
Construtor da classe VendeMaisMais que lê e guarda nas estruturas apropriadas o nome da loja, a informação relativa aos clientes,
a informação relativa aos produtos e a informação relativa às transações.
*/
VendeMaisMais::VendeMaisMais(string loja, string fichClientes, string fichProdutos, string fichTransacoes) {

	ifstream nome_ficheiro_clientes, nome_ficheiro_produtos, nome_ficheiro_transacoes;
	unsigned int numClientes;
	unsigned int numProdutos;
	unsigned int numTransacoes;
	string line_c, line_p, line_t, num, num2, num3;
	maxClientesId = 0;


	this->nomeLoja = loja;
	this->fichClientes = fichClientes;
	this->fichProdutos = fichProdutos;
	this->fichTransacoes = fichTransacoes;
	this->maxClientesId = 0;


	// lê informação dos clientes
	nome_ficheiro_clientes.open(fichClientes);
	//nome_ficheiro_clientes >> numClientes;
	getline(nome_ficheiro_clientes, num);
	numClientes = stoi(num);
	//cout << numClientes;


	//guarda informação dos clientes
	while (getline(nome_ficheiro_clientes, line_c))
	{
		istringstream is;
		is.str(line_c);         // a primeira linha fica em is
		string s, x_str, d_str, f_str, nome;
		int id;
		double volCompras;

		//lê id
		getline(is, x_str, ';'); id = stoi(x_str);
		atualizaMaxID(id);
		//lê nome
		getline(is, s, ';'); trim(s); nome = s;
		//lê data
		getline(is, d_str, ';'); trim(d_str);

		stringstream data(d_str); string dia, mes, ano;
		int d, m, a;

		(getline(data, dia, '/')); trim(dia); d = stoi(dia);
		(getline(data, mes, '/')); trim(mes); m = stoi(mes);
		(getline(data, ano, '/')); trim(ano); a = stoi(ano);

		Data cartaoCliente(a, m, d);

		//lê montante
		getline(is, f_str, ';'); volCompras = string_to_double(f_str.c_str());


		Cliente clienteAtual(id, nome, cartaoCliente, volCompras);

		clientes.push_back(clienteAtual);
	}


	// lê informação dos produtos
	nome_ficheiro_produtos.open(fichProdutos);
	//nome_ficheiro_produtos >> numProdutos;
	getline(nome_ficheiro_produtos, num2);
	numProdutos = stoi(num2);

	//guarda informação dos produtos
	while (getline(nome_ficheiro_produtos, line_p))
	{
		istringstream is;
		is.str(line_p);         // a primeira linha fica em is
		string price_str, nome;
		float custo;

		getline(is, nome, ';'); trim(nome);
		getline(is, price_str, ';'); custo = string_to_double(price_str);

		Produto produtoAtual(nome, custo);

		produtos.push_back(produtoAtual);
	}



	// lê informação das transações
	nome_ficheiro_transacoes.open(fichTransacoes);
	//nome_ficheiro_transacoes >> numTransacoes;
	getline(nome_ficheiro_transacoes, num3);
	numTransacoes = stoi(num3);

	//guarda informação das transacoes
	while (getline(nome_ficheiro_transacoes, line_t))
	{
		istringstream is;
		is.str(line_t); // a primeira linha fica em is

		unsigned int idCliente;
		vector<string> produtos;

		string x_str, data_str, v_str;

		// lê o id da transação
		getline(is, x_str, ';'); idCliente = stoi(x_str);
		atualizaMaxID(idCliente);

		// lê a data da transação
		getline(is, data_str, ';'); trim(data_str);

		Data data(data_str);

		// lê os produtos da transação
		getline(is, v_str, ';');

		stringstream prods(v_str); string prod;

		while (getline(prods, prod, ','))
		{
			trim(prod);
			produtos.push_back(prod);
		}

		Transacao transacaoAtual(idCliente, data, produtos);

		transacoes.push_back(transacaoAtual);
	}
}

void VendeMaisMais::atualizaMaxID(int n)
{
	if (n > maxClientesId)
		maxClientesId = n;

}


/*********************************
* Gestao de Clientes
********************************/

void VendeMaisMais::printSingleClient()
{
	unsigned int id;
	bool b = true;

	cout << "Introduza o ID do cliente: ";
	cin >> id;
	for (int a = 0; a < clientes.size(); a++) {
		unsigned int c = clientes[a].getId();
		if (c == id) {
			clearScreen();
			layout();
			cout << endl << TAB_BIG << "| CLIENTE |\n\n";
			cout << "\n   ID           Nome do Cliente      Data de adesao     Montante de compras" << endl;
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << clientes[a];
			b = false;
		}
	}
	if (b) { cout << "ID inexistente." << endl; }
	cin.get();
}

void VendeMaisMais::printClients()
{

	cout << "\n   ID           Nome do Cliente      Data de adesao     Montante de compras" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		cout << clientes[i];
	}

	cin.get();
}

void VendeMaisMais::displayClientesABC() {
	vector<Cliente> clientesABC = clientes;
	sort(clientesABC.begin(), clientesABC.end());
	cout << "\n   ID           Nome do Cliente      Data de adesao     Montante de compras" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (unsigned int i = 0; i < clientesABC.size(); i++)
	{
		cout << clientesABC[i];
	}

	cin.get();
}

void VendeMaisMais::criarCliente()
{
	int id;
	id = maxClientesId + 1;
	maxClientesId = id;

	string nome;
	cin.ignore();
	cout << "Introduza o nome do cliente: "; getline(cin, nome); trim(nome);

	char date[9];
	_strdate_s(date);

	string dia, mes, ano, data;

	mes = date[0]; mes = mes + date[1];
	dia = date[3]; dia = dia + date[4];
	ano = "20"; ano = ano + date[6]; ano = ano + date[7];
	data = dia + '/' + mes + '/' + ano;

	Data cartaoCliente(data);

	float volCompras = 0.00;

	Cliente clienteNovo(id, nome, cartaoCliente, volCompras);

	clientes.push_back(clienteNovo);
}

void VendeMaisMais::removerCliente()
{
	int id;
	int a;
	bool exist = false;

	cout << "\nIntroduza o ID do cliente: ";
	cin >> id;

	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		if (id == clientes[i].getId())
		{
			a = i;
			exist = true;
		}
	}

	if (exist == true)
	{
		char x;

		cout << "\nTem a certeza que pretende apagar o cliente '" << clientes[a].getNome() << "' (S/N) : ";
		cin >> x;
		x = tolower(x);

		switch (x)
		{
		case 's':
			clientes.erase(clientes.begin() + (a));
			cout << "\nO cliente foi removido com sucesso.";
			cin.get();
			break;
		case 'n':
			cout << "\nOperacao cancelada\n";
		default:
			break;
		}
	}
	else
	{
		cout << "\nO cliente nao existe." << endl;
		cin.get();

	}

	cin.get();
}

void VendeMaisMais::alterarCliente()
{
	int id;
	bool exist = false;
	cout << "\nIdentificador do cliente que deseja modificar: ";
	cin >> id;

	if (!(int)id)               // VERIFICAR INPUT INVALIDO !!!
		cout << "\nInput invalido" << endl;
	else {
		for (unsigned int i = 0; i < clientes.size(); i++)
		{
			if (id == clientes[i].getId())
			{
				string name;

				cin.ignore();
				cout << "\nNovo nome do cliente: ";
				getline(cin, name);
				//cin.ignore();

				clientes[i].setNome(name);

				exist = true;

				int d, m, y;

				cout << "\nInserir data\nAno: ";
				cin >> y;
				cout << "Mes: ";
				cin >> m;
				cout << "Dia: ";
				cin >> d;

				if (m > 12 || m < 1)
				{
					cout << "\nA data inserida nao e valida";
					cin.get();
				}
				else
				{
					if (!(isValidDate2(y, m, d)))
					{
						cout << "\nA data inserida nao e valida";
						cin.get();
					}
					else
					{
						Data data(y, m, d);

						clientes[i].setData(data);
					}
				}
			}
		}

		if (exist == false)
			cout << "\nO cliente nao existe." << endl;
		cin.get();
	}
}


/*********************************
* Gestao de Produtos
********************************/

void VendeMaisMais::printProducts() {

	vector<Produto> produtosABC = produtos;
	sort(produtosABC.begin(), produtosABC.end());

	cout << "\n              Produtos                 Custo" << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	for (unsigned int i = 0; i < produtos.size(); i++)
	{
		cout << produtosABC[i];
	}

	cin.get();
}


/*********************************
* Gestao de Transações
********************************/

void VendeMaisMais::addTransaction() {
	int id;
	bool b = true;
	cout << "Introduza o ID do cliente: "; cin >> id;

	for (int a = 0; a < clientes.size(); a++)
	{
		unsigned int c = clientes[a].getId();
		if (c == id) {
			b = false;
		}
	}

	if (b)
	{
		cout << "\nID inexistente na lista de clientes." << endl;
		cin.get();
		return;
	}


	char date[9];
	_strdate_s(date);

	string dia, mes, ano, dati;

	mes = date[0]; mes = mes + date[1];
	dia = date[3]; dia = dia + date[4];
	ano = "20"; ano = ano + date[6]; ano = ano + date[7];
	dati = dia + '/' + mes + '/' + ano;

	Data data(dati);


	bool again = false;
	string product;
	vector<string> vectorProds;
	do
	{

		char x;
		bool invalid = false;
		bool bo = false;
		float preco;

		cout << "\nProduto a adicionar: ";
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, product);

		for (unsigned int i = 0; i < produtos.size(); i++) {
			if (product == produtos[i].getNome()) {
				bo = true;
				//preco = produtos[i].getCusto();
			}
		}

		if (bo) {

			for (unsigned int i = 0; i < produtos.size(); i++)
			{
				produtoIdx.insert(pair <string, int>(produtos[i].getNome(), i));
			}

			preco = produtos[produtoIdx[product]].getCusto();


			vectorProds.push_back(product);

			//	clientes[a].get();**************************************************************************************

			for (int g = 0; g < clientes.size(); g++) {
				unsigned int l = clientes[g].getId();
				if (l == id) {
					float nc = clientes[g].getVolCompras() + preco;
					clientes[g].setVolCompras(nc);

				}
			}

			//******************************************************************************************************

			cout << endl;

			do
			{
				cout << "Deseja adicionar outro produto? (S/N)  :  ";
				cin >> x;
				x = tolower(x);

				if (x == 's')
				{
					invalid = false;
					again = true;
				}
				else
				{
					if (x == 'n')
					{
						again = false;
						invalid = false;
					}
					else
					{
						cout << "\nInput invalido!\n\n";
						invalid = true;
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}


			} while (invalid);
		}
		else {
			cout << "\nProduto inexistente na loja\n\n";
			do
			{
				cout << "Deseja adicionar outro produto? (S/N)  :  ";
				cin >> x;
				x = tolower(x);

				if (x == 's')
				{
					invalid = false;
					again = true;
				}
				else
				{
					if (x == 'n')
					{
						again = false;
						invalid = false;
					}
					else
					{
						cout << "\nInput invalido!\n\n";
						invalid = true;
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}


			} while (invalid);
		}
	} while (again);

	Transacao novaTransacao(id, data, vectorProds);

	transacoes.push_back(novaTransacao);
}

void VendeMaisMais::printTransactions() {
	cout << "\n   ID      Data da Transacao         Produtos" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (unsigned int i = 0; i < transacoes.size(); i++)
	{
		cout << transacoes[i];
	}

	cin.get();
}

void VendeMaisMais::printDayTransaction() {
	//string dd;
	int year, month, day;
	bool jj = true;
	//cout << "Introduza a data que pretende(DD/MM/AAAA): ";
	//cin >> dd;

	cout << "Ano da data: ";
	cin >> year;
	cout << "Mes da data: ";
	cin >> month;
	cout << "Dia da data: ";
	cin >> day;
	int value = day + (month * 31) + (year * 365);
	clearScreen();
	layout();
	for (int a = 0; a < transacoes.size(); a++) {
		string dt = transacoes[a].getDataT();
		int day2 = stoi(dt.substr(0, 2));
		int month2 = stoi(dt.substr(3, 2));
		int year2 = stoi(dt.substr(6, 4));
		int value2 = day2 + (month2 * 31) + (year2 * 365);
		if (value == value2) {
			cout << "\n   ID      Data da Transacao         Produtos" << endl;
			cout << "-----------------------------------------------------------------------------" << endl;
			cout << setw(5) << transacoes[a].getIdCliente()
				<< setw(20) << transacoes[a].getDataT()
				<< setw(7) << "   ";
			for (unsigned int j = 0; j < transacoes[a].getProducts().size(); j++) {
				if (j == transacoes[a].getProducts().size() - 1)
				{
					jj = false;
					cout << transacoes[a].getProducts()[j] << endl;
				}
				else { cout << transacoes[a].getProducts()[j] << ", "; }

			}
		}


		if (jj) {
			cout << "\nNao houveram transacoes nessa data";
		}

	}cin.get();
}

void VendeMaisMais::imprimeDiaTrans()
{
	int d, m, y;
	bool nexist = true, jj = true;

	cout << "Introduzir data\n";
	cout << "Ano: ";
	cin >> y;
	cout << "Mes: ";
	cin >> m;
	cout << "Dia: ";
	cin >> d;

	for (unsigned int i = 0; i < transacoes.size(); i++)
	{
		if (d == transacoes[i].getDiaT() && m == transacoes[i].getMesT() && y == transacoes[i].getAnoT())
		{
			nexist = false;
		}
	}

	if (m > 12 || m < 1)
	{
		cout << "\nA data inserida nao e valida";
		cin.get();
	}
	else
	{
		if (!(isValidDate2(y, m, d)))
		{
			cout << "\nA data inserida nao e valida";
			cin.get();
		}
		else {

			if (nexist)
				cout << "\nNao existem transacoes nessa data" << endl;
			else
			{

				cout << "\n   ID      Data da Transacao         Produtos" << endl;
				cout << "-----------------------------------------------------------------------------" << endl;


				for (unsigned int i = 0; i < transacoes.size(); i++)
				{
					if (d == transacoes[i].getDiaT() && m == transacoes[i].getMesT() && y == transacoes[i].getAnoT())
					{
						cout << transacoes[i];
					}
				}
			}
		}

		cin.get();
	}
}

void VendeMaisMais::printTbetweenDates() {
	bool t = true;
	int day1, day2, month1, month2, year1, year2;
	int value1, value2;
	cout << "Ano da primeira data: ";
	cin >> year1;
	cout << "Mes da primeira data: ";
	cin >> month1;
	cout << "Dia da primeira data: ";
	cin >> day1;
	cout << "Ano da segunda data: ";
	cin >> year2;
	cout << "Mes da segunda data: ";
	cin >> month2;
	cout << "Dia da segunda data: ";
	cin >> day2;
	cout << endl;
	clearScreen();
	layout();
	value1 = day1 + (month1 * 31) + (year1 * 365);
	value2 = day2 + (month2 * 31) + (year2 * 365);
	cout << "\n    | TRANSACOES ENTRE 2 DATAS |\n\n";
	cout << "\n   ID      Data da Transacao         Produtos" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (int a = 0; a < transacoes.size(); a++) {
		string dt = transacoes[a].getDataT();
		int day = stoi(dt.substr(0, 2));
		int month = stoi(dt.substr(3, 2));
		int year = stoi(dt.substr(6, 4));
		if (((year * 365) + (month * 31) + (day)) >= value1) {
			if (((year * 365) + (month * 31) + (day)) <= value2) {

				cout << setw(5) << transacoes[a].getIdCliente()
					<< setw(20) << transacoes[a].getDataT()
					<< setw(7) << "   ";
				for (unsigned int j = 0; j < transacoes[a].getProducts().size(); j++) {
					if (j == transacoes[a].getProducts().size() - 1)
					{
						t = false;
						cout << transacoes[a].getProducts()[j] << endl;
					}
					else { cout << transacoes[a].getProducts()[j] << ", "; }

				}
			}
		}
	}
	if (t) { cout << "\n\nNao houve transacoes entre as duas datas apresentadas." << endl; }
	cin.get();
}

//nova betweenDates
void VendeMaisMais::imprimeEntreDatas()
{
	int d1, d2, m1, m2, y1, y2;
	bool nexist = true;

	cout << "Inserir data\nAno: ";
	cin >> y1;
	cout << "Mes: ";
	cin >> m1;
	cout << "Dia: ";
	cin >> d1;

	cout << "\nInserir outra data\nAno: ";
	cin >> y2;
	cout << "Mes: ";
	cin >> m2;
	cout << "Dia: ";
	cin >> d2;
	cout << endl;

	for (unsigned int i = 0; i < transacoes.size(); i++)
	{

		if (compareDates(d1, d2, transacoes[i].getDiaT(), m1, m2, transacoes[i].getMesT(), y1, y2, transacoes[i].getAnoT()))
		{
			nexist = false;
		}
	}

	if (m1 > 12 || m1 < 1 || m2 > 12 || m1 < 1)
		cout << "As datas inseridas nao sao validas";
	else
	{
		if (!(isValidDate(y1, m1, d1, y2, m2, d2)))
			cout << "As datas inseridas nao sao validas";

		else
		{
			if (nexist)
				cout << "Nao existe nenhuma transacao entre as duas datas";
			else
			{
				clearScreen();
				layout();


				cout << endl << TAB_BIG << "| TRANSACOES ENTRE 2 DATAS |\n\n";
				cout << "\n   ID      Data da Transacao         Produtos" << endl;
				cout << "-----------------------------------------------------------------------------" << endl;



				for (unsigned int i = 0; i < transacoes.size(); i++)
				{

					if (compareDates(d1, d2, transacoes[i].getDiaT(), m1, m2, transacoes[i].getMesT(), y1, y2, transacoes[i].getAnoT()))
					{
						cout << transacoes[i];

					}
				}
			}
		}
	}

	cin.get();

}

void VendeMaisMais::printClientTransaction() {
	string name;
	bool bl = true;

	cout << "Nome do cliente que pretende ver: ";
	cin.ignore();
	getline(cin, name);

	for (int k = 0; k < clientes.size(); k++)
	{
		if (name == clientes[k].getNome())
		{
			bl = false;
		}
	}

	if (bl)
	{
		cout << "\nCliente Inexistente";
	}
	else
	{
		for (unsigned int i = 0; i < clientes.size(); i++)
		{
			clienteIdx.insert(pair <string, int>(clientes[i].getNome(), i));
		}

		unsigned int idd = clientes[clienteIdx[name]].getId();

		clearScreen();
		layout();
		cout << endl << TAB_BIG << "| TRANSACOES DE UM CLIENTE |\n\n";
		cout << "\n   ID      Data da Transacao         Produtos" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		for (int a = 0; a < transacoes.size(); a++)
		{
			if (idd == transacoes[a].getIdCliente())
			{
				cout << transacoes[a];
			}
		}
	}
	//cin.get();
}

void VendeMaisMais::printCrono()
{
	vector<Transacao> t = transacoes;
	sort(t.begin(), t.end());
	string nm;
	bool bl = true;

	cout << "Nome do Cliente: ";
	cin.ignore();
	getline(cin, nm);


	for (int k = 0; k < clientes.size(); k++)
	{
		if (nm == clientes[k].getNome())
		{
			bl = false;
		}
	}

	if (bl)
		cout << "\nCliente inexistente";
	else {



		clearScreen();
		layout();
		cout << endl << TAB_BIG << "| TRANSACOES DE UM CLIENTE |\n\n";
		cout << "\n   ID      Data da Transacao         Produtos" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		for (int k = 0; k < clientes.size(); k++)
		{
			if (nm == clientes[k].getNome())
			{
				bl = false;
				unsigned int idd = clientes[k].getId();

				for (int a = 0; a < t.size(); a++)
				{
					if (idd == t[a].getIdCliente()) {

						cout << t[a];
					}
				}
			}


		}

	}

	//cin.get();
}

// printCrono com maps
void VendeMaisMais::printCronologicamente()
{
	vector<Transacao> t = transacoes;
	sort(t.begin(), t.end());
	string nm;
	bool bl = true;

	cout << "Nome do Cliente: ";
	cin.ignore();
	getline(cin, nm);


	for (unsigned int k = 0; k < clientes.size(); k++)
	{
		if (nm == clientes[k].getNome())
		{
			bl = false;
		}
	}

	if (bl)
		cout << "\nCliente inexistente";
	else
	{
		for (unsigned int i = 0; i < clientes.size(); i++)
		{
			clienteIdx.insert(pair <string, int>(clientes[i].getNome(), i));
		}

		unsigned int idd = clientes[clienteIdx[nm]].getId();

		clearScreen();
		layout();
		cout << endl << TAB_BIG << "| TRANSACOES DE UM CLIENTE |\n\n";
		cout << "\n   ID      Data da Transacao         Produtos" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;


		for (int a = 0; a < t.size(); a++)
		{
			if (idd == t[a].getIdCliente())
			{
				cout << t[a];
			}
		}
	}
	//cin.get();
}




/*********************************
* Recomendações
********************************/

// | 4 | RECOMENDAÇÕES - A concluir...

bool compararMontanteClientes(Cliente c1, Cliente c2) {
	return c1.getVolCompras() < c2.getVolCompras();

}

/* void VendeMaisMais::Bottom5(){
	vector<Cliente> beta = clientes;
	vector<Cliente> b5;
	sort(beta.begin(), beta.end(), compararMontanteClientes);
	for (unsigned int i = 0; i < clientes.size() && i <= 4; i++)
	{
		b5.push_back(clientes[i]);
	}
} */

void VendeMaisMais::printBottom10() {
	vector<Cliente> beta = clientes;
	//vector<Cliente> b5;
	sort(beta.begin(), beta.end(), compararMontanteClientes);
	cout << "\n   ID      Nome do Cliente     Data de adesao           Montante de compras" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (unsigned int i = 0; i < clientes.size() && i <= 9; i++)
	{
		cout << setw(5) << beta[i].getId()
			<< setw(20) << beta[i].getNome()
			<< setw(20) << beta[i].getData()
			<< setw(20) << fixed << setprecision(2) << beta[i].getVolCompras() << endl;
	}

	cin.get();
}








/*

/*********************************
* Gestao de Clientes
********************************

// lista os clientes por ordem alfabetica crescente
void VendeMaisMais::listarClientesOrdemAlfa() const {

	// A IMPLEMENTAR

}

// mostra a informacao individual de um cliente
void VendeMaisMais::mostraInformacaoCliente(string nome) {



}

/*********************************
* Gestao de Produtos
********************************

// lisat os produto por ordem alfabetica crescente
void VendeMaisMais::listarProdutos() const {

	// A IMPLEMENTAR

}


/*********************************
* Preservar Informacao
********************************/

// guarda apenas a informacao de clientes e/ou de transacoes que foi alterada
void VendeMaisMais::saveChanges() const
{

	ofstream fout;
	fout.open(fichClientes);

	if (fout.fail())
	{
		cerr << "Erro a abrir o ficheiro de clientes para output.\n";
		exit(2);
	}

	fout << clientes.size() << endl;

	for (unsigned int i = 0; i < clientes.size(); i++)
	{
		clientes[i].save(fout);
	}

	fout.close();


	ofstream foutt;
	foutt.open(fichTransacoes);

	if (foutt.fail())
	{
		cerr << "Erro a abrir o ficheiro de transacoes para output.\n";
		exit(2);
	}

	foutt << transacoes.size() << endl;

	for (unsigned int i = 0; i < transacoes.size(); i++)
	{
		transacoes[i].save(foutt);
	}

	foutt.close();

}

/*********************************
* Mostrar Loja
********************************/
unsigned int VendeMaisMais::getNumClientes() const
{
	return clientes.size();

}

unsigned int VendeMaisMais::getNumProdutos() const
{
	return produtos.size();

}

unsigned int VendeMaisMais::getNumTransacoes() const
{
	return transacoes.size();

}

ostream& operator<<(ostream& out, const VendeMaisMais & supermercado) {

	out << "  | Numero de clientes   | " << setw(3) << supermercado.getNumClientes() << endl
		<< "  | Numero de produtos   | " << setw(3) << supermercado.getNumProdutos() << endl
		<< "  | Numero de transacoes | " << setw(3) << supermercado.getNumTransacoes() << endl;

	return out;
}
