//OPIS: case bez break naredbe nastavlja izvrsavanje u sledecoj grani
//RETURN: 6
int main()
{
    int a, result;
    a = 1;
    result = 0;

    switch(a)
    {
        case 1:
            result = result + 2;
        case 2:
            result = result * 3;
            break;
        default:
            result = 99;
    }

    return result;
}
