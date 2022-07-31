#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

long int income,money,cost,Cost,COST,total=0,Total,TOTAL=0,profit,loss,investment;
int time1,ID,choice,bricks,cement,labour,res;
unsigned int count=0,Count=0;
char name[50],str[50],ch,*s;
long long int orderno,phoneno;

class project
{
    public:
        int projectno;
        void input();
        void option();
        void search();
        void Del();
        void display();
}p[5];

class worker : public project
{
    public:
        void option();
        void input ();
        void search();
        void Del();
}w[5];

class client : public project
{
    public:
        void option();
        void input();
        void search();
        void Del();
}c[5];

class inventory : public project
{
    public:
        void input();
}i;

class P : public project
{
    public:
    void func()
    {
        investment=total+Total;
        profit=TOTAL-investment;
        loss=investment-TOTAL;
        cout<<"\n\nInvestment = Rs."<<investment;
        cout<<"\nMoney available = Rs."<<TOTAL;
        if (TOTAL>investment)
            cout<<"\nProfit = Rs."<<profit<<endl;
        else if (TOTAL==investment)
            cout<<"\nNo net gain or loss"<<endl;
        else
            cout<<"\nLoss = Rs."<<loss<<"\n\n";
        p[1].option();
    }
}m;

int main ()
{
    cout<<"\t\t\tDATABASE OF ATAL CONSTRUCTION COMPANY\n\n";
    p[0].option();
}

void worker::option()
{
    count++;
    cout<< "\nPress 1 : Input a new data\n"
        << "Press 2 : Search by name\n"
        << "Press 3 : Delete a data\n"
        << "Press 4 : Exit\n"
        << "Enter your choice : ";
    cin >> choice;

    if (choice == 1)
        input();

    else if (choice == 2)
        search();

    else if (choice == 3)
        Del();

    else
        cout<<"Invalid choice";
}

void worker :: input ()
{
    fstream worker ("worker.dat",ios::in|ios::out|ios::binary);
    cout << "\nName : ";
    cin.ignore();
    cin.getline(name,50);
    cout << "ID : ";          cin >> ID;
    cout << "Time of contract (in months) : ";      cin>>time1;
    income = time1*24373;
    cout<<"Annual income : Rs."<<income;
            total+=income;
    cout<<"\n\nContinue (y/n)? ";                     cin>>ch;
    if (ch=='y' || ch=='Y')
    {
        w[0].option();
    }
    else if (ch=='n' || ch=='N')
    {
        cout<<"Monthly income of a worker = Rs.24373\n";
        cout<<"Total cost of workers = Rs."<<total;
        cout<<"\n\n\t\t\t\t\tCLIENTS\n";
        c[0].option();
    }
    worker.close();
}

void worker :: search ()
{
    fstream worker ("worker.dat",ios::in|ios::out|ios::binary);
    cout << "\nName of worker to be searched : ";
    cin.ignore();
    cin.getline(str,50);
    int res=strcmp(str,name);
    if (res==0)
    {
        cout<< "Name : "<<name;
        cout<< "\nID : " <<ID;
        cout<< "\ntime1 of contract (in months) : "<<time1;
        cout<<"\nAnnual income : Rs."<<income;
        cout<<"\n\nContinue (y/n)? ";
        cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            w[0].option();
        }
        else if (ch=='n' || ch=='N')
        {
            cout<<"Monthly income of a worker = Rs.24373\n";
            cout<<"Total cost of workers = Rs."<<total;
            cout<<"\n\n\t\t\t\t\tCLIENTS\n";
            c[0].option();
        }
    }
    else
    {
        cout<<"Worker not found";
        cout<<"\n\nContinue (y/n)? ";
        cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            w[0].option();
        }
        else if (ch=='n' || ch=='N')
        {
            cout<<"Monthly income of a worker = Rs.24373\n";
            cout<<"Total cost of workers = Rs."<<total;
            cout<<"\n\n\t\t\t\t\tCLIENTS\n";
            c[0].option();
        }
    }
    worker.close();
}

