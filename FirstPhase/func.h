#ifndef __FUNC_H__
#define __FUNC_H__
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <json/json.h>
#include <stack>

#include "stdio.h"

#define ARGS_CHECK(argc,num) {if(argc!=num){printf("error args\n");return -1;}}
#define FSTREAM_CHECK(fstream) {if(!fstream.is_open()){printf("error fstream\n");}}

using std::fstream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::unordered_map;
using std::pair;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;
using std::istringstream;
using std::stack;
/*
void checkArgs(int argc,int num){
	if(argc!=num){
		cout<<"参数不匹配！"<<endl;
	}
}
void checkFstream(fstream &tmp){
	if(!tmp.is_open()){
		cout<<"读取文件失败！"<<endl;
	}
}
*/
struct queueNode{
	queueNode()
	{};
	queueNode(string str,int fre)
	{
		word=str;
		frequency=fre;
	};
	string word;//候选词
	int frequency;//词频
	int differentDegree;//与目标单词的差别度
	// < 运算符重载
	bool operator <(const queueNode &a) const{//true放后面,false放前面
		//先看差别度
		if(differentDegree<a.differentDegree){
			return true;
		}else if(differentDegree>a.differentDegree){
			return false;
		}else{//差别度相等，看词频
			if(frequency>a.frequency){
				return true;
			}else if(frequency<a.frequency){
				return false;
			}else{//差别度，词频都相同
				if(word<a.word){
					return true;
				}else{
					return false;
				}
			}
		}
	}
	//赋值运算符重载
	queueNode& operator =(const queueNode &a){
		this->word=a.word;
		this->frequency=a.frequency;
		this->differentDegree=a.differentDegree;
		return *this;
	}
};
//输入语料，输出字典
void wordFrequency(string corpusFile,string dictionaryFile);
///输入字典文件，输出索引文件
void createIndex(string dictionaryFile,string indexFile);
//读入字典文件和索引文件
void loadDictionaryIndex(string dictionaryFile,string indexFile,vector<pair<string,int>> &dictionary,unordered_map<string,set<int>> &index);
//输入3个数，返回最小值
int minThreenum(int num1,int num2,int num3);
//输入两个字符串，返回两字符串的最小编辑距离
int minLevenshtein(string str1,string str2);
//用set来存储要查询单词所含的字母
void getIndexChar(set<string> &setStr,string str);
//用set来存储与要查询单词含相同字母的候选单词
void getIndexWord(set<int> &setInt,set<string> &setStr,unordered_map<string,set<int>> &index);
//用优先级队列来获得关联度最高的前n个单词
void getPriorityQueue(
		set<int> &setInt,string str,
		vector<pair<string,int>> &dictionary,
		priority_queue<queueNode> &priQue,
		int queLen);
//输入文件，要查询的单词，队列长度，输出队列
void getCandidateWords(string dictionaryFile,string indexFile,string word,
		stack<queueNode> &staQue,int queLen);
#endif
