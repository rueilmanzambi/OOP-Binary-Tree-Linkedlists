/*  _____________________________
 * /                             \
 * | Binary Search Tree Tester   |
 * \_____________________________/
 *
 * @C - Galaxy Express Software
 *
 * Version 21.3.0
 * 
 * Purpose: Tests 'MyBSTree', an implementation of a Binary Search Tree.
 * 
 */
#include <iostream>
#include "mybstree.h"
using namespace std;


//------------------------------------------------------
void test1()
{
  MyBSTree<int> t;
  
  cout << endl << endl << "***** " << "Test #1" << endl;
  
  t.print();
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
    
  cout << "--" << endl;

  t.insert(7);
  t.insert(5);
  t.insert(9);
  t.insert(4);
  t.insert(6);
  t.insert(13);
  t.insert(10);

  
  t.print();
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
  cout << "--" << endl;
  cout << "height = " << t.height() << endl;
  cout << "size = " << t.size() << endl;
  cout << "--" << endl;

  return;
}


//------------------------------------------------------
void test2()
{
  MyBSTree<char> t;
  
  cout << endl << endl << "***** " << "Test #2" << endl;
  
  t.insert('F');
  t.insert('A');
  t.insert('C');
  t.insert('G');
  t.insert('B');
  t.insert('S');
  t.insert('K');
  t.insert('U');
  t.insert('L');
  t.insert('K');
  
  t.print();
  cout << "--" << endl;
  cout << "Min = " << t.getMin() << endl;
  cout << "Max = " << t.getMax() << endl;
	cout << "Find K? " << t.find('K') << endl;
	cout << "Find F? " << t.find('F') << endl;
	cout << "Find M? " << t.find('M') << endl;
	cout << "Find D? " << t.find('D') << endl;


  return;
}


//------------------------------------------------------
void test3()
{
  MyBSTree<string> t;
  MyBSTree<string> t2;
  
  cout << endl << endl << "***** " << "Test #3" << endl;

  t.insert(string("Paul"));
  t.insert(string("John"));
  t.insert(string("George"));
  t.insert(string("Ringo"));
  t.insert(string("Fry"));
  t.insert(string("Leela"));
  t.insert(string("Zoidberg"));

  
  t.print();
  cout << "--" << endl;
  cout << "Testing Operator= " << endl;
  t2 = t;
  t2.print();
  
  cout << "--" << endl;
  cout << "Is it a deep copy? " << endl;
  t2.remove(string("George"));
  t2.remove(string("John"));
  t2.remove(string("Ringo"));
  cout << "-- copy:" << endl;
  t2.print();
  cout << "-- original:" << endl;
  t.print();

  return;
}


//------------------------------------------------------
void test4()
{
  MyBSTree<string> t;
  
  cout << endl << endl << "***** " << "Test #4" << endl;

  t.insert(string("Pizza"));
  t.insert(string("Burger"));
  t.insert(string("HotDog"));
  t.insert(string("Shake"));
  t.insert(string("Fry"));
  t.insert(string("Salad"));
  t.insert(string("Soda"));

  
  t.print();
  cout << "--" << endl;
  cout << "Testing Copy Constructor " << endl;
  MyBSTree<string> t2(t);
  t2.print();
  
  cout << "--" << endl;
  cout << "Is it a deep copy? " << endl;
  t2.remove(string("Pizza"));
  t2.remove(string("Salad"));
  t2.remove(string("Fry"));
  cout << "-- copy:" << endl;
  t2.print();
  cout << "-- original:" << endl;
  t.print();

  return;
}

void test5()
{
  MyBSTree<int> t;
  
  cout << endl << endl << "***** " << "Test #5" << endl;
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;  
  cout << "--" << endl;
  
  try {
    t.getMin();
  }
  catch (Oops err)
  {
    cout << err.getMsg() << endl;
  }

  try {
    t.getMax();
  }
  catch (Oops err)
  {
    cout << err.getMsg() << endl;
  }

  return;
}


//------------------------------------------------------
void test6()
{
  MyBSTree<int> t;
  
  cout << endl << endl << "***** " << "Test #6" << endl;
 
  cout << "--" << endl;

  t.insert(7);
  t.insert(5);
  t.insert(9);
  t.insert(4);
  t.insert(6);
  t.insert(13);
  t.insert(10);

  
  t.print();
  
  cout << "--" << endl;
  cout << "Pre Order:" << endl;
  t.printPreOrder();
  cout << endl;
  
  cout << "--" << endl;
  cout << "Post Order" << endl;
  t.printPostOrder();
  cout << endl;

  return;
}

//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
int main ()
{
  cout << "Hello Tree Tester!! " << endl;

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
    
  return 0; 
}



