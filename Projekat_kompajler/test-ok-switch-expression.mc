//OPIS: switch prihvata izraz i izracunava ga jednom
//RETURN: 11
int main()
{
    int a, result;
    a = 4;
    result = 0;

    switch(a + 1)
    {
        case 5:
            result = 11;
            break;
        default:
            result = 99;
    }

    return result;
}
