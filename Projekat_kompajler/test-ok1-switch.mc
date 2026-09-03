 //OPIS: switch
//RETURN: 18
int main()
{
    int a, b, l;
    a = 9;
    b = 2;
    l = a;
    
    switch(l)
    {
        case 2:
            a = a * 2;
            break;
        case 9:
            a = a + 9;
            break;
        case 7:
            a = a * 7 + 7;
            break;           

        default:
            a = 24;
    }

    return a;
}
