#include <optional>
#include <cassert>

struct Node
{
    int val;
    Node* left;
    Node* right;
};

/*
        100
        / \
      50   200
      /  \
         1000
*/

bool helper(Node* node, const std::optional<int>& min, const std::optional<int>& max)
{
    if (!node) {
        return true;
    }
    if (min.has_value() && node->val < min.value()) {
        return false;
    }
    if (max.has_value() && node->val > max.value()) {
        return false;
    }
//spasibo! ;)
    return helper(node->left, min, node->val) && helper(node->right, node->val, max);
}

bool isBST(Node* root)
{
    return helper(root, std::nullopt, std::nullopt);
}

Node* buildInvalidTree()
{
    Node* root = new Node{100};
    root->left = new Node{50};
    root->right = new Node{200};
    root->left->right = new Node{1000};
    return root;
}

Node* buildValidTree()
{
    Node* root = new Node{100};
    root->left = new Node{50};
    root->right = new Node{200};
    root->left->right = new Node{60};
    return root;
}


int main()
{
    {
        Node* root = buildInvalidTree();
        assert(isBST(root) == false);
    }
    {
        Node* root = buildValidTree();
        assert(isBST(root) == true);
    }
    
    {
        assert(isBST(nullptr) == true);
    }
}
