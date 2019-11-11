#include "func.h"

void loadDictionaryIndex(int argc,char* argv[],vector<pair<string,int>> &dictionary,unordered_map<string,set<int>> &index)
{
	fstream inDictionary;
	inDictionary.open(argv[1],ios::in);
	FSTREAM_CHECK(inDictionary);
#if 1
	fstream inIndex;
	inIndex.open(argv[2],ios::in);
	FSTREAM_CHECK(inIndex);
#endif
	string word;
	int frequency;
	while(inDictionary>>word){
		inDictionary>>frequency;
		pair<string,int> pairWord(word,frequency);
		dictionary.push_back(pairWord);
	}
#if 1
	for(auto v:dictionary){
		cout<<v.first<<" "<<v.second<<endl;
	}
#endif

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
#if 1
	for(auto v:index){
		cout<<v.first<<endl;
	}
#endif
	inDictionary.close();
	inIndex.close();
}

