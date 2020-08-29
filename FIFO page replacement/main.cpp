#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 20 ,k=0;
    int ciag[n] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int pom = 0;
    bool IsIn = false;

    cout<<"Algoryrtm FIFO staly ciag"<<endl<<endl;

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
        if(!IsIn)
        {
            tab[pom] = ciag[i];
            pom++;
        }
        if(pom == 3)
            pom = 0;
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
    cout<<"\nAlgoryrtm FIFO wylosowany ciag"<<endl<<endl;

    }

    cout << endl;
    system("pause");
    return 0;
}
