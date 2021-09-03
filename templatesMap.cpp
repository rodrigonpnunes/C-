#ifndef _templatesBI_
#define _templatesBI_

#include <map>
#include <iostream>
#include <pthread.h>

using namespace std;

template <typename T, typename T2>
class templatesBI {
public:
  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  templatesBI(){
      printDebug ("Construtor templatesBI");
      pthread_mutex_init( &a_mutex, NULL);
      flag_em_carga=false;
  }

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  ~templatesBI(){}

  
  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  void insertDadosTemplate(const T &v, const T2 &z){
    pthread_mutex_lock( &a_mutex);
    mymap.insert( std::pair<T, T2>(v,z) );
    pthread_mutex_unlock( &a_mutex);
  }
  

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  void clearDadosTemplate(){
    pthread_mutex_lock( &a_mutex);
    mymap.clear();
    pthread_mutex_unlock( &a_mutex);
  }
  

// ---------------------------------------------------------------
// ---------------------------------------------------------------
  void sizeDadosTemplate(){
    pthread_mutex_lock( &a_mutex);
    printDebug("ESTRUTURA POSSUI [%d]ELEMENTOS", (int) mymap.size()); 
    pthread_mutex_unlock( &a_mutex);
  }
  

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  bool delDadosTemplate(const T &f){
       pthread_mutex_lock( &a_mutex);
    typename std::map<T,T2>::iterator it;
    
    if((it=mymap.find(f))!=mymap.end()) {
      printDebug("ENCONTREI DADOS PARA REMOCAO!");
      mymap.erase(it);
      pthread_mutex_unlock( &a_mutex);
      return true;
    }
    else {
      printDebug("NAO ENCONTREI DADOS PARA REMOCAO!");
    }
    pthread_mutex_unlock( &a_mutex);
    return false;
  }
  

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  bool findDadosTemplate(const T &f){
    
       pthread_mutex_lock( &a_mutex);
   
   if (!(flag_em_carga)) {
	typename std::map<T,T2>::iterator it;
	
	if((it=mymap.find(f))!=mymap.end()) {
	  printDebug("ENCONTREI DADOS - TRUE!");
	  pthread_mutex_unlock( &a_mutex);
	  return true;
	}
	else {
	  printDebug("NAO ENCONTREI DADOS - FALSE!");     
	}
	pthread_mutex_unlock( &a_mutex);
	return false;
  }
  pthread_mutex_unlock( &a_mutex);
  return false;
    
    
  }
  

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  T2 findDadosTemplateReturnSecond(const T &f){
       pthread_mutex_lock( &a_mutex);
    typename std::map<T,T2>::iterator it;
    
    if((it=mymap.find(f))!=mymap.end()) {
      printDebug("ENCONTREI DADOS - TRUE!");
    }
    else {
      printDebug("NAO ENCONTREI DADOS - FALSE!"); 
    }
   pthread_mutex_unlock( &a_mutex);
    return it->second;
    
    
  }
  

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  void printDadosTemplate(){
    pthread_mutex_lock( &a_mutex);
    typename std::map<T,T2>::iterator it;
    printDebug("---------------------");
      for (it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
    printDebug("---------------------");
   pthread_mutex_unlock( &a_mutex);
    
  }
  

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  void processoDeCargaFree(){
    pthread_mutex_lock( &a_mutex);
    flag_em_carga=false;
    pthread_mutex_unlock( &a_mutex);
  }
  
  

  
// ---------------------------------------------------------------
// ---------------------------------------------------------------
  void processoDeCargaBlock(){
    pthread_mutex_lock( &a_mutex);
    flag_em_carga=true;
    pthread_mutex_unlock( &a_mutex);
  }
  
  
  
// ---------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
  void removeEspacosDesnecessarios(char *p_str_original)
  {
    char *ibuf = p_str_original;
    char *obuf = p_str_original;
    int i   = 0;
    int cnt = 0;

    if (p_str_original)
    {
      //verifica numero de ' ' no inicio da string
      for (ibuf = p_str_original; *ibuf && isspace(*ibuf); ++ibuf);

      //remove os espacos da esquerda
      if (p_str_original != ibuf)
      {
	memmove(p_str_original, ibuf, ibuf - p_str_original);
      }

      //remove os espacos desnecessarios no meio da string
      while (*ibuf)
      {
	if (isspace(*ibuf) && cnt)
	{
	  //vai removendo espacos desnecessarios do meio da string
	  ibuf++;
	}
	else
	{
	  if (!isspace(*ibuf))
	  {
	    //se passou aqui, eh porque nao eh espaco, caractere normal
	    cnt = 0;
	  }
	  else
	  {
	    //se passou aqui, eh porque tem espaco
	    *ibuf = ' ';
	    cnt = 1;
	  }
	  obuf[i++] = *ibuf++;
	}
      }

      obuf[i] = '\0';

      //remove espacos da direita
      while (--i >= 0)
      {
	if (!isspace(obuf[i]))
	{
	  //achou final da string, acabou
	  break;
	}
      }

      obuf[++i] = '\0';
    }
  }
  
  
private:
  std::map<T,T2> mymap;
  bool flag_em_carga;
  pthread_mutex_t a_mutex;
};
#endif



