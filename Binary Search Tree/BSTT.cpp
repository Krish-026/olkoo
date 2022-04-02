#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long>
#define vvl vector<vl>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define pb push_back
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp make_pair
#define rep(a, b, c) for (long long a = b; a <= c; ++a)
#define repr(a, b, c) for (long long a = b; a >= c; --a)
#define input(a, b, n)                 \
    for (long long i = b; i <= n; ++i) \
        cin >> a[i];
#define output(a, b, n)                \
    for (long long i = b; i <= n; ++i) \
        cout << a[i] << " ";
#define Mod 1000000007
using namespace std;

#define SPACE 10
class TreeNode
{
public:
    int value;
    TreeNode *left, *right;
    TreeNode();          // done Line 146
    TreeNode(int value); // done Line 152
};

class BST
{
public:
    TreeNode *root;
    BST();                                                      // done
    bool isTreeEmpty();                                         // done
    void insertNode(TreeNode *new_node);                        // done
    TreeNode *insertRecursive(TreeNode *r, TreeNode *new_node); // done
    void print2D(TreeNode *r, int space);                       // done
    void printPreorder(TreeNode *r);                            // done
    void printInorder(TreeNode *r);                             // done
    void printPostorder(TreeNode *r);                           // done
    TreeNode *iterativeSearch(int value);                       // done
    TreeNode *recursiveSearch(TreeNode *r, int value);          // done
    int height(TreeNode *r);                                    // done
    void printGivenLevel(TreeNode *r, int level);
    void printLevelOrderBFS(TreeNode *r);
    TreeNode *minValueNode(TreeNode *node); // done
    TreeNode *deleteNode(TreeNode *r, int value);
};

// BST();
BST::BST()
{
    root = NULL;
}

// bool isTreeEmpty();
bool BST::isTreeEmpty()
{
    if (root == NULL)
        return true;
    return false;
}

// void insertNode(TreeNode *new_node);
void BST::insertNode(TreeNode *new_node)
{
    if (root == NULL)
    {
        root = new_node;
        cout << "Insertion successful " << endl;
    }
    else
    {
        TreeNode *temp = root;
        while (temp != NULL)
        {
            if (new_node->value == temp->value)
            {
                cout << "No Duplicate values allowed" << endl;
                return;
            }
            else if ((new_node->value < temp->value))
            {
                if (temp->left == NULL)
                {
                    temp->left = new_node;
                    cout << "Insertion successful " << endl;
                    break;
                }
                temp = temp->left;
            }
            else if ((new_node->value > temp->value))
            {
                if (temp->right == NULL)
                {
                    temp->right = new_node;
                    cout << "Insertion successful " << endl;
                    break;
                }
                temp = temp->right;
            }
        }
    }
}

// TreeNode *insertRecursive(TreeNode *r, TreeNode *new_node);
TreeNode *BST::insertRecursive(TreeNode *r, TreeNode *new_node)
{
    if (r == NULL)
    {
        r = new_node;
        cout << "Insertion Successful" << endl;
        return r;
    }
    if (new_node->value < r->value)
        r->left = insertRecursive(r->left, new_node);
    else if (new_node->value > r->value)
        r->right = insertRecursive(r->right, new_node);
    else
    {
        cout << "No duplicate values allowed" << endl;
    }
    return r;
}

// void print2D(TreeNode *r, int space)
void BST::print2D(TreeNode *r, int space)
{
    if (r == NULL) // Base case  1
        return;
    space += SPACE;           // Increase distance between levels   2
    print2D(r->right, space); // Process right child first 3
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5
        cout << " ";                    // 5.1
    cout << r->value << "\n";           // 6
    print2D(r->left, space);            // Process left child  7
}

// void printPreorder(TreeNode *r);
void BST::printPreorder(TreeNode *r)
{
    if (r == NULL)
        return;
    cout << r->value << " ";
    printPreorder(r->left);
    printPreorder(r->right);
}

// void printInorder(TreeNode *r);
void BST::printInorder(TreeNode *r)
{
    if (r == NULL)
        return;
    printInorder(r->left);
    cout << r->value << " ";
    printInorder(r->right);
}

// void printPostorder(TreeNode *r);
void BST::printPostorder(TreeNode *r)
{
    if (r == NULL)
        return;
    printPostorder(r->left);
    printPostorder(r->right);
    cout << r->value << " ";
}

// TreeNode *iterativeSearch(int value);
TreeNode *BST::iterativeSearch(int value)
{
    if (root == NULL)
        return NULL;
    TreeNode *temp = root;
    while (temp != NULL)
    {
        if (temp->value == value)
            return temp;
        else if (temp->value < value)
            temp = temp->left;
        else
            temp = temp->right;
    }
}

// TreeNode *recursiveSearch(TreeNode *r, int value);
TreeNode *BST::recursiveSearch(TreeNode *r, int value)
{
    if (r->value == value || r == NULL)
        return r;
    else if (r->value > value)
        return recursiveSearch(r->left, value);
    else
        return recursiveSearch(r->right, value);
}

// int height(TreeNode *r);
int BST::height(TreeNode *r)
{
    if (r == NULL)
        return 0;
    return 1 + max(height(r->left), height(r->right));
}

// TreeNode *minValueNode(TreeNode *node);
TreeNode *BST::minValueNode(TreeNode *node)
{
    TreeNode *temp = node;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

int main()
{
    BST obj;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        // Node n1;
        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insertRecursive(obj.root, new_node);
            // obj.insertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
            cin >> val;
            // new_node = obj.iterativeSearch(val);
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            cout << endl;
            //	      cout <<"PRE-ORDER: ";
            //	      obj.printPreorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"IN-ORDER: ";
            //	      obj.printInorder(obj.root);
            //	      cout<<endl;
            //	      cout <<"POST-ORDER: ";
            //	      obj.printPostorder(obj.root);
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);
    return 0;
}

TreeNode::TreeNode()
{
    value = 0;
    left = right = NULL;
}

TreeNode::TreeNode(int val)
{
    value = val;
    left = right = NULL;
}
