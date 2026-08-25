//OPIS: switch podrzava vise od deset case grana
//RETURN: 11
int main()
{
    int a, result;
    a = 11;
    result = 0;

    switch(a)
    {
        case 1: result = 1; break;
        case 2: result = 2; break;
        case 3: result = 3; break;
        case 4: result = 4; break;
        case 5: result = 5; break;
        case 6: result = 6; break;
        case 7: result = 7; break;
        case 8: result = 8; break;
        case 9: result = 9; break;
        case 10: result = 10; break;
        case 11: result = 11; break;
        default: result = 99;
    }

    return result;
}
