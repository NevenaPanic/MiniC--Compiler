// For - error

int main()
{

	int zbir, razlika;
	int i;
	zbir = 0;
	razlika = 0;
	i = 6;
	
	for (int i; i < 10; i++){ // i je vec deklarisana i koriscena ne sme biti u petlji
		zbir = zbir + i;
		razlika = razlika - i;
	}
	
	for (int k; k < 3; k++)
		razlika = zbir - k;
		
	for (int k; k < 3; k++) // ne sme da se ponovi petlja sa istim iteratorom
		zbir = zbir + k;

	return 0;
}
