//OPIS: Branch iskaz -- okej
//RETURN: 10

int main()
{
	int a;
	unsigned b;
	b = 9u;
	a = 5; // deklarisan i koriscen

	branch ( a ; 1 , 3 , 5 )
		first a = a + 1;
		second a = a + 3;
		third a = a + 5;
		otherwise a = a - 3;
		end_branch
		
	branch ( b ; 1u , 9u , 5u )
		first b = b + 1u;
		second b = b + 3u;
		third b = b + 5u;
		otherwise b = b - 3u;
		end_branch
		
	return a;
}
