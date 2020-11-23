#include <stdio.h>
#include <stdlib.h>

void pomenyatt (int*a, int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void bebebe(int a[], int n, int* per, int* sr)
{
    int i, j, k;
    for(i=1; i<n; i++)
        {
            k=1;
            for(j=0; j<n-i; j++)
            {
                *sr=*sr+1;
                if(a[j]>a[j+1])
                {
                    *per=*per+1;
                    pomenyatt(&a[j], &a[j+1]);
                    k=0;
                }
            }
            if(k)
                break;
        }

}

int main1()
{
    int n, i, per=0, sr=0;
    printf("kol-vo elementov = ");
    scanf("%d", &n);
    int* a;
    a = (int*) malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", a+i);
    }
    bebebe(a, n, &per, &sr);
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\nsravneniy = %d perestanovok = %d\n", sr, per);
    return 0;
}

int lopopam (int a[], int n, int* sr, int* per)
{
    int i=0, j=n-1;
    do
    {
        while (a[i] < a[n/2])
        {
            i++;
            *sr=*sr+1;
        }
        while (a[j] > a[n/2])
        {
            j--;
            *sr=*sr+1;
        }
        *sr=*sr+2;
        if (i <= j)
        {
            *sr=*sr+1;
            if (a[i] > a[j])
            {
                pomenyatt(&a[i], &a[j]);
                *per=*per+1;
            }
            i++;
            if (j > 0)
                j--;
        }
    }
    while (i <= j);
    return j+1;
}

void s(int a[], int n, int* sr, int* per)
{
    int k;
    if(n>1)
    {
        k=lopopam(a, n, sr, per);
        s(a, k, sr, per);
        s(a+k, n-k, sr, per);
    }

}

int main2()
{
    int n, i, sr=0, per=0;
    printf("kol-vo elementov = ");
    scanf("%d", &n);
    int* a;
    a = (int*) malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", a+i);
    }
    s(a, n, &sr, &per);
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\nsravneniy = %d perestanovok = %d\n", sr, per);
    return 0;
}

void bababa(int a[], int n, int* sr, int* per)
{
        int i, k, m;
        for(k=0; k<n-1; k++)
        {
            m=k;
            for(i=k+1; i<n; i++)
            {
                *sr=*sr+1;
                if (a[i]<a[m])
                    m=i;
            }
            pomenyatt(a+k, a+m);
            *per=*per+1;
        }
}

int main3()
{
    int n, i, sr=0, per=0;
    printf("kol-vo elementov = ");
    scanf("%d", &n);
    int* a;
    a = (int*) malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", a+i);
    }
    bababa(a, n, &sr, &per);
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\nsravneniy = %d perestanovok = %d\n", sr, per);
    return 0;
}


int main()
{
    int k;
    printf("Task 8\nvyberite zadanie:\n1 Bubble sort\n2 Quicksort\n3 Selection sort\n");
    scanf("%d", &k);
    switch(k)
    {
    case 1:
        k=main1();
        break;
    case 2:
        k=main2();
        break;
    case 3:
        k=main3();
        break;
    default:
        printf("Takogo nomera net, poprobuyte eshche raz\n");
        k=0;
    }
    printf("nazhmite <<1>>, esli hotite prodolzhitb\n");
    scanf("%d", &k);
    if(k==1)
        main();
    return 0;
}
