#include "../inc/func.h"

void test(string fileName){
	XMLDocument doc;
	XMLError errXml=doc.LoadFile(fileName.c_str());
	if(XML_SUCCESS==errXml){
		const char* txt;
		XMLElement* Rss=doc.RootElement();//rss
		XMLElement* Channel=Rss->FirstChildElement("channel");//channel
		XMLElement* Title=Channel->FirstChildElement("title");//title
		XMLElement* Link=Channel->FirstChildElement("link");//link
		XMLElement* Description=Channel->FirstChildElement("description");//description
		txt=Title->GetText();
		if(txt==nullptr){
			cout<<"title: nullptr"<<endl;
		}else{
			cout<<"title: "<< txt <<endl;
		}

		txt=Link->GetText();
		if(txt==nullptr){
			cout<<"link: null"<<endl;
		}else{
			cout<<"link: "<< txt <<endl;
		}

		txt=Description->GetText();	
		if(txt==nullptr){
			cout<<"description: null"<<endl;
		}else{
			cout<<"description: "<< txt <<endl;
		}

		string s;
		XMLElement* Item=Channel->FirstChildElement("item");//item
		while(Item){
			cin>>s;
			Title=Item->FirstChildElement("title");
			Link=Item->FirstChildElement("link");
			Description=Item->FirstChildElement("description");

			txt=Title->GetText();
			if(txt==nullptr){
				cout<<"title: nullptr"<<endl;
			}else{
				cout<<"title: "<< txt <<endl;
			}

			txt=Link->GetText();
			if(txt==nullptr){
				cout<<"link: null"<<endl;
			}else{
				cout<<"link: "<< txt <<endl;
			}

			txt=Description->GetText();	
			if(txt==nullptr){
				cout<<"description: null"<<endl;
			}else{
				cout<<"description: "<< txt <<endl;
			}
			Item=Item->NextSiblingElement("item");
		}
	}
}
int main(){
	string fileName;
	cin>>fileName;
	test(fileName);
}
