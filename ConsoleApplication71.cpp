#include<iostream>
#include<cstring>
#include<iomanip>
#include <Windows.h>
#include<fstream>
#include<string>
using  namespace std;

void SignInforcostumer(char names[50], char Contactno[13], string File)
{
	char IDCardno[15];
	char gender;
	int Costumerno = 1;
	int password[4];
	ofstream Costumerdetails;
	Costumerdetails.open(File, ios::app);
	ifstream C_Noread;
	C_Noread.open(File);
	string	header;
	char firstname[14];
	char lastname[14];
	int i = 0;
	cout << "First Name:";
	cin >> firstname;
	cout << "Last Name:";
	cin >> lastname;

	cout << "ID card number:";

	for (int h = 0; h < 15; h++)
	{
		cin >> IDCardno[h];
		if (h > 15)
		{
			cout << "invaalid number kindly enter again:" << endl;
			cin >> IDCardno[h];
		}
	}
	cout << "Gender(F/f or M/m):";
	cin >> gender;
	cout << "kindly enter 4 digit Password:";
	for (int i = 0; i < 4; i++)
	{
		cin >> password[i];

	}
	cout << " Contact No:";
	for (int i = 1; i < 13; i++)
	{
		cin >> Contactno[i];
	}
	cout << "." << endl;
	cout << "LOADING...";
	Sleep(2000);
	cout << ".....";

	cout << "" << endl;
	system("cls");

	string L,M,P,X,Z,Y;
	cout << "Congratulation you have sign up successfully." << endl;
	if (C_Noread.is_open())
	{
		getline(C_Noread, header);

		while (!C_Noread.eof())
		{
			C_Noread >> L;
			Costumerno = std::stoi(L);
			C_Noread >> M;
			C_Noread >> P;
			C_Noread >> X;
			C_Noread >> Z;
			C_Noread >> Y;
		}
		Costumerno++;
		if (Costumerdetails.is_open())
		{


			Costumerdetails << Costumerno << "\t\t";
			for (int i = 0; i < 4; i++)
			{
				Costumerdetails << password[i];
			}
			Costumerdetails << "\t\t";
			for (int k = 0; k < 15; k++)
			{
				Costumerdetails << IDCardno[k];
			}
			Costumerdetails << "\t\t";
			Costumerdetails << firstname << " " << lastname << "\t\t";
			Costumerdetails << gender << "\t\t";
			for (int i = 1; i < 13; i++)
			{

				Costumerdetails << Contactno[i];
			}
			Costumerdetails << endl;
		}
		Costumerdetails.close();
	}
}

