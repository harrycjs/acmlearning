#include <bits/stdc++.h>
using namespace std;
//约瑟夫游戏
//动态链表，静态链表（三种，结构体，一维数组），stl list(双向）
//动态链表法
/*struct node{
	int data;
	node* next;	
};
int main(){
	int n,m;
	cin>>n>>m;
	node *head,*p,*now,*prev;
	head=new node;head->data=1;head->next=NULL;
	now=head;
	for(int i=2;i<=n;i++){
		p=new node; p->data=i; p->next=NULL;
		now->next=p;
		now=p;
	}
	now->next=head;//循环链表
	
	now=head; prev=head;
	while((n--)>1){
		for(int i=1;i<m;i++){
			prev=now;
			now=now->next;
		
		}
		cout<<now->data<<" ";
		prev->next=now->next;//删除m节点
		delete now;
		now=prev->next;   
		
	}
	cout<<now->data;
	delete now;
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	return 0;
}*/

/*const int n=105;
struct node{
	int id,nextid;
}node[n];
int main(){
	int n,m; cin>>n>>m;
	node[0].nextid=1;
	for(int i=1;i<=n;i++){
		node[i].id=i;
		node[i].nextid=i+1;
	}
	node[n].nextid=1;//尾指向头
	int now=1,prev=1;
	while((n--)>1){
		for(int i=1;i<m;i++){
			prev=now;
			now=node[now].nextid;
		}
		cout<<node[now].id<<" ";
		node[prev].nextid=node[now].nextid;
		now=node[prev].nextid;
	}
	cout<<node[now].id;
	return 0;
}*/   //结构体数组实现单向静态链表
//STL list
int main(){
	int n,m;
	cin>>n>>m;
	list<int> node;
	for(int i=1;i<=n;i++) node.push_back(i);
	auto it=node.begin();//迭代器it
	while(node.size()>1){
		for(int i=1;i<m;i++){
			it++;
			if(it==node.end()) it=node.begin();
			
		}
		cout<<*it<<" ";
		auto next=++it;
		if(next==node.end()) next=node.begin();
		node.erase(--it);//删除m节点
		it=next;
	}	
	cout<<*it;
	return 0;
}



























