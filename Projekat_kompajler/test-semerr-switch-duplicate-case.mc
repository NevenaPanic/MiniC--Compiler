//OPIS: numericki jednake case vrednosti moraju biti prijavljene kao duplikati
//RETURN: 0
int main()
{
    int a, result;
    a = 1;
    result = 0;

    switch(a)
    {
        case 1:
            result = 1;
            break;
        case 01:
            result = 2;
            break;
    }

    return result;
}
