#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#define red 0
#define black 1

/*!
 * \brief Структура красно-черного дерева
 *
 * Данная структура представляет из себя набор переменных для работы с данными красно-черного дерева.
 */
 
struct Node
{
    int key; ///< Значение узла
    bool color; ///< Цвет узла
    Node *left; ///< Указатель на левого потомка
    Node *right; ///< Указатель на правого потомка
    Node *parent; ///< Указатель на родителя
    Node(int key) {
    this->key = key;
    color = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}
};

/*!
 * \brief Класс красно-черного дерева
 *
 * Данный класс представляет из себя набор методов для работы с красно-черным деревом.
 */
 
class RedBlackTree
{
    private:
        Node *root; ///< Корень дерева
    public:
        RedBlackTree(){
            root = nullptr;
        };
        void leftRotate(Node *&); // 
        void rightRotate(Node *&);
        void insertFixUp(Node *&);
        Node* insert(Node *&, Node *&);
        void insertValue(int);
        int searchKey(int);
        int IterativeSearch(Node *&, int);
        void functionOfNLR(Node *&);
        void NLR();
};

/*!
 * \brief Загрузка
 * \param argument Аргумент из консоли
 */
void load(std::string argument);
