#include "MyString.h"

ostream& operator<<(ostream& os, const String& string)
{
	for (int i = 0; i < string.lenght; i++)
	{
		os << string.text[i];
	}
	return os;
}

istream& operator>>(istream& is, String& string)
{
	setlocale(LC_ALL, "ru");
	is.getline(string.text, string.capacity);
	string.lenght = strlen(string.text);
	return is;
}


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
	/*String a;
	cout << "============================" << endl;
	cout << a.GetString() << endl;
	cout << a.GetCapacity() << endl;
	cout << a.GetLenght() << endl;
	cout << "============================" << endl;
	String b("Hello world");
	String c = b;
	cout << a.GetString() << endl;
	cout << b.GetString() << endl;
	cout << c.GetString() << endl;
	cout << "============================" << endl;
	cout << b.GetString() << endl;
	cout << b.GetLenght() << endl;
	cout << b.GetCapacity() << endl;*/
	/*cout << "============================" << endl;
	a.SetString("nice weather!");
	cout << a.GetString() << endl;
	cout << a.GetLenght() << endl;
	cout << a.GetCapacity() << endl;
	cout << "============================" << endl;
	a.Clear();
	cout << a.GetString() << endl;
	cout << a.GetLenght() << endl;
	cout << a.GetCapacity() << endl;
	cout << "============================" << endl;
	a.ShringToFit();
	cout << a.GetLenght() << endl;
	cout << a.GetCapacity() << endl;
	cout << "============================" << endl;
	a.SetString("nice weather!");
	a.ShringToFit();
	cout << a.GetString() << endl;
	cout << a.GetLenght() << endl;
	cout << a.GetCapacity() << endl;*/



	/*cout << "============================" << endl;
	String b("Hello this world!");
	cout << b.GetString() << endl;
	cout << b.GetLenght() << endl;
	cout << b.GetCapacity() << endl;
	for (int i = 0; i < b.GetLenght(); i++)
	{
		cout << b.GetCharAt(i) << endl;
	}*/

	/*String B("Hello");
	B.PrintLn();*/


	/*String a;
	a.GetLine();
	a.PrintLn();
	cout << a.GetLenght() << endl;
	cout << a.GetCapacity() << endl;*/

	/*String a("Hello world!");
	a.PrintLn();
	cout << a.GetLenght() << endl;
	cout << a.GetCapacity() << endl;
	cout << a.GetCharArray() << endl;*/


	// ��������� ����� 
	/*String a("Hello World!");
	String b("Hello World!");
	cout << boolalpha<< (bool)a.CompareTo(b) << endl;*/


	// ��������� ����� char*
	/*String a("Hello World!");
	char* tmp = new char[80];
	strcpy_s(tmp, 79, "Hello World!");
	cout << boolalpha << (bool)a.CompareTo(tmp) << endl;
	delete[] tmp;*/


	// ���������� ���� �����
	/*String a("Hello");
	String b("World");
	a.PrintLn();
	b.PrintLn();
	a.Concat(b);
	a.PrintLn();
	a.ShowInfo();*/



	/*String a("Hello");
	a.ShowInfo();
	cout << "===========" << endl;
	char* tmp = new char[80];
	strcpy_s(tmp, 79, " World!");
	a.Concat(tmp);
	a.ShowInfo();
	delete[] tmp;*/


	/*���������� � ������ ��������� ������ ������
	*/




	/*String a("Perturbator");
	String b("turbe");
	cout << boolalpha << a.Contains(b) << endl;*/



	// ���������� � ��������� ������ ������ ������
	/*String a("HelloWorld");
	a.ShowInfo();
	String b("ed");
	b.ShowInfo();
	cout << boolalpha << a.EndsWith(b) << endl;*/


	// ������ ���������� ������ �������

	/*String a("Hello World");
	String b("hello W");
	a.ShowInfo();
	b.ShowInfo();
	cout << boolalpha << a.StartsWith(b) << endl;*/

	// ������� ������� �������
	
	//String a("Hello World");
	//a.ShowInfo();
	//cout << a.IndexOf('w') << endl;

	/*String a("Hello World");*/
	/*a.ShowInfo();*/
	/*cout << a.LastIndexOf('r') << endl;*/


	//�������� ���� �������� �� ����� ������, ������� �� ����������� �������
	/*String a("Hello world!");
	a.ShowInfo();
	a.Remove(4);
	a.ShowInfo();*/

	//�������� count ��������, ������� �� ������� start 
	/*String a("alexander");
	a.ShowInfo();
	a.Remove(2,3);
	a.ShowInfo();*/

	//������ � ������ ��� ��������� ������� R �� ���������� ������ Z
	/*String a("alexander");
	a.ShowInfo();
	a.Replace('e', 'b');
	a.ShowInfo();*/

	//������ � ������� ��������(� ��� ����� � ��� �������� ������)
	/*String a("��������");
	a.ShowInfo();
	a.ToLower();
	a.ShowInfo();
	cout << "===========================" << endl;
	String b("ALEXANDER");
	b.ShowInfo();
	b.ToLower();
	b.ShowInfo();*/

	//������ � �������� �������� (� ��� ����� � ��� �������� ������)
	/*String a("��������");
	a.ShowInfo();
	a.ToUpper();
	a.ShowInfo();
	cout << "========================" << endl;
	String b("alexander");
	b.ShowInfo();
	b.ToUpper();
	b.ShowInfo();*/

	//������� ������ �������
	/*String a(" i have bought bear ");
	a.ShowInfo();
	a.Trim();
	a.ShowInfo();*/

	// ������
	/*String a("Hello World!");
	a.ShowInfo();
	a.Reverse();
	a.ShowInfo();*/
	

	// ���������� �� ��������
	/*String a("fggkjsklzggrgjnlaz");
	a.ShowInfo();
	a.SortAZ();
	a.ShowInfo();
	cout << "==========================" << endl;
	String b("gbfjgbskgkruaz");
	b.ShowInfo();
	b.SortZA();
	b.ShowInfo();
	cout << "==========================" << endl;
	String c("�����������������");
	c.ShowInfo();
	c.SortAZ();
	c.ShowInfo();
	cout << "==========================" << endl;
	String d("������������������");
	d.ShowInfo();
	d.SortZA();
	d.ShowInfo();*/

	// ��������� ����������
	/*String a("Hello World!");
	a.ShowInfo();
	a.Shuffle();
	a.ShowInfo();*/

	/*String a;
	a.ShowInfo();
	a.RandomFill();
	a.ShowInfo();*/

	// ���������� ��������� =

	/*String a("Hello!");
	a.ShowInfo();
	String b("World!");
	b.ShowInfo();
	a = b;
	cout << "====================" << endl;
	a.ShowInfo();*/


	// ���������� ��������� ==

	/*String a("Hello!");
	String b("Hello!");
	bool result_1 = a == b;
	cout << boolalpha << result_1 << endl;
	cout << "================" << endl;
	String c("Hella!");
	String d("Hello!");
	bool result_2 = c == d;
	cout << boolalpha << result_2 << endl;*/

	// ���������� ��������� !=

	/*String a("Hello!");
	String b("Hello!");
	bool result_1 = a != b;
	cout << boolalpha << result_1 << endl;
	cout << "================" << endl;
	String c("Hella!");
	String d("Hello!");
	bool result_2 = c != d;
	cout << boolalpha << result_2 << endl;*/

	// ���������� �������� < 
	/*String a("ab");
	String b("abc");
	bool result = a < b;
	cout << boolalpha << result << endl;*/

	// ���������� ��������� > 
	/*String a("abd");
	String b("abc");
	bool result = a > b;
	cout << boolalpha << result << endl;*/

	//���������� ��������� < = 

	/*String a("abc");
	String b("abc");
	bool result = a <= b;
	cout << boolalpha << result << endl;*/

	//���������� ��������� > = 

	//String a("ab");
	//String b("abc");
	//bool result = a >= b;
	//cout << boolalpha << result << endl;

	// ���������� ��������� ()
	
	/*String a("Hello");
	a.ShowInfo();
	cout << "==============" << endl;
	a("World!!!!");
	a.ShowInfo();*/

	// ���������� ��������� []

	//String b("Hello");
	//cout << b[1] << endl;
	//cout << b[0] << endl;
	//cout << b[8] << endl;  // ��������� � ��������������� ��������

	// ���������� ��������� + / +=
	
	/*String a("Hello");
	String b("World");
	a.ShowInfo();
	cout << "=================" << endl;
	b.ShowInfo();
	cout << "=================" << endl;
	a + b;
	a.ShowInfo();
	cout << "=================" << endl;
	a += b;
	a.ShowInfo();*/

	/*String a("Hello");
	a.ShowInfo();
	a += " World";
	a.ShowInfo();*/

	/*String a("Hello");
	a.ShowInfo();
	a + " World";
	a.ShowInfo();*/


	// ���������� <<
	
	/*String a("Hello World");
	cout << a << endl;*/

	// ���������� >>

	/*String a;
	a.ShowInfo();
	cin >> a;
	a.ShowInfo();*/

	String a("Hello!");
	a.ShowInfo();
	String b("World");
	b.ShowInfo();
	String c(b);
	c.ShowInfo();



	




	












	return 0;
}