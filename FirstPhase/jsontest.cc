#include "func.h"

void createJSON()
{
	Json::Value req;
	req["Result"] = 1;
	req["ResultMessage"] = "200";
	
	Json::Value object1;
	object1["cpuRatio"] = "4.04";
	object1["serverIp"] = "42.159.116.104";
	object1["conNum"] = "1";
	object1["websocketPort"] = "0";
	object1["mqttPort"] = "8883";
	object1["TS"] = "1504665880572";
	
	Json::Value object2;
	object2["cpuRatio"] = "2.04";
	object2["serverIp"] = "42.159.122.251";
	object2["conNum"] = "2";
	object2["websocketPort"] = "0";
	object2["mqttPort"] = "8883";
	object2["TS"] = "1504665896981";
	Json::Value jarray;
	jarray.append(object1);
	jarray.append(object2);
	
	req["ResultValue"] = jarray;
	Json::FastWriter fwriter;
	string fjsonstr = fwriter.write(req);
	printf("%s\n", fjsonstr.c_str());

	Json::StyledWriter swriter;
	string sjsonstr=swriter.write(req);
	printf("%s\n",sjsonstr.c_str());

	fstream out;
	out.open("result.json",ios::out);
	out<<fjsonstr<<fjsonstr<<sjsonstr;
	out.close();
}
void test()
{
	fstream in;
	in.open("result.json",ios::in);
	string str;
	while(in>>str){
		cout<<str<<endl<<"------------------------------------"<<endl;
	}
	in.close();
}
void test1(){
	fstream in;
	in.open("result.json",ios::in);
	string str;
	while(in>>str){
		Json::Value root;
		Json::Reader reader;
		if(!reader.parse(str,root)){
			cout<<"parse fail"<<endl;
		}else{
			cout<<root["Result"];
			cout<<root["ResultValue"].size()<<endl;
		}
	}
	in.close();
}

int main()
{
	createJSON();
	test();
	//test1();
}
