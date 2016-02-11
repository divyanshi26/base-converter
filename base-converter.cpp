#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

typedef long long int ll;

//int dest[20], nd;
char num[1000000], c[2], nums[1000000];
ll n, i, j, a, d, fnum, inum;
int src, dest;

void init()
{
    d = -1;
    nums[0] = '\0';
    c[1] = '\0';
    return;
}

ll dec_to_n(ll n, int dest)
{
    if(n == 0)
        return 0;
    a = n % dest;
    switch(a)
    {
        case 0:
            c[0] = '0';
            break;
        case 1:
            c[0] = '1';
            break;
        case 2:
            c[0] = '2';
            break;
        case 3:
            c[0] = '3';
            break;
        case 4:
            c[0] = '4';
            break;
        case 5:
            c[0] = '5';
            break;
        case 6:
            c[0] = '6';
            break;
        case 7:
            c[0] = '7';
            break;
        case 8:
            c[0] = '8';
            break;
        case 9:
            c[0] = '9';
            break;
        case 10:
            c[0] = 'A';
            break;
        case 11:
            c[0] = 'B';
            break;
        case 12:
            c[0] = 'C';
            break;
        case 13:
            c[0] = 'D';
            break;
        case 14:
            c[0] = 'E';
            break;
        case 15:
            c[0] = 'F';
            break;
        case 16:
            c[0] = 'G';
            break;
        case 17:
            c[0] = 'H';
            break;
        case 18:
            c[0] = 'I';
            break;
        case 19:
            c[0] = 'J';
            break;
        case 20:
            c[0] = 'K';
            break;
    }
    n /= dest;
    d++;
    strcat(nums, c);
    printf("Number = %s\n", nums);
    return ((pow(10, d) * a) + dec_to_n(n, dest));
}

ll n_to_dec(char num[], int src)
{
    d = 0, i = strlen(num);
    ll dec = 0;
    while(i)
    {
        switch(num[i-1])
        {
            case 'a':
            case 'A':
                a = 10;
                break;
            case 'b':
            case 'B':
                a = 11;
                break;
            case 'c':
            case 'C':
                a = 12;
                break;
            case 'd':
            case 'D':
                a = 13;
                break;
            case 'e':
            case 'E':
                a = 14;
                break;
            case 'f':
            case 'F':
                a = 15;
                break;
            case 'g':
            case 'G':
                a = 16;
                break;
            case 'h':
            case 'H':
                a = 17;
                break;
            case 'i':
            case 'I':
                a = 18;
                break;
            case 'j':
            case 'J':
                a = 19;
                break;
            default:
                c[0] = num[i-1];
                c[1] = '\0';
                a = atoll(c);
        }
        dec += (pow(src, d) * a);
        i--;
        d++;
    }
    return dec;
}

void reverse_num()
{
    for(i = 0, j = strlen(nums)-1; i < j; i++, j--)
    {
        char c = nums[i];
        nums[i] = nums[j];
        nums[j] = c;
    }
}

int main()
{
    char ch;
    do
    {
        init();
        printf("Enter the source base: ");
        scanf("%d", &src);
        printf("Enter a number: ");
        scanf("%s", num);
        printf("Enter the destination base(s) (If more than one, separate by a space): ");
        /*scanf("%s", deststr);
        dest = convert_to_num(deststr);*/
        scanf("%d", &dest);

        /*printf("Base\tNumber\n");
        for(i = 0; i < nd; i++)
        {
            (dest[i]);
        }*/

        if (src == 10 && dest == 10)
        {
            fnum = n;
        }
        else if (src == 10)
        {
            n = atoll(num);
            fnum = dec_to_n(n, dest);
            reverse_num();
        }
        else if (dest == 10)
        {
            fnum = n_to_dec(num, src);
        }
        else
        {
            inum = n_to_dec(num, src);
            fnum = dec_to_n(inum, dest);
            reverse_num();
        }

        printf("\nConverted number = %lld\n", fnum);
        printf("\nActual number = %s\n", nums);

        printf("Do you wish to do more conversions? (y/n): ");
        scanf(" %c", &ch);
    }
    while(ch == 'y' || ch == 'Y');
}
