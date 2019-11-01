#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

struct node *newNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(node));
    temp -> data = val;
    temp -> left = temp -> right = NULL;
    return temp;
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        cout<<root -> data<<" ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root -> left);
        cout<<root -> data<<" ";
        inorder(root -> right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root -> left);
        postorder(root -> right);
        cout<<root -> data<<" ";
    }
}

void preorderIterative(struct node *root)
{
    if(root == NULL)
        return;
        
    stack<node*> st;
    st.push(root);
    
    while(!st.empty())
    {
        //Pop and print as root comes first
        struct node *ptr = st.top();
        cout<<ptr -> data<<" ";
        st.pop();
        
        
        if(ptr -> right)
            st.push(ptr -> right);
            
        if(ptr -> left)
            st.push(ptr -> left);
    }
    
}

void inorderIterative(struct node *root)
{
    struct node *ptr = root;
    stack<node*> st;
    
    if(ptr == NULL)
        return;
        
    while(1)
    {
        //Reaching leftmost node
        while(ptr -> left != NULL)
        {
            st.push(ptr);
            //Push all lefts in the stack
            ptr = ptr -> left;   
        }
        
        while(ptr -> right == NULL)
        {
            cout<<ptr -> data<<" "; 
            //So last left visited here
            if(st.empty())
                return;
            
            //Keep visting lefts till a right child isn't found
            //As in while condition
            ptr = st.top();
            st.pop();
        }
        
        //If we come out of loop it means
        //Right child is present
        //So visit the root
        cout<<ptr -> data<<" ";
        //Now visit right child
        ptr = ptr -> right;
    }
    
}

void postorderIterative(struct node *root)
{
    struct node *q, *ptr = root;
    if(ptr ==  NULL)
        return;
    q = root; //tracks whether right subtree is traversed or not 
    stack<node*> st;
    
    while(1)
    {
        //Push all left into the stack
        while(ptr -> left)
        {
            st.push(ptr);
            ptr = ptr -> left;
        }
        
        
        //No right subtree or right subtree traversed
        while(ptr -> right == NULL || ptr -> right == q)
        {
            cout<<ptr -> data<<" ";
            q = ptr;
            if(st.empty())
                return;
                
            ptr = st.top();
            st.pop();
        }
        
        //Breaking of loop indicates there is a right subtree
        st.push(ptr);
        ptr = ptr -> right;
    }
}

struct node *insertNode(struct node *root, int key)
{
    if(root == NULL)
        return newNode(key);
        
    if(key < root -> data)
        root -> left = insertNode(root -> left,key);
    else if(key > root -> data)
        root -> right = insertNode(root -> right,key);
        
    return root;
}

struct node *minValueNode(struct node* node)
{
    struct node* current = node;
    
    //Finding leftmost leaf
    while(current && current -> left != NULL)
        current = current -> left;
    
    return current;
}

struct node *deleteNode(struct node* root, int key)
{
    if(root == NULL)
        return root;
        
    if(key < root -> data)
        root -> left = deleteNode(root -> left, key);
    
    else if(key > root -> data)
       root -> right = deleteNode(root -> right, key);
       
    else
    {
        //This means current node has to be deleted
        
        //Case for 0 or 1 child
        if(root -> left == NULL)
        {
            struct node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL)
        {
            struct node *temp = root -> left;
            free(root);
            return temp;
        }
    
    
    //Case for 2 child
    //Get the inorder successor
    //Smallest element in right subtree
    struct node *temp = minValueNode(root -> right);
    //Copy inorder succesor data to this node
    root -> data = temp -> data;
    //Delete the inorder successor
    root -> right = deleteNode(root -> right, temp -> data);
    
    }
    
    return root;
}


void levelOrder(struct node *root)
{
    struct node *ptr = root;
    
    if(ptr == NULL)
        return;
        
    queue<node*> qu;
    qu.push(root);
    
    while(!qu.empty())
    {
        ptr = qu.front();
        qu.pop();
        cout<<ptr -> data<<" ";
        
        if(ptr -> left)
            qu.push(ptr -> left);
        if(ptr -> right)
            qu.push(ptr -> right);
    }
}

int height(struct node *root)
{
    if(root == NULL)
    return 0;
    
    return max(1 + height(root -> left), 1 + height(root -> right));
}


int main() {
    /* Constructed binary tree is 
            10 
          /   \ 
        8      2 
      /  \    / 
    3     5  2 
            `                       */
            
    struct node *root = newNode(10);
    root -> left      = newNode(8);
    root -> right     = newNode(2);
    root -> left -> left = newNode(3);
    root -> left -> right = newNode(5);
    root -> right -> left = newNode(2);
    
    preorderIterative(root); cout<<"\n";
    inorderIterative(root);  cout<<"\n";
    postorderIterative(root); cout<<"\n";
    levelOrder(root); cout<<"\n";
    cout<<height(root);
    
    //Other functions are for personal reference but yeah they work :-p
}