//OPIS: Nema ponavljanja deklaracije promenljivih
//RETURN: 4
int fun1(int a)
{
	return a + 1;
}

unsigned fun2(int a, unsigned b)
{
	return b + b;
}

int main()
{
	int a;
	unsigned b;
	
	a = 3;
	b = 2u;
	
	return fun1(a);
}
