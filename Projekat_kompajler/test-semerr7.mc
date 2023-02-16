// Greska; void vraca vrednost
// Ok return 
void f(int m)
{
	m++;
	return ; // ok
}

void f1(int m)
{
	m++;
	// ok bez icega
}

void f2(int m)
{
	m = m++;
	return m; // error
}

int main()
{

	int a, b, c;
	unsigned j, k;
	
	f(9);
	f(a);
	
	f1(5);
	f1(b);
	
	f2(7);
	f2(c);

	return 0;
}
