//OPIS: Postincrement ok
//RETURN: 8
int main()
{
	int a, c;
	unsigned b;
	
	a = 5;
	c = 3;
	b = 7u;
	
	a = a + a++ - c;
	
	return a;
}
