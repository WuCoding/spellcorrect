#include "func.h"

int main(int argc,char* argv[])
{
	//检查输入参数个数
	checkArgs(argc,3);
	//打开输入文件
	fstream in;
	in.open(argv[1],ios::in);
	checkFstream(in);
	//打开输出文件
	fstream out;
	out.open(argv[2],ios::out);
	checkFstream(out);

	//创建词典<单词，词频>
	map<string,int> dictionary;
	string tmp;

	while(in>>tmp){
		string output;
		//去除标点符号和数字，同时将大写转为小写
		for(string::size_type i=0;i<tmp.size();++i){
			if(!ispunct(tmp[i])){
				if(tmp[i]>'9'){
					output+=tolower(tmp[i]);
				}
			}
		}
		if(output.size()==0){
			continue;
		}
		++dictionary[output];
	}
	for(auto x:dictionary){
		out<<x.first<<" "<<x.second<<endl;
	}
	in.close();
	out.close();
}
