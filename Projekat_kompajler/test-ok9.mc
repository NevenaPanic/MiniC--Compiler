//OPIS: Opercija mnozenja i deljenja
//RETURN: -21

int main()
{
	int a, b, c;
	unsigned j,k,l;
	
	a = 5;
	b = 6; 
	c = 3;
	j = 1u;
	k = 8u;
	l = 2u;

	a = b * c;
	b = a / c + a * b - 8 * a + 3 * c;
	
	j = k * l;
	j = k / l;
	
	return b;
}
