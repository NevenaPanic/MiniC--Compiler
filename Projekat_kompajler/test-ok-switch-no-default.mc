//OPIS: bez podudaranja i bez default grane switch ne menja rezultat
//RETURN: 7
int main()
{
    int a, result;
    a = 8;
    result = 7;

    switch(a)
    {
        case 1:
            result = 10;
            break;
        case 2:
            result = 20;
    }

    return result;
}