void worker :: Del ()
{
    fstream o;
    o.open ("new.dat",ios::out|ios::binary);
    fstream worker("binary.dat",ios::in| ios::binary);
    cout << "\nName of worker to be deleted : ";
    cin.ignore();
    cin.getline(str,50);

    if (str==name)
    {
        worker.read((char*)&s,sizeof(s));
		while(!worker.eof())
		{
			if(strcmp(str,name)!=0)
			{
				o.write((char*)&s, sizeof(s));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
			}
			worker.read((char*)&s, sizeof(s));
		}
		o.close();
        worker.close();
        remove("binary.dat");
        rename("new.dat", "binary.dat");
        cout<<"Record Deleted";
    }

    else if (str!=name)
    {
        cout<<"\n\nWorker not found";
        cout<<"\n\nContinue (y/n)? ";
        cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            w[0].option();
        }
        else if (ch=='n' || ch=='N')
        {
            cout<<"Monthly income of a worker = Rs.24373\n";
            cout<<"Total cost of workers = Rs."<<total;
            cout<<"\n\n\t\t\t\t\tCLIENTS\n";
            c[0].option();
        }
    }
}

void client :: option()
{
    Count++;
    cout<< "\nPress 1 : Input a new data\n"
        << "Press 2 : Search by name\n"
        << "Press 3 : Delete a record\n"
        << "Press 4 : Exit\n"
        << "Enter your choice : ";
    cin >> choice;

    if (choice == 1)
        input();

    else if (choice == 2)
        search();

    else if (choice == 3)
        Del();

    else
    cout<<"Invalid choice";
}

void client :: input()
{
    fstream client ("client.dat",ios::in|ios::out|ios::binary);
    cout << "\nName : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Phone number : ";      cin >> phoneno;
    cout<<"Order number : ";      cin >> orderno;
    cout<<"Money taken : Rs. ";    cin>>money;
    TOTAL+=money;
    cout<<"\nContinue (y/n)? ";            cin>>ch;
    if (ch=='y' || ch=='Y')
    {
        c[0].option();
    }
    else if (ch=='n' || ch=='N')
    {
        cout<<"Total money received from clients : Rs."<<TOTAL;
        cout<<"\n\n\t\t\t\t\tINVENTORY\n";
        i.input();
    }
}

void client :: search ()
{
    fstream client ("client.dat",ios::in|ios::out|ios::binary);
    cout << "\nName of client to be searched : ";
    cin.ignore();
    cin.getline(str,50);
    res=strcmp(str,name);
    if (res==0)
    {
        cout<<"Name : "<< name;
        cout<<"\nPhone number : "<<phoneno;
        cout<<"\nOrder number : "<<orderno;
        cout<<"\nMoney taken : Rs. "<<money;
        cout<<"\n\nContinue (y/n)? ";
        cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            c[0].option();
        }
        else if (ch=='n' || ch=='N')
            i.input();
    }
    else
    {
        cout<<"Client not found";
        cout<<"\n\nContinue (y/n)? ";
        cin>>ch;
        cout<<"\nContinue (y/n)? ";            cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            c[0].option();
        }
        else if (ch=='n' || ch=='N')
        {
            cout<<"Total money received from clients : Rs."<<TOTAL;
            cout<<"\n\n\t\t\t\t\tINVENTORY\n";
            i.input();
        }
    }
    client.close();
}

void client :: Del ()
{
    fstream o;
    fstream client ("client.dat",ios::in|ios::out|ios::binary);
    o.open ("new.dat",ios::in|ios::out|ios::binary);
    cout << "\nName of client to be deleted : ";
    cin.ignore();
    cin.getline(str,50);
    if (str!=name)
    {
        cout<<"\n\nClient not found";
        cout<<"\n\nContinue (y/n)? ";
        cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            c[0].option();
        }
        else if (ch=='n' || ch=='N')
        {
            cout<<"Total money received from clients : Rs."<<TOTAL;
            cout<<"\n\n\t\t\t\t\tINVENTORY\n";
            i.input();
        }
    }
    else if (str==name)
    {
        client.read((char*)&s,sizeof(s));
		while(!client.eof())
		{
			if(strcmp(str,name)!=0)
			{
				o.write((char*)&s, sizeof(s));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
			}
			client.read((char*)&s, sizeof(s));
		}
        o.close();
        client.close();
        remove("client.dat");
        rename("new.dat", "client.dat");
        cout<<"Record Deleted";
    }
}

