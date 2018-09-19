#include<iostream>
#include<string.h>
using namespace std;
#define size 50
char st[size];
int tos=0,ele;
void push(char);
char pop();
char infix[size],op[size];
int pre(char);
int main(){
    int j=0,i=0,length;
    char temp;
    cout<<"Enter An Infix Exp:"<<endl;
    cin>>infix;
    length = strlen(infix);
    for(i=0;i<length;i++){
        if(infix[i]!='+' && infix[i]!='-' && infix[i]!='/' && infix[i]!='*' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')'){
            op[j] = infix[i];
            j++;
        }
        else{
            if(tos==0)
                {
                push(infix[i]);
                }
                else{
                    if(infix[i]!='(' && infix[i]!=')'){
                        if(pre(infix[i])<=pre(st[tos-1])){
                            temp = pop();
                            op[j++] = temp;
                            push(infix[i]);
                        }
                        else{
                             push(infix[i]);
                        }
                    }
                    else{
                        if(infix[i]=='('){
                            push(infix[i]);

                           }
                           if(infix[i]==')'){
                            temp = pop();
                            while(temp!='('){
                                    op[j++] = temp;
                                    temp = pop();
                                }
                           }
                        }
                    }
                }
            }
            while(tos!=0){
                op[j++] = pop();
            }
            cout<<"The Postfix Expression is:"<<op;

            return 0;
    }
void push(char ele){
    st[tos] = ele;
    tos++;
    }
char pop(){
    tos--;
    return(st[tos]);
}
int pre(char symbol){
    if(symbol=='(' || symbol==')'){
        return 0;
       }
    if(symbol=='+' || symbol=='-'){
        return 1;
    }
    if(symbol=='*' || symbol=='/'){
        return 2;
    }
    if(symbol=='^'){
        return 3;
    }
    return 0;
}
