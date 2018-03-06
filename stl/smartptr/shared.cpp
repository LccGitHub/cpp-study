#include<iostream>
#include<memory>
#include<vector>
#include<iostream>

using namespace std;

class Base
{
	public:
		Base(string name)
			:name(name)
		{
			cout<<name<<"create "<<endl;
		}
		~Base()
		{
			cout<<name<<"destroy "<<endl;
		}
		void print()
		{
			cout<<name<<" ";
		}
	private:
		string name;
};

int main()
{
#if 0
	shared_ptr<string> sp1(new string("xxxs"));
	shared_ptr<string> sp2(new string("ksksk"),
			[](string *p){
			cout<<"delete "<<*p<<endl;
			});

	sp1.reset(new string("yyy"));

	(*sp1)[0] = 'J';

	/*shared_ptr支持复制构造，所以他可以作为标准库容器中的元素, auto_ptr和unique_ptr不能实现的*/
	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(sp1);
	whoMadeCoffee.push_back(sp2);
	whoMadeCoffee.push_back(sp1);
	whoMadeCoffee.push_back(sp2);

	for (auto sp:whoMadeCoffee)
	{
		cout<<*sp<<" ";
	}
	cout<<endl;

	cout<<"use count "<< whoMadeCoffee[0].use_count()<<endl;

	*sp1 = "James";

	cout<<"use count "<<whoMadeCoffee[0].use_count()<<endl;

	shared_ptr<int> sp3(new int[10],
			[](int *p){delete[] p;});

	shared_ptr<int> sp4(new int[10],
			default_delete<int[]>());


#endif
	shared_ptr<Base> shared_b1(new Base("shared ptr"));
	shared_ptr<Base> shared_b2 = shared_b1; /*reference count will +1, only when reference count= 0, will call decontruct function*/
	shared_b1->print();
	
	auto_ptr<Base> auto_b1 = (auto_ptr<Base>)(new Base("auto ptr"));
	auto_ptr<Base> auto_b2 = auto_b1; /*b1 will changed null ptr*/
	auto_b1->print(); /*this will core dump*/

	unique_ptr<Base> unique_b1(new Base("unique ptr"));
	unique_ptr<Base> unique_b2 = unique_b1; /* compile error, <use of delete function>*/
	unique_b1->print();

	unique_ptr<double[]> auto_b1_array(new double(5)); /* unique_ptr相较auto_ptr和share_ptr，提供了可用于数组的变体*/
	
	return 0;
}

