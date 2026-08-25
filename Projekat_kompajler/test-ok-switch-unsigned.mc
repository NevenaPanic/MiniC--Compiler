//OPIS: switch i case podrzavaju unsigned tip
//RETURN: 22
int main()
{
    unsigned a;
    int result;
    a = 2u;
    result = 0;

    switch(a)
    {
        case 1u:
            result = 11;
            break;
        case 2u:
            result = 22;
            break;
        default:
            result = 99;
    }

    return result;
}
