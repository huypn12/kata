// Example implementation of RB tree with test, later generalize to Generic RBTree.h in competitive/datastructure

struct RbTreeNode {
    int val;
    struct RbTreeNode *parent;
    struct RbTreeNode *left;
    struct RbTreeNode *right;
};

struct RbTree {
    struct RbTreeNode *head;
};


extern struct RbTreeNode *createRbTreeNode(int val);
extern struct RbTreeNode *deleteRbTreeNode(int val);
extern void insertRbTreeNode(int val);
extern void removeRbTreeNode(int val);
extern struct RbTreeNode *findRbTreeNode(struct RbTreeNode *head);


struct RbTreeNode *createRbTreeNode(int val)
{
    
}
