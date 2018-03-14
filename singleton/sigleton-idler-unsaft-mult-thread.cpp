#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void* thread_func(void* arg);


class Singleton
{
	private:
		Singleton()
		{

		}

	public:
		static Singleton* instance(int a);

		int getvaule()
		{
			return test;
		}

		static void setvaule(int a)
		{
			test = a;
		}
	private:
		static Singleton* p;
		static int test;
};
Singleton* Singleton::p = NULL;
int Singleton::test = 0;

Singleton* Singleton::instance(int a)
{
	if (p == NULL)
	{
		cout<<"NULL!!!"<<endl;
		sleep(5);/*for test multi thread unsafe, mybe creat multi object */
		p = new Singleton();
		setvaule(a);
	}
	return p;
}


void* thread_func(void* arg)
{
	int res = -1, res1 = -1;
	Singleton* p = NULL;
	p = Singleton::instance(1);
	res = p->getvaule();
	cout<<"result ="<<res<<endl;
	cout<<"p ="<<p<<endl;
	return NULL;
}

void* thread1_func(void* arg)
{
	int res = -1, res1 = -1;
	Singleton* p = NULL;
	p = Singleton::instance(2);
	res = p->getvaule();
	cout<<"result1 ="<<res<<endl;
	cout<<"p ="<<p<<endl;
	return NULL;
}

int main()
{
	pthread_t thr1, thr2;
	pthread_create(&thr1, NULL, thread_func, NULL);
	pthread_create(&thr2, NULL, thread1_func, NULL);

	while(1)
	{
	}
	return 0;
}

