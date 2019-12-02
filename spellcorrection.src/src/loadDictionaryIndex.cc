#include "../inc/func.h"

//导入字典文件和索引文件
//传入:-------------------------------------------->
//字典文件名 string dictionaryFile
//索引文件名 string indexFile
//传出:-------------------------------------------->
//字典 vector<pair<string,int>> dictionary
//索引 unordered_map<string,set<int>> index
void loadDictionaryIndex(string dictionaryFile,string indexFile,vector<pair<string,int>> &dictionary,unordered_map<string,set<int>> &index)
{
	fstream inDictionary;
	inDictionary.open(dictionaryFile,ios::in);
	FSTREAM_CHECK(inDictionary);

	fstream inIndex;
	inIndex.open(indexFile,ios::in);
	FSTREAM_CHECK(inIndex);

	string word;
	int frequency;
	while(inDictionary>>word){
		inDictionary>>frequency;
		pair<string,int> pairWord(word,frequency);
		dictionary.push_back(pairWord);
	}

	string line;
	string indexChar;
	int indexInt;
	while(getline(inIndex,line)){
		istringstream lineStream(line);//字符串流
		lineStream>>indexChar;//索引字符
		//索引位置
		while(lineStream>>indexInt){
			index[indexChar].insert(indexInt);
		}
	}

	inDictionary.close();
	inIndex.close();
}
