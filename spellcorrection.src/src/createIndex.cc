#include "func.h"
//通过输入的
//vector<pair<string,int>> dictionary
//<单词,词频> 词典 来创建
//unordered_map<string,set<int>> index
//<字母,<含该字母的单词下标>> 索引
//输入的参数分别为：
//1.输入的词典文件
//2.输出的索引文件
void createIndex(string dictionaryFile,string indexFile)
{
	//打开输入文件
	fstream in;
	in.open(dictionaryFile,ios::in);
	FSTREAM_CHECK(in);
	//打开输出文件
	fstream out;
	out.open(indexFile,ios::out);
	FSTREAM_CHECK(out);

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

