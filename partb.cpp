/*******************************************************************
Author: Jason Klamert                                              *
Description:  Program to satisfy part B of project 3.              *
This program creates 't' binary trees entered by the user so there *
will be 't' BSTs each of 100,500,and 1000 elements in size.        *        
Then the average heights will be taken and duplicates handled.     *
********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
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

void getRandom(int numbers[][100] ,int userchoice );
void getRandom2(int numbers[][500] ,int userchoice);
void getRandom3(int numbers[][1000] ,int userchoice);
void inorderPrint(TreeNode* root);
void preorderPrint(TreeNode* root);
void postorderPrint(TreeNode* root);
int getHeight(TreeNode* root);
void Insert(TreeNode* root, int item);


int main()
{

   int usernumber;
   int averageHeights = 0,averageHeights2 = 0,averageHeights3 = 0;
   
   cout << "Enter the number of binary trees you would like to build for each set: \n";
   cout << "***Note: If you enter 5, then 5 binary trees of 100 elements will be built.\nLikewise, 5 trees of 500 elements and 5 trees of 1000 elements will be built \nand the height averaged over each case.***\n";
   cin >> usernumber;
   
   //Make arrays to hold random generated values to be used for keys in each tree.
   int BSTNumbers[usernumber][100];
   int BSTNumbers2[usernumber][500];
   int BSTNumbers3[usernumber][1000];
   
   //Generate these Random numbers.
   getRandom(BSTNumbers,usernumber);
   getRandom2(BSTNumbers2,usernumber);
   getRandom3(BSTNumbers3,usernumber);
   
   //Create the arrays required for multi-tree processing. This allows us to have an array of trees.
   TreeNode* roots[usernumber];
   TreeNode* roots2[usernumber];
   TreeNode* roots3[usernumber];
   
   //Create the arrays to hold the height of each corresponding tree.
   int Heights[usernumber];
   int Heights2[usernumber];
   int Heights3[usernumber];
   
   
   for(int j = 0; j < usernumber; j++)
   {
       //Set the roots for the j'th set of trees.
       roots[j] = new TreeNode(BSTNumbers[j][0]);
       roots2[j] = new TreeNode(BSTNumbers2[j][0]);
       roots3[j]= new TreeNode(BSTNumbers3[j][0]);
       
       //Construct trees from the roots for BST size of 100
        for(int i = 1; i < 100; i++)
        {
            Insert(roots[j], BSTNumbers[j][i]);
        }
        
        //Construct trees from the roots for BST size of 500
        for(int i = 1; i < 500; i++)
        {
            Insert(roots2[j], BSTNumbers2[j][i]);
        }
        
        //Construct trees from the roots for BST size of 1000
        for(int i = 1; i < 1000; i++)
        {
            Insert(roots3[j], BSTNumbers3[j][i]);
        }
        
        Heights[j] = getHeight(roots[j]);
        Heights2[j] = getHeight(roots2[j]);
        Heights3[j] = getHeight(roots3[j]);
   }
   
   //Add together all of the heights of the 100,500, and 1000 element BSTs. Note that there are usernumber of each tree type.
   for(int k = 0; k < usernumber; k++)
   {
       averageHeights += Heights[k];
       averageHeights2 += Heights2[k];
       averageHeights3 += Heights3[k];
   }
   
   //Divide by total number of each tree type to receive an average height for each tree type.
   averageHeights /= usernumber;
   averageHeights2 /= usernumber;
   averageHeights3 /= usernumber;
   
   cout << "\nAverage Height of 100 Element BSTs To The Nearest Integer: " << averageHeights << endl;
   cout << "Average Height of 500 Element BSTs To The Nearest Integer: " << averageHeights2 << endl;
   cout << "Average Height of 1000 Element BSTs To The Nearest Integer: " << averageHeights3 << endl;
   
}


/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Fills arrays with random key values from 1-10,000.        *
 ************************************************************************/
void getRandom(int numbers[][100], int choice) {
    //Seed Random Generator.
    time_t seed = time(NULL);
    srand(seed);
    
    for(int i = 0; i < choice; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            numbers[i][j] = 1 + (rand() % 10000);
        }
    }
}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Fills arrays with random key values from 1-10,000.        *
 ************************************************************************/
void getRandom2(int numbers [][500], int choice) {
    //Seed Random Generator.
    time_t seed = time(0);
    srand(seed);
    
    for(int i = 0; i < choice; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            numbers[i][j] = 1 + (rand() % 10000);
        }
    }
}

/************************************************************************
 Author: Jason Klamert                                                  *
 Description: Fills arrays with random key values from 1-10,000.        *
 ************************************************************************/
void getRandom3(int numbers[][1000], int choice) {
    //Seed Random Generator.
    time_t seed = time(0);
    srand(seed);
    
    for(int i = 0; i < choice; i++)
    {
        for(int j = 0; j < 1000; j++)
        {
            numbers[i][j] = 1 + (rand() % 10000);
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
 Description: Inserts new item into the BST.                            *
 ************************************************************************/
void Insert(TreeNode *root, int item)
    {   
        if (item <= root->item)
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


