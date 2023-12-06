#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Doi mau chu
void textcolor(int x)//X la ma mau
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}

// thuc hien ham chuc nang
void functionalActivity(int option)
{
	switch (option) {
	case 1:
		cout << "Function 1" << endl;
		Sleep(5000);
		break;
	case 2:
		cout << "Function 2" << endl;
		Sleep(5000);
		break;
	case 3:
		cout << "Function 3" << endl;
		Sleep(5000);
		break;
	}
}

// thuc hien chuyen mau menu
void displayMenu(int selectedOption)
{
	system("cls");
	string func[] = { "function 1", "function 2", "function 3" };
	string tab = "\t\t\t\t\t\t";
	cout << tab << " --------------- CHUC NANG ---------------" << endl;

	for (int i = 0; i < 3; ++i) {
		if (i + 1 == selectedOption) {
			textcolor(10); // mau duoc chon
		}
		else {
			textcolor(15); // mau trang mac dinh khong duoc chon
		}
		cout << tab << func[i] << endl;
	}

	textcolor(15);
	cout << tab << " -----------------------------------------" << endl;
}

void menu()
{
	char check_select;
	int location_func = 1;
	while (true)
	{

		displayMenu(location_func);
		//bat su kien nhap tu ban phim (mui ten: 72: len 80: xuong 13: enter)
		do {
			check_select = _getch();
		} while ((check_select != 13 && check_select != 72 && check_select != 80) || (location_func == 1 && check_select == 72) || (location_func == 3 && check_select == 80));

		// khi an enter -> thuc thi ham tai vi tri location_func
		if (check_select == 13)
			functionalActivity(location_func);
		// truong hop bam mui ten len
		else if (check_select == 80) location_func++;
		// truong hop bam mui ten xuong
		else location_func--;
	}

}
int main() {
	menu();
	system("pause");
	return 0;
}