
VANAKKAM ! Simple C++ program to implement a Banking system

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class account
{
	int acc_no;
	char name[50];
	//ifsc code
	char acc_type;
	int deposit_amt;
	//address	

public:
	void create_account();	
	void disp_account();	
	void modify();	
	void deposit(int);	
	void withdraw(int);	
	//input from ATM machine
	//autodetect ifsc;
	void report();	
	int retacc_no();	
	//interface for UPI
	int retdeposit_amt() const;	
	char retacc_type() const;	
};         

void account::create_account()
{
	cin>>acc_no;
	cin.ignore();
	cin.getline(name,50);
	cin>>acc_type;
	acc_type=toupper(acc_type);
	cin>>deposit_amt;
	cout<<"\n\n\nAccount Created..";
}

void account::disp_account() const
{
	cout<<"\nAccount No. : "<<acc_no;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nAcc_type of Account : "<<acc_type;
	cout<<"\nBalance amount : "<<deposit_amt;
}

void account::deposit(int x)
{
	deposit_amt+=x;
}
	
void account::withdraw(int x)
{
	deposit_amt-=x;
}
	
void account::modify()
{
	cout<<"\nAccount No. : "<<acc_no;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Acc_type of Account : ";
	cin>>acc_type;
	acc_type=toupper(acc_type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit_amt;
}
	
int account::retacc_no() const
{
	return acc_no;
}

int account::retdeposit_amt() const
{
	return deposit_amt;
}

char account::retacc_type() const
{
	return acc_type;
}

void account::report() const
{
	cout<<acc_no<<setw(10)<<" "<<name<<setw(10)<<" "<<acc_type<<setw(6)<<deposit_amt<<endl;
}

void write_account();	
void disp(int);	
void mod_acc(int);	
void del_acc(int);	
void disp_all();		
void withdraw(int, int); 
void print();

int main()
{
	char ch;
	int num;
	print();
	do
	{
		system("cls");
		cout<<"\nMAIN MENU";
		cout<<"\n 1. NEW ACCOUNT";
		cout<<"\n 2. DEPOSIT_AMT AMOUNT";
		cout<<"\n 3. WITHWITHDRAW AMOUNT";
		cout<<"\n 4. BALANCE ENQUIRY";
		cout<<"\n 5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n 6. CLOSE AN ACCOUNT";
		cout<<"\n 7. MODIFY AN ACCOUNT";
		cout<<"\n 8. EXIT";
		cin>>ch;
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cin>>num;
			withdraw(num, 1);
			break;
		case '3':
			cin>>num;
			withdraw(num, 2);
			break;
		case '4': 
			cin>>num;
			disp(num);
			break;
		case '5':
			disp_all();
			break;
		case '6':
			cin>>num;
			del_acc(num);
			break;
		 case '7':
			cin>>num;
			mod_acc(num);
			break;
		 case '8':
			cout<<"\n NANDRI !";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//Four more function definitions to be included

void disp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacc_no()==n)
		{
			ac.disp_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}



