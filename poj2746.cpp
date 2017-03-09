#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Node{
	public:
	Node* next;
	int data;
	Node(int _data){
		data = _data;
		next = NULL; 
	}
}; 
class Linklist{
	public:
	Node* head;
	Linklist(){
		head = NULL;
	}
	void insert(int val){
		Node* temp=new Node(val);
//		Node temp2= *head;
		if(head == NULL){
			head = temp;
			head->next = head;
			Node start = *head;
			return;
		}
		Node* start = head;
		while(start->next != head){
			start = start->next;
		}
		start->next = temp;
		temp->next = head;
	}
	void pop(int index){
		Node* start = head;		 
		while(start->next!=start){
			if(index == 1){
				while(start->next != head){
					start = start->next;
				}
//				cout<<start->next->data<<endl;
				start->next = start->next->next;
				start= start->next;
				head = start;
				continue ;
			} 
			int count = 1;
			
			while(count<(index-1)){
				start = start->next;
				count ++;
			}
//			cout<<start->next->data<<endl;
			Node *delete_node = start->next;
			if(delete_node == head){
				head = delete_node->next;
			}
			start->next = start->next->next;
			start= start->next;
//			delete delete_node;
			if(start->next==start){
				cout<<start->data<<endl;
				return; 
			}
		}
		cout<<start->data<<endl;
		return; 
		
	}
	void display(){
		Node* start = head;
		for(int i = 1; i<=10 ;i++){
			cout<<start->data<<endl;
			start = start->next;
		}
	}
};
int main(int argc, char** argv) {
	int n,m;
	Linklist linklist;
	while(1){
		linklist = Linklist();
		cin>>n>>m;
		if(n==0&&m==0){
			return 0;
		}
		for(int i = 1; i <= n ; i++){
			linklist.insert(i);
		}
		linklist.pop(m);
//		linklist.display();
//		cout<<linklist.head->data<<endl;
	}
	return 0;
}
