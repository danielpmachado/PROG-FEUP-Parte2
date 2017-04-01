#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include<algorithm>
#include <iomanip>
#include <tchar.h>
#include <sstream>

#include "defs.h"

using namespace std;

void layout(); // mostra o cabeçalho do programa

void clearScreen();  // limpa o ecrâ

unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int max);  // faz com que seja apenas possivel ler inteiros validos entre o min e o max 

double string_to_double(const std::string& s);  // funcao auxiliar que transforma uma string num double

void trim(string &str);  // remove os espaços no inicio e no fim de uma string dada

void latestDate(int &d1, int &m1, int &y1, int &d2, int &m2, int &y2);  // funcao que coloca nas variaveis 1 a data mais antiga

bool compareDates(int d1, int d2, int d3, int m1, int m2, int m3, int y1, int y2, int y3); // função que verifica se a data 3 se encontra entre 1 e 2

bool anoBissexto(int n); // função auxiliar que verifica se um ano é bissexto

int diasMes(int a, int m);  // funcao auxiliar que devolve os dias de um dado mes

bool isValidDate(int &y1, int &m1, int &d1, int &y2, int &m2, int &d2); // funçao auxiliar que verifica ambas as datas sao validas

bool isValidDate2(int &y, int &m, int &d); // funçao auxiliar que verifica se uma data e valida



