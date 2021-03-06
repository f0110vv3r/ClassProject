#include "common/example_export.h"
#include <iostream>
#include <vector>
#include <ctime>

#define m4x 100
#define ture true
using namespace std;

namespace examples {
namespace dcps {
namespace ContentFilteredTopic {
namespace isocpp  {
    OS_EXAMPLE_IMPL_EXPORT int publisher(int argc, char *argv[]);
    OS_EXAMPLE_IMPL_EXPORT int subscriber(int argc, char *argv[]);
	OS_EXAMPLE_IMPL_EXPORT int Market();
	OS_EXAMPLE_IMPL_EXPORT int Event();
	OS_EXAMPLE_IMPL_EXPORT int Client();
	OS_EXAMPLE_IMPL_EXPORT int Midware();




	class Stock
	{
	public:
		string stockID, name, details;
		float pricee;
	public:
		float getPrice();
		float setPrice(float change);//参数为涨跌幅，返回涨跌之后的值。	
		float increase(float range);
	};
	class Having
	{//持有的股票
	public:
		string stockName;
		int number;
		Having();
	};
	class User
	{
	public:
		string name;
		string password;
		float cash;//余额
		Having hold[m4x];//给你一百个够了吧
		string care[m4x];//都只存股票名称
		int holdNum, careNum;
	public:
		string checkLogin(string userName, string password);
		User(string path);//从path路径的文件中读取用户信息，生成对象。
		User() {};
		void saveUser(string path);//将对象**按格式写入到path文件中**
		void buy(string stockname, int num);
		void sell(string stockname, int num);
		void sendMsg(string username, string stockname, int num,int tYpe);
		//bool addCare(string stockID);
	};
	class Exchange
	{//单例交易所
	public:
		vector <Stock> stocks;//
		int cont;//收纳股种数量
	//private:
		Exchange();
		//Exchange* singleInstance;//急切创建单例
	public:
		//Exchange* getInstance();//使用单例模式
		//string toBuy(int userID, string stockID, int num);
		//string toSell(int userID, string stoclID, int num);
		void importStock(string filename);//获取全部股票的信息。
		//void importStocks();//将存储中的股票信息导入程序中，在程序开始执行时启动
		void adjustStocks();//调整股价
		void saveStocks();//闭市时将股票信息保存在数据库中

	};
	//Exchange* Exchange::singleInstance = new Exchange();//直接急切创建单例
}
}
}
}
