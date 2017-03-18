#include <iostream> //堆排序+二叉树 
#include <queue> 
/*简便解法 优先队列 
# include <iostream>
# include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main(){
	int n, num, num1, num2, i;
	while(cin>>n){
		while(!q.empty()){
			q.pop();
		}
		for(i=1; i<=n; i++){
			cin>>num;
			q.push(num);
		}
		int ans=0;
		while(q.size()!=1){
			num1=q.top();
			q.pop();
			num2=q.top();
			q.pop();
			ans=ans+num1+num2;
			q.push(num1+num2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
*/

/*优先队列+生成二叉树  by yanring
#include <iostream> //堆排序+二叉树 
#include <queue> 
using namespace std;
int len=0,mark=0;
struct TreeNode{
	TreeNode* lChild;
	TreeNode* rChild;
	int data;
	TreeNode(){
		lChild = NULL;
		rChild = NULL;
		data = 1<<31;
	}
};
struct PCmp
{
    bool operator () (TreeNode const *x, TreeNode const *y)
    {
        return x->data>y->data;
    }
}; 
class HuffmanTree{
	public:
		TreeNode* root;
		TreeNode* merge(TreeNode* left,TreeNode* right){
			TreeNode* res =new TreeNode();
			res->lChild = left;
			res->rChild = right;
			res->data = left->data + right->data;
//			cout<<res->data<<" ";
			root = res;
			return res;
		}
	
};
void search(TreeNode* node,int level){
//	cout<<node->data<<endl;
	if(node->lChild!=NULL)
		search(node->lChild,level+1);
	if(node->rChild!=NULL)
		search(node->rChild,level+1);
	if(node->rChild==NULL&&node->lChild==NULL)
		mark+=level*node->data;
		
}
priority_queue<TreeNode*,vector<TreeNode*>,PCmp> q;
int main(int argc, char** argv) {
	int N,temp;
	HuffmanTree tree;
	cin>>N;
	for(int i = 1; i <= N ; i++){
		cin>>temp;
		TreeNode* node = new TreeNode;
		node->data = temp;
		q.push(node);
		
	}
	for(int i = 1; i <= N-1 ; i++){
		TreeNode* temp_node1_pointer ;
		TreeNode* temp_node2_pointer ;
		temp_node1_pointer = q.top();
		q.pop();
		temp_node2_pointer = q.top();
		q.pop();

		TreeNode* temp_node_pointer = tree.merge(temp_node1_pointer,temp_node2_pointer);
		q.push(temp_node_pointer);
	}
	search(tree.root,0);
	cout<<mark<<endl;
	return 0;
}
*/
using namespace std;
int len=0,mark=0;
struct TreeNode{
	TreeNode* lChild;
	TreeNode* rChild;
	int data;
	TreeNode(){
		lChild = NULL;
		rChild = NULL;
		data = 1<<31;
	}
};
struct PCmp
{
    bool operator () (TreeNode const *x, TreeNode const *y)
    {
        return x->data>y->data;
    }
}; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class HuffmanTree{
	public:
		TreeNode* root;
		TreeNode* merge(TreeNode* left,TreeNode* right){
			TreeNode* res =new TreeNode();
			res->lChild = left;
			res->rChild = right;
			res->data = left->data + right->data;
//			cout<<res->data<<" ";
			root = res;
			return res;
		}
	
};
TreeNode* heap[110];
void shift_up(int index){
	
}
void shift_down(int index){
	heap[0] = heap[index];
	int i = index;
	int j = index*2;
	while(j<=len){
		if(j<=len-1&&(heap[j]->data>heap[j+1]->data)){
			j++;
		}
		if(heap[0]->data>heap[j]->data){
			heap[i] = heap[j];
			i = j;
			j = i*2;
		}else break;
	}
	heap[i] = heap[0];
}
void build_heap(){
	for(int i = len/2;i>=1;i--){
		shift_down(i);
	}
} 
void insert(TreeNode* node){
	len++;
	heap[len] = node;
	build_heap();
}
TreeNode* delete_node(){
	TreeNode* res = heap[1];
	heap[1] = heap[len];
	heap[len] = NULL;
	len--;	
	build_heap();
	return res;
}
void search(TreeNode* node,int level){
//	cout<<node->data<<endl;
	if(node->lChild!=NULL)
		search(node->lChild,level+1);
	if(node->rChild!=NULL)
		search(node->rChild,level+1);
	if(node->rChild==NULL&&node->lChild==NULL)
		mark+=level*node->data;
		
}
int main(int argc, char** argv) {
	int N,temp;
	HuffmanTree tree;
	cin>>N;
	for(int i = 1; i <= N ; i++){
		cin>>temp;
		TreeNode* node = new TreeNode;
		node->data = temp;
		insert(node);
		
	}
	for(int i = 1; i <= N-1 ; i++){
		TreeNode* temp_node1 = delete_node();
		TreeNode* temp_node2 = delete_node();
		TreeNode* temp_node_pointer = tree.merge(temp_node1,temp_node2);
//		q.push(temp_node_pointer);
//		cout<<temp_node1->data<<" "<<temp_node2->data<<endl;
		insert(tree.merge(temp_node1,temp_node2));
	}
	search(tree.root,0);
	cout<<mark<<endl;
	return 0;
}