int LoginIDforCustomer(string IDcardNo, string Costumerpassword,string name[1000])
{
		string header, p, q, r, s, t, u;
		int Password[1000];
		string IDcards[1000];
		int count = 0;
		bool check = true;
		string Cname;
		string name_t [1000];
		int H;
		string CostumerNo[100];
		ifstream read;
		read.open("CostumerAccountDetails.txt");
		cout << "kindly enter the follwing information for log in" << endl;
		cin.ignore();


		cout << "ID card Number:";
		getline(cin, IDcardNo);
		
		cout << "Password :";
		getline(cin, Costumerpassword);
	

		cin.ignore();

		if (read.is_open())
		{
			getline(read, header);
			while (!read.eof())
			{
				read >> p;
				CostumerNo[count] = p;
				read >> q;
				Password[count] = std::stoi(q);
				read >> r;
				IDcards[count] = r;
				read >> s;
				name_t[count] = s;
				
				read >> t;
				read >> u;

				count++;
				H = count;
			}
			for (int i = 0; i <H ; i++)                                         
			{
				if ((Costumerpassword == to_string(Password[i])) && (IDcardNo == IDcards[i]))
				{
					check = true;
					name[0]= name_t[i];
					name[1] = CostumerNo[i];
				
					return check;

				}
				else
				{
					check = false;
				}
			}

		}
		return check;

		read.close();

}
bool Adminlogin(int ResNo, string IDpassword)
{
	bool check = true;
	cout << "Select your Resturant respective No " << endl;
	cin >> ResNo;
	cout << "Enter ID Password" << endl;
cin.ignore();

		getline(cin, IDpassword);
	

	string ResturantID[500];

	string Resturant_No[500];
	ifstream Fileread;
	Fileread.open("Resturants.txt");
	int count = 0;
	int  R_NO;
	string header, R_ID;
	string T, P, S, Q, L;
	int Size;
	if (Fileread.is_open())
	{
		int count = 0;
		getline(Fileread, header);
		while (!Fileread.eof())
		{

			Fileread >> R_NO;
			Resturant_No[count] = to_string(R_NO);
			Fileread >> R_ID;
			ResturantID[count] = (R_ID);
			Fileread >> T >> P >> S >> Q >> L;
			if (R_NO== ResNo && R_ID == IDpassword)
			{
				return true;
			}


				count++;
			
		}

	}
	Fileread.close();
	return false;
}
void resturantdisplay(char name[12][30], int listofRes_IDno[12], int Rating[10])
{
	ofstream resturantsfile;
	resturantsfile.open("Resturants.txt",ios::app);
	int resNo[5];
	string Address[500];
	string ContactNo[12];
	char Category[100];
	
	for (int i = 0; i < 1; i++)
	{
		cout << "Enter the name of the Resturant:";
		cin.getline(name[i], 30);
		cout << "enter address:" << endl;

		getline(cin, Address[i]);

		cout << "Enter Contact Name" << endl;
		getline(cin, ContactNo[i]);
		cout << "Enter category" << endl;
		cin.getline(Category, 100);
	}
	for (int i = 0; i < 1; i++)
	{
		cout << "Enter Resturant id"<<endl;
		cin >> listofRes_IDno[i];
		cout << endl;
		cout << "Enter the Ranking of resturnat:"<<endl;
		cin >> Rating[i];
			
		cout << endl;
	}
	if (resturantsfile.is_open())
	{
		/*resturantsfile << "Res NO\t\t";
		resturantsfile << "ID no\t\t";
		resturantsfile << "Resturant name\t\t";
		resturantsfile << "Ranting" <<"\t\t";
			resturantsfile<<"Category"<<"\t\t";
			resturantsfile << "Contact" << "\t\t";
			resturantsfile << "Address" << endl;*/


		for (int i = 0; i < 1; i++)
		{
			resturantsfile  << i+1<<"\t\t"<<listofRes_IDno[i] << "\t\t" << name[i] << " \t\t" << Rating[i] << "\t\t"<<Category[i]<<"\t"<< ContactNo[i]<<"\t\t"<< Address[i]<<endl;
		
		}

	}
}
void Read(string filename)
{
	string data;
	ifstream Fileread;
	Fileread.open(filename);
		if (Fileread.is_open())
		{

			while(!Fileread.eof())
			{
				while (getline(Fileread, data))
				{
					cout << data << endl;
				} 				
			}
		}
		else
		{
			cout << "Unable to read" << endl;
		}
		Fileread.close();

}


void resOrderHistory(string filename, string orderdata[][4], int item_quantity[], int C,  string Current_CostumerName, string Current_CostumerID)
{
	ofstream fileObj;
	string file_name = "OrderHistory/" + Current_CostumerID + ".txt";
	fileObj.open(file_name,ios::app);
	if (fileObj.is_open())
	{

		for (int i = 0; i < C; i++)
		{

			fileObj << orderdata[i][0] << "\t\t\t " << item_quantity[i] << " \t\t " << orderdata[i][1] << endl;
			fileObj << endl;
		}
	}
}
void ReadOrderHistory( string Current_CostumerID)
{
	ifstream fileObj;
	string header;
	string file_name = "OrderHistory/" + Current_CostumerID + ".txt";
	fileObj.open(file_name);
	if (fileObj.is_open())
	{
		
		
		while (!fileObj.eof())
		{
			
			getline(fileObj, header);
			cout << header;
		}
	}
}


