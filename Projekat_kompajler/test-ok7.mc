//OPIS: Ok return 
//RETURN: 2
void f(int m)
{
	m++;
	return ; // ok
}

void f1(int m, int l)
{
	m = m + l;
	// ok bez icega
}

int f2(int e)
{
	return e; // ok
}


unsigned f5(unsigned q)
{
	return q; //ok
}



int main()
{

	int a, b, c;
	unsigned j, k;
	
	a = 20;
	b = 3;
	
	f(5);
	f(a);
	
	f1(1, 5);
	f1(a, b);
	
	a = f2(2);
	b = f2(a);



	return b;
}
