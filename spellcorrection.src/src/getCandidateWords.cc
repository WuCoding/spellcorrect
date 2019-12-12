#include "../inc/func.h"

//用set来存储要查询单词所含的字母
//传入:-------------------------------------------------->
//目标单词 string str
//输出:-------------------------------------------------->
//该单词所包含的所有字母(不含重复的) set<string> setStr
void getIndexChar(set<string> &setStr,string str){
	for(string::size_type i=0;i<str.size();++i){//将字母放入set容器中
		string result;
		result=str[i];
		setStr.insert(result);
	}
}

//用set来存储与要查询单词含相同字母的候选单词
//传入:------------------------------------------------->
//包含所有字母 set<string> setStr
//索引 unordered_map<string,set<int>> index
//输出:------------------------------------------------->
//候选词的下标 set<int> setInt
void getIndexWord(set<int> &setInt,set<string> &setStr,unordered_map<string,set<int>> &index){
	for(auto v:setStr){//遍历该单词所含的字母
		setInt.insert(index[v].begin(),index[v].end());
	}
}

//用优先级队列来获得关联度最高的前n个单词
//传入:------------------------------------------------->
//包含所有候选词的下标 set<int> setInt
//目标单词 string str
//词典 vector<pair<string,int>> dictionary
//队列长度 int queLen
//输出:------------------------------------------------->
//优先级队列 priority_queue<QueueNode> priQue
void getPriorityQueue(
		set<int> &setInt,string str,
		vector<pair<string,int>> &dictionary,
		priority_queue<QueueNode> &priQue,
		int queLen){
	for(set<int>::iterator it=setInt.begin();
			it!=setInt.end();
			it++){//遍历候选词
		//创建队列节点
		QueueNode newNode(dictionary[*it].first,dictionary[*it].second);
		newNode.setDifferentDegree(minLevenshtein(newNode.getWord(),str));
		//插入队列中
		priQue.push(newNode);
		//检查队列长度
		if(priQue.size()>queLen){
			priQue.pop();
		}
	}
}

//读取dictionary.txt index.txt
//void loadDictonaryIndex(string dictionaryFile,string indexFile,
//	vector<pair<string,int>> &dictionary,
//	unordered_map<string,set<int>> &index);

//输入:---------------------------------------------------------------->
//字典文件，索引文件，查询词，队列长度
//输出:---------------------------------------------------------------->
//
void getCandidateWords(string dictionaryFile,string indexFile,string word,
		stack<QueueNode> &staQue,int queLen)
{
	//载入字典和索引
	vector<pair<string,int>> dictionary;
	unordered_map<string,set<int>> index;
	loadDictionaryIndex(dictionaryFile,indexFile,dictionary,index);

	set<string> setStr;//存储单词中的字母
	getIndexChar(setStr,word);

	set<int> setInt;//存储相同字母的单词
	getIndexWord(setInt,setStr,index);

	priority_queue<QueueNode> priQue;//获取优先级队列
	getPriorityQueue(setInt,word,dictionary,priQue,queLen);

	while(!priQue.empty()){
		staQue.push(priQue.top());
		priQue.pop();
	}
}
//构造json字符串
//传入：查询词 候选词栈
//传出：json字符串
string createJson(string word,stack<QueueNode> &staQue){
	Json::Value req;
	req["Word"]=word;

	Json::Value result;

	while(!staQue.empty()){
		Json::Value candidateWord;
		candidateWord["candidateWord"]=staQue.top().getWord();
		candidateWord["frequency"]=staQue.top().getFrequency();
		candidateWord["differentDegree"]=staQue.top().getDifferentDegree();
		result.append(candidateWord);
		staQue.pop();
	}
	req["result"]=result;

	Json::FastWriter fwriter;
	return fwriter.write(req);
}

int main(){
	const string dictionaryFile="../data/dictionary.txt";
	const string indexFile="../data/index.txt";

	int queLen=5;
	string word;
	while(1){
		cin>>word;
		stack<QueueNode> staQue;
		getCandidateWords(dictionaryFile,indexFile,word,staQue,queLen);
		cout<<createJson(word,staQue)<<endl;
	}
}
