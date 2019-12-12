#include "../inc/func.h"

bool QueueNode::operator <(const QueueNode &a) const{//true放后面,false放前面
	//先看差别度
	if(_differentDegree<a.getDifferentDegree()){
		return true;
	}else if(_differentDegree>a.getDifferentDegree()){
		return false;
	}else{//差别度相等，看词频
		if(_frequency>a.getFrequency()){
			return true;
		}else if(_frequency<a.getFrequency()){
			return false;
		}else{//差别度，词频都相同
			if(_word<a.getWord()){
				return true;
			}else{
				return false;
			}
		}
	}
}
//赋值运算符重载
QueueNode& QueueNode::operator=(const QueueNode &a){
	_word=a.getWord();
	_frequency=a.getFrequency();
	_differentDegree=a.getDifferentDegree();
	return *this;
}







