#include "utils.h"


void layout()
{
	_tsetlocale(LC_ALL, _T("portuguese"));

	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n\n";
	cout << "			        VENDE++\n\n";
	cout << "ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл\n\n";
}

void clearScreen() 
{
	system("cls");
}

unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int  max) 
{
	bool valid = false;
	unsigned short opcao = 0;
	
	while(valid ==false)
	{
		cin >> opcao;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Inserir uma opcao valida." << endl << "Opcao: ";

		}
		else if (opcao <= max && opcao >= min)
			valid = true;
		else
		{
			cout << "Inserir uma opcao valida." << endl << "Opcao: ";
		}
	}
	return opcao;
}

double string_to_double(const std::string& s)
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
}
void trim(string &str)
{
	int i = 0;
	int spacesBegin = 0;
	while (' ' == str[i++])
	{
		spacesBegin++;
	}

	i = str.length();
	int spacesEnd = 0;

	while (' ' == str[--i])
	{
		spacesEnd++;
	}

	int strLength;

	strLength = str.length() - spacesBegin - spacesEnd;

	str = str.substr(spacesBegin, strLength);
}

void latestDate(int &d1, int &m1, int &y1, int &d2, int &m2, int &y2)
{
	if (y2 > y1)
	{
		swap(d1, d2);
		swap(m1, m2);
		swap(y1, y2);
	}
	else
	{
		if (y1 == y2)
		{
			if (m2 > m1)
			{
				swap(d1, d2);
				swap(m1, m2);
				swap(y1, y2);
			}
			else
			{
				if (m1 == m2)
				{
					if (d2 > d1)
					{
						swap(d1, d2);
						swap(m1, m2);
						swap(y1, y2);
					}
				}
			}
		}
	}
}

bool compareDates(int d1, int d2, int d3, int m1, int m2, int m3, int y1, int y2, int y3)
{
	latestDate(d1, m1, y1, d2, m2, y2);

	if (y2 < y3 && y3 < y1)
		return true;
	else
	{
		if (y2 == y3)
		{
			if (m2 < m3)
				return true;
			else
			{
				if (m2 == m3)
				{
					if (d2 <= d3)
						return true;
					else return false;
				}
				else return false;

			}
		}
		else
		{
			if (y1 == y3)
			{
				if (m3 < m1)
					return true;
				else
				{
					if (m3 == m1)
					{
						if (d3 <= d1)
							return true;
						else return false;
					}
					else return false;
				}
			}
			else return false;

		}

	}

}

bool anoBissexto(int n)
{
	if (n % 400 == 0)
		return true;
	else if (n % 100 != 0 && n % 4 == 0)
		return true;
	else return false;
}

int diasMes(int a, int m) {

	int d, f;


	if (anoBissexto(a))


		f = 29;
	else f = 28;


	switch (m)
	{
	case 1:
		d = 31;
		break;
	case 2:
		d = f;
		break;
	case 3:
		d = 31;
		break;
	case 4:
		d = 30;
		break;
	case 5:
		d = 31;
		break;
	case 6:
		d = 30;
		break;
	case 7:
		d = 31;
		break;
	case 8:
		d = 31;;
		break;
	case 9:
		d = 30;
		break;
	case 10:
		d = 31;
		break;
	case 11:
		d = 30;
		break;
	case 12:
		d = 31;
		break;
	default:
		break;
	}

	return d;
}

bool isValidDate(int &y1, int &m1, int &d1, int &y2, int &m2, int &d2)
{
	if (1 <= d1 && d1 <= diasMes(y1, m1))
		if (1 <= d2 && d2 <= diasMes(y2, m2))
			return true;
		else return false;
	else return false;

}

bool isValidDate2(int &y, int &m, int &d)
{
	if (1 <= d  && d <= diasMes(y, m))
		return true;
	else return false;
}