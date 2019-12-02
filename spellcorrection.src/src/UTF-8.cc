#include "../inc/func.h"

//返回一个字符占的字节数
size_t nBytesCode(const char ch){
	size_t nBytes=1;
	if(ch & 1<<7){//判断首位是否是0
		for(size_t i=0;i<5;++i){
			if(ch & 1<<(6-i)){//依然为1
				++nBytes;
			}else{//为0了
				return nBytes;
			}
		}
		return nBytes;
	}
	//首位为0
	return 1;
}
//返回一个字符串含有的字符数
size_t length(string str){
	size_t strSize=str.size();
	if(strSize!=0){//字符串不为空
		size_t len=0;
		size_t spa=0;
		for(int i=0;i<strSize;){
			spa=nBytesCode(str[i]);
			i+=spa;
			++len;			
		}
		return len;
	}else{//字符串为空
		return 0;
	}
}

int main(){
	string s1="王道abc";
	string s2="王道论坛";
	string s3;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	cout<<"s1.size()="<<s1.size()<<endl;
	cout<<"s2.size()="<<s2.size()<<endl;
	cout<<"s3.size()="<<s3.size()<<endl;
//	int i;
//	while(1){
//		cin>>i;	
//		cout<<nBytesCode(s1[i])<<endl;
//	}
	cout<<"s1.length()="<<length(s1)<<endl;
	cout<<"s2.length()="<<length(s2)<<endl;
	cout<<"s3.length()="<<length(s3)<<endl;
	string s4;
	while(1){
		cin>>s4;
		cout<<length(s4)<<endl;
	}
}
