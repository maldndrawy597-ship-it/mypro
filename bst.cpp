#include <iostream>
#include <string>
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
    Node* lift;
    Node* right;
    
    Node() 
    {
        lift = NULL;
        right = NULL;
    }
};

class BST
{
    Node* Root;
    
    public:
        BST() { Root = NULL; }
        
        void insert(Book newData) { insert(Root, newData); }
        
        void insert(Node* root, Book newData)
        {
            if (root == NULL)
            {
                Node* newNode;
                newNode->data = newData;
                root = newNode;
            }
            else
            {
                if (root->data.id = newData.id )
                    cout<< "The book already exists" <<endl;
                    
                else if (root->data.id > newData.id)
                    insert(root->lift,newData);
                    
                else
                    insert(root->right,newData);
            }
        }
        
        void display() { display(Root); }
        
        void display(Node* p)
        {
            if (p != NULL)
            {
                display(p->lift);
                
                cout<< "id: " << p->data.id << "\n"
                    << "title: " << p->data.title << "\n"
                    << "author: " << p->data.author << "\n\n";
                
                display(p->right);
            }
        }
};

int main()
{
    BST bst;
    
    for (int i = 0; i < 3; i++) {
        int d;
        string t,a;
        
        std::cout << "d t a" << std::endl;
        std::cin >> d >> t >> a;
        
        Book book;
        book.title = t;
        book.author = a;
        book.id = d;
        
        bst.insert(book);
    }
    
    bst.display();
}