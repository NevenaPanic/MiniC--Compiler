//OPIS: vise case labela moze da deli isto telo
//RETURN: 30
int main()
{
    int a, result;
    a = 2;
    result = 0;

    switch(a)
    {
        case 1:
        case 2:
        case 3:
            result = 30;
            break;
        default:
            result = 99;
    }

    return result;
}