void OrderCalculation_display(string Data[100][3], string filename,string salesreport,int SelectResNo,string Current_CostumerID, string Current_CostumerName)
{
	int Item_Select;
	int sum = 0;
	int Q;
	string order[30][4];
	char choice{};
	cout << "Do you want to start ?" << endl;
	cin >> choice;
	int i;
	ifstream Fileread;
	Fileread.open(filename);

	salesreport = "Sales Report" + to_string(SelectResNo) + ".txt" ;
	ofstream sale_report;
	sale_report.open(salesreport, ios::app);
	int count = 0;
	int price;
	string serving;
	string Description;
	string name;
	int id;
	string header;
	int C = 0;
	string K, L,N;
	int G;
	string h,o,n;
	int P[100];
	char Option;
	string HAddress;
	int T;
	char Confirmation;
	int rating[12];

	if (Fileread.is_open())
	{
		getline(Fileread, header);
		getline(Fileread, header);
		getline(Fileread, header);
		getline(Fileread, header);
	
		int count = 0;
		while (!Fileread.eof())
		{
			Fileread >> id;
			Data[id][0] = to_string(id);
			Fileread >> name;
			Data[id][1] = name;
			Fileread >> price;
			Data[id][2] = to_string(price);
			Fileread >> serving;
			Fileread >> Description;

			count++;
			G = count;
		}
	}
	Fileread.close();
	while (choice == 'y')
	{
		cout << "Select your item" << endl;
		cin >> Item_Select;

		cout << "Select the quntity" << endl;
		cin >> Q;
		
			if (Item_Select == std::stoi(Data[Item_Select][0]))
			{
				sum = Q * std::stoi(Data[Item_Select][2]) + sum;
				order[C][0] = Data[Item_Select][1];
				order[C][1] = Data[Item_Select][2];
				order[C][2] = Data[Item_Select][0];
				K = order[C][0];
				L = order[C][1];
				N = order[C][2];
				P[C] = Q;
				C++;
			}
		


		cout << "Do you want ot selct more?" << endl;
		cin >> choice;
		int orderNO = 0;

		if (choice == 'n')
		{
				cout << "\n\t\t\t\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL ";
				for (int a = 1; a < 8; a++)
				{
					Sleep(400);
					cout << "...";
				}
				cout << "\n\t\t\t\t\t\t\t";
				system("PAUSE");
				system("CLS");
				cout << "Select Your Option" << endl;
				cout << "D for Home Dilivery" << endl;
				cout << "T for Takeaway" << endl;
				cin >> Option;
				cout << endl;
				if (Option == 'T')
				{
					cout << "\t\t\t\--------------------------Final Order-----------------------" << endl;
					cout << endl;


					cout << "\tItems" << "\t\t\t\t" << "Quantity" << "\t" << "Price(for per)" << endl;

					for (int i = 0; i < C; i++)
					{

						cout << " " << order[i][0] << "\t\t\t" << P[i] << " \t\t   " << order[i][1] << endl;
						cout << endl;
					}
					cout << "Total  Bill:" << "\t\t\t\t\t\t" << "Rs" << sum << endl;
					Sleep(300);
					cout << " thank you For Ordering from Us" << endl;
					resOrderHistory( "", order, P,C, Current_CostumerID, Current_CostumerName);
					cout << endl;
					if (sale_report.is_open())
					{
		
						for (int i = 0; i < C; i++)
						{

							sale_report << std::stoi(order[i][2]) << "\t\t" << order[i][0] << "\t" << P[i] << "\t\t" << order[i][1] << endl;
						}
					}
				}
			
			else if (Option == 'D')
			{
				cout << "kindly your address" << endl;
				for (int i = 0; i < 1; i++)
				{
					getline(cin, HAddress);
				}
				cout << "\t\t\t\--------------------------Final Order-----------------------" << endl;
				cout << endl;


				cout << "\tItems" << "\t\t\t\t" << "Quantity" << "\t" << "Price(for per)" << endl;

				for (int i = 0; i < C; i++)
				{

					cout << "\t" << order[i][0] << "\t\t  "<< P[i] << " \t\t " << order[i][1] << endl;
					cout << endl;
				}
				cout << "Total  Bill:" << "\t\t\t\t\t\t" << "Rs" << sum << endl;
				cout << "Diliver to :" << HAddress << endl;
				Sleep(300);
				cout << " thank you For Ordering from Us" << endl;
				if (sale_report.is_open())
				{
					for (int i = 0; i < C; i++)
					{

						sale_report << std::stoi(order[i][2]) << "\t\t" << order[i][0] << "\t" << P[i] << "\t\t" << order[i][1] << endl;


					}
				}
				
			}
			cout << endl;
		}
	}

}

