#include<iostream>
#include<cstdlib>
using namespace std;


struct Node{
int data;
Node*left,*right;
int height;
};
 int getheight(Node*n){
 if(n==NULL)
    return 0;
    return n->height;
    }

    int getbalance(Node *n){
    if(n==NULL)
       return 0;
       return getheight(n->left)-getheight(n->right);}

 Node*createnode(int value){
 Node *newNode=(Node*)malloc(sizeof(Node));
 newNode->data=value;
 newNode->left=NULL;
     newNode->right=NULL;
     newNode->height=1;
     return newNode;
     }
     Node* rightrotate(Node*y){
     Node*x=y->left;
     Node*T2=x->right;
     x->right=y;
     y->left=T2;
     y->height=max(getheight(y->left),getheight(y->right))+1;
     x->height=max(getheight(x->left),getheight(x->right))+1;
     return x;}

     Node* leftrotate(Node*x){
     Node*y=x->left;
     Node*T2=y->right;
     y->left=T2;
     x->right=T2;
     x->height=max(getheight(x->left),getheight(x->right))+1;
     y->height=max(getheight(y->left),getheight(y->right)) +1;
     return y;}

     Node*insertnode(Node*node,int key){
     if(node==NULL)
     return createnode(key);

     if(key<node->data)
        node->left=insertnode(node->left,key);
     else if(key>node->data)
        node->right=insertnode(node->right,key);
     else
        return node;
     node->height=1+max(getheight(node->left),getheight(node->right));

    int balance=getbalance(node);
     if(balance>1&&key<node->left->data)
        return rightrotate(node);
     if(balance<-1&&key>node->left->data)
        return leftrotate(node);
     if(balance>1&&key>node->left->data){
        node->left=leftrotate(node->left);
        return rightrotate(node);

     }
     if(balance<-1&&key<node->right->data){
        node->right=rightrotate(node->right);
        return leftrotate(node);

     }
     return node;
     }


     void inorder(Node*root){
     if(root==NULL)
        return;
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
        }

        int main(){
        Node*root=NULL;
        int n,value;
        cout<<"how many nodes??";
        cin>>n;
        cout<<"enter the values";
        for(int i=0;i<n;i++){
            cin>>value;
            root=insertnode(root,value);

        }
        cout<<"\n inoprder traversal of avl treee";
        inorder (root);
        cout<<endl;
        return 0;
        }

