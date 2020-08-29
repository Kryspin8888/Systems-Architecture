#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 20 ,k=0;
    int ciag[n] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int pom1 = 0, pom2 = -1,pom = 0;
    bool IsIn = false;
    int tabpom[3];

    cout<<"Algoryrtm optymalny staly ciag"<<endl<<endl;

    while(k < 2)
    {
    int tab[3] = {-1,-1,-1};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (tab[j] == ciag[i])
                IsIn = true;
        }
        if(!IsIn && tab[2] == -1)
        {
            tab[pom] = ciag[i];
            pom++;
        }
        else if(!IsIn)
        {
            tabpom[0] = tab[0];
            tabpom[1] = tab[1];
            tabpom[2] = tab[2];
            for(int m = i; m<n; m++)
            {
                if(tabpom[0] == ciag[m])
                    tabpom[0] = m *-1;
                else if(tabpom[1] == ciag[m])
                    tabpom[1] = m *-1;
                else if(tabpom[2] == ciag[m])
                    tabpom[2] = m *-1;
            }
            pom1 = max(max(tabpom[0]*-1,tabpom[1]*-1),tabpom[2]*-1);
            if(tabpom[0] < 0 && tabpom[1] < 0 && tabpom[2] < 0)
                for(int j=0; j<3; j++)
                {
                    if(tab[j] == ciag[pom1])
                        pom2 = j;
                }
            else
                for(int j=2; j>=0; j--)
                {
                    if(tabpom[j] > 0)
                        pom2 = j;
                }
            tab[pom2] = ciag[i];
            pom1 = 0;
        }

        cout<<"Dla numeru strony: "<<ciag[i]<<" ramka wyglada: ";
        for(int j=0; j<3; j++)
        {
            if(tab[j] != -1)
            cout<<tab[j]<<" ";
        }
        if(IsIn) cout<<" nie dodano ";
        IsIn = false;
        cout<<endl;
    }


    for(int i=0; i<n; i++)
    {
        ciag[i] = rand()%10;
    }
    k++;
    pom=0;
    if(k==1)
    cout<<"\nAlgoryrtm optymalny wylosowany ciag"<<endl<<endl;
    }

    cout << endl;
    system("pause");
    return 0;
}