void Createitem(string filenameofreturantitems)
{
	int no_of_item;
	string header;
	cout << "how many items you want to add" << endl;
	cin >> no_of_item;
	string ItemId,B,C,D,E;
	int Price[20];
	int SPrice[20];
		int CPrice[20];
	char name[20][90];
	string serving;
	string despcrition;
	string IDS[20][20];
	ofstream Menu;
	ifstream Numread;
	Numread.open(filenameofreturantitems);
	Menu.open(filenameofreturantitems, ios::app);
	int NewID=0;
	cout << " The item id of dishes will be"<<endl;
	if (Numread.is_open())
	{
		getline(Numread, header);
		getline(Numread, header);
		getline(Numread, header);
		getline(Numread, header);
		int count = 0;

		while (!Numread.eof())
		{
			Numread >> ItemId;
			NewID = std::stoi(ItemId) + 1;
			Numread >> B;
			Numread >> C;
			Numread >> D;
			Numread >> E;
			count++;
			
		}
		cout << NewID << endl;
	}
	Numread.close();

	cout << "Name of items:" << endl;
	for (int i = 0; i <= no_of_item; i++)
	{

		cin.getline(name[i], 90);
	}
	cout << "enter the Sale Prices:" << endl;
	for (int i = 1; i <= no_of_item; i++)
	{
		cin >> SPrice[i];
	}
	cout << "enter the Cost Prices:" << endl;
	for (int i = 1; i <= no_of_item; i++)
	{
		cin >> CPrice[i];
	}
	cout << "enter the serving" << endl;
	for (int i = 0; i <= no_of_item; i++)
	{
		getline(cin, serving);
	}
	cout << "Enter the description" << endl;
	for (int i = 1; i <= no_of_item; i++)
	{
		getline(cin, despcrition);
	}
	for (int i = 1; i <= no_of_item; i++)
	{
		cout << NewID << "\t\t" << name[i] <<"\t\t"<< SPrice[i]+CPrice[i] <<"\t\t"<<serving<<"\t\t  "<<despcrition<< endl;

	}
	
	if (Menu.is_open())
	{
		
		for (int i = 1; i <= no_of_item; i++)
		{
			Menu << NewID << "\t" << name[i] << "\t\t\t" << SPrice[i]+CPrice[i] << "\t\t" << serving <<"\t\t    "<<despcrition<< endl;

		}
		for (int l = 1; l < 6; l++)
		{
			Sleep(200);
			cout <<"...";
		}
		cout << endl;
		cout << "Successfully update the Menu" << endl;
	}
	else
	{
		for (int l = 1; l < 6; l++)
		{
			Sleep(400);
			cout << "..." ;
		}
		cout << endl;
		cout << "Sorry .Due to some error the the Menu could not updated" << endl;
	}
	Menu.close();
}
void createRes(string filename)
{
	ifstream file;
	file.open(filename, ios::app);
	ofstream file_write;
	file_write.open(filename, ios::app);
	ofstream NEWAdminID;
	ifstream ReadNewID;
	ReadNewID.open("New Admin ID.txt");
	int resNo=0;
	int RESID=0;
	string header;
	char name[1][12];
	string Address[500];
	string ContactNo[12];
	char Category[100];
	int listofRes_IDno[12];
	int Rating[12];
	int itemID;

	char itemname;
	char Size;
	int Serving;
	int SPrice;
	int R_no;
	int Rid;
	cout << "AS you are noe admin " << endl;


	cout << " New Resturant Number  :";
	if (ReadNewID.is_open())
	{
		while (!ReadNewID.eof())
		{
			
			ReadNewID >> resNo;
			ReadNewID >> RESID;
			
		}
		 R_no = resNo;
		 Rid = RESID;
		cout << resNo << endl;
		cout << "New Resturant ID will be:";
		cout << RESID;
		NEWAdminID.open("New Admin ID.txt");
		if (NEWAdminID.is_open())
		{
			resNo = resNo + 1;
			RESID = RESID + 1;
			NEWAdminID << resNo << "\t";
			NEWAdminID << RESID << endl;
		}
	}
		NEWAdminID.close();
		ReadNewID.close();
		cout << "Kindly fil the given information to create a resturant " << endl;
	cout << "Enter the name of the Resturant:";
	for (int i = 0; i < 1; i++)
	{
		cin.getline(name[i], 12);
	}
		cout << "enter address:" << endl;
		for (int i = 0; i < 1; i++)
		{
			getline(cin, Address[i]);
		}
		cout << "Enter Contact Name" << endl;
		for (int i = 0; i < 1; i++)
		{
			getline(cin, ContactNo[i]);
		}
		cout << "Enter category" << endl;
		for (int i = 0; i < 1; i++)
		{
		cin.getline(Category, 50);
	    }
	for (int i=0; i < 1; i++)
	{
		cout << "Enter the Ranking of resturnat:" << endl;
		cin >> Rating[i];


		if (file_write.is_open())
		{
			for (int i=0; i < 1; i++)
			{
				cout <<R_no<<"\t\t"<<Rid <<"\t\t" << name[i] << " \t\t" << Rating[i] << "\t\t" << Category  << "\t\t" << ContactNo[i] << "\t" << Address[i] << endl;
				file_write << R_no << "\t\t" << Rid << "\t\t" << name[i] << " \t\t  " << Rating[i] << "\t\t" << Category << "\t\t" << ContactNo[i] << "\t  " << Address[i] << endl;
			}
			cout << endl;
		}
	}
	string menufile;
	cout << "Kindly name your menu file";
	cin >> menufile;
	cout << "Now create the menu of that resturant" << endl;
	ofstream menu;

}
void DisplayRes(char name[12][30], int listofRes_IDno[10], int Rating[10])
{
	ifstream resturantsfile_read;
	resturantsfile_read.open("Resturants.txt");
	string data;
	
	char heading[100];
	if (resturantsfile_read.is_open())
	{
		
			while (getline(resturantsfile_read, data))
			{
				cout <<data << endl;
			}		
	
	}
	else
	{
		cout << "Sorry, there is some error in display" << endl;
	}
	resturantsfile_read.close();
}

