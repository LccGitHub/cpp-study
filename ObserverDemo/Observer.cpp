#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class Observer {
	public:
	virtual void update() = 0;
};


class Subject {
	private:
		vector<Observer*> observers;
	public:
		void attach(Observer* observer)
		{
			observers.push_back(observer);
		}

		void notifyAllObservers()
		{
			for(vector<Observer*>::iterator  observer = observers.begin(); observer != observers.end(); observer++)
			{
				(*observer)->update();
			}
		}
};

class Client1 :public Observer {
	public:
		Client1(Subject* subject)
		{
			subject->attach(this);
		}

		void update()
		{
			printf("Client1 update \n");
		}
};


class Client2 :public Observer {
	public:
		Client2(Subject* subject)
		{
			subject->attach(this);
		}

		void update()
		{
			printf("Client1 update \n");
		}
};



int main()
{
	Subject* subject = new Subject();
	Client1* client1 = new Client1(subject); 
	Client2* client2 = new Client2(subject); 

	subject->notifyAllObservers();
}
