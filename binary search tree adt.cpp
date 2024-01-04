#include<stdio.h>
#include<stdlib.h>
struct bst{
    int data;
    struct bst *left;
    struct bst *right;
};
typedef struct bst node;
node *getnode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
node *insert(node *node2, int key){
    if(node2 == NULL){
        return getnode(key);
    }
    else if(key < node2->data){
        node2->left = insert(node2->left, key);
    }
    else{
        node2->right = insert(node2->right, key);
    }
    return node2;
}

void preorder(node *node1){
    if(node1 != NULL){
        printf("%d ", node1->data);
        preorder(node1->left);
        preorder(node1->right);
    }
}

void inorder(node *node1){
    if(node1 != NULL){
        inorder(node1->left);
        printf("%d ", node1->data);
        inorder(node1->right);
    }
}

void postorder(node *node1){
    if(node1 != NULL){
        postorder(node1->left);
        postorder(node1->right);
        printf("%d ", node1->data);
    }
}
void search(node *node1, int key){
    int pos= 1;
    while (node1 != NULL && node1->data != key) {
        if (key < node1->data) {
            node1 = node1->left;
        } else {
            node1 = node1->right;
        }
        pos++;
    }

    if (node1 != NULL) {
        printf("Element found at %d\n", pos);
    } else {
        printf("Element not found\n");
    }
}
node*del(node *root,int key){
	if(root==NULL){
	return root;
}
	if(root->data>key)
	root->left=del(root->left,key);
	else if(root->data<key)
	root->right=del(root->right,key);
	else {
	if(root->left==NULL){
		node *temp=root->right;
		free(temp);
		return temp;
	}
	else if(root->right==NULL){
		node *temp=root->left;
		free(temp);
		return temp;
	}
	 node *temp=root->right;
	while(temp->left!=NULL)
	temp=temp->left;
	root->data=temp->data;
	root->right=del(root->right,temp->data);
}
return root;
}
int main(){
    node *root = getnode(10);
    root = insert(root, 49);
    root = insert(root, 45);
    root = insert(root, 23);
    root = insert(root, 78);
    root = insert(root, 87);

    printf("Before Deletion:\n");
    printf("Inorder: ");
    inorder(root);
    int x = 23;
    search(root, x);
    root = del(root, x);
    printf("After Deletion of %d:\n", x);
    printf("Inorder: ");
    inorder(root);
    printf("Postorder: ");
    postorder(root);
    printf("Preorder: ");
    preorder(root);
    return 0;
}
