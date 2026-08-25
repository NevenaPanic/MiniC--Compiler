//OPIS: default moze da se nalazi pre case grana i grana ima vise naredbi
//RETURN: 15
int main()
{
    int a, result;
    a = 2;
    result = 0;

    switch(a)
    {
        default:
            result = 99;
            break;
        case 2:
            result = 10;
            result = result + 5;
            break;
        case 3:
            result = 30;
    }

    return result;
}
