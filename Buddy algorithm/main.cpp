#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));
    int tab1[6];
    int tab2[6];
    cout<<"Algorytm blizniakow\n\n";
    for (int i = 0; i<6; i++)
	{
	    do
            {
	    tab1[i] = 6 + rand() % 300;
            } while(tab1[i] == 2 || tab1[i] == 4 || tab1[i] == 8 || tab1[i] == 16
                    || tab1[i] == 32 || tab1[i] == 64 || tab1[i] == 128 || tab1[i] == 256);
		cout << "Zapotrzebowanie procesu: "<<setw(2)<<i <<"  to "<<setw(4)<<tab1[i]<<"\n";
	}
    vector <int> memory;
    memory.push_back(2048);
    int pom = -1;
    bool IsFind = false;

    for (int i = 0; i<6; i++)
	{
	    while(!IsFind)
        {
            for(int j=0; j<memory.size(); j++)
            {
                if(tab1[i]< memory[j] && tab1[i] > memory[j]/2 && memory[j+1] != memory[j])
                {
                    pom = j;
                    IsFind = true;
                    break;
                }
            }
            if(!IsFind)
            {
                for(int k=0; k<memory.size(); k++)
                {
                    if(tab1[i] < memory[k]/2)
                    {
                        pom = k;
                    }
                }
                if(pom >-1)
                {
                    memory.insert(memory.begin()+pom+1,memory[pom]/2);
                    memory[pom] /= 2;
                    pom=-1;
                }
            }
        }
        cout<<"\n\n\nProcesor: "<<i<<"("<<tab1[i]<<")"<<" zapisano do "<<memory[pom]<<endl<<endl;
        tab2[i] = memory[pom];
        memory[pom]=i;
        IsFind = false;
        for(int j=0; j<memory.size(); j++)
        {
            cout<<memory[j]<<"  ";
        }

	}
    cout << endl<<endl;
	for(int i=0; i<4; i++)
    {
        cout<<"Proces: "<<i+1<<" zwalnia pamiec "<<tab2[i+1]<< "\n";
    }
    cout << endl;
    for(int j=0; j<memory.size(); j++)
    {
        for(int i=1; i<5; i++)
        {
            if(memory[j] == i)
                memory[j] = tab2[i];
        }
        cout<<memory[j]<<"  ";
    }
    cout<<endl<<endl<<"Po fragmentacji"<<endl<<endl;
    for(int j=memory.size()-1; j>=0; j--)
    {
        if(memory[j] == memory[j-1])
        {
            memory[j-1] += memory[j];
            memory.erase(memory.begin()+j);
            j--;                            //usunac gdy jedna komorka moze byc laczona wiecej niz raz
        }
    }
    for(int j=0; j<memory.size(); j++)
    {
        cout<<memory[j]<<"  ";
    }
    cout << endl;
    return 0;
}
