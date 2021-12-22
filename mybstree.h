// Rueil Manzambi
// Header file for derived tree class




#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <iostream>
#include "abstractbstree.h"

using namespace std;


template <typename T>
class TreeNode
{
public:
   T m_data;
   TreeNode<T>* m_right;
   TreeNode<T>* m_left;
   TreeNode(T data):m_data(data){m_right = NULL; m_left = NULL;};
   TreeNode(T data, TreeNode<T>* left, TreeNode<T>* right):m_data(data), m_right(right), m_left(left){};
   TreeNode():m_right(NULL), m_left(NULL){};
};


template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
    TreeNode<T>* m_root;
    int m_size;

    const T& recursive_getMin( TreeNode<T>* t ) const {
      if ( t->m_left == NULL )
        return t->m_data;
      else
        return recursive_getMin( t->m_left );
    }
    int height_helper(TreeNode<T>* &root) const;
    const T& getMaxHelper(TreeNode<T>* &root) const;
    int find_helper(TreeNode<T>* &root, T &data, int& place) const;
    void clear_helper(TreeNode<T>* &root);
    void insert_helper(TreeNode<T>* &root, const T& data);
    void remove_helper(TreeNode<T>* &root, const T& data);
    void prettyPrint (const TreeNode<T>* t, int pad) const;
    TreeNode<T>* clone(const TreeNode<T>* t);
    void printPreOrderHelper(TreeNode<T>* &root) const;
    void printPostOrderHelper(TreeNode<T>* &root) const;

  public:

    MyBSTree();
    ~MyBSTree();
    MyBSTree<T>& operator=(const MyBSTree<T>& rhs);
    MyBSTree(const MyBSTree<T>& copy);
    int size() const;
    bool isEmpty() const;
    int height() const;
    const T& getMax() const throw (Oops);
    const T& getMin() const throw (Oops);
    int find(const T& x) const;
    void clear();
    void insert(const T& x);
    void remove(const T& x);
    void printPreOrder() const;
    void printPostOrder() const;
    void print() const;

};


#include "mybstree.hpp"
#endif

