#pragma once

#include <iostream>
#include <fstream>
#include <string>


#include "defs.h"
#include "utils.h"
#include "Vende++.h"

using namespace std;

bool infoInicial(string & loja, string & fichClients, string & fichProdutos, string & fichTransacoes);  // verifica se os ficheiros sao validos

void opcoesIniciais(VendeMaisMais & supermercado);  // menu inicial

void opcoesGestaoClientes(VendeMaisMais & supermercado); // menu de clientes

void opcoesGestaoTransacoes(VendeMaisMais & supermercado);  // menu de transacoes

void opcoesRecomendacao(VendeMaisMais & supermercado);       // menu de recomendações
