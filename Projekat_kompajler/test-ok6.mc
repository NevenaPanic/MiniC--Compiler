//OPIS: Void tip funkcije
//RETURN: 13
void fun(int n)
{
	int m;
	m = n + n;
	// nista je isto okej kod void f-je
}

void fun2(unsigned m)
{
	m = m + m;
	return ; // ovo je okej
}

int main()
{
	int b, c;
	unsigned l;
	l = 9u;
	b = 4;
	c = 9;
	
	fun(c);
	fun(2);
	
	fun2(l);
	fun2(8u);

	return c + b;
}
