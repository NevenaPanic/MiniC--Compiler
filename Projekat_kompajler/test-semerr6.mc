// Void tip funkcije
void fun(int n)
{
	n = n + n;
	return n; // ne sme da se vrati vrednost, greska
}

void fun2(unsigned m)
{
	m = m + m;
	return m; // ne sme da se vrati vrednost void f-ji
}

void fun3(void f) // ovo isto ne sme, greska
{
	f++; // greska isto
}

int main()
{
	int b, c;
	unsigned l;
	void f; // ovo nece proci, greska
	
	fun3(f); // ovo ne sme, greska
	
	l = 9u;
	b = 4;
	c = 9;
	
	fun(c);
	fun(2);
	
	fun2(l);
	fun2(8u);

}
