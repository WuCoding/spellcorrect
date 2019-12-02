#include "func.h"

//将string写入到文件
void writeDiscCache(string cacheJson,string discFile){
	fstream outDiscFile;
	outDiscFile.open(discFile,ios::out);
	FSTREAM_CHECK(outDiscFile);

	outDiscFile<<cacheJson;
	outDiscFile.close();
}
//将文件中的数据全部读取到string中
string readJsonFile(string discFile){
	stringstream resStream;
	
	fstream inDiscFile;
	inDiscFile.open(discFile,ios::in);
	FSTREAM_CHECK(inDiscFile);

	string line;
	while(getline(inDiscFile,line)){
		resStream<<line<<endl;
	}
	return resStream.str();
}
//将文件Cache的json字符串放入内存Cache中
void createMemoryCache(string json,QueueMap* pQuemap){
	Json::Value root;
	Json::Reader reader;
	if(!reader.parse(json,root)){
		cout<<"parse discCache failed"<<endl;
		return;
	}else{
		
