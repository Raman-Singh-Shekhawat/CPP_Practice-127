// Trees

/*

144. Print Level Wise: Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,…,xn where, N is data of any node present in the generic tree. x1, x2, x3, …., xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.

*/

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void printLevelWise(TreeNode<int> *root)
{

    queue<TreeNode<int> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {

        TreeNode<int> *front = nodes.front();
        nodes.pop();

        cout << front->data << ":";

        for (int i = 0; i < front->children.size(); i++)
        {

            cout << front->children[i]->data;

            if (i < front->children.size() - 1)
            {

                cout << ",";
            }

            nodes.push(front->children[i]);
        }

        cout << endl;
    }
}