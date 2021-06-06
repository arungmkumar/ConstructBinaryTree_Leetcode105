#include <iostream>
#include <vector>

using namespace std;


struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode* build(vector<int>& preorder, int& p, vector<int>& inorder, int start, int end)
{

	//base condition

	if (p >= preorder.size()) return nullptr;
	if (end<start || start >end) return nullptr;

	TreeNode* root = new TreeNode(preorder[p]);
	
	//find the index of root ininorder
	int rootIndex;
	for (int i = 0; i<inorder.size(); i++)
	{
		if (inorder[i] == preorder[p])
		{
			rootIndex = i;
		}
	}

	p++;
	root->left = build(preorder, p , inorder, start, rootIndex - 1);
	
	root->right = build(preorder, p, inorder, rootIndex + 1, end);
	
	
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	int p = 0;
	int start = 0;
	int end = inorder.size() - 1;
	return build(preorder, p, inorder, start, end);
}

/*
[3,1,2,4]
[1,2,3,4]
Output
[3,1,2,null,2,null,4]
Expected
[3,1,4,null,2]
*/

int main()
{
	vector<int> preorder = { 3, 9, 20, 15, 7 };
	vector<int> inorder = { 9, 3, 15, 20, 7 };


	/*
	[3,9,20,15,7]
[9,3,15,20,7]*/
	TreeNode* root = buildTree(preorder, inorder);
	return 0;
}

