#include "func.h"

#if 1
//用set来存储要查询单词所含的字母
void getIndexChar(set<string> &setStr,string str){
	for(string::size_type i=0;i<str.size();++i){//将字母放入set容器中
		string result;
		result=str[i];
		setStr.insert(result);
	}
}
#endif

#if 1
//用set来存储与要查询单词含相同字母的候选单词
void getIndexWord(set<int> &setInt,set<string> &setStr,unordered_map<string,set<int>> &index){
	for(auto v:setStr){//遍历该单词所含的字母
		setInt.insert(index[v].begin(),index[v].end());
	}
}
#endif

#if 1
//用优先级队列来获得关联度最高的前n个单词
void getCandidateWord(
		set<int> &setInt,string str,
		vector<pair<string,int>> &dictionary,
		priority_queue<queueNode> &priQue,
		int queLen){
	for(set<int>::iterator it=setInt.begin();
			it!=setInt.end();
			it++){//遍历候选词
		//创建队列节点
		queueNode qNode(dictionary[*it].first,dictionary[*it].second);
		qNode.differentDegree=minLevenshtein(qNode.word,str);
		//插入队列中
		priQue.push(qNode);
		//检查队列长度
		if(priQue.size()>queLen){
			priQue.pop();
		}
	}
}
#endif

//读取dictionary.txt index.txt
//void loadDictonaryIndex(int,char**,vector<pair<string,int>>&,unordered_map<string,set<int>>&);
int main(int argc,char* argv[])
{
	vector<pair<string,int>> dictionary;
	unordered_map<string,set<int>> index;
	loadDictionaryIndex(argc,argv,dictionary,index);

	string word;
	cin>>word;
	cout<<word<<endl;
	
	set<string> setStr;//存储单词中的字母
	getIndexChar(setStr,word);
	for(auto v:setStr){
		cout<<v<<endl;
	}

	set<int> setInt;//存储相同字母的单词
	getIndexWord(setInt,setStr,index);
	cout<<"setInt.size()="<<setInt.size()<<endl;
	
	priority_queue<queueNode> priQue;//存储候选词的优先级队列
	getCandidateWord(setInt,word,dictionary,priQue,5);
	cout<<"priQue.size()="<<priQue.size()<<endl;
	for(int i=priQue.size();i>0;--i){
		cout<<priQue.top().word<<" "<<priQue.top().frequency<<
			" "<<priQue.top().differentDegree<<endl;
		priQue.pop();
	}

	
#if 0
	string word;//用户传入的单词
	while(cin>>word){
		set<string> setChar;//存储单词的字母
		getIndexChar(setChar,word);

		set<int> setInt;//存储有相同字母的候选词
		getIndexWord(setInt,setChar,index);

		priority_queue<queueNode> priQue;//用来存储候选词的优先级队列
		getCandidateWord(setInt,word,dictionary,priQue,5);

		for(int i=0;i<priQue.size();++i){
			cout<<priQue.top().word<<endl;
			priQue.pop();
		}
	}
#endif
}






	

