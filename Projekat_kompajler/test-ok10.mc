//OPIS: For - okej
//RETURN: 63

int main()
{

	int zbir, razlika, b;
	b = 0;
	zbir = 0;
	razlika = 0;
	
	// mogu ugljezdeni for-ovi
	for (int i; i < 10; i++){
		for (int j; j < 8; j++)
			b++;
	}
	
	// mogu i obicni
	for (int k; k < 3; k++)
		razlika = zbir - k;

	return b;
}