void inventory :: input()
{
    cout<<"\nBricks : ";                            cin>>bricks;
    cost=bricks*6500;
    cout<<"Cost of one brick : Rs.6500"
        <<"\nCost of bricks : Rs."<<cost;
    cout<<"\nCement (in kgs) : ";                   cin>>cement;
    Cost=cement*300;
    cout<<"Cost of 1 kg cement : Rs.300"
        <<"\nCost of cement : Rs."<<Cost;
    cout<<"\nLabour : ";                            cin>>labour;
    COST=labour*250;
    cout<<"Cost of one labourer : Rs.250"
        <<"\nCost of labour : Rs."<<COST;
    Total=cost+Cost+COST;
    cout<<"\nTotal cost of inventory = Rs."<<Total;
    m.func();
}

void project :: input()
{
    cout<<"\n\nProject Name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<< "\n\t\t\t\t\tWORKERS\n";
    w[0].option();
}

void project :: option()
{
    cout<<"\t\t\t\tPROJECT MENU\n"
        <<"\nPress 1 : Input a new data\n"
        << "Press 2 : Search by name\n"
        << "Press 3 : Delete a data\n"
        << "Press 4 : Exit\n"
        << "Enter your choice : ";
    cin >> choice;
    if (choice == 1)
        p[0].input();
    else if (choice == 2)
        search();
    else if (choice == 3)
        Del();
    else if (choice == 4)
        exit(0);
}

void project :: search ()
{
    fstream project ("project.dat",ios::in|ios::out|ios::binary);
    cout << "\nName of project to be searched : ";
    cin.ignore();
    cin.getline(str,50);
    res=strcmp(str,name);
    if (res==0)
    {
        p[0].display();
        cout<<"\n\nContinue (y/n)? ";
        cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            p[1].option();
        }
        else
            exit(0);
    }
    else
    {
        cout<<"Project not found";
        cout<<"\nContinue (y/n)? ";            cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            p[1].option();
        }
        else if (ch=='n' || ch=='N')
        {
            exit(0);
        }
    }
    project.close();
}

void project :: Del()
{
    fstream o;
    o.open ("new.dat",ios::out|ios::binary);
    fstream project("binary.dat",ios::in| ios::binary);
    cout << "\nName of project to be deleted : ";
    cin.ignore();
    cin.getline(str,50);
    if (str!=name)
    {
        cout<<"\n\nProject not found"
            <<"\n\nContinue (y/n)? ";
        cin>>ch;
        if (ch=='y' || ch=='Y')
        {
            p[1].option();
        }
        else if (ch=='n' || ch=='N')
        {
            exit(0);
        }
    }
    else
    {
        project.read((char*)&s,sizeof(s));
		while(!project.eof())
		{
			if(strcmp(str,name)!=0)
			{
				o.write((char*)&s, sizeof(s));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
			}
			project.read((char*)&s, sizeof(s));
		}
        o.close();
        project.close();
        remove("binary.dat");
        rename("new.dat", "binary.dat");
        cout<<"Record Deleted";
    }
}

void project :: display()
{
    cout<<"\t\t\tWORKERS"
        <<"\nName : "<<name
        <<"\nID : "<<ID
        <<"\nTime of contract (in months) : "<<time1
        <<"\nAnnual income : Rs."<<income<<"\n\n";

    cout<<"\t\t\tCLIENTS"
        <<"\nName : "<<name
        <<"\nPhone number : "<<phoneno
        <<"\nOrder number : "<<orderno
        <<"\nMoney taken : Rs. "<<money<<"\n\n";

    cout<<"\t\t\tINVENTORY"
        <<"\nCost of bricks : Rs."<<cost
        <<"\nCost of cement : Rs."<<Cost
        <<"\nCost of labour : Rs."<<COST
        <<"\nTotal cost of inventory = Rs."<<Total;

    cout<<"\n\nInvestment = Rs."<<investment
        <<"\nMoney available = Rs."<<TOTAL;
    if (TOTAL>investment)
        cout<<"\nProfit = Rs."<<profit<<endl;
    else if (TOTAL==investment)
        cout<<"\nNo net gain or loss"<<endl;
    else
        cout<<"\nLoss = Rs."<<loss<<"\n\n";
}
