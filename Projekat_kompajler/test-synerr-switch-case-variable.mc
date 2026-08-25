//OPIS: case mora da koristi konstantnu literalnu vrednost
//RETURN: 0
int main()
{
    int a, b;
    a = 1;
    b = 1;

    switch(a)
    {
        case b:
            return 1;
    }

    return 0;
}
