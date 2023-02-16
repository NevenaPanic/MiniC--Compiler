// Branch iskaz -- okej

int main()
{
	unsigned b;
	int c;
	c = 9;
	b = 9u; 

	branch ( a ; 1 , 3 , 5 ) // nedeklarisana a, greska
		first a = a + 1;
		second a = a + 3;
		third a = a + 5;
		otherwise a = a - 3;
		end_branch
		
	branch ( b ; 1u , 9u , 5u )
		first b = b + 1u;
		second b = b + 3; 	// neodgovarajuca vrednost dodele, greska
		third b = b + 5u;
		otherwise b = b - 3u;
		end_branch
		
	branch ( c ; 1 , 3u , 5 ) // pogresan tip za constante, nije isti kao c, greska
		first c = c + 1;
		second c = c + 3; 
		third c = c + 5;
		otherwise c = c - 3;
		end_branch
		
	return 0;
}
