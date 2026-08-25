//OPIS: switch ne sme da sadrzi vise od jedne default grane
//RETURN: 0
int main()
{
    int a, result;
    a = 1;
    result = 0;

    switch(a)
    {
        default:
            result = 1;
            break;
        default:
            result = 2;
    }

    return result;
}
