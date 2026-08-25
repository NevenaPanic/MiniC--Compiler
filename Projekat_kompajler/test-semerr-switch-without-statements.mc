//OPIS: switch sa labelama ali bez ijedne naredbe je semanticka greska
//RETURN: 0
int main()
{
    int a;
    a = 1;

    switch(a)
    {
        case 1:
        case 2:
    }

    return 0;
}
