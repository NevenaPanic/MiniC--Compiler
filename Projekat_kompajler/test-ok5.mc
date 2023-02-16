//OPIS: Postincrement da radi 
//RETURN: 4

int inc(int x)
{
	x++;
	return x;
}

int main()
{
	int a, b, c;
	unsigned m, n, p;
	a = 0;
	b = 0;
	m = 1u;
	n = 2u;
	a++;
	
	b = a++;
	c = a + b++;

	m++;
	n++;
	p = m++ + n++;

	return a + b;
}
