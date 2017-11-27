## 枚举实例测试 (2017.11.27)
//1. 
#include <iostream>
using namespace std;

int main()
{
	enum days
	{
		one,two,three
	}day;
	day = one;
	switch (day)
	{
	case one:
		cout << "one" << endl;
		break;
	case two:
		cout << "two" << endl;
		break;
	default:
		cout << "three" << endl;
		break;
	}
	return 0;
}

//2. 枚举类型不一定要在 main 中定义
#include <iostream>
using namespace std;

enum time
{
	first,second,
	third,forth,fifth
};

int main()
{
	enum time a = fifth;
	if (a == fifth) {
		cout << "sucess!\n";
	}
	return 0;
}