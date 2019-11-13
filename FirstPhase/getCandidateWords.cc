#include "func.h"

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
//优先级队列 priority_queue<queueNode> priQue
void getPriorityQueue(
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

//读取dictionary.txt index.txt
//void loadDictonaryIndex(string dictionaryFile,string indexFile,
//	vector<pair<string,int>> &dictionary,
//	unordered_map<string,set<int>> &index);
void getCandidateWords(string dictionaryFile,string indexFile,string word,
		priority_queue<queueNode> &priQue,
		int queLen)
{
	vector<pair<string,int>> dictionary;
	unordered_map<string,set<int>> index;
	loadDictionaryIndex(dictionaryFile,indexFile,dictionary,index);
	
	set<string> setStr;//存储单词中的字母
	getIndexChar(setStr,word);

	set<int> setInt;//存储相同字母的单词
	getIndexWord(setInt,setStr,index);
	
	getPriorityQueue(setInt,word,dictionary,priQue,queLen);
}

