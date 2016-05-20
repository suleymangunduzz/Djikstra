#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

 int dugumSayisi;


int minUzaklik(int uzaklik[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < dugumSayisi; v++)
     if (sptSet[v] == false && uzaklik[v] <= min)
         min = uzaklik[v], min_index = v;

   return min_index;
}


int sonucYaz(int uzaklik[], int n)
{
   printf("Kaynak Dugumden Diger Dugumlere Minimum Uzaklik\n");
   for (int i = 0; i < dugumSayisi ; i++)
      printf("%d \t\t %d\n", i+1, uzaklik[i]);
}



int main()
{

     cout << "\nDugum Sayisi : ";
     cin   >> dugumSayisi;


   int dugumler[dugumSayisi][dugumSayisi];


    for (int i=0;i<dugumSayisi;i++)
    {
        for(int j=0;j<dugumSayisi;j++)
        {
            if(i == j)
            {
                dugumler[i][j]=0;
            }
            else if ((i>j) && (dugumler[j][i] != 0))
            {
                dugumler[i][j]=dugumler[j][i];
            }
            else
            {
                cout << "\n "<<i+1<<" . Dugumun "<<j+1<<" . dugume uzakligi : ";
                cin >> dugumler[i][j];
            }
        }
    }


    int uzaklik[dugumSayisi];

    bool sptSet[dugumSayisi];


     for (int i = 0; i < dugumSayisi ; i++)
        uzaklik[i] = INT_MAX, sptSet[i] = false;


     uzaklik[0] = 0;


     for (int count = 0; count < dugumSayisi-1; count++)
     {

       int u = minUzaklik(uzaklik, sptSet);


       sptSet[u] = true;

       for (int v = 0; v < dugumSayisi ; v++)


         if (!sptSet[v] && dugumler[u][v] && uzaklik[u] != INT_MAX
                                       && uzaklik[u]+dugumler[u][v] < uzaklik[v])
            uzaklik[v] = uzaklik[u] + dugumler[u][v];
     }

     sonucYaz(uzaklik, dugumSayisi);


    return 0;
}


