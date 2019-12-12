#include "../inc/func.h"

string cleanCNString(string str){
	str.erase(
		remove_if(str.begin(),str.end(),static_cast<int(*)(int)>(&ispunct)),
		str.end()
	);
	str.erase(
		remove_if(str.begin(),str.end(),static_cast<int(*)(int)>(&isspace)),
		str.end()
	);
	const set<string> CNChar{ "·" , "！" , "￥" , "……" , "（" , "）" , "——" , "-" , "—" , "【" , "】" , 
	"、" , "；" , "：" , "’" , "‘" , "“" , "”" , "，" , "。" , "《" , "》" , "？" , "_" };
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


void wordFrequencyCN(string corpusFile,string dictionaryFile){
	fstream in;
	in.open(corpusFile,ios::in);
	FSTREAM_CHECK(in);

	fstream out;
	out.open(dictionaryFile,ios::out);
	FSTREAM_CHECK(out);

	map<string,int> dictionary;
	string line;
	string cleanLine;
	while(getline(in,line)){
		cleanLine=cleanCNString(line);

		vector<string> words;
		cutStringWithJieba(cleanLine,words);
		for(auto i:words){
			++dictionary[i];
		}
	}
	for(auto x:dictionary){
		out<<x.first<<" "<<x.second<<endl;
	}
	in.close();
	out.close();
}

int main(){
	const string corpusFile="../data/art/C3-Art0002.txt";
	const string dictionaryFile="../data/dictionaryCN.txt";
	wordFrequencyCN(corpusFile,dictionaryFile);
}
