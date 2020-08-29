#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;

int main()
{
    srand(time(NULL));
    int tab1[10];
    int tab2[10];
    int choice = 0;
    cout<<"Wybierz algorytm:\n\nPierwsze dopasowanie  - 1\nNajgorsze dopasowanie - 2\nNajlepsze dopasowanie - 3\n";
    cin>>choice;
    for (int i = 0; i<10; i++)
	{
	    tab1[i] = 1 + rand() % 200;
		 tab2[i] = 1 + rand() % 200;

		cout << "Zapotrzebowanie procesu: "<<setw(2)<<i <<"  to "<<setw(4)<<tab1[i]<<"  ";
		cout<<"Wolna przestrzen nr: "<<setw(2)<<i<<"  to "<<setw(4)<<tab2[i]<<endl;
	}

    cout<<"\n";
    if(choice == 1)
        for(int i=0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
            {
                if(tab1[i] <= tab2[j])
                   {
                       cout<<"Procesor nr: "<<setw(2)<<i<<" ("<<setw(3)<<tab1[i]<<")"<<"  trafia do przestrzeni "
                       <<setw(2)<<j<<" ("<<setw(3)<<tab2[j]<<")"<<"  pozostalo  "<<tab2[j]-tab1[i]<<endl;
                       tab2[j]-=tab1[i];
                       break;
                   }
            }
        }

    else if(choice == 2)
    {
        int max = 0,pom;
        for(int i=0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
            {
                if(max<tab2[j])
                {
                    max = tab2[j];
                    pom=j;
                }
            }
            if(tab1[i] <= max)
                {
                    cout<<"Procesor nr: "<<setw(2)<<i<<" ("<<setw(3)<<tab1[i]<<")"<<"  trafia do przestrzeni "
                    <<setw(2)<<pom<<" ("<<setw(3)<<tab2[pom]<<")"<<"  pozostalo  "<<tab2[pom]-tab1[i]<<endl;
                    tab2[pom]-=tab1[i];
                    max -= tab1[i];
                }
        }
    }
    else if(choice == 3)
    {
        int max = 0,pom, pom1 = 1000;
        for(int i=0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
            {
                if(tab1[i] <= tab2[j] && tab2[j] - tab1 [i] < pom1)
                {
                    max = tab2[j];
                    pom=j;
                    pom1 = tab2[j] - tab1[i];
                }
            }
            if(tab1[i] <= max)
                {
                    cout<<"Procesor nr: "<<setw(2)<<i<<" ("<<setw(3)<<tab1[i]<<")"<<"  trafia do przestrzeni "
                    <<setw(2)<<pom<<" ("<<setw(3)<<tab2[pom]<<")"<<"  pozostalo "<<setw(3)<<tab2[pom]-tab1[i]<<endl;
                    tab2[pom]-=tab1[i];
                    pom1 = 1000;
                }
        }
    }
    cout << endl;
    return 0;
}
