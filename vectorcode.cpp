#include <stdio.h>
#include <vector>
#include <iostream>
#include <pthread.h>
#include <algorithm>    // std::find

using namespace std;

template <typename T>
class templatesVector {
public:
  
// ---------------------------------------------------------------
// CONSTRUTOR
// ---------------------------------------------------------------
  templatesVector(){
      cout<< "TEMPLATE CONSTRUTOR" << endl; // PRINT CONSOLE / SCREEN
      pthread_mutex_init( &a_mutex, NULL); // START MUTEX
  }

  
// ---------------------------------------------------------------
// DESCONSTRUTOR
// ---------------------------------------------------------------
  ~templatesVector(){}
 
  
// ---------------------------------------------------------------
// INSERT ONE INFORMATION IN MAP
// ---------------------------------------------------------------
  void insertDadosTemplate(const T &v) {
    pthread_mutex_lock( &a_mutex); //MUTEX LOCK CRITICAL AREA
    myvector.push_back(v); // STL INSERT VECTOR
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  }
  

  
// ---------------------------------------------------------------
// MAP CLEAR
// ---------------------------------------------------------------
  void clearDadosTemplate(){
    pthread_mutex_lock( &a_mutex); //MUTEX LOCK CRITICAL AREA
    myvector.clear(); // REMOVE ALL ELEMENTS/REGISTER VECTOR
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  }
  

// ---------------------------------------------------------------
// SHOW SIZE MAP
// ---------------------------------------------------------------
  void sizeDadosTemplate(){
    pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    cout <<"THERE ARE [" << (int) myvector.size() <<"] ELEMENTS" << endl; // PRINT CONSOLE / SCREEN
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  }
  

  
// ---------------------------------------------------------------
// REMOVE SPECIFIC ELEMENT
// ---------------------------------------------------------------
  bool delDadosTemplate(const T &f) {
    pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    typename std::vector<T>::iterator it; // POINTER ITERATOR
    int x=0;
    it = find (myvector.begin(), myvector.end(), f); // STL algorithm - FIND    
    if (it != myvector.end()){  // IF NOT END VECTOR - EXIST
      x= (((int)(myvector.begin()-it))*(-1)); // GET INDICE VECTOR REMOVE
      myvector.erase(myvector.begin()+x);  // REMOVE SPECIFIC ELEMENT
      cout << "FOUND DATA FOR REMOVE!" << endl; // PRINT CONSOLE / SCREEN
      pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
      return true;
    } 
    else {
       cout << "DID NOT FIND DATA FOR REMOVE!" << endl; // PRINT CONSOLE / SCREEN
    }
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    return false;    
  }
  

  
// ---------------------------------------------------------------
// CKECK SPECIFIC ELEMENT/KEY EXIST IN MAP
// RETURN TRUE OR FALSE 
// ---------------------------------------------------------------
  bool findDadosTemplate(const T &f){   
  
    pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    typename std::vector<T>::iterator it; // POINTER ITERATOR
    int x=0;
    it = find (myvector.begin(), myvector.end(), f); // STL algorithm - FIND    
    if (it != myvector.end()){  // IF NOT END VECTOR - EXIST
      cout << "FOUND DATA -TRUE!" << endl; // PRINT CONSOLE / SCREEN
      pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
      return true;
    } 
    else {
       cout << "DID NOT FIND DATA - FALSE!" << endl; // PRINT CONSOLE / SCREEN
    }
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    return false;  
    
    
  }
  
  
// ---------------------------------------------------------------
// SHOW IN SCREEN/CONSOLE ALL DATA IN MAP
// ---------------------------------------------------------------
  void printDadosTemplate(){
    pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    typename std::vector<T>::iterator it; // POINTER ITERATOR
    cout <<"---------------------" << endl; // PRINT CONSOLE / SCREEN
      for (it=myvector.begin(); it!=myvector.end(); ++it) // RUN ALL ELEMENTS IN MAP
       std::cout << *it << '\n'; // PRINT IN CONSOLE
    cout <<"---------------------" << endl; // PRINT CONSOLE / SCREEN
   pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    
  }
   
private:
  vector<T> myvector;
  pthread_mutex_t a_mutex;
  
};


int main()
{
    //printf("Hello World");
    templatesVector<int> * ptrVector;
    ptrVector=new templatesVector<int>; 
    ptrVector->insertDadosTemplate(10);
    ptrVector->sizeDadosTemplate();
    ptrVector->printDadosTemplate();
    ptrVector->findDadosTemplate(10); //bool    
    ptrVector->delDadosTemplate(10);
    ptrVector->clearDadosTemplate();
    //return 0;
}
