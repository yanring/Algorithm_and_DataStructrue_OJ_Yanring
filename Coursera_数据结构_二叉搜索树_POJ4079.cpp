#include <iostream>
using namespace std;
struct Node{
	Node* left = NULL;
	Node* right= NULL;
	int value;
	Node(int val){
		value = val;
	}
};
class Tree{
	public:
	Node* root;
	Tree(int root_val){
		root = new Node(root_val);
	}
	void add_node(Node* sub_root,int val){
		if(sub_root->value<val){
			if(sub_root->right!=NULL)
				add_node(sub_root->right,val);
			else{
				Node* new_node = new Node(val);
				sub_root->right = new_node;
				return;
			}
		}else if(sub_root->value>val){
			if(sub_root->left!=NULL)
				add_node(sub_root->left,val);
			else{
				Node* new_node = new Node(val);
				sub_root->left = new_node;
				return;
			}
		}
	}
	void traversal(Node* sub_root){
		cout<<sub_root->value<<" ";
		if(sub_root->left!=NULL)
			traversal(sub_root->left);
		if(sub_root->right!=NULL)
			traversal(sub_root->right);
	}
};
int main(int argc, char** argv) {
	int temp;	char temp_char;
	cin>>temp;
	Tree tree(temp);
	temp_char = cin.get();
	while(temp_char==' '){
		cin>>temp;
		temp_char = cin.get();
//		cout<<temp_char;
		tree.add_node(tree.root,temp);
	}
	tree.traversal(tree.root);
	cout<<endl;
	return 0;
}
