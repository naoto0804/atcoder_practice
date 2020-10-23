// ctrl+shift+b
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll> >;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

// C++ program to demonstrate delete operation in binary search tree
struct node
{
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		// cout<< root->key;
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// Driver Program to test above functions
// void Main()
// {
// 	/* Let us create following BST
// 			50
// 		/	 \
// 		30	 70
// 		/ \ / \
// 	20 40 60 80 */
// 	struct node *root = NULL;
// 	root = insert(root, 50);
// 	root = insert(root, 30);
// 	root = insert(root, 20);
// 	root = insert(root, 40);
// 	root = insert(root, 70);
// 	root = insert(root, 60);
// 	root = insert(root, 80);

//     cout << minValueNode(root)->key << endl;
// 	inorder(root);

// 	cout<<"\nDelete 20\n";
// 	root = deleteNode(root, 20);
// 	inorder(root);

//     cout << minValueNode(root)->key << endl;
// 	cout<<"\nDelete 30\n";
// 	root = deleteNode(root, 30);
// 	cout<<"Inorder traversal of the modified tree \n";
// 	inorder(root);

// 	cout<<"\nDelete 50\n";
// 	root = deleteNode(root, 50);
// 	cout<<"Inorder traversal of the modified tree \n";
// 	inorder(root);
// }

// This code is contributed by shivanisinghss2110


void Main() {
    ll N; cin >> N;
    vector<ll> x(N); rep(i, N){cin >> x.at(i);}

    // construct tree
    struct node *root = NULL;
    vector<int> v(200001); // vector with 100 ints.
    iota(std::begin(v), std::end(v), 0); // Fill with 0, 1, ..., 99.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    random_shuffle(v.begin(), v.end());
    for (auto a: v){
        root = insert(root, a);
    }
    rep(i, N){
        root = deleteNode(root, x.at(i));
    	inorder(root);
        cout << minValueNode(root)->key << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
