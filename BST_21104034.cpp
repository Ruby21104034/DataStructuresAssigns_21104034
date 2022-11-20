#include<iostream>
using namespace std;

//binary tree node
struct node{
    int data;
    node *left, *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//function to convert array to BST
node* sortedArrayToBST(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    //make mid element of array as the root of BST
    int mid=(start+end)/2;
    node* root =new node(arr[mid]);
    
    //Recusively construct left and right subtrees and make them children of root
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);

    return root;
}

//function to print preorder of BST
void preorderPrint(node * root){
      if(root==NULL){
        return;
      }
      cout<<root->data<<" ";
      preorderPrint(root->left);
      preorderPrint(root->right);
}

//return the node with minimum value found in the BST
struct node* minNode(struct node* node)
{
    struct node* current = node;
  
    // loop down to find the leftmost leaf 
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

//Function to delete node from BST 
struct node* Delete(struct node* root,int data){
        if(root==NULL){
            return root;
        }

        //finding the node to be deleted
        else if(data<root->data){
           root->left= Delete(root->left,data);
        }

        else if(data>root->data){
            root->right= Delete(root->left,data);
        }

        //now deleting the node from BST
        else{
            //CASE 1: No child
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }

            //CASE 2: One child
            if(root->left==NULL){
                struct node* temp =root->right;
                free(root);
                return temp;
            }

            if(root->right==NULL){
                struct node* temp =root->left;
                free(root);
                return temp;
            }

            //CASE 3: Two children
            else{
                
                struct node* temp = minNode(root->right);
                root->data=temp->data;
                root->right=Delete(root->right,temp->data);
            }
        
        return root;    
        }
        
};

//Function to delete node from an array
int deleteElement(int arr[], int n, int x)
{
// Search x in array
int i;
for (i=0; i<n; i++)
    if (arr[i] == x)
        break;
 
// If x found in array
if (i < n)
{
    // reduce size of array and move all elements on space ahead
    n = n - 1;
    for (int j=i; j<n; j++)
        arr[j] = arr[j+1];
}
 
return n;
}


int main(){
int arr[]={10,20,30,40,50};
int n= sizeof(arr) / sizeof(arr[0]);

//BST Transversal preorder
node* root=sortedArrayToBST(arr,0,n-1);
cout<<"Preorder transversal of BST is : ";
preorderPrint(root);
cout<<endl;

//BST DELETION
root=Delete(root,30);
cout<<"Preorder transversal after deleting 30 from BST: ";
preorderPrint(root);
cout<<endl;

//ARRAY DELETION
cout<<"Array before deletion: ";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

cout<<endl;
cout<<"Array after deletion: ";
deleteElement(arr,5,10);
for(int i=0;i<n-1;i++){
    cout<<arr[i]<<" ";
}

//SPACE COMPLEXITY-

//ARRAY-
//If you'll always create an array of size N, it's O(1), because no matter what input your algorithm takes, the space taken by array is the same.
//If N grows with the size of the input, it's O(f(n)), where f(n) is the relation between n (size of input) and N (size of array).

//BST-
// In the average case (and best case) - assuming a tree is balanced, then the height would be about (log N to base 2). Hence, space complexity would be O(log N to base 2)
// In a worst case , where the tree is just a sorted linked list branching right with incrementing values, then O(N) as worst case.

return 0;
}