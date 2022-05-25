#pragma once
#include< iostream>
#pragma warning(disable : 4996)
using namespace std;
class BigDecimal
{
protected:

	char* cifre;
	int len;

public:
	BigDecimal();
	BigDecimal(char* a, int lungime);
	BigDecimal(char* a);
	BigDecimal(const BigDecimal&);
	BigDecimal(long number);


	~BigDecimal();


	friend istream& operator>> (istream&, BigDecimal&);
	friend ostream& operator<< (ostream&, const  BigDecimal&);

	BigDecimal operator + (BigDecimal&);

	BigDecimal& operator=(const BigDecimal&);

	bool operator < (BigDecimal&);


	long getElementAt(int);

	void setlen(int);
	int getlen();

	long transforma();
};
