#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book 
{
    int id;
    string title;
    string author;
};

struct Node 
{
    Book data;
    Node* left;
    Node* right;
    
    Node() 
    {
        left = NULL;
        right = NULL;
    }
};

class BST
{
    Node* Root;
    
    public:
        BST() { Root = NULL; }
        
        void insert(Book newData) { insert(Root, newData); }
        
        void insert(Node* &root, Book newData)
        {
            if (root == NULL)
            {
                Node* newNode = new Node;
                newNode->data = newData;
                root = newNode;
            }
            else
            {
                if ((root->data).id == newData.id )
                    cout<< "The book already exists\n" <<endl;
                    
                else if ((root->data).id > newData.id)
                    insert(root->left,newData);
                    
                else
                    insert(root->right,newData);
            }
        }
        
        void display() 
        {
            if ( Root == NULL )
            {
                cout << "Empty !" << endl;
            }else
            {
                display(Root); 
            }
        }
        
        void display(Node* p)
        {
            if (p != NULL)
            {
                display(p->left);
                
                cout<< "id: " << (p->data).id << "\n"
                    << "title: " << (p->data).title << "\n"
                    << "author: " << (p->data).author << "\n\n";
                
                display(p->right);
            }
        }
    
        Node* search(int Id)
        {
            return search(Root,Id);
        }
        
        Node* search(Node* root, int ID)
        {
            if (root == NULL) 
                 return NULL;
    
            if (root->data.id == ID)
                return root;
    
            if (root->data.id > ID)
                return search(root->left, ID);
    
            return search(root->right, ID);
        }
    
        Node* findMin(Node* root) 
        {
            while (root->left != NULL) root = root->left;
            return root;
        }

        void deleteBook(int id) 
        {
            Root = deleteNode(Root, id);
        }

        Node* deleteNode(Node* root, int id)
        {
            if (root == NULL) return NULL;

            if (id < root->data.id)
                root->left = deleteNode(root->left, id);
            else if (id > root->data.id)
                root->right = deleteNode(root->right, id);
            else 
            {
                if (root->left == NULL)
                {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } 
                else if (root->right == NULL)
                {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data.id);
            }       
            return root;    
        }
        
        Book findClosest(int target) 
        {
            if (Root == NULL) return { -1, "None", "None" };

            Node* current = Root;
            Node* closestNode = Root;
            int minDiff = abs(Root->data.id - target);

            while (current != NULL) 
            {
                int currentDiff = abs(current->data.id - target);
                
                if (currentDiff < minDiff) 
                {
                    minDiff = currentDiff;
                    closestNode = current;
                }
                
                if (currentDiff == 0) break;
                
                if (target < current->data.id)
                    current = current->left;
                else
                    current = current->right;
            }

            return closestNode->data;
        }

        vector<Book> findByRange(int first, int last)
        {
            vector<Book> list;
        
            for (int i= first; i <= last; i++)
            {
                Node* node = search(i);
        
                if (node != NULL)
                    list.push_back(node->data);
            }
            return list;
        }

};




