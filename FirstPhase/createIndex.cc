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

	string word;
	int frequency;
	pair<string,int> pairElement;
	vector<pair<string,int>> dictionary;
	//读取输入文件
	while(in>>word){
		in>>frequency;
		pairElement.first=word;
		pairElement.second=frequency;
		dictionary.push_back(pairElement);
	}
	
	//创建索引
	unordered_map<string,set<int>> index;
	//遍历字典中的每一个单词
	string letter;
	for(vector<pair<string,int>>::size_type i=0;i<dictionary.size();++i){
		//遍历单词中的每个字母
		for(string::size_type j=0;j<dictionary[i].first.size();++j){
			letter=(dictionary[i].first)[j];
			index[letter].insert(i);
		}
	}

	//输出索引
	for(auto pairElem:index){
		out<<pairElem.first<<" ";//输出字母
		for(auto intElem:pairElem.second){
			out<<intElem<<" ";
		}
		out<<endl;
	}
	in.close();
	out.close();
}




