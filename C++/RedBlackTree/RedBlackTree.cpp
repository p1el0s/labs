#include "RedBlackTree.h"

/*!
 * \brief Балансировка
 * \param TreeZ Узел на балансировку
 */

void RedBlackTree::insertFixUp(Node *&TreeZ) {
    while (TreeZ != nullptr && TreeZ->parent != nullptr && TreeZ->color == red && TreeZ->parent->color == red) {
        Node *parent = TreeZ->parent;
        Node *grandfather = parent->parent;
        if (parent == grandfather->left) {
            Node *uncle = grandfather->right;
            if (uncle != nullptr && uncle->color == red) { // Case 1 uncle - red
                uncle->color = black;
                parent->color = black;
                grandfather->color = red;
                TreeZ = grandfather;
            } else {         
                if (TreeZ == parent->right) {  // Case 2 uncle - black, z - right parent
                    TreeZ = parent;
                    leftRotate(parent);
                }
                TreeZ->parent->color = black;
                grandfather->color = red;
                rightRotate(grandfather);
                
            }
        } else {
            Node *uncle = grandfather->left;
            if (uncle != nullptr && uncle->color == red) {
                uncle->color = black;
                parent->color = black;
                grandfather->color = red;
                TreeZ = grandfather;
            } else { // Case 3 uncle - black, z - left parent
                if (TreeZ == parent->left) {
                    TreeZ = parent;
                    rightRotate(parent);
                }
                TreeZ->parent->color = black;
                grandfather->color = red;
                leftRotate(grandfather);
            }
        }
    }
    root->color = black;
}

/*!
 * \brief Вставка
 * \param root Корень дерева
 * \param TreeZ Узел для вставки
 * \return Корень дерева
 */

Node* RedBlackTree::insert(Node *&root, Node *&TreeZ) {
    Node *TreeY = nullptr;
    Node *TreeX = root;
    while (TreeX != nullptr) {
        TreeY = TreeX;
        if (TreeZ->key < TreeX->key)
            TreeX = TreeX->left;
        else TreeX = TreeX->right;
    }
    TreeZ->parent = TreeY;
    if (TreeY == nullptr)
        root = TreeZ;
    else if (TreeZ->key < TreeY->key)
        TreeY->left = TreeZ;
    else TreeY->right = TreeZ;
    TreeZ->left = nullptr;
    TreeZ->right = nullptr;
    TreeZ->color = red;
    return root;
}

/*!
 * \brief Вставка значения
 * \param key Число
 */

void RedBlackTree::insertValue(int key) {
    Node *node = new Node(key);
    root = insert(root, node);
    insertFixUp(node);
}

/*!
 * \brief Правый поворот
 * \param TreeX Узел для правого поворота
 */

void RedBlackTree::rightRotate(Node *&TreeX) {
    Node *TreeY = TreeX->left;
    TreeX->left = TreeY->right;
    if (TreeX->left != nullptr)
        TreeX->left->parent = TreeX;
    TreeY->parent = TreeX->parent;
    if (TreeX->parent == nullptr)
        root = TreeY;
    else if (TreeX == TreeX->parent->left)
        TreeX->parent->left = TreeY;
    else
        TreeX->parent->right = TreeY;
    TreeY->right = TreeX;
    TreeX->parent = TreeY;
}

/*!
 * \brief Левый поворот
 * \param TreeX Узел для левого поворота
 */

void RedBlackTree::leftRotate(Node *&TreeX) {
    Node *TreeY = TreeX->right;
    TreeX->right = TreeY->left;
    if (TreeX->right != nullptr)
        TreeX->right->parent = TreeX;
    TreeY->parent = TreeX->parent;
    if (TreeX->parent == nullptr)
        root = TreeY;
    else if (TreeX == TreeX->parent->left)
        TreeX->parent->left = TreeY;
    else
        TreeX->parent->right = TreeY;
    TreeY->left = TreeX;
    TreeX->parent = TreeY;
}

/*!
 * \brief Вывод дерева
 * \param TreeX Узел для вывода дерева
 */

void RedBlackTree::functionOfNLR(Node *&TreeX) {
    if (TreeX == nullptr)
        return;
    if (TreeX->parent == nullptr) {
        std::cout << "This Node is root - " << TreeX->key << " " << ", color - ";
        if (TreeX->color == 0) std::cout << "red" << std::endl;
        else std::cout << "black" << std::endl;
    }
    else { if (TreeX->left == nullptr && TreeX->right == nullptr) {
        std::cout << "This Node has leaf - " << TreeX->key << " " << ", color - ";
        if (TreeX->color == 0) std::cout << "red" << std::endl;
        else std::cout << "black" << std::endl;
    }
    else {
        std::cout << "This Node hasn't leaf - " << TreeX->key << " " << ", color - ";
        if (TreeX->color == 0) std::cout << "red" << std::endl;
        else std::cout << "black" << std::endl;
    }}
    functionOfNLR(TreeX->left);
    functionOfNLR(TreeX->right);
}

/*!
 * \brief Запуск вывода дерева
 */

void RedBlackTree::NLR() {
    functionOfNLR(root);
}

/*!
 * \brief Поиск значения
 * \param key Число
 * \return Найденное значение
 */

int RedBlackTree::searchKey(int key) {
    return IterativeSearch(root, key);
}

/*!
 * \brief Итеративный поиск значения
 * \param TreeX Узел для поиска
 * \param key Число
 * \return Найденное значение
 */

int RedBlackTree::IterativeSearch(Node *&TreeX, int key) {
    if (TreeX == nullptr || key == TreeX->key)
        return TreeX->key;
    if (key < TreeX->key)
        return IterativeSearch(TreeX->left, key);
    else return IterativeSearch(TreeX->right, key);
}

void load(std::string argument) {
    bool find = true;
    int e = 0;
    std::ifstream file;

    RedBlackTree a;
    file.open(argument);
    int i = 0, c = 0;
    while (file >> i) {
        a.insertValue(i);
    }
    a.NLR();
    while (find == true) {
        std::cout << "Type number for search - ";
        std::cin >> i;
        int b = a.searchKey(i);
        std::cout << "Here is your number - " << b;
        std::cout << "\nDo you want to continue?\nType 1 for yes, 0 for no.\n";
        std::cin >> e;
        if (e == 0) break;
    } 
};