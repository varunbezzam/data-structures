#include<iostream>
using namespace std;

class BST
{
    private:
        int data;
        BST *left;
        BST *right;
    public:

        BST()
        {
            this->left = NULL;
            this->right = NULL;
        }

        BST(int data)
        {
            this->data = data;
        }

        BST *insert(BST *root,int data)
        {
            if(root == NULL)
            {
                BST * node = new BST;
                node->data = data;
                return node;
            }
            else if(data>=root->data)
                root->right = insert(root->right,data);
            else if(data<root->data)
                root->left = insert(root->left,data);

            return root;
        }

        void inorder(BST *root)
        {
            if(root!=NULL)
            {
                inorder(root->left);
                cout<<root->data<<"|";
                inorder(root->right);
            }
        }

        void preorder(BST *root)
        {
            if(root!=NULL)
            {
                cout<<root->data<<"|";
                preorder(root->left);
                preorder(root->right);
            }
        }

        void postorder(BST *root)
        {
            if(root!=NULL)
            {
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<"|";
            }
        }

        int findMin(BST *root)
        {
            while(root->left != NULL)
                root = root->left;
            return root->data;
        }

        int findMax(BST *root)
        {
            while(root->right != NULL)
                root = root->right;
            return root->data;
        }

        bool isBST(BST *root,int min,int max)
        {
            if(root == NULL)
                return true;
            if(root->data < min || root->data > max)
                return false;
            return isBST(root->left,min,root->data) && isBST(root->right,root->data,max);
        }
        BST *deleter(BST *root,int data)
        {
            if(root == NULL)
            {
                cout<<"The node does not exist";
            }
            else if(data > root->data)
            {
                root->right = deleter(root->right,data);
            }
            else if(data < root->data)
            {
                root->left = deleter(root->left,data);
            }
            else
            {
                if(root->left == NULL && root->right == NULL)
                {
                    delete root;
                    return NULL;
                }
                else if(root->right == NULL)
                {
                    BST *tmp = root->left;
                    delete root;
                    return tmp;
                }
                else if(root->left == NULL)
                {
                    BST *tmp = root->right;
                    delete root;
                    return tmp;

                }
                else
                {
                    int min = findMin(root->right);
                    root->data = min;
                    root->right = deleter(root->right,min);
                }
            }
            return root;
        }
};

int main()
{
    BST *tree;
    tree = tree->insert(tree,10);
    tree = tree->insert(tree,16);
    tree = tree->insert(tree,14);
    tree = tree->insert(tree,2);
    tree = tree->insert(tree,3);
    tree->inorder(tree);
    cout<<"\n";
    tree->deleter(tree,10);
    tree->inorder(tree);
    return 0;
}
