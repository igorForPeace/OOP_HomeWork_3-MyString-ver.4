#include "MyString.h"

void String::Initialize(const char* str, unsigned int capacity = 80)
{
	lenght = strlen(str);
	this->capacity = (capacity > lenght) ? capacity : lenght + 20;
	this->text = new char[this->capacity];
	strcpy_s(this->text, lenght + 1, str);
}

String::String(const char* text, unsigned int capacity = 80)
{
	this->lenght = strlen(text);
	this->capacity = capacity;
	this->text = new char[this->capacity];
	strcpy_s(this->text, lenght + 1, text);
}

String::String() : String("", 80) {}

String::String(const char* text) :String(text, 80) {}

String::String(unsigned int capacity):String("" , capacity) {}

String::String(const String& original): String (original.text, original.capacity) {}

String::~String()
{
	delete[] text;
}

const char* String::GetString() const
{
	return text;
}

void String::SetString(const char* text)
{
	lenght = strlen(text);
	if (lenght >= capacity)
	{
		delete[] this->text;
		capacity = lenght + 20;
		this->text = new char[capacity];
	}
	strcpy_s(this->text, lenght + 1, text);
}

int String::GetLenght() const
{
	return lenght;
}

int String::GetCapacity() const
{
	return capacity;
}

void String::Clear()
{
	text[0] = '\0';
	lenght = 0;
}

void String::ShringToFit()
{
	if (lenght + 1 == capacity)
	{
		return;
	}
	capacity = lenght + 1;
	char* temp = new char[capacity];
	strcpy_s(temp, capacity, text);
	delete[] text;
	text = temp;
}

char String::GetCharAt(unsigned int index)  // возврат символа по индексу
{
	for (int i = 0; i < lenght; i++)
	{
		if (i == index)
		{
			return text[i];
		}
	}
	return 0;
}

void String::Print() // показ строки на экран
{
	cout << GetString();
}

void String::PrintLn() // показ строки на экран с переводом курсора на следующую строку
{
	cout << GetString() << endl;
}

void String::GetLine()
{
	cin.getline(text, capacity);
	lenght = strlen(text);
}

const char* String::GetCharArray() const
{
	return text;
}

void String::ShowInfo() const
{
	cout << "Text: " << GetString() << endl;
	cout << "Length: " << GetLenght() << endl;
	cout << "Capacity: " << GetCapacity() << endl;
}

int String::CompareTo(String& other)
{
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->text[i] == other.text[i])
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int String::CompareTo(char* text)
{
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->text[i] == text[i])
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

void String::Concat(String& other)
{
	strcat_s(text, lenght+other.lenght+1, other.text);
	lenght += other.lenght;
	capacity *= 2;
}

void String::Concat(char* tmp)
{
	int other_lenght = strlen(tmp);
	strcat_s(text, other_lenght+lenght+1, tmp);
	lenght += other_lenght;
	capacity *= 2;
}

