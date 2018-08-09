#include <iostream>
#include <stack>
using namespace std;
int Duyet (char c){
	if(c=='^') return 3;
	if(c=='*' || c=='/' || c=='%') return 2;
	if(c=='+' || c=='-') return 1;
	return 0;
}
void hauto(){
	stack<char> s;
	int i=0;
	string str,str1="";
	cout << "Nhap bt:";
	getline(cin,str);
	while(i<str.length()){
		char c=str.at(i);
		if(c!=' '){
			if(c-'0'>=0 && c-'0'<=9 || c>='a'&& c<= 'z'){
				str1+=c;
			}
			else {
				cout<<str1<<" ";
				str1="";
				if(c=='('){
					s.push(c);
				}
				else {
					if(c==')'){
						while(s.top()!='('){
							cout<<s.top();
							s.pop();
						}
						s.pop();
					}
					else{
						while(!s.empty()&& Duyet(c)<=Duyet(s.top())){
							cout<<s.top();
							s.pop();
						}
						s.push(c);
					}
				}
			}
		}
		i++;
	}
	if(str1!=""){
		cout<<str1<<" ";
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}
main(){
	hauto();
}

