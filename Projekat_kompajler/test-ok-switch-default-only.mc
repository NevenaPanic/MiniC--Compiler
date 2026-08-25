//OPIS: switch moze da sadrzi samo default granu ako ona ima naredbu
//RETURN: 42
int main()
{
    int a, result;
    a = 8;
    result = 0;

    switch(a)
    {
        default:
            result = 42;
    }

    return result;
}
