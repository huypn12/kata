#define RB_TREE_NODE(KEY_TYPE, VALUE_TYPE) \
    struct RbTreeNode_##KEY_TYPE_##VALUE_TYPE \
    { \
        KEY_TYPE k; \
        VALUE_TYPE v; \
    }