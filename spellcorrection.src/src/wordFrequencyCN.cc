#include "../inc/func.h"
const set<string> CNChar{ "·" , "！" , "￥" , "……" , "（" , "）" , "——" , "【" , "】" , 
	"、" , " ；" , "：" , "’" , "‘" , "“" , "”" , "，" , "。" , "《" , "》" , "？"};
int cutWord(string,vector<string>&);
void test5(){
	for(auto i:CNChar){
		cout<<i<<endl;
	}
}
string stringCN(string str){
	str.erase(
		remove_if(str.begin(),str.end(),static_cast<int(*)(int)>(&ispunct)),
		str.end()
	);
	str.erase(
		remove_if(str.begin(),str.end(),static_cast<int(*)(int)>(&isspace)),
		str.end()
	);
	const set<string> CNChar{ "·" , "！" , "￥" , "……" , "（" , "）" , "——" , "【" , "】" , 
	"、" , " ；" , "：" , "’" , "‘" , "“" , "”" , "，" , "。" , "《" , "》" , "？"};
	size_t spa;
	vector<string> words;
	for(size_t i=0;i<str.size();){
		spa=nBytesCode(str[i]);
		if(spa==1){
			++i;
			continue;
		}
		string strTmp;//单个字符
		for(size_t j=0;j<spa;++j){
			strTmp+=str[i+j];
		}
		i=i+spa;
		if(CNChar.find(strTmp)==CNChar.end()){
			words.push_back(strTmp);
		}
	}
	string res;
	for(auto i:words){
		res+=i;
	}
	return res;
}
void test3(){
	string s;
	while(1){
		cin>>s;
		cout<<stringCN(s)<<endl;
	}
}

void printLine(string corpusFile){
	fstream in;
	in.open(corpusFile,ios::in);
	FSTREAM_CHECK(in);

	string line;
	string str;
	while(1){
		cin>>str;
		cin>>line;
		cout<<"--------------------------------------------"<<endl;
		//getline(in,line);	
		cout<<line<<endl;


		vector<string> word;
		getCharFromString(line,word);
		for(auto i:word){
			cout<<i<<endl;
		}
	/*
		vector<string> words;
		cutWord(line,words);
		for(auto i:words){
			cout<<i<<endl;
		}
	*/
		cout<<line<<endl;
		cout<<"--------------------------------------------"<<endl;
	}

	in.close();
}

void test(){
	const string corpusFile="../data/art/C3-Art0002.txt";
	printLine(corpusFile);
}
void test1(){
	string str;
	while(1){
		cin>>str;
		vector<string> words;
		cutWord(str,words);
		for(auto i:words){
			cout<<i<<endl;
		}
	}
}

int main(){
	test3();
}
