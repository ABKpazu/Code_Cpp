//本程序的测试环境：在 Visual Studio 2022 标准下成功编译并运行
//本程序已上传 https://github.com/ABKpazu/Code_Cpp
//本程序为原创程序，转载请标明出处
//本程序仅供学习交流使用，请勿用于商业用途

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class ABKpazu_book
{
public:
	ABKpazu_book()
	{
		name = new char[10];
		const char* t = "Null";
		strcpy_s(name, strlen(t) + 1, t);
		pages = 0;
	}
	ABKpazu_book(char* t, int i = 0)
	{
		name = new char[10];
		strcpy_s(name, strlen(t) + 1, t);
		pages = i;
	}
	ABKpazu_book(const ABKpazu_book& o)
	{
		name = new char[10];
		strcpy_s(name, strlen(o.name) + 1, o.name);
		pages = o.pages;
	}
	virtual ~ABKpazu_book()
	{
		delete[] name;
	}
	void reset_book(int i = 0)
	{
		pages = i;
	}
	void getinformation_book()
	{
		cout << "The name of this book is: " << name << " (" << pages << " pages)" << endl;
	}
private:
	char* name;
	int pages;
};

int main()
{
	vector <ABKpazu_book*> ABKpazu_library;
	ABKpazu_book Book1;  //Default constructor
	ABKpazu_library.push_back(&Book1);
	char t2[10];
	cout << "Please enter the name of the Book2:" << endl;
	cin >> t2;
	ABKpazu_book Book2(t2);
	ABKpazu_library.push_back(&Book2);
	char t3[10];
	int i3;
	cout << "Please enter the name and pages of the Book3:" << endl;
	cin >> t3 >> i3;
	ABKpazu_book Book3(t3, i3);
	ABKpazu_library.push_back(&Book3);
	ABKpazu_book Book4(Book2);  //Copy constructor
	ABKpazu_library.push_back(&Book4);
	ABKpazu_book Book5(Book3);  //Copy constructor
	ABKpazu_library.push_back(&Book5);
	vector <ABKpazu_book*>::iterator it = ABKpazu_library.begin();
	for (; it != ABKpazu_library.end(); it++)
	{
		(**it).getinformation_book();
	}  //Way 1 of iterating
	int i2;
	cout << "Please enter the reset pages of the Book2:" << endl;
	cin >> i2;
	Book2.reset_book(i2);
	for (int i = 0; i < ABKpazu_library.size(); i++)
	{
		(*(ABKpazu_library[i])).getinformation_book();
	}  //Way 2 of iterating
	return 0;
}
