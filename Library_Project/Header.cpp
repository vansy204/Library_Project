#include "Header.h"

void Read_Book_From_File(Book book[MAX])
{
	ifstream File_Book_In;
	File_Book_In.open("Book.txt", ios_base::in);
	if (!File_Book_In.is_open())
	{
		cerr << "FAIL TO OPEN FILE Book.txt" << endl;
		return;
	}
	int i = 0;
	while (!File_Book_In.eof())
	{
		File_Book_In >> book[i].ID_Book;
		File_Book_In.seekg(1, 1);
		File_Book_In.ignore();
		getline(File_Book_In, book[i].Name_book, ',');
		File_Book_In.seekg(1, 1);
		getline(File_Book_In, book[i].Author, ',');
		File_Book_In.seekg(1, 1);
		File_Book_In >> book[i].Price;
		book->LengOfBook++;
		i++;
	}
}
void Print_List_Book(Book book[MAX])
{
	for (int i = 0; i < book->LengOfBook; i++)
	{
		cout << book[i].ID_Book << ", " << book[i].Name_book << ", " << book[i].Author << ", " << book[i].Price << endl;
	}
}
void Read_Manages_From_File(Members& members)
{
	ifstream File_Manage_In;
	File_Manage_In.open("Manages.txt", ios_base::in);
	if (!File_Manage_In.is_open())
	{
		cerr << "FAIL TO OPEN FILE Manages.txt" << endl;
		return;
	}
	int i = 0;
	while (!File_Manage_In.eof())
	{
		File_Manage_In >> members.manages[i].ID_Manages;
		File_Manage_In.seekg(1, 1);
		File_Manage_In.ignore();
		getline(File_Manage_In, members.manages[i].Name_Manages, ',');
		File_Manage_In.seekg(1, 1);
		File_Manage_In >> members.manages[i].Birth_Manages;
		string temp;
		getline(File_Manage_In, temp);
		members.LengOfManages++;
		i++;
	}
	File_Manage_In.close();
}
void Read_Students_From_File(Members& members)
{
	ifstream File_Students_In;
	File_Students_In.open("Students.txt", ios_base::in);
	if (!File_Students_In.is_open())
	{
		cerr << "FAIL TO OPEN FILE Students.txt" << endl;
		return;
	}
	int i = 0;
	while (!File_Students_In.eof())
	{
		File_Students_In >> members.students[i].ID_Students;
		File_Students_In.seekg(1, 1);
		File_Students_In.ignore();
		getline(File_Students_In, members.students[i].Name_Students, ',');
		File_Students_In.seekg(1, 1);
		File_Students_In >> members.students[i].Birth_Students;
		string temp;
		getline(File_Students_In, temp);
		members.LengOfStudents++;
		i++;
	}
}
bool signin_with_managements(Members members)
{
	int id;
	cout << "Input your ID MANAGE: ";
	cin >> id;
	string name;
	cout << "Input your Name: ";
	cin.ignore();
	getline(cin, name);

	for (int i = 0; i < members.LengOfManages; i++)
	{
		if (id == members.manages[i].ID_Manages && name == members.manages[i].Name_Manages)
		{
			return true;
		}
	}
	return false;
}
bool signin_with_students(Members members)
{
	long long id;
	cout << "Input Your ID STUDENTS: ";
	cin >> id;
	string name;
	cout << "Input Your Name: ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < members.LengOfStudents; i++)
	{
		if (id == members.students[i].ID_Students && name == members.students[i].Name_Students)
		{
			return true;
		}
	}
	return false;
}
void Read_Data_From_File(Data data[MAX])
{
	ifstream File_Data_In;
	File_Data_In.open("Task.txt", ios_base::in);
	if (!File_Data_In.is_open())
	{
		cerr << "FAIL TO OPEN FILE Task.txt" << endl;
		return;
	}
	int i = 0;
	while (!File_Data_In.eof())
	{
		File_Data_In >> data[i].STT;
		File_Data_In.seekg(1, 1);
		File_Data_In.ignore();
		getline(File_Data_In, data[i].Task, ',');
		File_Data_In.seekg(1, 1);
		getline(File_Data_In, data[i].Name_Book, ',');
		File_Data_In.seekg(1, 1);
		getline(File_Data_In, data[i].Name_Student_Use, ',');
		File_Data_In.seekg(1, 1);
		File_Data_In >> data[i].Id_Student_Use;
		File_Data_In.seekg(1, 1);
		File_Data_In >> data[i].Days;
		File_Data_In.seekg(1, 1);
		File_Data_In >> data[i].Price;
		string temp;
		getline(File_Data_In, temp);
		data->LengOfData++;
		i++;
	}
}
void Print_Data(Data data[MAX])
{
	for (int i = 0; i < data->LengOfData; i++)
	{
		cout << data[i].STT << ", " << data[i].Task << ", " << data[i].Name_Book << ", " << data[i].Name_Student_Use << ", " << data[i].Id_Student_Use << ", " << data[i].Days << ", " << data[i].Price;
		if (i <= data->LengOfData - 2)
		{
			cout << endl;
		}
	}
}
void Manage_Add_Book(Book book[MAX])
{
	string name;
	string author;
	float price;
	cout << "Input Name of Book: ";
	cin.ignore();
	getline(cin, name);
	cout << "Input Author of Book: ";
	getline(cin, author);
	cout << "Input price: ";
	cin >> price;
	ofstream File_Book_out;
	File_Book_out.open("book.txt", ios_base::app);
	if (!File_Book_out.is_open())
	{
		cerr << "FAIL TO OPEN FILE Book.txt" << endl;
		return;
	}
	cout << "ADD SUCCES!!!" << endl;
	File_Book_out << "\n" << book->LengOfBook + 1 << ", " << name << ", " << author << ", " << price;
	File_Book_out.close();
	book->LengOfBook = book->LengOfBook + 1;
}
void Print_New_data(Data data[MAX])
{
	ofstream File_Data_New_Out;
	File_Data_New_Out.open("Task.txt", ios_base::out);
	if (!File_Data_New_Out.is_open())
	{
		cerr << "FAIL TO OPEN FILE Task.txt" << endl;
		return;
	}
	for (int i = 0; i < data->LengOfData; i++)
	{
		File_Data_New_Out << data[i].STT << ", " << data[i].Task << ", " << data[i].Name_Book << ", " << data[i].Name_Student_Use << ", " << data[i].Id_Student_Use << ", " << data[i].Days << ", " << data[i].Price;
		if (i <= data->LengOfData - 2)
		{
			File_Data_New_Out << endl;
		}
	}
	File_Data_New_Out.close();
}
void Manages_Edit_Task(Data data[MAX])
{
	int index;
	int check = 0;
	cout << "Input index you want to edit: ";
	cin >> index;
	string temp;
	cout << "Input new task: ";
	cin.ignore();
	getline(cin, temp);
	int x = sizeof(temp);
	for (int i = 0; i < data->LengOfData; i++)
	{
		if (i == index)
		{
			data[i].Task = temp;
			check = 1;
			cout << "EDIT SUCCESS!!!" << endl;
		}
	}
	if (check == 0)
	{
		cout << "Can't find your input" << endl;
	}
	Print_New_data(data);
}
void Manages_Edit_Name_Book(Data data[MAX])
{
	int index;
	string name;
	cout << "Input index you want to edit: ";
	cin >> index;
	cout << "Input name book you want to change: ";
	cin.ignore();
	getline(cin, name);
	int check = 0;
	for (int i = 0; i < data->LengOfData; i++)
	{
		if (i == index)
		{
			data[i].Name_Book = name;
			check = 1;
			cout << "EDIT SUCCESS!!!" << endl;
		}
	}
	if (check == 0)
	{
		cout << "Can't Find Book" << endl;
	}
	Print_New_data(data);
}
void Manages_Edit_Name_Students(Data data[MAX])
{
	int index;
	string name;
	cout << "Input index you want to edit: ";
	cin >> index;
	cout << "Input name students you want to change: ";
	cin.ignore();
	getline(cin, name);
	int check = 0;
	for (int i = 0; i < data->LengOfData; i++)
	{
		if (i == index)
		{
			data[i].Name_Student_Use = name;
			check = 1;
			cout << "EDIT SUCCESS!!!" << endl;
		}
	}
	if (check == 0)
	{
		cout << "Can't fint student name" << endl;
	}
	Print_New_data(data);
}
void Manages_Edit_Price(Data data[MAX])
{
	int index;
	float price;
	cout << "Input index you want to edit: ";
	cin >> index;
	cout << "Input new price: ";
	cin >> price;
	int check = 0;
	for (int i = 0; i < data->LengOfData; i++)
	{
		if (i == index)
		{
			data[i].Price = price;
			check = 1;
			cout << "EDIT SUCCESS!!!" << endl;
		}
	}
	if (check == 0)
	{
		cout << "Can't find your index: " << endl;
	}
	Print_New_data(data);
}
void Manages_Edit_Day(Data data[MAX])
{
	int index;
	int day;
	cout << "Input index you want to edit: ";
	cin >> index;
	cout << "Input new day: ";
	cin >> day;
	int check = 0;
	for (int i = 0; i < data->LengOfData; i++)
	{
		if (i == index)
		{
			data[i].Days = day;
			check = 1;
			cout << "EDIT SUCCESS!!!" << endl;
		}
	}
	if (check == 0)
	{
		cout << "Can't find your index: " << endl;
	}
	Print_New_data(data);
}
void Manages_Edit_Data(Data data[MAX])
{

	cout << "\n\n\n\t\t\t\t     WHAT DO YOU WANT TO DO?" << endl;
	cout << "\t\t\t=====================================" << endl;
	cout << "\t\t\t=\t1. Edit Task                =" << endl;
	cout << "\t\t\t=                                   =" << endl;
	cout << "\t\t\t=\t2. Edit Name Students       =" << endl;
	cout << "\t\t\t=                                   =" << endl;
	cout << "\t\t\t=\t3. Edit Name Book           =" << endl;
	cout << "\t\t\t=                                   =" << endl;
	cout << "\t\t\t=\t4. Edit Price               =" << endl;
	cout << "\t\t\t=                                   =" << endl;
	cout << "\t\t\t=\t5. Edit Day                 =" << endl;
	cout << "\t\t\t=====================================" << endl;
	int choose;
	cout << "your choose is: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		Manages_Edit_Task(data);
		break;
	}
	case 2:
	{
		Manages_Edit_Name_Students(data);
		break;
	}
	case 3:
	{
		Manages_Edit_Name_Book(data);
		break;
	}
	case 4:
	{
		Manages_Edit_Price(data);
		break;
	}
	case 5:
	{
		Manages_Edit_Day(data);
		break;
	}
	default:
		break;
	}

}
void Students_Rent_Buy_Book(Data data[MAX], Book book[MAX])
{

	Print_List_Book(book);
	int index;
	string name;
	string task;
	cout << "=======================================" << endl;
	cout << "Input your mumber of book: ";
	cin >> index;
	for (int i = 0; i < book->LengOfBook; i++)
	{
		if (i == index)
		{
			cout << "Are you sure to choose this book:" << endl;
			cout << book[i].ID_Book << ", " << book[i].Name_book << ", " << book[i].Author << ", " << book[i].Price << endl;
		}
	}
	int choose;
	cout << "YES/NO?" << endl;
	cin >> choose;
	if (choose == 1)
	{
		int day;
		long long mssv;
		do
		{
			cout << "Input your name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Input your id:";
			cin >> mssv;
			cout << "Input Task you want to do: ";
			cin.ignore();
			getline(cin, task);
			if (task == "Buy")
			{
				day = 0;
			}
			else
			{
				cout << "How many days you want to rent: ";
				cin >> day;
			}
			if (day > 15)
			{
				cout << "Overtimes!!" << endl;
				return;
			}
			cout << task << " SUCCSESS!!" << endl;
		} while (day > 15);
		ofstream File_New_Data_Out;
		File_New_Data_Out.open("Task.txt", ios_base::app);
		if (!File_New_Data_Out.is_open())
		{
			cerr << "FAIL TO OPEN FILE" << endl;
		}
		File_New_Data_Out << "\n" << data->LengOfData + 1 << ", " << task << ", " << book[index].Name_book << ", " << name << ", " << mssv << ", " << day << ", " << book[index].Price;
		File_New_Data_Out.close();
	}
	else
	{
		cout << task << " Fail!!" << endl;
		return;
	}


}
void login(Members members, Book book[MAX], Data data[MAX])
{
	while (true)
	{
		system("cls");
		cout << "\n\n\n\t\t\t\t     WHO ARE YOU?" << endl;
		cout << "\t\t\t=====================================" << endl;
		cout << "\t\t\t=\t1. Managements              =" << endl;
		cout << "\t\t\t=                                   =" << endl;
		cout << "\t\t\t=\t2. Students                 =" << endl;
		cout << "\t\t\t=                                   =" << endl;
		cout << "\t\t\t=\t0. Exit                     =" << endl;
		cout << "\t\t\t=====================================" << endl;
		int WAY;
		cout << "You Are: ";
		cin >> WAY;
		if (WAY == 1)
		{
			if (signin_with_managements(members))
			{
				cout << "LOGIN SUCCES!!" << endl;
				system("pause");
				system("cls");
				while (true)
				{
					cout << "\n\n\n\t\t\t\t     WHAT DO YOU WANT TO DO?" << endl;
					cout << "\t\t\t=====================================" << endl;
					cout << "\t\t\t=\t1. Print list book          =" << endl;
					cout << "\t\t\t=                                   =" << endl;
					cout << "\t\t\t=\t2. Print list task          =" << endl;
					cout << "\t\t\t=                                   =" << endl;
					cout << "\t\t\t=\t3. Add book to list         =" << endl;
					cout << "\t\t\t=                                   =" << endl;
					cout << "\t\t\t=\t4. Edit Data                =" << endl;
					cout << "\t\t\t=                                   =" << endl;
					cout << "\t\t\t=\t0. Exit                     =" << endl;
					cout << "\t\t\t=====================================" << endl;
					int choose;
					cout << "Your choose is: ";
					cin >> choose;
					switch (choose)
					{
					case 1:
					{
						system("cls");
						book->LengOfBook = 0;
						Read_Book_From_File(book);
						Print_List_Book(book);
						system("pause");
						system("cls");
						break;
					}
					case 2:
					{
						system("cls");
						data->LengOfData = 0;
						Read_Data_From_File(data);
						Print_Data(data);
						cout << endl;
						system("pause");
						system("cls");
						break;
					}
					case 3:
					{
						system("cls");
						Manage_Add_Book(book);
						system("pause");
						system("cls");
						break;
					}
					case 4:
					{
						system("cls");
						Manages_Edit_Data(data);
						system("pause");
						system("cls");
						break;
					}
					default:
					{
						break;

					}
					}
					if (choose == 0)
					{
						break;
					}
				}
			}
			else
			{
				cout << "Whoops, something went wrong!!" << endl;
				return;
			}

		}
		else if (WAY == 2)
		{
			if (signin_with_students(members))
			{
				cout << "LOGIN SUCCES!!" << endl;
				system("pause");
				system("cls");
				while (true)
				{
					system("cls");
					cout << "\n\n\n\t\t\t\t     WHAT DO YOU WANT TO DO?" << endl;
					cout << "\t\t\t=====================================" << endl;
					cout << "\t\t\t=\t1. Print list book          =" << endl;
					cout << "\t\t\t=                                   =" << endl;
					cout << "\t\t\t=\t2. Rent/Buy Book            =" << endl;
					cout << "\t\t\t=                                   =" << endl;
					cout << "\t\t\t=\t0. Exit                     =" << endl;
					cout << "\t\t\t=====================================" << endl;
					int choose;
					cout << "Your choose: ";
					cin >> choose;
					switch (choose)
					{
					case 1:
					{
						system("cls");
						Read_Book_From_File(book);
						Print_List_Book(book);
						system("pause");
						break;
					}
					case 2:
					{
						system("cls");
						book->LengOfBook = 0;
						Read_Book_From_File(book);
						Students_Rent_Buy_Book(data, book);
						system("pause");
						system("cls");
						break;
					}
					default:
					{
						break;
					}
					}
					if (choose == 0)
					{
						break;
					}
				}

			}
			else
			{
				cout << "Whoops, Something went wrong!!" << endl;
				return;
			}
		}
		else
		{
			break;
		}
	}
}