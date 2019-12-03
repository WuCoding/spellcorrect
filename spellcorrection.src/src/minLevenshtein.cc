#include "../inc/func.h"

//输入3个数，返回最小值
int minThreenum(int num1,int num2,int num3){
	int result=num1<num2?num1:num2;
	return result<num3?result:num3;
}

//返回一个字符所占的字节数
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

//返回一个字符串中的字符数
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

//输入一个字符串返回一个存储该字符串字符的vector<string>
void getCharFromString(string str,vector<string> &vecStr){
	for(int i=0;i<str.size();){
		string temStr;
		size_t spa=nBytesCode(str[i]);
		for(int j=0;j<spa;++j){
			temStr+=str[i+j];
		}
		vecStr.push_back(temStr);
		i+=spa;
	}
}

//输入两个字符串，返回两字符串的最小编辑距离
size_t minLevenshtein(string str1,string str2){
	int rowLen=length(str1)+1;//横向长度 str1
	int rankLen=length(str2)+1;//竖向长度 str2
	vector<vector<int>> rank;//列
	vector<int> line(rowLen);//行
	vector<string> vecStr1;//存储str1的单个字符
	vector<string> vecStr2;//存储str2的单个字符
	
	getCharFromString(str1,vecStr1);
	getCharFromString(str2,vecStr2);
	//构建二维数组
	for(int i=0;i<rankLen;++i){
		rank.push_back(line);
	}
	//填充横向初值
	for(int i=0;i<rowLen;++i){
		rank[0][i]=i;
	}
	//填充纵向初值
	for(int i=0;i<rankLen;++i){
		rank[i][0]=i;
	}
	//填充数组 【行】【列】(1~rowLen-1)(1~rankLen-1)
	int a,b,c;
	for(int i=1;i<rankLen;++i){
		for(int j=1;j<rowLen;++j){//rank[i][j]
			a=rank[i][j-1]+1;
			b=rank[i-1][j]+1;
			c=vecStr2[i-1]==vecStr1[j-1]?rank[i-1][j-1]:rank[i-1][j-1]+1;
			rank[i][j]=minThreenum(a,b,c);	
		}
	}
	return rank[rankLen-1][rowLen-1];
}//minLevenshtein

