#include "../inc/func.h"

//插入一个新的节点（头插法）若已满则删除尾节点再进行插入
void LRUCache::insert(string key,string json){
	if(full()){//如果已满就删除一个尾节点
		deleteTailNode();
	}
	CacheNode* pNewCacheNode=new CacheNode(key,json);
	if(empty()){//队列为空
		_QueHead=_QueTail=pNewCacheNode;
	}else{//队列不为空
		pNewCacheNode->_next=_QueHead;
		_QueHead->_last=pNewCacheNode;
		_QueHead=pNewCacheNode;
	}
	++_QueLen;
	_keys[pNewCacheNode->_key]=pNewCacheNode;
}

//删除队尾节点，如果队列为空不进行操作
void LRUCache::deleteTailNode(){
	if(empty()){
		return;
	}
	string deleteKey=_QueTail->_key;
	CacheNode* deleteNode=_QueTail;
	if(size()==1){//队列只有一个元素
		_QueTail=_QueHead=nullptr;
	}else{//队列中至少有两个
		deleteNode->_last->_next=nullptr;
		_QueTail=deleteNode->_last;
	}
	--_QueLen;
	_keys.erase(deleteKey);
	delete deleteNode;
}

//访问一个<已存在>的节点，返回其json字符串，无需判断队列是否为空，同时将该节点放到链表头
string LRUCache::getJson(string key){
	CacheNode* pKeyNode=_keys[key];
	//将该节点提到队首
	if(pKeyNode!=_QueHead){//该节点不是队首
		if(pKeyNode==_QueTail){//该节点是队尾
			pKeyNode->_last->_next=nullptr;
			_QueTail=pKeyNode->_last;
			pKeyNode->_next=_QueHead;
			_QueHead->_last=pKeyNode;
			pKeyNode->_last=nullptr;
			_QueHead=pKeyNode;
		}else{//该节点不是队尾
			pKeyNode->_last->_next=pKeyNode->_next;
			pKeyNode->_next->_last=pKeyNode->_last;
			pKeyNode->_next=_QueHead;
			_QueHead->_last=pKeyNode;
			pKeyNode->_last=nullptr;
			_QueHead=pKeyNode;
		}
	}
	return pKeyNode->_json;
}
//将LRUCache中的cache转为json风格字符串
string LRUCache::output(){
	Json::Value discCache;
	CacheNode* pCurCacheNode=_QueHead;
	while(pCurCacheNode!=nullptr){
		Json::Value object;
		object["key"]=pCurCacheNode->_key;
		object["json"]=pCurCacheNode->_json;
		discCache.append(object);
		pCurCacheNode=pCurCacheNode->_next;
	}
	Json::StyledWriter swriter;
	return swriter.write(discCache);//结尾自带换行
}

//将json风格字符串转为LRUCache内的数据
void LRUCache::input(string json){
	Json::Value discCache;
	Json::Reader reader;
	if(!reader.parse(json,discCache)){
		cout<<"parse fail"<<endl;
		return;
	}else{
		string key,json;
		for(int i=discCache.size()-1;i>=0;--i){
			key=discCache[i]["key"].asString();
			json=discCache[i]["json"].asString();
			insert(key,json);
		}
	}
}

void test(){
	LRUCache cache;
	cache.print();
	cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
	cout<<"cache.output()="<<cache.output()<<endl;
/*
	string s1,s2;
	for(int i=0;i<5;++i){
		cin>>s1>>s2;
		cache.insert(s1,s2);
	}
	cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<endl;
	cache.print();
	cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl;
	cout<<cache.output()<<endl;
	LRUCache cache1;
	string json=cache.output();
	cout<<json<<endl;
	cache1.input(json);
	cache1.print();
*/
}
int main(){
	test();
}
