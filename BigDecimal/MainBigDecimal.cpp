#include"BigDecimal.h"
#include <string>


BigDecimal::BigDecimal()
{
	this->len = 0;

	this->cifre = new char[len + 1];
}

BigDecimal::BigDecimal(char* A, int lungime)
{
	len = lungime;
	cifre = new char[len + 1];
	strcpy(cifre, A);

}

BigDecimal::BigDecimal(char* A)
{
	len = strlen(A);
	cifre = new char[strlen(A) + 1];
	strcpy(cifre, A);

}

BigDecimal::BigDecimal(const BigDecimal& B)
{
	this->len = B.len;
	this->cifre = new char[B.len + 1];
	strcpy(cifre, B.cifre);

}

long BigDecimal::transforma()
{

	long addcif = 0; int cif = 0;

	for (int i = 0; i <= len - 1; i++)
	{
		cif = *(cifre + i) - '0';

		addcif = addcif + cif;
		addcif = addcif * 10;

	}

	return addcif / 10;

}

BigDecimal::BigDecimal(long num)
{
	long number_aux = num; int nr_cif = 0;

	while (number_aux != 0)
	{
		number_aux = (long)number_aux / 10;
		nr_cif++;
	}

	number_aux = num;

	char* numar = new char[nr_cif + 1];

	for (int i = nr_cif - 1; i >= 0; i--)
	{

		*(numar + i) = '0' + number_aux % 10;

		number_aux = number_aux / 10;
	}


	this->cifre = numar;
	this->len = nr_cif;
}


BigDecimal::~BigDecimal()
{
	if ( cifre )
		delete[] cifre;
}


void BigDecimal::setlen(int l)
{
	this->len = l;
}

long BigDecimal::getElementAt(int poz)
{
	return  *(cifre + poz) - '0';
}


BigDecimal BigDecimal::operator + (BigDecimal& B)
{

	int i = 0;

	int lungime_curent = len - 1;
	int lungime_B = B.len - 1;


	char* suma = new char[(len >= B.len ? len : B.len) + 2];

	long in_plus = (long)0;

	while (lungime_curent >= 0 || lungime_B >= 0)
	{
		long z = 0;

		if (!(lungime_curent >= 0))
		{
			z = B.getElementAt(lungime_B) + in_plus;


			if (z >= 10)
			{
				suma[i] = (z % 10) + '0';
				in_plus = (long)1;
			}

			else {
				suma[i] = (z)+'0';
				in_plus = (long)0;
			}
		}


		else if (!(lungime_B >= 0))
		{
			z = getElementAt(lungime_curent) + in_plus;

			if (z >= 10)
			{
				suma[i] = (z % 10) + '0';
				in_plus = (long)1;
			}

			else {
				in_plus = (long)0;
				suma[i] = (z)+'0';
			}
		}


		else if (lungime_curent >= 0 && lungime_B >= 0)
		{
			z = getElementAt(lungime_curent) + B.getElementAt(lungime_B) + in_plus;


			if (z >= 10)
			{
				suma[i] = (z % 10) + '0';
				in_plus = (long)1;
			}

			else {
				in_plus = (long)0;
				suma[i] = (z) + '0';
			}
		}


		i++;
		lungime_curent--;
		lungime_B--;

	}


	if (in_plus != (long)0)
	{

		suma[i] = (in_plus) + '0';
		i++;
	}


	int lungime = i; char* suma_inv = new char[i + 1];

	for (int j = 0; j < i; j++)
	{
		suma_inv[j] = suma[lungime - 1];

		lungime--;
	}


	return BigDecimal(suma_inv, i);


}

int BigDecimal::getlen()
{
	return len;
}


bool BigDecimal::operator < (BigDecimal& B)
{
	if (len > B.len)
		return false;

	else {

		int a = 0;
		int b = 0;

		while (a < len && b < B.len)
		{
			if (getElementAt(a) > B.getElementAt(b))
				return false;

			else {

				a++;
				b++;

			}
		}
	}
	return true;
}


BigDecimal& BigDecimal::operator=(const BigDecimal& b)
{
	if (this != &b)

	{
		len = b.len;

		if (cifre)
			delete[]cifre;

		cifre = new char[strlen(b.cifre) + 1];

		strcpy(cifre, b.cifre);

	}
	return *this;
}


ostream& operator<<(ostream& out, const  BigDecimal& B)
{
	for (int i = 0; i < B.len; i++)
		cout << *(B.cifre + i);

	cout << endl;
	return out;
}


istream& operator>>(istream& in, BigDecimal& B)
{
	char* temp = new char[1000000];
	in >> temp;

	B = BigDecimal(temp);
	return in;

}
int main()
{
	//declarari a 2 numere mari
	BigDecimal numar1, numar2;

	//citirea lor
	cin >> numar1;
	cin >> numar2;

	//afisarea lor
	cout << numar1 << numar2;

	//compararea a doua numere mari
	if (numar1 < numar2)
		cout << "primul e mai mic ca al doilea" << endl;
	else cout << "aldoilea e mai mic ca primul" << endl;


	//suma a doua numere mari
	cout << "Suma este: ";
	BigDecimal S;
	S = numar1 + numar2;
	cout << S;


	return 0;
}