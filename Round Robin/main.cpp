#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct proces {
	int p_id;
	int p_bt;
	int p_at;
	int p_ft;
}Proces;

int main()
{
    srand(time(NULL));

    Proces myproces[5];
	int time = 0;
	int q = 2;

	for (int i = 0; i<5; i++)
	{
	    if(i==0)
            myproces[i].p_at=0;
		else
            myproces[i].p_at = 1 + rand() % 20;
		myproces[i].p_id = i;
		myproces[i].p_bt = 1 + rand() % 10;

		cout << "Wartosci procesow: " << myproces[i].p_id
			<< " czas wykonania " << myproces[i].p_bt << " czas nadejscia " << myproces[i].p_at << endl;

		time += myproces[i].p_bt;
	}

	cout<<endl<<"Czas trwania wszystkich procesow: "<<time<<endl<<endl;

	Proces buffor[5];
	bool IsStart[5] = {0,0,0,0,0};
	bool IsAddToBuffor[5] = {0,0,0,0,0};
	int pos = 0;
	int counter = 0;
	int cykl = 1;

	for(int i = 0; i < time; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if( myproces[j].p_at <= i && !IsAddToBuffor[j])
            {
                buffor[pos] = myproces[j];
                IsStart[pos] = true;
                IsAddToBuffor[j] = true;
                pos++;
            }
        }
        cout<<"Cykl: "<<cykl<<" sekunda: "<<i<<endl;
        for(int j=0; j<5; j++)
        {
            if( IsStart[j] && buffor[j].p_bt > 0 )
            {
                for(int k=0; k<q; k++)
                {
                    if(buffor[j].p_bt > 0)
                    {
                        buffor[j].p_bt--;
                        counter++;
                    }
                }
                cout<<"    sec. "<<i+counter<<" obcialem czas procesorowi: "<<buffor[j].p_id;

                if(buffor[j].p_bt < 1 )
                {
                    cout<<" - zakonczyl dzialanie";
                    myproces[buffor[j].p_id].p_ft = i+counter;
                }

                cout<<endl;
            }
        }
        if(counter !=0)
            i += counter-1 ;
        else
            time++;
        counter = 0;
        cykl++;
        cout<<endl;
    }

    int averwaitingtime = 0;
	cout << endl;
	for (int i = 0; i<5; i++)
	{
		cout << "Czas wykonania procesu: " << myproces[i].p_id << " to: " << myproces[i].p_ft << endl;
		cout << "Czas oczekiwania procesu: " << myproces[i].p_id << " to: " << myproces[i].p_ft - myproces[i].p_bt-myproces[i].p_at << endl<<endl;
		averwaitingtime += myproces[i].p_ft - myproces[i].p_bt - myproces[i].p_at;
	}
	cout << "Sredni czas oczekiwania procesow: " << averwaitingtime/5 << endl;

	cout << endl;
	system("pause");
	return 0;
}