void LoadResturantData(string Data[][3], int SelectResNo,string Current_CostumerID,string Current_CostumerName) {
	
		Data[100][3];
		string Sales;
		system("cls");
		string fileName = "Menu" + to_string(SelectResNo) + ".txt";
		Read(fileName);
		
		OrderCalculation_display(Data, fileName,Sales,SelectResNo,Current_CostumerID, Current_CostumerName);
	
}

void SalereportAnalysis (string file, int SelectResNo )
{

	string a, b, c, d,header;
	int Selection;
	int S;
	int Quantity[10000];
	string Price[10000];
	string Selecteditems[10000];
	int total=0;
	int Totalq=0;

	char UserChoice{};
	/*file= "Sales Rport" + to_string(SelectResNo) + ".txt";*/
	ifstream fileread;
	fileread.open(file);
	Read(file);
	
	if (fileread.is_open())
	{
		int Count = 0;
		getline(fileread, header);
		while (!fileread.eof())
		{
			fileread >> a >> b;
			Selecteditems[Count] = a;
			fileread >> c;
			Quantity[Count] =std::stoi(c);
			fileread >> d;
			Price[Count] = d;
			Count++;
			S = Count;
		}
		
		while (UserChoice != 'N')
		{
				cout << "Kindly Select the items id whose total sale you want to know" << endl;
				cin >> Selection;
				for (int j = 0; j < S; j++)
				{
					if (to_string(Selection) == Selecteditems[j])
					{
						Totalq = Quantity[j] + Totalq;
						total = (Quantity[j]) * std::stoi(Price[j]);
						cout << "The item is   " << Selecteditems[j] << endl;
						cout << "The Total Quantity selled is     " << Totalq << endl;
						cout << "The Revenue calculated from this item is    " << total << endl;
					}

				}

				cout << endl;
			cout << "Do you want to analyse more  " << endl;
			cout << "Select Y for Yes" << endl;
			cout << "Select N for No" << endl;
			cin >> UserChoice;
			if (UserChoice == 'N')
			{
				cout <<"Loading";
				for (int i = 0; i < 5; i++)
				{
					cout << "...";
					Sleep(300);
				}
				cout << endl;
				cout << "Exiting the Analyzing" << endl;
			}
				
			
		}
	}
}
void Edit_in_Menu(string MenuFile, int SelectResNo)
{
	int Select_Edit;
	int Pr;
	string serv;
	string descrip;
	int Selected_ID;
	string Item_list[100][5];
	int SIZE{};

	int ID;
	string Item, S, P, D, header1, header2, header3, header4;

	ifstream Menuread;
	Menuread.open(MenuFile);

	ofstream write_inMenu;
	write_inMenu.open(MenuFile, ios::app);
	if (Menuread.is_open())
	{
		int COUNT = 0;
		getline(Menuread, header1);
		getline(Menuread, header2);
		getline(Menuread, header3);
		getline(Menuread, header4);
		while (!Menuread.eof())
		{
			Menuread >> ID;
			Item_list[ID][0] = to_string(ID);
			Menuread >> Item;
			Item_list[ID][1] = Item;
			Menuread >> P;
			Item_list[ID][2] = P;
			Menuread >> S;
			Item_list[ID][3] = S;
			Menuread >> D;
			Item_list[ID][4] = D;
			COUNT++;
			SIZE = COUNT;
		}

		cout << "Select the item ID in which You Want to Make Updates " << endl;
		cin >> Selected_ID;
		cout << " What You want to edit in Menu?  Kindly Select it: " << endl;
		cout << "[1]- Update in price" << endl;
		cout << "[2]- Update Serving" << endl;
		cout << "[3]- Update the Desrcrption" << endl;
		cin >> Select_Edit;
		if (Select_Edit == 1)
		{
			cout << "Enter The new price :";
			cin >> Pr;
			if (write_inMenu.is_open())
			{
					Item_list[Selected_ID][2] = to_string(Pr);

				write_inMenu << (Menuread, header1) << endl;
				write_inMenu << (Menuread, header2) << endl;
				write_inMenu << (Menuread, header3) << endl;
				write_inMenu << (Menuread, header4) << endl;;
				for (int j = 0; j < SIZE; j++)
				{
					write_inMenu << Item_list[j][0] << "\t" << Item_list[j][1] << "\t \t" << Item_list[j][2] << "\t \t" << Item_list[j][3] << "\t \t" << Item_list[j][4] << endl;

				}
				cout << "Succesfully edited." << endl;
			}
		}
		else if (Select_Edit == 2)
		{
			cout << "Enter The updated Serving :";
			cin >> serv;
			if (write_inMenu.is_open())
			{

				Item_list[Selected_ID][3] = serv;

				write_inMenu << (Menuread, header1) << endl;
				write_inMenu << (Menuread, header2) << endl;
				write_inMenu << (Menuread, header3) << endl;
				write_inMenu << (Menuread, header4) << endl;;
				for (int j = 0; j < SIZE; j++)
				{
					write_inMenu << Item_list[j][0] << "\t  " << Item_list[j][1] << "\t  " << Item_list[j][2] << "\t\t" << Item_list[j][3] << "\t\t" << Item_list[j][4] << endl;

				}
				cout << "Succesfully edited." << endl;
			}
		}
		else if (Select_Edit == 3)
		{
			cout << "Enter The updated Serving :";
			getline(cin, descrip);
			if (write_inMenu.is_open())
			{
					Item_list[Selected_ID][4] = descrip;

				
				write_inMenu << (Menuread, header1) << endl;
				write_inMenu << (Menuread, header2) << endl;
				write_inMenu << (Menuread, header3) << endl;
				write_inMenu << (Menuread, header4) << endl;;
				for (int j = 0; j < SIZE; j++)
				{
					write_inMenu << Item_list[j][0] << "\t  " << Item_list[j][1] << "\t  " << Item_list[j][2] << "\t\t" << Item_list[j][3] << "\t\t" << Item_list[j][4] << endl;

				}
				cout << "Succesfully edited." << endl;
			}
			
		}
	}
	Menuread.close();
	write_inMenu.close();

}
void Delete_Item(string file,int SelectResNo)
{
	int ItemID_toremove;
	string Menu_items_list[100][4];
	cout << "Select the  item id  whose item you want to delete from menu " << endl;
	cin >> ItemID_toremove;
	string header1, header2, header3, header4, items,P, S, D;
	int ID;
	int LastID;
	ifstream Menu_read;
	Menu_read.open(file);
	
	if (Menu_read.is_open())
	{
		int COUNT = 0;
		getline(Menu_read, header1);
		getline(Menu_read, header2);
		getline(Menu_read, header3);
		getline(Menu_read, header4);
		while (!Menu_read.eof())
		{
			Menu_read >> ID;
			Menu_items_list[ID][0] = to_string(ID);
			Menu_read >> items;
			Menu_items_list[ID][1] = items;
			Menu_read >> P;
			Menu_items_list[ID][2] = P;
			Menu_read >> S;
			Menu_items_list[ID][3] = S;
			Menu_read >> D;
			Menu_items_list[ID][4] = D;

			COUNT++;
			LastID = ID;
			
		}
		Menu_read.close();
		Menu_items_list[ItemID_toremove][0] = "-1";

		ofstream Updated_Write;
		Updated_Write.open(file);
		if (Updated_Write.is_open())
		{
			Updated_Write <<header1<<endl;
			Updated_Write<<header2 << endl;
			Updated_Write << header3 << endl;
			Updated_Write << header4 << endl;
			for (int j = 0; j < LastID; j++)
			{
				if (Menu_items_list[j][0] != "-1")
				{
					Updated_Write << Menu_items_list[j][0] <<"\t\t"<< Menu_items_list[j][1] << "\t\t"<<Menu_items_list[j][2] <<"\t\t"<< Menu_items_list[j][3] <<"\t\t"<< Menu_items_list[j][4] << endl;
				}

			}
			cout << "Succefully removed From List" << endl;
		}
		Updated_Write.close();
			
		
	}
}


