//OPIS: break je regularna naredba i moze da se nalazi unutar if naredbe
//RETURN: 5
int main()
{
    int a, result;
    a = 1;
    result = 5;

    switch(a)
    {
        case 1:
            if(a == 1)
                break;
            result = 99;
        default:
            result = 88;
    }

    return result;
}
