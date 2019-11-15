#include "func.h"

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

	Json::StyledWriter swriter;
	string sjsonstr=swriter.write(req);
	cout<<sjsonstr;

	return fjsonstr;
}

void parseJson(string json){
	Json::Value root;
	Json::Reader reader;
	if(!reader.parse(json,root)){//解析失败
		cout<<"parse fail"<<endl;
	}else{//解析成功

}
int main(int argc,char* argv[]){
	
	ARGS_CHECK(argc,3);
	
	stack<queueNode> staQue;
	string word;
	cin>>word;
	
	getCandidateWords(argv[1],argv[2],word,staQue,6);
	
	createJson(word,staQue);
}

