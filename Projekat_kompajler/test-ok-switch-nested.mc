//OPIS: ugnjezdeni switch cuva odvojene kontekste i break labele
//RETURN: 17
int main()
{
    int a, b, result;
    a = 1;
    b = 2;
    result = 0;

    switch(a)
    {
        case 1:
            switch(b)
            {
                case 2:
                    result = 7;
                    break;
                default:
                    result = 90;
            }
            result = result + 10;
            break;
        default:
            result = 99;
    }

    return result;
}
