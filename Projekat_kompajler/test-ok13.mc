//OPIS: Uslovni izraz kao deo izraza
//RETURN: 30

int main()
{
	int a;
	int b;
	a = 15;
	b = 12;
	
	a = a + (a == b) ? a : b + 3;
	
	return a;
}