void LoadforAdminFucntions(int Funct, int SelectResNo,string Current_CostumerID)
{
	if (Funct == 1)
	{
		string Filename = "Menu" + to_string(SelectResNo) + ".txt";

		Read(Filename);
		Createitem(Filename);
	}
	else if (Funct == 2)
	{
		string file = "Sales Report" + to_string(SelectResNo) + ".txt";
		SalereportAnalysis(file, SelectResNo);
	}
	else if (Funct == 3)
	{
	

		ReadOrderHistory( Current_CostumerID);
	
	}
	else if (Funct == 4)
	{
		string MenuFile = "Menu" + to_string(SelectResNo) + ".txt";
		Read(MenuFile);
		Edit_in_Menu( MenuFile,SelectResNo);
	}
	else if (Funct == 5)
	{
		string File= "Menu" + to_string(SelectResNo) + ".txt";
		Read(File);
		Delete_Item(File, SelectResNo);
	}
}

int main()
{
	char roles;
	char contactno[13];
	char names[100];
	char Rest_name[5][30];
	int ID[5];
	int Rating[5];
	int SelectResNo;
	string Cname;
	string Data[100][3];
	int choice;
	int ResId = 0;
	string name[100];
	string CostumerPassword;
	string AdminPassword;
	string Idcardno;
	bool L;
	string Current_CostumerID, Current_CostumerName = "";

	char ExitOptions;

	string Order[30][20];
	int Price[10];
	cout << "\t\t\t\t W";
	Sleep(300);
		cout << "e";
		Sleep(300);
		cout << "l";
		Sleep(300);
			cout << "c";
			Sleep(300);
		cout << "o";
		Sleep(300);
		cout << "m";
		Sleep(300);
		cout <<"e ";

	Sleep(400);
	cout << "\t to";
	Sleep(400);
	cout << "\t\t KHANA BAZAAR App"<<endl;
	Sleep(400);

	cout << "Enter the role  :" << endl;
	cin >> roles;
	if (roles == 'C')
	{
		cout << "Select your choice" << endl;
		cout << "[1]   Sign UP If you do not have any account" << endl;
		cout << "[2]    Login /Sign In" << endl;
		cin >> choice;
		if (choice == 1)
		{
			SignInforcostumer(names, contactno, "CostumerAccountDetails.txt");

			bool isLogin = false;;

			while (isLogin == false)
			{
				L = LoginIDforCustomer(Idcardno, CostumerPassword, name);
				Current_CostumerID = name[0];
				Current_CostumerName = name[1];
				isLogin = L;

				if (isLogin == false)

				{
					cout << "Incorrect Information from either.Kindly reenter the information" << endl;
					cin.ignore();

				}

				cout << "Successfully log in.Now you can proceed" << endl;
				DisplayRes(Rest_name, ID, Rating);

				cout << "Select your favorite resturant" << endl;
				cin >> SelectResNo;
				system("CLS");
				LoadResturantData(Data, SelectResNo, Current_CostumerID, Current_CostumerName);
				cout << " Enter Y to exi the system" << endl;
				cin >> ExitOptions;
				if (ExitOptions == 'Y')
				{
					cout << endl;
				}

			}
		}
		else
		{
			bool isLogin = false;;

			while (isLogin == false)
			{
				L = LoginIDforCustomer(Idcardno, CostumerPassword, name);
				Current_CostumerID = name[0];
				Current_CostumerName = name[1];
				isLogin = L;
				if (isLogin == false)

				{
					cout << "Incorrect Information from either.Kindly reenter the information" << endl;
					cin.ignore();

				}
			}
			cout << "Successfully log in.Now you can proceed" << endl;
			DisplayRes(Rest_name, ID, Rating);
			cout << "Select your favorite resturant" << endl;
			cin >> SelectResNo;

			LoadResturantData(Data, SelectResNo, Current_CostumerID, Current_CostumerName);
	
			cout << " Press Y to exit the system" << endl;
			cin >> ExitOptions;
			if (ExitOptions == 'Y')
			{
				cout <<endl;
			}
		}
	}
	else if (roles == 'A')
	{
		int Funct;
		

		bool is_Login = false;;

		while (is_Login == false)
		{
			bool K = Adminlogin(ResId, AdminPassword);
			is_Login = K;
			if (is_Login == false)

			{
				cout << "Incorrect Information from either.Kindly reenter the information" << endl;
				cin.ignore();
			}
		}
		cout << "Select your Rseturant" << endl;
		cin >> SelectResNo;
		if (is_Login == true)
		{
			cout << "Successfully log in.Now you can proceed" << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t [1] - create Items/update your menu" << endl;
			cout << "\t\t\t\t\t\t\t[2]- Analyse Sale report" << endl;
			cout << "\t\t\t\t\t\t\t[3]-See your Order history" << endl;
			cout << "\t\t\t\t\t\t\t[4]-made Edits in  Menu" << endl;
			cout << "\t\t\t\t\t\t\t[5]-Delete items from Menu" << endl;
			cout << "\t\t\t\t\t\t\  Select the operations you want to perform  :";
			cin >> Funct;

			LoadforAdminFucntions(Funct, SelectResNo, Current_CostumerID);
		}
		
	}
}




	
		
	

	





