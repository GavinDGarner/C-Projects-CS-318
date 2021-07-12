//Gavin Garner CS 318
// Trees (They are in them)
// We will be inserting data into trees and manipulating that data

// Include Libraries
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// CONSTANTS & STRUCTS
ifstream inf;
ofstream outf;

struct NodeGen
{
    NodeGen *GoLeft; // a pointer to take us left
    NodeGen *GoRight; // a pointer to take us right

    int val;
};
    NodeGen *root; // This is the beginning of the tree

// PROTOTYPES

void Insert(NodeGen *cur, int number); // Puts values in tree
NodeGen* MakeNewNode(); // creates empty nodes
void PrintInOrderTree(NodeGen *node, int &nbr); // Prints the tree in order
void PrintPreOrderTree(NodeGen *node, int &nbr); //
void PrintPostOrderTree(NodeGen *node, int &nbr); //
void Write(string message);
void TreeSum(NodeGen *node, float &total);
void LeafSum(NodeGen *node, float &total, float &NumLeaf);
void OneChild(NodeGen *node);
void PrintLeftTree(NodeGen *node);
void PrintRightTree(NodeGen *node);
void Dig(NodeGen *node, int depth, int &maxDepth, int &res);

int deepestNode(NodeGen *node);

int main()
{

    inf.open("TreeData.txt");
    outf.open("Results.txt");
    int temp = 0;
    int NumNodes = 0; // Total Nodes in tree
    float NumLeaf = 0;
    float total = 0;

    while(inf >> temp)
    {
        NumNodes++;
        Insert(root, temp);
    }

    temp = 0;
    Write("In Order Tree List:");
    PrintInOrderTree(root, temp);
    Write("\n");

    temp = 0;
    Write("Pre Order Tree List:");
    PrintPreOrderTree(root, temp);
    Write("\n");

    temp = 0;
    Write("Post Order Tree List:");
    PrintPostOrderTree(root, temp);
    Write("\n");

    Write("Number of Nodes Values in Tree: ");
    cout << NumNodes;
    outf << NumNodes;
    Write("\n");

    Write("Sum and Average of All Values");
    TreeSum(root, total);
    cout << "Sum: " << total << endl;
    cout << "Average: " << setprecision(3) << fixed << total/NumNodes << endl;
    outf << "Sum: " << total << endl;
    outf << "Average: " << setprecision(3) << fixed << total/NumNodes << endl;

    Write("\nAverage of Leaves");
    total=0;
    LeafSum(root, total, NumLeaf);
    cout << "Average: " << setprecision(3) << fixed << total/NumLeaf << endl;
    outf << "Average: " << setprecision(3) << fixed << total/NumLeaf << endl;

    Write("\nDeepest Node Value:");
    total = deepestNode(root);
    cout << setprecision(0) << fixed << total << endl;
    outf << setprecision(0) << fixed << total << endl;


    Write("\nNodes that have One Child: ");
    OneChild(root);
    Write("\n");

    Write("All numbers to the Left of the Root");
    PrintLeftTree(root);
    Write("\n");

    Write("All numbers to the Right of the Root");
    PrintRightTree(root);
    Write("\n");


    inf.close();
    outf.close();
    return 0;
}

void Write(string message)
{
    cout << message << "\n";
    outf << message << "\n";
    return;
}

void Insert(NodeGen *cur, int number) // Put a node into the tree
{
    cur = root; // start at the root
    NodeGen *prev; // follow our pointer so we can link the tree
    prev = NULL;


    while (cur != NULL) // while there is something to read
    {
        prev = cur; // update our following pointer

        if (number > (*cur).val)
            cur = (*cur).GoRight; // Bigger numbers go right
        else
            cur = (*cur).GoLeft; // Smaller numbers go left
    }

    // Create the new node and input the value
    cur = MakeNewNode();
    (*cur).val = number; // populate the new node

    // Now let's add it to the list
    if(prev != NULL)
    {
        if (number > (*prev).val)// If bigger then its on right else its on the left
            (*prev).GoRight = cur;
        else
            (*prev).GoLeft = cur;
    }
    else
        root = cur; // if previous DNE then we need to establish our root

    return;
}

