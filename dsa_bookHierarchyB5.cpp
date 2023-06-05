#include <iostream>
#include <string>
using namespace std;

struct node
{
    char label[10];
    int ch_cnt;
    struct node *child[10];
} *root;

class BookTree
{
public:
    void create_tree();
    void display(node *r1);
    BookTree()
    {
        root = NULL;
    }
};

void BookTree ::create_tree()
{
    int tbk, tch, i, j, k;
    root = new node;
    cout << "Enter name of book :";
    cin >> root->label;
    cout << "Enter no of chapter in book :";
    cin >> tch;
    root->ch_cnt = tch;

    for (i = 0; i < tch; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name :";
        cin >> root->child[i]->label;
        cout << "Enter no of sections in chapter " << root->child[i]->label << " : ";
        cin >> root->child[i]->ch_cnt;
        for (j = 0; j < root->child[i]->ch_cnt; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter subsection " << j + 1 << " name  :";
            cin >> root->child[i]->child[j]->label;
        }
    }
}

void BookTree ::display(node *r1)
{
    int i, j, k, tch;
    if (r1 != NULL)
    {
        cout << "Book Tree Hierarchy" << endl;
        tch = r1->ch_cnt;
        for (i = 0; i < tch; i++)
        {
            cout << "\nChapter " << i + 1 <<":" ;
            cout << " " << r1->child[i]->label;
            cout << "\nSection";
            for (j = 0; j < r1->child[i]->ch_cnt; j++)
            {
                cout<<"\n"<<r1->child[i]->child[j]->label;
            }
        }
    }
}

int main()
{
    BookTree b;
    int ch;
    bool flag = true;

    while (flag)
    {
        cout << "\n1.Write Data for Tree\n2.Display Tree\n3.Exit" << endl;
        cout << "Enter your choice :";
        cin >> ch;

        switch (ch)
        {
        case 1:
            b.create_tree();
            break;

        case 2:
            b.display(root);
            break;

        case 3:
            cout << "Exitting Program!!" << endl;
            flag = false;
            break;

        default:
            cout << "Wrong choice entere !!" << endl;
            break;
        }
    }
    return 0;
}