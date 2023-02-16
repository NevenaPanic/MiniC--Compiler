// Greska, increment se ne moze primeniti na poziv funkcije
int f(int gg)
{
	return gg;
}

int main()
{
	int w;
	unsigned v;

	w++;
	v++;
	w = f++;

	return 0;
}
