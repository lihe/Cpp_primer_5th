## 构造函数

```c++
TreeNode::TreeNode() : value(""), count(1), left(nullptr), right(nullptr) {}
BinStrTree::BinStrTree() : root(nullptr) {}
```

## 拷贝构造函数

```c++
BinStrTree::BinStrTree(const BinStrTree &bst) : root(bst.root){
    root -> CopyTree();          // 应拷贝整棵树，而非仅仅根节点
}

void TreeNode::CopyTree() {
    if (left)
        left -> CopyTree();
    if (right)
        right -> CopyTree();
    count ++;
}

TreeNode::TreeNode(const TreeNode &tn) : value(tn -> value), count(1), left(tn -> left) {
    if (left)
        left -> CopyTree();
    if (right)
        right -> CopyTree();
}
```

## 析构函数

```c++
BinStrTree::~BinStrTree(){
    if (!root -> ReleaseTree())     // 释放整棵树，而非仅仅释放根节点
        delete root;
}

int BinStrTree::ReleaseTree() {
    if (left) {                          // 左子树不空，释放左子树
        if (!left -> ReleaseTree())
            delete left;
    }
    if (right) {                         // 右子树不空，释放右子树
        if (!right -> ReleaseTree())
            delete right;
    }
    count --;
    return count;
}

TreeNode::~TreeNode() {
    if (count) {
        ReleaseTree();
    }
}
```

