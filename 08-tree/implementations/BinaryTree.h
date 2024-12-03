#pragma once
#include <iostream>
#include <queue> 

template <typename T>
class BinaryTree {
private:
    struct node {
        T data;
        node* left;
        node* right;

        node(T data = T(), node* left = nullptr, node* right = nullptr)
            : data(data), left(left), right(right) {};
    };

public:
    BinaryTree();
    BinaryTree(T data, const BinaryTree& left = BinaryTree(), const BinaryTree& right = BinaryTree());
    BinaryTree(const BinaryTree& other);
    BinaryTree& operator=(const BinaryTree& other);
    ~BinaryTree();

    bool empty() const;
    bool find(const T& key) const;
    void insert(const T& key);
    bool remove(const T& key);
    size_t get_size() const;
    size_t get_height() const;

    template <typename Function>
    void map(const Function& f);

    void print_in_order() const { print_in_order(root); }
    void print_pre_order() const { print_pre_order(root); }
    void print_post_order() const { print_post_order(root); }

    void trim() { trim(root); }
    void bloom() { bloom(root); };

private:
    static void clear(node* root);
    static node* copy(node* root);

    static bool find(const node* root, const T& key);
    static node* insert(node* root, const T& key);
    static node* remove(node* root, const T& key, bool& removed);
    static size_t height(const node* root);

    template <typename Function>
    static void map(const Function& f, node* root);

    void print_in_order(const node* root) const;
    void print_pre_order(const node* root) const;
    void print_post_order(const node* root) const;

    void trim(node*& root);
    void bloom(node* root);

private:
    node* root;
    size_t size;
};

template <typename T>
BinaryTree<T>::BinaryTree()
    : root(nullptr), size(0) {}

template <typename T>
BinaryTree<T>::BinaryTree(T data, const BinaryTree& left, const BinaryTree& right)
    : root(new node(data, copy(left.root), copy(right.root))), size(1 + left.size + right.size) {}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other)
    : root(copy(other.root)), size(other.size) {}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other) {
    if (this != &other) {
        clear(root);
        root = copy(other.root);
        size = other.size;
    }
    return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}

template <typename T>
bool BinaryTree<T>::empty() const {
    return root == nullptr;
}

template <typename T>
bool BinaryTree<T>::find(const T& key) const {
    return find(root, key);
}

template <typename T>
void BinaryTree<T>::insert(const T& key) {
    root = insert(root, key);
    ++size;
}

template <typename T>
bool BinaryTree<T>::remove(const T& key) {
    bool removed = false;
    root = remove(root, key, removed);
    if (removed) --size;
    return removed;
}

template <typename T>
size_t BinaryTree<T>::get_size() const {
    return size;
}

template <typename T>
size_t BinaryTree<T>::get_height() const {
    return height(root);
}

template <typename T>
template <typename Function>
void BinaryTree<T>::map(const Function& f) {
    map(f, root);
}

// Private methods
template <typename T>
void BinaryTree<T>::clear(node* root) {
    if (!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
}

template <typename T>
typename BinaryTree<T>::node* BinaryTree<T>::copy(node* root) {
    if (!root) return nullptr;
    return new node(root->data, copy(root->left), copy(root->right));
}

template <typename T>
bool BinaryTree<T>::find(const node* root, const T& key) {
    if (!root) return false;
    if (root->data == key) return true;
    return find(root->left, key) || find(root->right, key);
}

template <typename T>
typename BinaryTree<T>::node* BinaryTree<T>::insert(node* root, const T& key) {
    if (!root) return new node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

template <typename T>
typename BinaryTree<T>::node* BinaryTree<T>::remove(node* root, const T& key, bool& removed) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = remove(root->left, key, removed);
    }
    else if (key > root->data) {
        root->right = remove(root->right, key, removed);
    }
    else {
        removed = true;
        if (!root->left) {
            node* right_child = root->right;
            delete root;
            return right_child;
        }
        else if (!root->right) {
            node* left_child = root->left;
            delete root;
            return left_child;
        }
        else {
            node* successor = root->right;
            while (successor->left) successor = successor->left;
            root->data = successor->data;
            root->right = remove(root->right, successor->data, removed);
        }
    }
    return root;
}

template <typename T>
size_t BinaryTree<T>::height(const node* root) {
    if (!root) return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

template<typename T>
inline void BinaryTree<T>::print_in_order(const node* root) const {
    if (!root)
        return;

    print_in_order(root->left);
    std::cout << root->data << " ";
    print_in_order(root->right);
}

template<typename T>
inline void BinaryTree<T>::print_pre_order(const node* root) const {
    if (!root)
        return;

    std::cout << root->data << " ";
    print_pre_order(root->left);
    print_pre_order(root->right);
}

template<typename T>
inline void BinaryTree<T>::print_post_order(const node* root) const {
    if (!root)
        return;

    print_post_order(root->left);
    print_post_order(root->right);
    std::cout << root->data << " ";
}

template<typename T>
inline void BinaryTree<T>::trim(node*& root) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        delete root;
        root = nullptr;
    }
    else {
        trim(root->left);
        trim(root->right);
    }
}

template<typename T>
inline void BinaryTree<T>::bloom(node* root) {
    if (!root)
        return;

    if (!root->left && !root->right) {
         root->left = new node(root->data);
         root->right = new node(root->data);
    }
    else {
        bloom(root->left);
        bloom(root->right);
    }
}

template <typename T>
template <typename Function>
void BinaryTree<T>::map(const Function& f, node* root) {
    if (!root) return;
    f(root->data);
    map(f, root->left);
    map(f, root->right);
}

