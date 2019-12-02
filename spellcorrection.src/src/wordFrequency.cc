#include "../inc/func.h"

//输入语料文件，输出字典文件
void wordFrequency(string corpusFile,string dictionaryFile)
{
	//打开输入文件
	fstream in;
	in.open(corpusFile,ios::in);
	FSTREAM_CHECK(in);
	//打开输出文件
	fstream out;
	out.open(dictionaryFile,ios::out);
	FSTREAM_CHECK(out);

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
