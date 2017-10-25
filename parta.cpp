/*******************************************************************
Author: Jason Klamert                                              *
Description:  Program to satisfy part A of project 3.              *
This program creates a binary  search tree out of the following    *
key values:                                                        *
30, 10, 45, 38, 20, 50, 25, 33, 8, 12                              *
The program is menu driven featuring traversal displaying, height, *
delete, and search.                                                *
 *******************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;


struct TreeNode {
    int item;         // The data in this node.
    TreeNode *left;   // Pointer to the left subtree.
    TreeNode *right;  // Pointer to the right subtree.
    TreeNode *parent;
    
    TreeNode(int n){
        item = n;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

void inorderPrint(TreeNode* root);
void preorderPrint(TreeNode* root);
void postorderPrint(TreeNode* root);
TreeNode* TreeSearch(TreeNode* root, int value);
TreeNode* Delete(TreeNode* root, int item);
int getHeight(TreeNode* root);
TreeNode* FindMin(TreeNode* root);
TreeNode* FindMax(TreeNode* root);
void Insert(TreeNode* root, int item);


int main(){
   int  BSTNumbers[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12}; 
   int userchoice,usernumber;
   TreeNode* search = NULL;
   TreeNode * root = new TreeNode(BSTNumbers[0]);
   
   for(int i = 1; i < 10; i++)
   {
       Insert(root, BSTNumbers[i]);
   }
   
   cout << "\nOriginal Tree: ";
   for(int i = 1; i < 10; i++){
       cout << BSTNumbers[i] << " ";}
   cout << "\nFrom here on out you will have to use menu option 1 to see the current tree values.\n";
   
   while(userchoice != 5)
   {
        cout << "____________________________ Menu ____________________________\n";
        cout << "*Enter the number of the operation you want performed*\n";
        cout << "1) Print In-Order, Pre-Order, and Post-Order Traversals. \n";
        cout << "2) Print Height of the BST.\n";
        cout << "3) Enter a node value to be deleted.\n";
        cout << "4) Enter a node value to be searched for.\n";
        cout << "5) Quit the Program.\n";
        cout << "______________________________________________________________\n";
        
        cin >> userchoice;
        cout << endl;
        
        switch(userchoice)
        {
            case 1:
                cout << "InOrder:\n";
                inorderPrint(root);
                cout << endl;
                cout << "PreOrder:\n";
                preorderPrint(root);
                cout << endl;
                cout << "PostOrder:\n";
                postorderPrint(root);
                cout << endl;
                cout << endl;
                break;
            case 2:
                cout << endl;
                cout << "Height: " << getHeight(root);
                cout << endl;
                break;
            case 3:
                cin >> usernumber;
                Delete(root,usernumber);
                cout << endl;
                cout << "InOrder:\n";
                inorderPrint(root);
                cout << endl;
                cout << "PreOrder:\n";
                preorderPrint(root);
                cout << endl;
                cout << "PostOrder:\n";
                postorderPrint(root);
                cout << endl;
                cout << endl;
                break;
            case 4:
                cin >> usernumber;
                search = TreeSearch(root,usernumber);
                cout << endl;
                if(search == NULL)
                    cout << "The Value Was Not Found In The Tree!\n";
                else
                {
                    cout << "Node Value: " << search->item;
                    
                    if(search->parent != NULL)
                        cout << "\nParent Value: " << search->parent->item;
                    else
                        cout << "\nParent Value: The node you found is the root and doesn't have a parent!";
                }
                cout << endl;
                cout << endl;
                break;
            case 5:
                return 0;
        }
   }

}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Prints key values of the BST in Pre-Order (Root,LST,RST ) *
 ************************************************************************/
void preorderPrint( TreeNode *root ) {
    if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
        cout << root->item << " ";      // Print the root item.
        preorderPrint( root->left );    // Print items in left subtree.
        preorderPrint( root->right );   // Print items in right subtree.
    }
}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Prints key values of the BST in Post-Order (LST,RST,Root) *
 ************************************************************************/
void postorderPrint( TreeNode *root ) {
    if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
        postorderPrint( root->left );    // Print items in left subtree.
        postorderPrint( root->right );   // Print items in right subtree.
        cout << root->item << " ";       // Print the root item.
    }
}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Prints key values of the BST in In-Order (LST,Root,RST)   *
 ************************************************************************/
void inorderPrint( TreeNode *root ) {
    if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
        inorderPrint( root->left );    // Print items in left subtree.
        cout << root->item << " ";     // Print the root item.
        inorderPrint( root->right );   // Print items in right subtree.
    }
    
}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Prints key values of the BST in In-Order (LST,Root,RST)   *
 ************************************************************************/
TreeNode* TreeSearch( TreeNode *root, int value )
    {
        cout << "Search Sequence: ";
        
        while(root != NULL && root->item != value)
        {
            cout << root->item << " ";
            if(value < root->item)
            {
              if(root->left)
                root = root->left;
              else
              {
                  root = NULL;
                  cout << "NULL ";
              }
                  
            }
            else if(value > root->item)
            {
                if(root->right)
                root = root->right;
                else
                {
                    root = NULL;
                    cout << "NULL ";
                }      
            }    
        }
        
        if(root != NULL)
        cout << root->item << " ";
        
        return root;
    }

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Inserts new item into the BST.                            *
 ************************************************************************/
void Insert(TreeNode *root, int item)
    {   
        if (item < root->item)
        {
            if (root->left)
            {
                Insert(root->left,item);
            }
            else {
                TreeNode* left = new TreeNode(item);
                left->parent = root;
                root->left = left;
            }
        }
        else {
            if (root->right)
            {
                Insert(root->right,item);
            }
            else {
                TreeNode* right = new TreeNode(item);
                right->parent = root;
                root->right = right;
            }
        }
    }

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Returns the maximum depth of the tree from root to deepest*
 leaf. This will be the height.                                         *
 ************************************************************************/
int getHeight(TreeNode * node) { 
  if (node == NULL) { 
    return(-1); 
  } 
  else { 
    // compute the depth of each subtree 
    int lDepth = getHeight(node->left); 
    int rDepth = getHeight(node->right);
    // use the larger one 
    if (lDepth > rDepth) return(lDepth+1); 
    else return(rDepth+1); 
  } 
} 

/************************************************************
 Author: Jason Klamert                                      *
 Description: Function for deleting a node with specified   *
 user value.                                                *
 ************************************************************/
TreeNode* Delete(TreeNode *root, int item){
  if(root == NULL) return root;
  else if(item < root->item) root->left = Delete(root->left,item);
  else if(item > root->item) root->right = Delete(root->right, item);
  else {
    // Case 1: No Child
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    // Case 2: one child
    } else if(root->left == NULL){
      struct TreeNode *temp = root;
      root = root->right;
      delete temp;
    } else if(root->right == NULL){
      struct TreeNode *temp = root;
      root = root->left;
      delete temp;
    } else{
      struct TreeNode *temp = FindMin(root->right);
      root->item = temp->item;
      root->right = Delete(root->right, temp->item);
    }
  }
  return root;
}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Finds the Minimum key value of the BST.                   *
 ************************************************************************/
TreeNode* FindMin(TreeNode* root){
  while(root->left != NULL) root = root->left;
  return root;
}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Finds the Maximum key value of the BST.                   *
 ************************************************************************/
TreeNode* FindMax(TreeNode* root){
  while(root->right != NULL) root = root->right;
  return root;
}