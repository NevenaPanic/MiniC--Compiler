//OPIS: switch izraz sa sporednim efektom se izracunava samo jednom
//RETURN: 1
int counter;

int nextvalue()
{
    counter = counter + 1;
    return counter;
}

int main()
{
    int result;
    counter = 0;
    result = 0;

    switch(nextvalue())
    {
        case 1:
            result = counter;
            break;
        default:
            result = 99;
    }

    return result;
}
