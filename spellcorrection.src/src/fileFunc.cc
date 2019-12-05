#include "../inc/func.h"

//将string写入到文件
void writeInFile(string json,string file){
	fstream out;
	out.open(file,ios::out);
	FSTREAM_CHECK(out);

	out<<json;
	out.close();
}
//将文件中的数据全部读取到string中
string readFromFile(string file){
	stringstream strStream;
	
	fstream in;
	in.open(file,ios::in);
	FSTREAM_CHECK(in);

	string line;
	while(getline(in,line)){
		strStream<<line<<endl;
	}
	return strStream.str();
}