bool String::Contains(String& other)
{
	for (int i = 0; i < this->lenght; i++)
	{
		if (text[i]==other.text[0])
		{
			int c = i + 1;
			for (int j = 1; j < other.lenght; j++)
			{
				
				if (text[c] == other.text[j])
				{
					c++;
					continue;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

bool String::EndsWith(String& other)
{
	int j = 0;
	for (int i = lenght-other.lenght; i < lenght; i++)
	{
		if (text[i] == other.text[j])
		{
			j++;
			continue;
		}
		else
		{
			return false;
		}
		return true;
	}
}

bool String::StartsWith(String& other)
{
	for (int i = 0; i < other.lenght; i++)
	{
		if (text[i] == other.text[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int String::IndexOf(char ch)
{
	for (int i = 0; i < lenght; i++)
	{
		if (text[i] == ch)
		{
			return i;
		}
	}
	return -1;
}

int String::LastIndexOf(char ch)
{
	for (int i = lenght-1; i >=0; i--)
	{
		if (text[i] == ch)
		{
			return i;
		}
	}
	return -1;
}

void String::Remove(int index)
{
	char* temp = new char[capacity];
	for (int i = 0; i < index; i++)
	{
		temp[i] = text[i];
	}
	temp[index] = '\0';
	delete[] text;
	text = temp;
	lenght = strlen(text);
}

void String::Remove(int start, int count)
{
	char* temp = new char[capacity];
	for (int i = 0; i < start; i++)
	{
		temp[i] = this->text[i];
	}
	int j = start;
	for (int i = start+count; i < this->lenght; i++)
	{
		temp[j] = this->text[i];
		j++;
	}
	temp[lenght - count] = '\0';
	delete[] this->text;
	this->text = temp;
	this->lenght -= count;
}

void String::Replace(char R, char Z)
{
	char* temp = new char[capacity];
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->text[i] == R)
		{
			temp[i] = Z;
		}
		else
		{
			temp[i] = this->text[i];
		}
	}
	temp[lenght] = '\0';
	delete[] this->text;
	this->text = temp;
}

String& String::ToLower()
{
	char* temp = new char[capacity];
	for (int i = 0; i < this->lenght; i++)
	{
		temp[i] = tolower(this->text[i]);
	}
	temp[lenght] = '\0';
	delete[] this->text;
	this->text = temp;
	return *this;
}

String& String::ToUpper()
{
	char* temp = new char[capacity];
	for (int i = 0; i < this->lenght; i++)
	{
		temp[i] = toupper(this->text[i]);
	}
	temp[lenght] = '\0';
	delete[] this->text;
	this->text = temp;
	return *this;
}

void String::Trim()
{
	char* temp = new char[capacity];
	int j = 0;
	int count = 0;
	for (int i = 0; i < lenght; i++)
	{
		if (text[i] == ' ')
		{
			count++;
			continue;
		}
		else
		{
			temp[j] = this->text[i];
			j++;
		}
	}
	temp[lenght - count] = '\0';
	delete[] this->text;
	this->text = temp;
	lenght -= count;
}

void String::Reverse()
{
	char* temp = new char[capacity];
	for (int i = 0; i < lenght; i++)
	{
		temp[i] = this->text[lenght - 1 - i];
	}
	temp[lenght] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::SortAZ()
{
	char* temp = new char[capacity];
	for (int i = 0; i < lenght; i++)
	{
		temp[i] = this->text[i];
	}
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < lenght-1; j++)
		{
			if (temp[j] > temp[j + 1])
			{
				char t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
		}
	}
	temp[lenght] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::SortZA()
{
	char* temp = new char[capacity];
	for (int i = 0; i < lenght; i++)
	{
		temp[i] = this->text[i];
	}
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < lenght - 1; j++)
		{
			if (temp[j] < temp[j + 1])
			{
				char t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
		}
	}
	temp[lenght] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::Shuffle()
{
	char* temp = new char[capacity];
	for (int i = 0; i < lenght; i++)
	{
		temp[i] = this->text[i];
	}
	temp[lenght] = '\0';
	for (int i = 0; i < lenght; i++)
	{
		int j = rand() % lenght;
		if (i != j)
		{
			char t = temp[i];
			temp[i] = temp[j];
			temp[j] = t;
		}
	}
	delete[] this->text;
	this->text = temp;
}

void String::RandomFill()
{
	char* temp = new char[capacity];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = (char)rand() % 100 + 1;
	}
	this->lenght = capacity;
	delete[] this->text;
	this->text = temp;
}

String& String:: operator=(const String& other)
{
	this->lenght = other.lenght;
	if (this->text != nullptr)
	{
		delete[] this->text;
	}
	this->text = new char[capacity];
	strcpy_s(this->text, lenght + 1, other.text);
	this->text[lenght] = '\0';
	return *this;
}

bool String:: operator ==(const String& other)
{
	if (this->lenght == other.lenght)
	{
		for (int i = 0; i < this->lenght; i++)
		{
			if (this->text[i] == other.text[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool String:: operator !=(const String& other)
{
	if (this->lenght != other.lenght)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < this->lenght; i++)
		{
			if (this->text[i] != other.text[i])
			{
				return true;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
}


bool String::operator <(const String& other)
{
	return strcmp(this->text, other.text) < 0;
}



bool String::operator>(const String& other)
{
	return strcmp(this->text, other.text) > 0;
}

bool String::operator<= (const String& other)
{
	return strcmp(this->text, other.text) <= 0;
}

bool String::operator>=(const String& other)
{
	return strcmp(this->text, other.text) >= 0;
}

String& String:: operator() (const char* text)
{
	delete[] this->text;
	this->text = new char[capacity];
	this->lenght = strlen(text);
	strcpy_s(this->text, this->lenght + 1, text);
	this->text[lenght] = '\0';
	return *this;
}

char String:: operator [] (int index)
{
	for (int i = 0; i < capacity; i++)
	{
		if (i == index)
		{
			return this->text[i];
		}
	}
}

String& String::operator + (const String& other)
{
	char* temp = new char[capacity];
	for (int i = 0; i < this->lenght; i++)
	{
		temp[i] = this->text[i];
	}
	temp[this->lenght] = '\0';
	delete[] this->text;
	this->text = new char[capacity * 2];
	int temp_lenght = strlen(temp);
	for (int i = 0; i < temp_lenght; i++)
	{
		this->text[i] = temp[i];
	}
	
	for (int i = temp_lenght; i < temp_lenght+other.lenght; i++)
	{
		this->text[i] = other.text[i-temp_lenght];
	}
	this->text[temp_lenght + other.lenght] = '\0';
	this->lenght += other.lenght;
	this->capacity *= 2;
	return *this;
}

String& String::operator += (const String& other)
{
	char* temp = new char[capacity];
	for (int i = 0; i < this->lenght; i++)
	{
		temp[i] = this->text[i];
	}
	temp[this->lenght] = '\0';
	delete[] this->text;
	this->text = new char[capacity * 2];
	int temp_lenght = strlen(temp);
	for (int i = 0; i < temp_lenght; i++)
	{
		this->text[i] = temp[i];
	}

	for (int i = temp_lenght; i < temp_lenght + other.lenght; i++)
	{
		this->text[i] = other.text[i - temp_lenght];
	}
	this->text[temp_lenght + other.lenght] = '\0';
	this->lenght += other.lenght;
	this->capacity *= 2;
	return *this;
}

String& String::operator += (const char* text)
{
	char* temp = new char[capacity];
	for (int i = 0; i < this->lenght; i++)
	{
		temp[i] = this->text[i];
	}
	temp[this->lenght] = '\0';
	delete[] this->text;
	this->text = new char[capacity * 2];
	int temp_lenght = strlen(temp);
	for (int i = 0; i < temp_lenght; i++)
	{
		this->text[i] = temp[i];
	}
	int text_lenght = strlen(text);
	for (int i = temp_lenght; i < temp_lenght + text_lenght; i++)
	{
		this->text[i] = text[i - temp_lenght];
	}
	this->text[temp_lenght + text_lenght] = '\0';
	this->lenght += text_lenght;
	this->capacity *= 2;
	return *this;
}

String& String::operator + (const char* text)
{
	char* temp = new char[capacity];
	for (int i = 0; i < this->lenght; i++)
	{
		temp[i] = this->text[i];
	}
	temp[this->lenght] = '\0';
	delete[] this->text;
	this->text = new char[capacity * 2];
	int temp_lenght = strlen(temp);
	for (int i = 0; i < temp_lenght; i++)
	{
		this->text[i] = temp[i];
	}
	int text_lenght = strlen(text);
	for (int i = temp_lenght; i < temp_lenght + text_lenght; i++)
	{
		this->text[i] = text[i - temp_lenght];
	}
	this->text[temp_lenght + text_lenght] = '\0';
	this->lenght += text_lenght;
	this->capacity *= 2;
	return *this;
}





//bool String::operator< (const String& other)
//{
//	for (int i = 0; i < (this->lenght < other.lenght ? this->lenght : other.lenght); i++)
//	{
//		if (this->text[i] == other.text[i])
//		{
//			
//			continue;
//		}
//		else if (this->text[i] < other.text[i])
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	if (this->lenght < other.lenght)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
