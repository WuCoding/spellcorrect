#include "func.h"
//构造json字符串
//传入：查询词 候选词栈
//传出：json字符串
string createJson(string word,stack<queueNode> &staQueueNode){
	Json::Value req;
	req["Word"]=word;

	Json::Value result;

	while(!staQueueNode.empty()){
		Json::Value candidateWord;
		candidateWord["candidateWord"]=staQueueNode.top().word;
		candidateWord["frequency"]=staQueueNode.top().frequency;
		candidateWord["differentDegree"]=staQueueNode.top().differentDegree;
		result.append(candidateWord);
		staQueueNode.pop();
	}
	req["result"]=result;

	Json::FastWriter fwriter;
	string fjsonstr=fwriter.write(req);
	cout<<fjsonstr;

	return fjsonstr;
}
#if 1
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
#endif
int main(int argc,char* argv[]){
	
	ARGS_CHECK(argc,3);
	
	stack<queueNode> staQue;
	string word;
	cin>>word;
	
	getCandidateWords(argv[1],argv[2],word,staQue,6);
	
	string json;
	json=createJson(word,staQue);
	cout<<json<<endl;

	parseJson(json);
}

