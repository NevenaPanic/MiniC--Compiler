/* Funkcija sa vise parametara i poziv iste, greske neogovarajuci broj argumenata, pogresni argumenti*/

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
	
	p = funkcija(m, k, n, l);
	p = funkcija(k, m, l, n); //  sva 4 parametra pogresna, izbacice sve greske
	o = funkcija(1, 3u, 5, 9u);
	o = funkcija(1, 3, 5, 9u); // 1 pogresan argument, 1 greska
	
	o = funkcija(1, 3u, 5, 9u, 7); // pogresan broj argumenata
	o = funkcija(1, 3u, 5); // pogresan broj argumenata

	return 0;
}
