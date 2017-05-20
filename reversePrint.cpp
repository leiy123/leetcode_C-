#include <iostream> //cout
#include <string.h> //strlen
#include <vector>
#include <stack>

using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x): //缺省构造函数
        val(x),next(NULL){
    }
};


int main(){
    ListNode *head = NULL;
    for(int i = 0; i < 10; i++){ //头插法创建链表9->0
       ListNode *x = new ListNode(i); //分配ListNode结构体，返回指针;c中使用malloc
       x->next = head;
       head = x;
    }
    ListNode *p = head;
    while(p != NULL){
        cout<<p->val<<' ';
        p = p->next;
    }
    cout<<endl;
    stack<int> rev;
    p = head;
    while(p != NULL){
        rev.push(p->val);
        p = p->next;
    }
    vector<int> vec;
    while(!rev.empty()){
        vec.push_back(rev.top());
        rev.pop();
    }
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        cout<<*iter<<' ';
    }
    return 0;
}
