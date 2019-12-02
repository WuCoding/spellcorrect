#include "func.h"

//插入一个新的节点（头插法）直接放到头部不进行检测
void insertNewNode(QueueMap* pQuemap,ListNode* pNode){
	if(pQuemap->_QueLen==0){//队列为空
		pQuemap->_QueHead=pQuemap->_QueTail=pNode;
	}else{//队列不为空
		pNode->_next=pQuemap->_QueHead;
		pQuemap->_QueHead->_last=pNode;
		pQuemap->_QueHead=pNode;
	}
	++(pQuemap->_QueLen);
	(pQuemap->_keys)[pNode->_key]=pNode;
}
//删除队尾节点，直接删除，不进行队列是否为空的检查
void deleteQueTail(QueueMap* pQuemap){
	string deleteKey=pQuemap->_QueTail->_key;
	ListNode* deleteNode=pQuemap->_QueTail;
	if(pQuemap->size()==1){//队列只有一个元素
		pQuemap->_QueTail=pQuemap->_QueHead=nullptr;
	}else{//队列中至少有两个
		deleteNode->_last->_next=nullptr;
		pQuemap->_QueTail=deleteNode->_last;
	}
	--(pQuemap->_QueLen);
	(pQuemap->_keys).erase(deleteKey);
	delete deleteNode;
}
//访问一个已存在的节点，返回其json字符串，无需判断队列是否为空
string getJson(QueueMap* pQuemap,string key){
	ListNode* pKeyNode=(pQuemap->_keys)[key];
	//将该节点提到队首
	if(pKeyNode!=pQuemap->_QueHead){//该节点不是队首
		if(pKeyNode==pQuemap->_QueTail){//该节点是队尾
			pKeyNode->_last->_next=nullptr;
			pQuemap->_QueTail=pKeyNode->_last;
			pKeyNode->_next=pQuemap->_QueHead;
			pQuemap->_QueHead->_last=pKeyNode;
			pKeyNode->_last=nullptr;
			pQuemap->_QueHead=pKeyNode;
		}else{//该节点不是队尾
			pKeyNode->_last->_next=pKeyNode->_next;
			pKeyNode->_next->_last=pKeyNode->_last;
			pKeyNode->_next=pQuemap->_QueHead;
			pQuemap->_QueHead->_last=pKeyNode;
			pKeyNode->_last=nullptr;
			pQuemap->_QueHead=pKeyNode;
		}
	}
	return pKeyNode->_json;
}
//打印队列
void printQue(QueueMap* pQuemap){
	ListNode* pNode=pQuemap->_QueHead;
	while(pNode!=nullptr){
		cout<<pNode->_key<<" "<<pNode->_json<<endl;
		pNode=pNode->_next;
	}
}
void test(){
	string s1,s2;
	ListNode* pNewNode;
	QueueMap queMap(5);
	cout<<"queMap.size()="<<queMap.size()<<endl;
	for(int i=0;i<5;++i){
		cin>>s1>>s2;
		pNewNode=new ListNode(s1,s2);
		insertNewNode(&queMap,pNewNode);
	}

	cout<<"queMap.size()="<<(queMap._QueLen)<<endl;
	cout<<"通过map打印元素："<<endl;
	for(auto it=(queMap._keys).begin();it!=(queMap._keys).end();++it){
		cout<<it->first<<" "<<it->second->_json<<endl;
	}
	cout<<"检测元素是否存在："<<endl;
	for(int i=0;i<2;++i){
		cin>>s1;
		if(queMap.exist(s1)){
			cout<<"队列中存在"<<endl;
		}else{
			cout<<"队列中不存在"<<endl;
		}
	}
	cout<<"当前队列排序："<<endl;
	printQue(&queMap);
	while(1){
		cout<<"获取元素信息"<<endl;
		cin>>s1;
		cout<<getJson(&queMap,s1)<<endl;
		printQue(&queMap);
	}

#if 0
	for(int i=0;i<2;++i){
		deleteQueTail(&queMap);
		cout<<"queMap.size()="<<queMap.size()<<endl;
		for(auto it=(queMap._keys).begin();it!=(queMap._keys).end();++it){
			cout<<it->first<<" "<<it->second->_json<<endl;
		}
	}
#endif
}
void test1(){
	QueueMap queMap;
	cout<<queMap.size()<<endl;
	cout<<queMap._Capacity<<endl;
	string s1;
	cin>>s1;
	if(queMap.exist(s1)){
		cout<<"存在"<<endl;
	}else{
		cout<<"不存在"<<endl;
	}
}

int main(){
	test();
}
