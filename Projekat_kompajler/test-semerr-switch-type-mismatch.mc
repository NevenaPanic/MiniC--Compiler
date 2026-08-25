//OPIS: case vrednost mora imati isti tip kao switch izraz
//RETURN: 0
int main()
{
    int a, result;
    a = 1;
    result = 0;

    switch(a)
    {
        case 1u:
            result = 1;
    }

    return result;
}
