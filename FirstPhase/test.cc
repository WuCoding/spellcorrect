#include "func.h"
#if 0
void test(){
	unordered_map<string,set<int>> index;
	string s="wangdao";
	index[s].insert(5);
	for(auto v:index){
		cout<<v.first<<" ";
		for(auto m:v.second){
			cout<<m<<" ";
		}
	}
	cout<<endl;
}
#endif

#if 0
void test1(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<minLevenshtein(s1,s2)<<endl;
}
#endif

#if 0
void test2(){
	set<int> set1={1,2,3,4,5};
	set<int> set2={3,4,5,6,7};
	set<int> set3;
	set3.insert(set1.begin(),set1.end());
	set3.insert(set2.begin(),set2.end());
	for(auto v:set3){
		cout<<v<<" ";
	}
	cout<<endl;
}
#endif

#if 0
struct cmp1{
	bool operator()(int &a,int &b){
		return a>b;
	}
};

struct number{
	number(int i)
	{
		x=i;
	};
	int x;
	bool operator < (const number &a) const {
		return x>a.x;
	}
};
void test3(){
	priority_queue<number> q;
	number n1(1);
	number n2(4);
	number n3(2);
	q.push(n1);
	q.push(n2);
	q.push(n3);
	for(int i=0;i<3;++i){
		cout<<q.top().x<<" ";
		q.pop();
	}
	cout<<endl;
}//输出 1 2 4
#endif
#if 0
void test4(){
	string s1,s2;
	cin>>s1>>s2;
	if(s1>s2){
		cout<<s1<<">"<<s2<<endl;
	}else if(s1<s2){
		cout<<s1<<"<"<<s2<<endl;
	}else{
		cout<<s1<<"="<<s2<<endl;
	}
}
#endif
#if 0
void test5(){
	queueNode q1,q2,q3;
	cin>>q1.word>>q1.frequency>>q1.differentDegree;
	cin>>q2.word>>q2.frequency>>q2.differentDegree;
	cin>>q3.word>>q3.frequency>>q3.differentDegree;
	priority_queue<queueNode> m;
	m.push(q1);
	m.push(q2);
	m.push(q3);
	for(int i=0;i<3;++i)
	{
		cout<<m.top().word<<endl;
		m.pop();
	}
}
#endif
#if 1
void test6(){
	stack<queueNode> staQueueNode;
	vector<queueNode> vecQueueNode;
	for(int i=0;i<5;++i){


int main(int argc,char* argv[])
{
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
}
