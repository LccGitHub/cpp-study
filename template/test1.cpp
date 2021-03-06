
#include<iostream>
#include<vector>

using namespace std;

class CompanyBase
{
	public:
		CompanyBase() 
		{
		}
		virtual ~CompanyBase()
		{
		}

		virtual void SendClear(const string& msg) const = 0;
		virtual void SendEncrypted(const string& msg) const = 0;
};

class CompanyA: public CompanyBase
{
	public:
		virtual void SendClear(const string& msg)const
		{
			cout<<"A send clear "<<msg<<endl;
		}
		virtual void SendEncrypted(const string& msg)const
		{
			cout<<"A send encrypted "<<msg<<endl;
		}
};

class CompanyB: public CompanyBase
{
	public:
		virtual void SendClear(const string& msg)const
		{
			cout<<"B send clear "<<msg<<endl;
		}
		virtual void SendEncrypted(const string& msg)const
		{
			cout<<"B send encrypted "<<msg<<endl;
		}
};



template <typename T>
class MsgSender
{
	public:
		void sendClear(const string& msg)
		{
			T c;
			cout<<"this addr= "<<this<<endl;
			c.SendClear(msg);
		}
		void sendEncrypted(const string& msg)
		{
			T c;
			c.SendEncrypted(msg);
		}
};

template <typename T>
class LoggingMsgSender:public MsgSender<T>
{
	public:
		using MsgSender<T>::sendClear;
		using MsgSender<T>::sendEncrypted;
		void sendClearWithLog(const string& msg)
		{
			cout<<" derived this addr= "<<this<<endl;;
			cout<<"logging clear start \n";
			sendClear(msg);
			cout<<"logging clear end \n";
		}

		void sendEncryptedWithLog(const string& msg)
		{
			cout<<"logging Encrypted start \n";
			sendEncrypted(msg);
			cout<<"logging Encrypted end \n";
		}

};


int main()
{
	LoggingMsgSender<CompanyA> log;
	log.sendClearWithLog("hello");
	log.sendEncryptedWithLog("hello");

	LoggingMsgSender<CompanyB> logB;
	logB.sendClearWithLog("hello");
	logB.sendEncryptedWithLog("hello");
	
	return 0;
}
