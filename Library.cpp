#include "BST.cpp"
#include <vector>
#include <fstream>


int main()
{
    int choose, stored ; 
    cout << "Smart Library Book Management System\n"
         << "Choose a method for storing books\n"
         << "1. BST  OR  2. AVL  :" ;
    cin >> choose;
    
    cout << "choose 1. random  OR  2. stored :";
    cin >> stored;
    
    if ( choose == 1 )
    {
        BST bst;
        ifstream in((stored - 1) ? "stored_books.txt" : "random_books.txt" );
    
        if(in.is_open())
        {
            Book book;
        
            while ( in >> book.id >> book.title >> book.author)
            {
                bst.insert(book);
            }
            in.close();
        }else cout<< "error\n";
    
        cout << "display\n";
        bst.display();
        
        cout << "search book by id 22\n";
        Node* node = bst.search(22);
        cout<< "id: " << (node->data).id << "\n"
            << "title: " << (node->data).title << "\n"
            << "author: " << (node->data).author << "\n\n";
        
        cout << "delete book by id 100\n";
        bst.deleteBook(100);
        
        bst.display();
        
        cout << "find by range\n";
        vector<Book> vec = bst.findByRange();
        for(const auto& b : vec)
            cout << b.id << ": " << b.title << endl;
            
        cout << "find closet book id 20\n";
        Book book = bst.findCloset(20);
        cout << book.id << ": " << book.title << endl;
    }
}