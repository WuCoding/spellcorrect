#include "../inc/func.h"
//构造json字符串
//传入：查询词 候选词栈
//传出：json字符串
string createJson(string word,stack<QueueNode> &staQueueNode){
	Json::Value req;
	req["Word"]=word;

	Json::Value result;

	while(!staQueueNode.empty()){
		Json::Value candidateWord;
		candidateWord["candidateWord"]=staQueueNode.top().getWord();
		candidateWord["frequency"]=staQueueNode.top().getFrequency();
		candidateWord["differentDegree"]=staQueueNode.top().getDifferentDegree();
		result.append(candidateWord);
		staQueueNode.pop();
	}
	req["result"]=result;

	Json::FastWriter fwriter;
	string fjsonstr=fwriter.write(req);
	return fjsonstr;
}
//解析json字符串
void parseJson(string json){
	Json::Value root;
	Json::Reader reader;
	if(!reader.parse(json,root)){//解析失败
		cout<<"parse fail"<<endl;
	}else{//解析成功
		Json::StyledWriter swriter;
		string sjsonstr=swriter.write(root);
		cout<<sjsonstr<<endl;
	}
}
#if 0
int main(){
	stack<queueNode> staQue;
	string str;
	cin>>str;
	const string dictionaryFile="../data/dictionary.txt";
	const string indexFile="../data/index.txt";


	getCandidateWords(dictionaryFile,indexFile,str,staQue,5);
	string json=createJson(str,staQue);
	Json::Value discCache;
	Json::Value object;
	object["key"]=str;
	object["json"]=json;
	discCache.append(object);
	Json::StyledWriter swriter;
	string cache=swriter.write(discCache);
	string discFile="../data/discCache.json";
	writeDiscCache(cache,discFile);
}
#endif
