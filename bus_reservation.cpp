//bus reservation system program
#include<iostream>

#include<cstdlib>

#include<conio.h>

#include<string.h>

#include<cstdio>

using namespace std;

static int p=0;

class sys
{
public:
    char busn[5],driver[50],from[30],to[30],arrival[10],depart[10];

    char seat[8][4][10];

    void install();

    void avail();

    void allot();

    void show();

    void empty();

    void position(int i);

    void vline(char ch)
    {
        for(int i=90;i>0;i--)
        {
            cout<<ch;
        }
        cout<<"\n";
    }

}
bus[10];

void sys::install()
{
    cout<<"Enter Bus no:";

    cin>>bus[p].busn;

    cout<<"Enter Driver's name:";

    cin>>bus[p].driver;

    cout<<"Enter Arrival Time:";

    cin>>bus[p].arrival;

    cout<<"Enter Departure Time:";

    cin>>bus[p].depart;

    cout<<"From:";

    cin>>bus[p].from;

    cout<<"To:";

    cin>>bus[p].to;

    bus[p].empty();

    p++;

}

void sys::empty()
{
   for(int i=0; i<8;i++)

  {
    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }
}
void sys::avail()
{
    for(int n=0;n<p;n++)
    {
         vline('*');

        cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

        <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

        <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

        <<bus[n].to<<"\n";

        vline('*');

        vline('_');
    }
}
void sys::allot()
{
    char number[5];

    top:

    cout<<"Enter Bus Number:\n";

    cin>>number;

    int sit,n;

    for(n=0;n<p;n++)
    {
        if(strcmp(bus[n].busn,number)==0)
            break;
    }
        while(n<=p)
        {
            cout<<"Enter seat no:(there are 32 seats available):-\n";

            cin>>sit;

            if(sit>32)
            {
                cout<<"There are only 32 seats available \n";
            }
            else
            {
                if(strcmp(bus[n].seat[sit/4][(sit%4)-1],"Empty")==0)
                {
                    cout<<"Enter Passengers Name:\n";

                    cin>>bus[n].seat[sit/4][(sit%4)-1];

                    break;
                }


            else
            {
                cout<<"The Seat is already reserved\n";
            }}
        }
        if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }
}
void sys::show()
{
    int n;

    char number[5];

    cout<<"Enter Bus Number:\n";

    cin>>number;

    for(n=0;n<p;n++)
    {
        if(strcmp(bus[n].busn,number)==0)

            break;
    }
    while(n<=p)
    {

     vline('*');

        cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

        <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

        <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

        <<bus[n].to<<"\n";

        vline('*');

        bus[0].position(n);

        int a=1;

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                {
                   cout<<"\nThe seat no "<<(a-1)<<" is reserved for:"<<bus[n].seat[i][j]<<endl;
                }
            }
        }
        break;
    }
    if(n>p)
    {
        cout<<"Enter correct bus number\n";
    }
}
void sys::position(int l)
{
    int s=0,p=0;

    for(int i=0;i<8;i++)
    {
        cout<<"\n";
        for(int j=0;j<4;j++)
        {
            s++;

            if(strcmp(bus[l].seat[i][j],"Empty")==0)
            {
                cout.width(5);

                cout.fill(' ');

                cout<<s<<".";

                cout.width(10);

                cout.fill(' ');

                cout<<bus[l].seat[i][j];

                p++;
            }
            else
            {
                cout.width(5);

                cout.fill(' ');

                cout<<s<<".";

                cout.width(10);

                cout.fill(' ');

                cout<<bus[l].seat[i][j];
            }
        }
    }
    cout<<"\n";
    vline('*');
    cout<<"\n\nThere are  "<<p<<"  seats Empty in Bus No: "<<bus[l].busn<<endl;
    vline('-');
}

int main()
{

   int ch;

   while(ch!=5)
   {
       cout<<"\n\n\t****Simple Bus Reservation System*****\n";

       cout<<"\t\t1.Enter Bus Details\n\t\t2.Reservation\n\t\t3.Show Bus Status\n\t\t4.Buses Available\n\t\t5.Exit\n\n\n";

       cout<<"\t\tEnter Your Choice: \n\t\t";

       cin>>ch;

       switch(ch)
       {
       case 1:

        bus[p].install();

        break;

       case 2:
        bus[p].allot();

        break;

       case 3:

        bus[0].show();

        break;

       case 4:

        bus[0].avail();

        break;

       case 5:

        cout<<"Thank you Visit Again...:)\n";

        break;

       }
   }
return 0;
}
