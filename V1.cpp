#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<time.h>
#include<math.h>
void gotoxy(int ,int );
void start(void);
void loading(int);
void login();
using namespace std;

class room{
	protected:
	char type[10];				//COMFORT SUITE OR NORMAL ROOM
	
	
	public:
		float rent;			//DAILY RENT OF ROOM
		int status;	            //Available or not
		int roomNumber;			//ROOM NUMBER
		room()
		{
			status=0;
		}
		void setdata();
		void getdata();
		int RoomScreen();
		int roomMenu();
		int Addroom();
		int Viewroom();
		int Modifyroom();
		int Deleteroom();
		int Searchroom();
		int add();
		int getroomNumber();
		int getstatus();
		void setstatus();

};
void room::setstatus()
{
	status=1;
}
int room :: RoomScreen()
{
	system("cls");
	char c=219;
	time_t t;
	time(&t);
	cout << "\n\t\t\t\t\t\t " << ctime(&t);
	int i;
	gotoxy(27,5);
	for(i=1;i<=29;i++)
	{
		cout << c;
	}
	gotoxy(27,6);
	cout << c << c << "      Room Management    "<<c<<c;
	gotoxy(27,7);
	for(i=1;i<=29;i++)
	{
		cout << c;
	}
	loading(10000000);
	cout << endl;
	getch();
	if(roomMenu()==1);
		return 1;
	return 0;
}
int room :: roomMenu()
{
		system("cls");
	int option;
	char c=219;
    time_t t;
	time(&t);
	cout << "\n\t\t\t\t\t\t " << ctime(&t);
	int i;
	gotoxy(13,3);
	for(i=0;i<20;i++)
    	cout << c;
    gotoxy(13,4);
    cout<<c<<c<<"Room  Management"<<c<<c;
    gotoxy(13,5);
	for(i=0;i<20;i++)
    	cout << c;
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	cout << c;
//
	gotoxy(9,8);
    cout<<c<<" 1 : Add Room.           "<<c;
    gotoxy(9,9);
    cout<<c<<" 2 : View Room.          "<<c;
    gotoxy(9,10);
    cout<<c<<" 3 : Search Room.        "<<c;
    gotoxy(9,11);
    cout<<c<<" 4 : Modify Room.        "<<c;
    gotoxy(9,12);
    cout<<c<<" 5 : Delete Room.        "<<c;
    gotoxy(9,13);
    cout<<c<<"  Any other key to exit  "<<c;
    gotoxy(9,14);
	cout<<c<<" Choose an option:       "<<c;
//
	gotoxy(9,16);
	for(i=0;i<27;i++)
    	cout << c;
	gotoxy(9,15);
	cout<<c<<"                         "<<c;
	gotoxy(19,15);
//
	cin>>option;
	switch(option)
	{
		case 1:
			{
			system("cls");
			add();
			puts("\n\nPress any key to go back.");
			getch();
			roomMenu();
			break;	
			}
		case 2:
			{
			system("cls");
			Viewroom();
			puts("\n\nPress any key to go back.");
			getch();
			roomMenu();
			break;	
			}
		case 3:
			{
			system("cls");
			Searchroom();
			puts("\n\nPress any key to go back.");
			getch();
			roomMenu();
			break;
			}
		case 4:
			{
			system("cls");
			Modifyroom();
			puts("\n\nPress any key to go back.");
			getch();
			roomMenu();
			break;	
			}
		case 5:
			{
			system("cls");
			Deleteroom();
			puts("\nPress any key to go back.");
			getch();
			roomMenu();
			break;
			}
		default:
			{
		fflush(stdin);
		puts("\n\n            Press any key to Exit.");
		getch();
		return 1;
		}
			
	}
	

}
void room::setdata()
{
	fstream f;
	int flag=0;
	f.open("room.dat",ios::in|ios::binary);
	room r;
	while(1)
	{
	cout << "room number:" << endl;
	cin >> roomNumber ;
	while(f.read((char*)&r,sizeof(r)))
	{
	if(r.roomNumber==roomNumber)
	{
		flag=1;
	}
    }
    if(flag==1)
    {
    	flag=0;
    	
    	cout << endl << "ROOM NUMBER ALREADY IN USE ENTER AGAIN!" << endl;
    	continue;
	}
	break;
	}
	f.close();
	cout << "TYPES OF ROOM:" << endl << 
	"1. Single (For One Person)" << endl<<
	"2. Double (For Two Person)" << endl <<
	"3. Master (A parlour or living room connected to one or more bedrooms)"<< endl;

cout << "enter type:" << endl;
cin >> type;
type[0]=toupper(type[0]);

cout << "enter rent" << endl;
cin >> rent;

cout << "Room Status: " << endl << "1=Booked / 0=Available : " << endl;
cin >> status;
}
int room::getroomNumber()
{
	return roomNumber;
}
int room::getstatus()
{
	return status;
}
void room::getdata()
{
	cout<<"Room Number: "<<roomNumber<<endl
<<"type: "<<type<<endl
<<"rent: "<<rent<<"$"<<endl;
if(status == 0)
{
	cout << "Status: Available" << endl;
}
else
{
	cout << "Status: Booked" << endl;
}
cout << endl << "**********************"<< endl;
}
int room :: add()
{
	room s;

	char c = 'n';
	do{
		system("cls");
	s.Addroom();
	cout << "do you want to add another record";
	cin >> c;
	} while (c == 'y' || c == 'Y');
	//cout << "data written successfully";
}
int room::Addroom()
{
	fstream f;
	room s;
	f.open("room.dat",ios::app | ios::binary );
	s.setdata();
	f.write((char*)&s, sizeof(s));
	f.close();
}
int room::Viewroom()
{
		fstream f;
		room s;
		f.open("room.dat",ios::in | ios::binary);

		while(f.read((char*)&s,sizeof(s))){
		cout<<endl<<endl;
		s.getdata();
			}
}
int room::Deleteroom()
{
	int flag=0;
	room r;
	fstream f, temp;
	int num;
	f.open("room.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	cout << "ENTER ROOM NUMBER OF RECORD YOU WANT TO DELETE:";
	cin >> num;
	while(f.read((char*)&r,sizeof(r)))
	{
		if(r.roomNumber==num)
		{
		flag=1;
		}
		if(r.roomNumber!=num)
		{
			temp.write((char*)&r,sizeof(r));
		}
	}
	f.close();
	temp.close();
	if(flag==1){
		remove("room.dat");
	    rename("temp.dat","room.dat");
	    cout << "\nRecord Deleted Successfully!";
    }
    else{
    	remove("temp.dat");
    	cout<< "\nThere is no room with this number!";
	}
	
}
int room::Searchroom()
{
	int flag=1;
	room r;
	fstream f;
	f.open("room.dat",ios::in|ios::binary);
	char t[10];
	cout << "Which Type Of Room You Want To Search:" << endl;
	cin >> t;
	t[0] = toupper(t[0]);
	while(f.read((char*)&r,sizeof(r)))
	{
		if(strcmp(t,r.type)==0)
		{
			flag=0;
			r.getdata();
		}
	}
	if(flag==1)
	{
		cout << "No Such Type of Room!" << endl;
	}
	
}
int room::Modifyroom()
{
	int flag=0;
	int num;
	room r;
	fstream f,temp;
	f.open("room.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	cout << "Enter Room Number of Room which Record You Want To Modify:" << endl;
	cin >> num;
	while(f.read((char*)&r,sizeof(r)))
	{
		if(r.roomNumber==num)
		{
		flag=1;
		r.setdata();
		temp.write((char*)&r,sizeof(r));
		}
		else
		{
			temp.write((char*)&r,sizeof(r));
		}
	}
	f.close();
	temp.close();
    if(flag==1){
		remove("room.dat");
	    rename("temp.dat","room.dat");
	    cout << "\nRecord Modified Successfully!";
    }
    else{
    	remove("temp.dat");
    	printf("\nThere is no room with that number!");
	}
}
class customer: public room{
	public:
	char name[30];	   			 //CUSTOMER FULL NAME
	char phone[15];				//CONTACT NUMBER
	int days;	    			//DURATION OF STAY
	float payment_advance;		//ADVANCE PAYMENT
	int roomNum;					//ROOM NO
	
	room r;

	int id;
	int inDay;
	int inMonth;
	int inYear;
	int outDay;
	int outMonth;
	int outYear;
		customer()
		{
			outDay=0;
			outMonth=0;
			outYear=0;
			days = 0;
		}
	int CustomerScreen();
	int recordMenu();
	int ViewRecord();
	int SearchRecord();
	int DeleteRecord();
	int ModifyRecord();
	void getdata();
	void getout();
	void setdata();
	int count();
		
};
int customer :: CustomerScreen()
{
	system("cls");
	char c=219;
	time_t t;
	time(&t);
	cout << "\n\t\t\t\t\t\t " << ctime(&t);
	int i;
	gotoxy(27,5);
	for(i=1;i<=29;i++)
	{
		cout << c;
	}
	gotoxy(27,6);
	cout << c << c << "      Customer Record    "<<c<<c;
	gotoxy(27,7);
	for(i=1;i<=29;i++)
	{
		cout << c;
	}
	loading(10000000);
	cout << endl;
	getch();
	if(recordMenu()==1);
		return 1;
	return 0;
}
int customer :: recordMenu()
{
	system("cls");
	int option;
	char c=219;
    time_t t;
	time(&t);
	cout << "\n\t\t\t\t\t\t " << ctime(&t);
	int i;
	gotoxy(13,3);
	for(i=0;i<20;i++)
    	cout << c;
    gotoxy(13,4);
    printf("%c%cCustomer Records%c%c",219,219,219,219);
    gotoxy(13,5);
	for(i=0;i<20;i++)
    	cout << c;
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	cout << c;
//
	gotoxy(9,8);
    cout<<c<<" 1 : View Record.        "<<c;
    gotoxy(9,9);
    cout<<c<<" 2 : Search Record.      "<<c;
    gotoxy(9,10);
    cout<<c<<" 3 : Delete Record.      "<<c;
    gotoxy(9,11);
    cout<<c<<" Any other key to exit   "<<c;
    gotoxy(9,12);
    cout<<c<<"  Choose an option:      "<<c;
    

//
	gotoxy(9,14);
	for(i=0;i<27;i++)
    	cout << c;
	gotoxy(9,13);
	cout<<c<<"                         "<<c;
	gotoxy(19,13);
//
	cin>>option;
//
	switch(option){

	case 1:
		{
		system("cls");
		ViewRecord();
		puts("\n\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 2:
		{
		system("cls");
		SearchRecord();
		puts("\n\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 3:
		{
		system("cls");
		DeleteRecord();
		
		puts("\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	default:
		{
		fflush(stdin);
		puts("\n\n            Press any key to Exit.");
		getch();
		return 1;
		}
	}
	return 0;
}
void customer::setdata()
{
	fstream f,temp;
	int flag=0;
	f.open("customer.dat",ios::in|ios::binary);
	customer c;
	while(1)
	{
	cout << "Customer ID:" << endl;
	cin >> id ;
	while(f.read((char*)&c,sizeof(c)))
	{
	if(c.id==id)
	{
		flag=1;
	}
    }
    if(flag==1)
    {
    	flag=0;
    	
    	cout << endl << "CUSTOMER ID ALREADY IN USE ENTER AGAIN!" << endl;
    	continue;
	}
	break;
	}
	f.close();	
	cout << "Enter Customer Full Name: ";
	fflush(stdin);
	cin.getline(name,30);
	while(1)
	{
	cout << "Enter Phone Number: ";
	cin.getline(phone,15);
	if(strlen(phone)>11||strlen(phone)<11)
	{
		cout << "Incorrect Phone Number, It must be 11 Character! Enter Again" << endl << endl;
		continue;
	}
	break;
	}
	 flag=0;
	int num,l=0;
	room r;
	while(1)
	{
	f.open("room.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	cout << "Enter Room Number :" << endl;
	cin >> roomNum;
	while(f.read((char*)&r,sizeof(r)))
	{
		if(r.roomNumber==roomNum)
		{
		flag=1;
		if(r.status==0)
		{
			l=1;
		r.status=1;
		}
		temp.write((char*)&r,sizeof(r));
		}
		else
		{
			temp.write((char*)&r,sizeof(r));
		}
	}
	f.close();
	temp.close();
    if(flag==1 && l==1){
		remove("room.dat");
	    rename("temp.dat","room.dat");
	    break;
	   // cout << "\nRecord Modified Successfully!";
    }
    else{
    	remove("temp.dat");
    	printf("\nThere is no room with that number or Room already booked!");
	}
}
	while(1)
	{
	cout << "Enter Check In Date (DD MM YY):";
	fflush(stdin);
	cin >> inDay >> inMonth >> inYear;
	if(inDay > 31 || inDay <= 0)
    {
        cout<<"Incorrect Date entered Enter Again"<<endl;
        continue;
    }
	else if(inMonth > 12 || inMonth <= 0)
	{
		cout<<"Incorrect Date entered Enter Again"<<endl;
        continue;
	}
	break;
	}

	cout << "Enter Advance Payment: ";
	cin >> payment_advance;
	 
}
void customer :: getout()
{
	while(1)
	{
	cout << "Enter Check Out Date (DD MM YY):";
	fflush(stdin);
	cin >> outDay >> outMonth >> outYear;
	if(outDay > 31 || outDay <= 0)
    {
        cout<<"Incorrect Date entered Enter Again"<<endl;
        continue;
    }
	else if(outMonth > 12 || outMonth <= 0)
	{
		cout<<"Incorrect Date entered Enter Again"<<endl;
        continue;
	}
	break;
	}

}
void customer::getdata()
{
	cout << "Customer ID: " <<id << endl;
	cout << "Customer Name: " << name << endl;
	cout << "Phone Number: " << phone << endl;
	cout << "Room Number: " << roomNum << endl;
	cout << "Check-In Date: " << inDay <<"\\"<< inMonth << "\\" << inYear << endl;
	cout << "Check-Out Date: " << outDay <<"\\"<< outMonth << "\\" << outYear << endl;
	cout << "Total Days Stay: " << days << endl;
	cout << "Advance Payment: " << payment_advance << "$" << endl;

	cout << endl << "***********************" << endl <<  endl;
}
int customer::ViewRecord()
{
	fstream f;
		customer s;
		f.open("customer.dat",ios::in | ios::binary);

		while(f.read((char*)&s,sizeof(s))){
		cout<<endl<<endl;
		s.getdata();
			}
}
int customer::SearchRecord()
{
	int flag=1;
	customer r;
	fstream f;
	f.open("customer.dat",ios::in|ios::binary);
	int t;
	cout << "Customer ID of Customer To Search For Him:" << endl;
	cin >> t;
	
	while(f.read((char*)&r,sizeof(r)))
	{
		if(t==r.id)
		{
			flag=0;
			r.getdata();
		}
	}
	if(flag==1)
	{
		cout << "No Such Customer!" << endl;
	}
	
}
int customer::DeleteRecord()
{
	int flag=0;
	customer r;
	fstream f, temp;
	int num;
	f.open("customer.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	cout << "ENTER CUSTOMER ID OF CUSTOMER RECORD YOU WANT TO DELETE:";
	cin >> num;
	while(f.read((char*)&r,sizeof(r)))
	{
		if(r.id==num)
		{
		flag=1;
		}
		if(r.id!=num)
		{
			temp.write((char*)&r,sizeof(r));
		}
	}
	f.close();
	temp.close();
	if(flag==1){
		remove("customer.dat");
	    rename("temp.dat","customer.dat");
	    cout << "\nRecord Deleted Successfully!";
    }
    else{
    	remove("temp.dat");
    	cout<< "\nThere is no custoemr with this number!";
	}
	
}
int customer::count()
{
	int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int years_difference, days_difference;
    int months_total;
	int reg_year = 365;
	if(inYear == outYear)
    {
        years_difference = 0;
    }
    else
    {
        if(inYear % 4 == 0 && inYear % 100 != 0 || inYear % 400 == 0)
        {
            if(outYear % 4 == 0 && outYear % 100 != 0 || outYear % 400 == 0)
            {
                if(inYear > outYear)
               {
                    years_difference = (inYear - outYear) * (reg_year) + 2;
                }
                else
                {
                    years_difference = (outYear - inYear) * (reg_year) + 2;
                }
                if(outMonth > inMonth)
                {
                    if(days_in_months[inMonth - 1] > days_in_months[1])
                    {
                        --years_difference;
                    }
                }
            }
            else
            {
                if(inYear > outYear)
                {
                    years_difference = (inYear - outYear) * (reg_year) + 1;
                }
                else
                {
                    years_difference = (outYear - inYear) * (reg_year) + 1;
                }
                if(inMonth > outMonth)
                {
                    if(days_in_months[outMonth - 1] > days_in_months[1])
                    {
                        --years_difference;
                    }
                }
            }
        }
        else
        {
           if(inYear > outYear)
            {
                years_difference = (inYear - outYear) * (reg_year);
            }
            else
            {
                years_difference = (outYear - inYear) * (reg_year);
            }
        }
    }
    /////////////////////////////Months////////////////////////////////////
    if(inMonth == outMonth)
    {
        months_total = 0;
    }
    else
    {
        if(inMonth > outMonth)
        {
            for(int i = (inMonth - 1); i > (outMonth - 1); i--)
            {
                static int months_total_temp = 0;
                months_total_temp += days_in_months[i];
                months_total = months_total_temp;
            }
        }
        else
        {
            for(int i = (inMonth - 1); i < (outMonth - 1); i++)
            {
                static int months_total_temp = 0;
                months_total_temp += days_in_months[i];
                months_total = months_total_temp;
           }
        }
    }
    ////////////////////////////Days//////////////////////////////////
    int days_total;
    if (inDay == outDay)
    {
        days_difference = 0;
        days_total = (years_difference + months_total) - days_difference;
    }
    else

    {
        if(inDay > outDay)
        {
            days_difference = inDay - outDay;
            days_total = (years_difference + months_total) - days_difference;
        }
        else
        {
            days_difference = outDay - inDay;
            days_total = (years_difference + months_total) + days_difference;
        }
    }
    //////////////////////////In Between Leap Years///////////////////////////////
    if(inYear == outYear)
    {
    }
    else
    {
        if(inYear > outYear)
        {
            for(int i = (outYear + 1); i < inYear; i++)
            {
                if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
                {
                    cout<<endl;
                    cout<<i<<endl;
                    ++days_total;
                }
            }
        }
        else
        {
            for(int i = (inYear + 1); i < outYear; i++)
            {
                if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
                {
                    cout<<endl;
                    cout<<i<<endl;
                    ++days_total;
                }
            }
            }
    }
    days = days_total;
}
class hotel:public customer{
	private:
	public:
	hotel()
	{
	}
	customer c;
	room r;
	void menu(void);
	int bookscreen();
	int checkIn();
	int checkOut();
	void getdate();
	

};
void hotel :: menu(){
	system("cls");
	int option;
	char c=219;
	time_t t;
	time(&t);
	cout << "\n\t\t\t\t\t\t " << ctime(&t);
	int i;
	gotoxy(24,5);
	for(i=1;i<=37;i++)
	{
		cout << c;
	}
	gotoxy(24,6);
	cout << c << c << "      WELCOME TO FAST HOTEL      "<<c<<c;
	gotoxy(24,7);
	for(i=1;i<=37;i++)
	{
		cout << c;
	}
	loading(10000000);
	cout << endl;
	getch();
	system("cls");
	gotoxy(15,3);
	for(i=0;i<15;i++)
    	cout << c;
    gotoxy(15,4);
    cout <<c<<c<< " Main Menu "<<c<<c;
    gotoxy(15,5);
	for(i=0;i<15;i++)
    	cout << c;
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	cout << c;
    gotoxy(9,8);
    cout<< c<<" 1 : Customer Records    "<<c;
    gotoxy(9,9);
    cout<< c<<" 2 : Room Management     "<<c;
    gotoxy(9,10);
    cout<< c<<" 3 : Check-in/Check-out  "<<c;
    gotoxy(9,11);
    cout<<c<<"  Any other key to exit  "<<c;
    gotoxy(9,12);
    cout<<c<<"  Choose an Option       "<<c;
    gotoxy(9,13);
	cout<<c<<"                         "<<c;
    gotoxy(9,14);
	for(i=0;i<27;i++)
    	cout << c;
	
	gotoxy(19,13);
	scanf("%d",&option);
	switch(option)
	{
		case 1:
		{
		system("cls");
		if(CustomerScreen()==0){
			puts("\n\nPress any key to go back.");
			getch();
		}
		menu();
		break;
		}
	case 2:
		{
		system("cls");
		if(RoomScreen()==0){
			puts("\n\nPress any key to go back.");
			getch();
		}
		menu();
		break;
		}
	case 3:
		{
		system("cls");
		if(bookscreen()==0){
			
			puts("\n\nPress any key to go back.");
			getch();
		}
		menu();
		break;
		}
	default:
		{
		puts("\n\n            Press any key to Exit.");
		getch();
		break;
		}
	}
}
int hotel :: bookscreen()
{
	system("cls");
	int option;
	char c=219;
    time_t t;
	time(&t);
	cout << "\n\t\t\t\t\t\t " << ctime(&t);
	int i;
	gotoxy(13,3);
	for(i=0;i<22;i++)
    	cout << c;
    gotoxy(13,4);
    cout<<c<<c<<"Check-in/Check-out"<<c<<c;
    gotoxy(13,5);
	for(i=0;i<22;i++)
    	cout << c;
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	cout << c;
//
	gotoxy(9,8);
    cout<<c<<" 1 : Check-in            "<<c;
    gotoxy(9,9);
    cout<<c<<" 2 : Check-out           "<<c;
    gotoxy(9,10);
    cout<<c<<"  Any other key to exit  "<<c;
    gotoxy(9,11);
	cout<<c<<" Choose an option:       "<<c;
//
	gotoxy(9,13);
	for(i=0;i<27;i++)
    	cout << c;
	gotoxy(9,12);
	cout<<c<<"                         "<<c;
	gotoxy(19,12);
//
	cin>>option;
	switch(option)
	{
		case 1:
		{
			system("cls");
			checkIn();
			puts("\n\nPress any key to go back.");
			getch();
			bookscreen();
			break;	
		}
		case 2:
		{
			system("cls");
			checkOut();
			puts("\n\nPress any key to go back.");
			getch();
			bookscreen();
			break;	
		}
		default:
			{
				puts("\n\n            Press any key to Exit.");
				getch();
				break;
			}
}
}
int hotel::checkIn()
{
	fstream f;
	customer s;
	f.open("customer.dat",ios::app | ios::binary );
	s.setdata();
	f.write((char*)&s, sizeof(s));
	f.close();
}
void hotel::getdate()
{
	
}
int hotel::checkOut()
{
		int flag=1,day=0,n;
		float advpay,bill;
	customer c;
	fstream f;
	int t;
	while(1)
	{
	f.open("customer.dat",ios::in|ios::binary);
	cout << "Enter Customer ID:" << endl;
	cin >> t;
	
	while(f.read((char*)&c,sizeof(c)))
	{
		if(t==c.id)
		{
			flag=0;
			cout << "Customer ID: " <<c.id << endl;
			cout << "Customer Name: " <<c.name << endl;
			cout << "Phone Number: " <<c.phone << endl;
			cout << "Room Number: " <<c.roomNum << endl;
			n=c.roomNum;
			cout << "Check-In Date: " <<c.inDay <<"\\"<< c.inMonth << "\\" << c.inYear << endl;
			cout << "Advance Payment: " << c.payment_advance << endl;
			advpay = c.payment_advance;
		}
	}
	if(flag==1)
	{
		cout << "No Such Customer!" << endl;
		f.close();
		continue;
	}
	f.close();
	break;
	}
	flag=0;
	room r;
	f.open("room.dat",ios::in|ios::binary);

	while(f.read((char*)&r,sizeof(r)))
	{
		if(r.roomNumber==n)
		{


		if(r.status==0)
		{
				flag=1;
		}
		
		}
		else
		{
		
		}
	}
	if(flag==1)
	{
		f.close();
		cout << "Customer Has Already Check-out No Such Customer Staying in our Hotel!" << endl;
		return 0;
	}
	f.close();
	 flag=0;
	fstream temp;
	f.open("customer.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);

	while(f.read((char*)&c,sizeof(c)))
	{
		if(c.id==t)
		{
		flag=1;
		c.getout();
		temp.write((char*)&c,sizeof(c));
		}
		else
		{
			temp.write((char*)&c,sizeof(c));
		}
	}
	f.close();
	temp.close();
    if(flag==1){
		remove("customer.dat");
	    rename("temp.dat","customer.dat");
	   // cout << "\nRecord Modified Successfully!";
    }
    else{
    	remove("temp.dat");
    //	printf("\nThere is no room with that number!");
	}
	f.open("customer.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);

	while(f.read((char*)&c,sizeof(c)))
	{
		if(c.id==t)
		{
		flag=1;
		c.count();
		day = c.days;
		temp.write((char*)&c,sizeof(c));
		}
		else
		{
			temp.write((char*)&c,sizeof(c));
		}
	}
	f.close();
	temp.close();
    if(flag==1){
		remove("customer.dat");
	    rename("temp.dat","customer.dat");
	   // cout << "\nRecord Modified Successfully!";
    }
    else{
    	remove("temp.dat");
    //	printf("\nThere is no room with that number!");
	}
cout << "Total Days Stay:" << day << endl;
cout << endl <<  endl << "**************************" << endl << endl;




flag=0;
float num;
f.open("room.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	while(f.read((char*)&r,sizeof(r)))
	{
		if(r.roomNumber==n)
		{
		flag=1;
		num = r.rent;
		if(r.status==1)
		{
		r.status=0;
		}
		temp.write((char*)&r,sizeof(r));
		}
		else
		{
			temp.write((char*)&r,sizeof(r));
		}
	}
	f.close();
	temp.close();
    if(flag==1){
		remove("room.dat");
	    rename("temp.dat","room.dat");
	   // cout << "\nRecord Modified Successfully!";
    }
    else{
    	remove("temp.dat");
	}
float amt;
bill = day * num;
cout << "Total Amount: " << bill <<"$"<< endl;
amt = bill - advpay;
if(amt > 0)
{
	cout << "Total Amount After Subtracting Advance Payment: "<< amt<<"$"<<endl;
	cout << "Amount to Return: 0$" << endl;
	cout << endl << "********Thank You For Choosing Fast Hotel********" << endl; 
}
else
{
	amt = advpay - bill;
	cout << "Total Amount After Subtracting Advance Payment: 0$ "<<endl;
	cout << "Amount to Return: "  <<amt<<"$"<<endl;
	cout << endl << "********Thank You For Choosing Fast Hotel********" << endl; 
}
	
	
}
int main()
{
	start();
	return 0;
}

//

void start()
{
	login();
	hotel h;
	h.menu();
}
void gotoxy(int x,int y) //function to print anything at desired position...
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void loading(int N) //function for loading screen 7 zeros,
{	
	int i,j; 
	char c;//42 is ASCII code for Character which is to be printed
	c=42;
	gotoxy(24,10);
	for(i=1;i<=37;i++)
	{
		cout << c;
	}
	gotoxy(24,11);
	cout << "*                                   *";
	gotoxy(24,12);
	for(i=1;i<=37;i++)
	{
		cout << c;
	}
	c= 219;//219 is ASCII code for Character which is to be printed
	gotoxy(25,11);
	cout << "Loading : ";
	
	gotoxy(35,11);
	
	for(i=1;i<=25;i++)
	{
		for(j=0; j<=N;j++);
		{
		} //determine speed of loading screen
		cout << c; 
		
	}
}
void login()
{
		int ch,i;
	string user, pass;
	
	while(1)
	{
	gotoxy(24,9);
	cout << "\n\n                       Username: ";
	cin >> user;
	gotoxy(24,10);
	cout << "\n\n                       Password: ";
	ch = getch();
	
	while(ch != 13)
	{
		pass.push_back(ch);
		cout << '*';
		ch = getch();
	}
	
	if(user == "Fast@Hotel" && pass == "fast")
	{
		gotoxy(24,12);
		cout << endl << "Login Successful !" << endl;
		gotoxy(24,13);
		cout << "Press Enter to continue!" << endl;
		getch();
		break;
	}
	else
	{
		gotoxy(24,12);
		cout << endl << "Wrong Username or Passwrod! ENTER AGAIN !" << endl;
		gotoxy(24,13);
		cout << "Press Enter to continue!";
		getch();
		system("cls");
		pass.erase(0);
		user.erase(0);
		continue;
	}
	
}
}
