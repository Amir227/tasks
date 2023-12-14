#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
};

int Main_Root(TreeNode *root);
int Main_Root_1(TreeNode *root, int level);

TreeNode *read_tree(istream &in)
{
    int value;
    map<string, TreeNode *> nodes;
    cout << "Please input Tree root" << endl;
    cin >> value;
    nodes["root"] = new TreeNode();
    nodes["root"]->value = value;
    // ..
    // parent direction(left,right) value(int) name
    cout << "Please input tree" << endl;
    while (!in.eof()) {
        string parent;
        string direction;
        int value;
        string name;
        in >> parent >> direction >> value >> name;
        if (name.empty()) {
            break;
        }
        TreeNode *parentNode = nodes.at(parent);
        TreeNode *newNode = new TreeNode();
        newNode->value = value;
        if (direction == "left") {
            parentNode->left = newNode;

        } else if (direction == "right") {
            parentNode->right = newNode;
        } else {
            cout << "ERROR" << direction << endl;
        }
        if (nodes.find(name) != nodes.end()) {
            cout << "Ошибка имя не уникально" << endl;
        }
        nodes[name] = newNode;
    }
    return nodes["root"];
}


int Tree_Sum(TreeNode *root, int val)
{
    if (root == nullptr){
        return 0;
    }
    val = (val*10 + root->value);
    if (root->left==nullptr && root->right==nullptr){
        return val;
    }
    return Tree_Sum(root->left, val) + Tree_Sum(root->right, val);

}

int Tree_Sum_last(TreeNode* root){
    int a = Tree_Sum(root, 0);
    return a;
}

void Clear_Tree(TreeNode* root){
    if (root != nullptr){
        Clear_Tree(root->left);
        Clear_Tree(root->right);
    }
    delete root;
}

int main()
{

    TreeNode *tree = read_tree(cin);
    int ans = Tree_Sum_last(tree);
    cout << "Ответ:  " << ans << endl;
    Clear_Tree(tree);
    return 0;
}