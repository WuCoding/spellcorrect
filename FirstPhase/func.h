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
};

int minThreenum(int,int,int);//求三个数中的最小值
int minLevenshtein(string,string);//求两个字符串的最小编辑路径
//读入字典文件和索引文件
void loadDictionaryIndex(int,char**,vector<pair<string,int>>&,unordered_map<string,set<int>>&);
#endif
