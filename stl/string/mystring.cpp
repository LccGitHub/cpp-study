#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;

//template<typename T>
class mystring
{
	public:
		mystring()
		{
			length = 0;
			data = new char[1];
			*data = '\0';
		}
		mystring(char * str)
		{
			if (str == NULL){
				length = 0;
				data = new char[1];
				*data = '\0';
			}
			else {
				length = strlen(str);
				data = new char[length + 1];
				strcpy(data, str);
			}
		}
		mystring(const mystring& str)
		{
			length = str.size();
			data = new char[length + 1];
			strcpy(data, str.c_str());
		}
		~mystring()
		{
			delete []data;
			length = 0;
		}
		mystring operator+(const mystring& str)
		{
			mystring newstr;
			newstr.length = length + str.size();
			newstr.data = new char[newstr.length + 1];
			strcpy(newstr.data, data);
			strcat(newstr.data, data);
			return newstr;
		}
		mystring& operator=(const mystring& str)
		{
			if (this == &str) {
				return *this;
			}

			char* tmp = data;
			data = new char[str.length + 1];
			delete []tmp;
			length = str.length;
			strcpy(data, str.c_str());

			return *this;

		}
		mystring& operator+=(const mystring& str)
		{
			length += str.length;
			char *newData = new char[length + 1];
			strcpy(newData, data);
			strcat(newData, str.data);
			delete []data;
			data = newData;

			return *this;
		}

		inline bool operator==(const mystring& str)
		{
			if (length != str.length)
				return false;
			return strcmp(data, str.data) ? false:true;
		}

		inline char& operator[](int n)
		{
			if (n >= length)
				return data[length - 1];
			else 
				return data[n];
		}

		inline size_t size() const
		{
			return length;
		}

		friend istream& operator>>(istream &is, mystring& str)
		{
			char tem[1024];
			is>>tem;
			str.length = strlen(tem);
			str.data = new char[str.length + 1];
			strcpy(str.data, tem);

			return is;
		}

		friend ostream& operator<<(ostream& os, mystring& str)
		{
			os << str.data;
			return os;
		}

		inline const char* c_str() const
		{
			return data;
		}


	private:
		char* data;
		int length;
};


int main()
{
	mystring s;
	cin>>s;
	cout<<s<<":"<<s.size()<<endl;

	char a[] = "hello", b[] = "world!";
	mystring s1(a);
	mystring s2(b);
	cout<<s1<<"+"<<s2<<"=";

	mystring s3 = s1+ s2;
	cout<<s3<<endl;
	if (s1 == s3) {
		cout<<"First s1==s3"<<endl;
	}
	s1 += s2;

	if (s1 == s3) {
		cout<<"Second s1==s3"<<endl;
	}
	return 0;
}

