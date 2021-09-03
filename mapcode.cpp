#include <stdio.h>
#include <map>
#include <iostream>
#include <pthread.h>

using namespace std;

template <typename T, typename T2>
class templatesMap {
public:
  
// ---------------------------------------------------------------
// CONSTRUTOR
// ---------------------------------------------------------------
  templatesMap(){
      cout<< "TEMPLATE CONSTRUTOR" << endl;
      pthread_mutex_init( &a_mutex, NULL); // START MUTEX
  }

  
// ---------------------------------------------------------------
// DESCONSTRUTOR
// ---------------------------------------------------------------
  ~templatesMap(){}
 
  
// ---------------------------------------------------------------
// INSERT ONE INFORMATION IN MAP
// ---------------------------------------------------------------
  void insertDadosTemplate(const T &v, const T2 &z){
    pthread_mutex_lock( &a_mutex); //MUTEX LOCK CRITICAL AREA
    mymap.insert( std::pair<T, T2>(v,z) ); // STL INSERT MAP
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  }
  

  
// ---------------------------------------------------------------
// MAP CLEAR
// ---------------------------------------------------------------
  void clearDadosTemplate(){
    pthread_mutex_lock( &a_mutex); //MUTEX LOCK CRITICAL AREA
    mymap.clear(); // REMOVE ALL ELEMENTS/REGISTER MAP
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  }
  

// ---------------------------------------------------------------
// SHOW SIZE MAP
// ---------------------------------------------------------------
  void sizeDadosTemplate(){
    pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    cout <<"THERE ARE [" << (int) mymap.size() <<"] ELEMENTS" << endl;
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  }
  

  
// ---------------------------------------------------------------
// REMOVE SPECIFIC ELEMENT
// ---------------------------------------------------------------
  bool delDadosTemplate(const T &f){
       pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    typename std::map<T,T2>::iterator it; // POINTER ITERATOR
    
    if((it=mymap.find(f))!=mymap.end()) { // STL MAP - FIND
      cout << "FOUND DATA FOR REMOVE!" << endl;
      mymap.erase(it);
      pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
      return true;
    }
    else {
       cout << "DID NOT FIND DATA FOR REMOVE!" << endl;
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
   
   typename std::map<T,T2>::iterator it; // POINTER ITERATOR
	
  	if((it=mymap.find(f))!=mymap.end()) { // STL MAP - FIND
  	  cout << "FOUND DATA - TRUE!" << endl;
  	  pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  	  return true;
  	}
  	else {
  	  cout << "DID NOT FOUND DATA - FALSE!" << endl;     
  	}
  	pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
  	return false;
   
    
    
  }
  
// ---------------------------------------------------------------
// CKECK SPECIFIC ELEMENT/KEY EXIST IN MAP
// RETURN SECOND DATA  
// ---------------------------------------------------------------
  T2 findDadosTemplateReturnSecond(const T &f){
       pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    typename std::map<T,T2>::iterator it; // POINTER ITERATOR
    
    if((it=mymap.find(f))!=mymap.end()) {  // STL MAP - FIND
      cout << "FOUND DATA - TRUE!" << endl;
    }
    else {
      cout << "DID NOT FOUND DATA - FALSE!" << endl;
    }
    pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    return it->second;
    
    
  }
  

  
// ---------------------------------------------------------------
// SHOW IN SCREEN/CONSOLE ALL DATA IN MAP
// ---------------------------------------------------------------
  void printDadosTemplate(){
    pthread_mutex_lock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    typename std::map<T,T2>::iterator it; // POINTER ITERATOR
    cout <<"---------------------" << endl;
      for (it=mymap.begin(); it!=mymap.end(); ++it) // RUN ALL ELEMENTS IN MAP
       std::cout << it->first << " => " << it->second << '\n'; // PRINT IN CONSOLE
    cout <<"---------------------" << endl;
   pthread_mutex_unlock( &a_mutex); // MUTEX UNLOCK CRITICAL AREA
    
  }
   
private:
  std::map<T,T2> mymap;
  pthread_mutex_t a_mutex;
  
};


int main()
{
    //printf("Hello World");
    templatesMap<int,int> * ptrMap;
    ptrMap=new templatesMap<int,int>; 
    ptrMap->insertDadosTemplate(10, 20);
    ptrMap->sizeDadosTemplate();
    ptrMap->printDadosTemplate();
    ptrMap->findDadosTemplate(10); //bool
    int r=ptrMap->findDadosTemplateReturnSecond(10);
    ptrMap->delDadosTemplate(10);
    ptrMap->clearDadosTemplate();
    //return 0;
}
