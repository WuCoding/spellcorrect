#include "func.h"

//输入3个数，返回最小值
int minThreenum(int num1,int num2,int num3){
	int result=num1<num2?num1:num2;
	return result<num3?result:num3;
}
//输入两个字符串，返回两字符串的最小编辑距离
int minLevenshtein(string str1,string str2){
	int rowLen=str1.size()+1;//横向长度 str1
	int rankLen=str2.size()+1;//竖向长度 str2
	vector<vector<int>> rank;//列
	vector<int> line(rowLen);//行
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
			c=str2[i-1]==str1[j-1]?rank[i-1][j-1]:rank[i-1][j-1]+1;
			rank[i][j]=minThreenum(a,b,c);	
		}
	}
	return rank[rankLen-1][rowLen-1];
}//minLevenshtein
