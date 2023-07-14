
#include "Header.h"

int main()
{
	Members members;
	Book book[MAX];
	Data data[MAX];
	Read_Manages_From_File(members);
	Read_Students_From_File(members);
	login(members, book, data);
	return 0;
}