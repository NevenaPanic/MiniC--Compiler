//OPIS: Funkcija sa vise parametara i poziv iste
//RETURN: 5

int funkcija(int a, unsigned b, int c, unsigned d)
{
	a = a + c;
	b = b + b + d;
	return a;
}

int main()
{

	int m, n, p , o;
	unsigned k, l;
	
	m = 1; 
	n = 4;
	k = 9u;
	l = 3u;
	
	p = funkcija(m , k, n, l);
	o = funkcija(1, 3u, 5, 9u);

	return p;
}
