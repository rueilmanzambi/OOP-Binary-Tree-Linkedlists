// Rueil Manzambi
// hpp file for header file mybstree.h



#include <iostream>

using namespace std;


template <typename T>
MyBSTree<T>::MyBSTree()
{
  m_root = NULL;
  m_size = 0;
}

template <typename T>
TreeNode<T>* MyBSTree<T>::clone(const TreeNode<T>* t)
{
  if (t == NULL)
    return NULL;
  else{
    return new TreeNode<T>(t->m_data,clone(t->m_left),clone(t->m_right));
 }
}


template <typename T>
MyBSTree<T>::~MyBSTree()
{
  clear();
    delete m_root;
}

template <typename T>
MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T>& rhs)
{
  clear();
  if (rhs.m_root == NULL)
    m_root = NULL;
  else{
    m_root=clone(rhs.m_root);
  }
  return *this;
}

template<typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& copy)
{
  m_root = NULL;
  *this = copy;
}

template <typename T>
int MyBSTree<T> :: size()const
{
  return m_size;
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
  if (m_root == NULL)
    return true;
  else
    return false;
}

template <typename T>
int MyBSTree<T>:: height() const
{
  TreeNode<T>* temp = m_root;
  if (m_root == NULL)
    return 0;
  else if (m_root->m_left == NULL && m_root->m_right == NULL)
    return 1;
  else
  {
    return height_helper(temp);
  }

}

template <typename T>
int MyBSTree<T>:: height_helper(TreeNode<T>* &root) const
{
  int left;
  int right;
  if (root == NULL)
    return 0;
  left = height_helper(root->m_left);
  right = height_helper(root->m_right);
  if (left > right)
    return 1+left;
  else
    return 1+right;
}

template <typename T>
const T& MyBSTree<T>::getMax() const throw (Oops)
{
  Oops error("OOPS! : Tree is Empty!!");
  if (isEmpty())
    throw(error);

  TreeNode<T>* temp = m_root;
   return getMaxHelper(temp);
}


template <typename T>
const T& MyBSTree<T>::getMaxHelper(TreeNode<T>* &root) const
{
  if (root->m_right==NULL)
    return root->m_data;
  else
    return getMaxHelper(root->m_right);
}

template <typename T>
const T& MyBSTree<T>::getMin() const throw (Oops)
{
  Oops error("OOPS! : Tree is Empty!!");
  if (isEmpty())
    throw(error);
  return recursive_getMin( m_root );
}

template <typename T>
int MyBSTree<T> :: find(const T&x) const
{
  if (isEmpty())
    return -1;
  else{
    TreeNode<T>* temp = m_root;
    T data = x;
    int countPlace = 0;
    return find_helper(temp, data, countPlace);
  }
}

template <typename T>
int MyBSTree<T>::find_helper(TreeNode<T>* &root, T &data, int &place) const
{
  place++;
  if (root->m_data == data )
    return place;
  if (data < root->m_data )
  {
    if (root->m_left == NULL)
      return (place + 1) * -1;
    else
      return find_helper(root->m_left, data,place);
  }
  else
  {
    if (root->m_right==NULL)
      return (place + 1) * -1;
    else
      return find_helper(root->m_right, data,place);
  }
}

template <typename T>
void MyBSTree<T>::clear()
{
  if (isEmpty())
    return;
  else
    clear_helper(m_root);
  m_root = NULL;
  m_size = 0;
  return;
}

template <typename T>
void MyBSTree<T>::clear_helper(TreeNode<T>* &root)
{
  if (root==NULL)
    return;
  clear_helper(root->m_left);
  clear_helper(root->m_right);
  delete root;
}

template <typename T>
void MyBSTree<T>::insert(const T&x)
{
  insert_helper(m_root, x);
  m_size++;
  return;
}

template <typename T>
void MyBSTree<T>::insert_helper(TreeNode<T>* &root, const T &data)
{
  if ( root == NULL )
    root = new TreeNode<T>(data);
  else{
    if ( data < root->m_data )
      insert_helper( root->m_left , data);
    else if ( data > root->m_data )
      insert_helper( root->m_right, data);
     }
     return;
}


template <typename T>
void MyBSTree<T>:: remove(const T& x)
{
  remove_helper(m_root, x);
  m_size--;
  return;
}

template <typename T>
void MyBSTree<T>::remove_helper(TreeNode<T>* &root, const T &data)
{
  if( root==NULL )
    return;
  if( data < root->m_data)
    remove_helper( root->m_left, data);
  else if ( data > root->m_data)
    remove_helper( root->m_right, data);
  else
  {
     if (root->m_left == NULL && root->m_right == NULL){
       delete root;
       root = NULL;
     }
     else if (root->m_left == NULL || root->m_right == NULL){

       TreeNode<T>* child = root->m_left;
       if ( child == NULL )
         child = root->m_right;
       delete root;
       root = child;
     }
     else
     {
       root->m_data = getMaxHelper( root->m_left );
       remove_helper( root->m_left, root->m_data );
     }
  }
}


template <typename T>
void MyBSTree<T>::prettyPrint(const TreeNode<T>* t, int pad) const
{
  string s(pad, ' ');
  if (t == NULL)
    cout << endl;
  else{
    prettyPrint(t->m_right, pad+4);
    cout << s << t->m_data << endl;
    prettyPrint(t->m_left, pad+4);
  }
  return;
}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  TreeNode<T>* temp = m_root;
  printPreOrderHelper(temp);
  return;
}

template <typename T>
void MyBSTree<T>::printPreOrderHelper(TreeNode<T>* &root) const
{
  if (root == NULL)
    return;
  cout << root->m_data << " ";
  printPreOrderHelper(root->m_left);
  printPreOrderHelper(root->m_right);
  return;
}

template<typename T>
void MyBSTree<T>::printPostOrder() const
{
  TreeNode<T>* temp = m_root;
  printPostOrderHelper(temp);
  return;
}

template<typename T>
void MyBSTree<T>::printPostOrderHelper(TreeNode<T>* &root) const
{
  if (root == NULL)
    return;
  printPostOrderHelper(root->m_left);
  printPostOrderHelper(root->m_right);

  cout << root->m_data << " ";
  return;
}


template <typename T>
void MyBSTree<T>::print() const
{
  prettyPrint(m_root, 0);
  return;
}