NodeGen* MakeNewNode() // Making empty nodes for the tree
{
    NodeGen *T;
    T = new NodeGen;
    (*T).val = 0;
    (*T).GoLeft = NULL;
    (*T).GoRight = NULL;

    return T;
}

void PrintInOrderTree(NodeGen *node, int &nbr) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf
    nbr++;
    if (nbr < 25)
    {
    PrintInOrderTree((*node).GoLeft, nbr);
    }

    cout << (*node).val << " ";
    outf << (*node).val << " ";

    if (nbr < 25)
    {
    PrintInOrderTree((*node).GoRight, nbr);
    }

    return;
}

void PrintPreOrderTree(NodeGen *node, int &nbr) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf

    nbr++;
    if( nbr < 26 )
    {
    cout << (*node).val << " ";
    outf << (*node).val << " ";

    PrintPreOrderTree((*node).GoLeft, nbr);
    PrintPreOrderTree((*node).GoRight, nbr);
    }

    return;
}

void PrintPostOrderTree(NodeGen *node, int &nbr) // Let's use some recursion
{

    if (node ==  NULL)
        return; // We have reached a leaf

        nbr++;
    if(nbr < 26)
    {
    PrintPostOrderTree((*node).GoLeft, nbr);
    PrintPostOrderTree((*node).GoRight, nbr);
    cout << (*node).val << " ";
    outf << (*node).val << " ";
    }

    return;
}

void TreeSum(NodeGen *node, float &total)
{
    if (node == NULL)
        return;
    total = total + (*node).val;

    TreeSum((*node).GoLeft, total);
    TreeSum((*node).GoRight, total);

    return;
}

void LeafSum(NodeGen *node, float &total, float &NumLeaf)
{
    if (node == NULL)
        return;
    if ((*node).GoLeft == NULL && (*node).GoRight == NULL)
        {
            total = total + (*node).val;
            NumLeaf++;
        }
    LeafSum((*node).GoLeft, total, NumLeaf);
    LeafSum((*node).GoRight, total, NumLeaf);

    return;
}

void Dig(NodeGen *node, int depth, int &maxDepth, int &res)
{
    if (node != NULL)
    {
        Dig((*node).GoLeft, ++depth, maxDepth, res);

        // Update depth and resue
        if (depth > maxDepth)
        {
            res = (*node).val;
            maxDepth = depth;
        }

        Dig((*node).GoRight, depth, maxDepth, res);
    }
    return;
}

// Returns value of deepest node
int deepestNode(NodeGen *node)
{
    // Initialze result and max depth
    int res = -1;
    int maxDepth = -1;

    // Updates value "res" and "maxDepth"

    Dig(node, 0, maxDepth, res);
    return res;
}


void OneChild(NodeGen *node)
{
    if (node == NULL)
        return;

        if((*node).GoLeft != NULL && (*node).GoRight == NULL )
            {
            cout << (*node).val << " ";
            outf << (*node).val << " ";
            }

        if((*node).GoLeft == NULL && (*node).GoRight != NULL )
            {
            cout << (*node).val << " ";
            outf << (*node).val << " ";
            }

    OneChild((*node).GoLeft);
    OneChild((*node).GoRight);

    return;
}

void PrintLeftTree(NodeGen *node) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf

    if ((*node).val > (*root).val)
        return;

    PrintLeftTree((*node).GoLeft);

    if ((*node).val != (*root).val)
    {
    cout << (*node).val << " ";
    outf << (*node).val << " ";
    }

    PrintLeftTree((*node).GoRight);

    return;
}

void PrintRightTree(NodeGen *node) // Let's use some recursion
{
    if (node ==  NULL)
        return; // We have reached a leaf

    if ((*node).val < (*root).val)
        return;

    PrintRightTree((*node).GoLeft);

    if ((*node).val != (*root).val)
    {
    cout << (*node).val << " ";
    outf << (*node).val << " ";
    }

    PrintRightTree((*node).GoRight);

    return;
}
