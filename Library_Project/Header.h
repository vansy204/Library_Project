#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#define MAX 100
using namespace std;
struct Manages
{
	int ID_Manages;
	string Name_Manages;
	int Birth_Manages;
};
struct Students
{
	long long ID_Students;
	string Name_Students;
	int Birth_Students;
};
struct Members
{
	int LengOfManages = 0;
	int LengOfStudents = 0;
	Manages manages[MAX];
	Students students[MAX];

};
struct Book
{
	int ID_Book;
	string Name_book;
	string Author;
	float Price;
	int LengOfBook = 0;
};
struct Data
{
	int STT;
	string Task;
	string Name_Book;
	string Name_Student_Use;
	long long Id_Student_Use;
	int Days;
	float Price;
	int LengOfData = 0;
};
void Read_Book_From_File(Book book[MAX]);
void Print_List_Book(Book book[MAX]);
void Read_Manages_From_File(Members& members);
void Read_Students_From_File(Members& members);
bool signin_with_managements(Members members);
bool signin_with_students(Members members);
void login(Members members, Book book[MAX], Data data[MAX]);
void Manage_Add_Book(Book book[MAX]);
void Read_Data_From_File(Data data[MAX]);
void Print_Data(Data data[MAX]);
void Manages_Edit_Data(Data data[MAX]);
void Manages_Edit_Task(Data data[MAX]);
void Manages_Edit_Name_Book(Data data[MAX]);
void Manages_Edit_Name_Students(Data data[MAX]);
void Manages_Edit_Price(Data data[MAX]);
void Manages_Edit_Day(Data data[MAX]);
void Students_Rent_Buy_Book(Data data[MAX],Book book[MAX]);
void Print_New_data(Data data[MAX]);