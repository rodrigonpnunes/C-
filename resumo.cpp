#include <map>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

#define USERNAME   "TESTE"
#define VALOR_TIME_OUT 5

std::auto_ptr<idTermInformado> gIdTermInformado (new idTermInformado());;


  typedef struct {
    int action_index;
    char session_id[C_COSS_UNIQUE_ID_SIZE+1];
    char terminal_e_cpf[20];
    bool status_terminal;
  } S_ACTION_INDEX;


  typedef struct {
  std::vector<std::string> vTerminaisClientes;
  std::string clienteSolo;
  std::string dataAtivacao;
  std::string assinatura;
  int status;
} T_DADOS_CONSULTA_2;



// --------------------------------------------------------------------------------
//STRING
// --------------------------------------------------------------------------------
//.size
//.clear
//.append
//.assign
//.copy

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
 char buffer[5000];
	   std::size_t length = y.copy(buffer,(cf-ci)-1, ci+1);
	   buffer[length]='\0';
	   retorno.append(buffer);
	   retorno.append("|");

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
if ((request.size()>0)){

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------

string ConexaoWsGerais::converteXML(string str, string str1){

  size_t found = str.find(str1);
  if ((found!=string::npos)) {
    str.replace(str.find(str1),str1.length(),"<xxxx>");
  }
  return str;
}

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
bool ConexaoWsGerais::converteBoolXML(string str, string str1){

  size_t found = str.find(str1);
  if (found!=string::npos) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
    string ConexaoWsGerais::substituirRequisicao(string p_label, string p_parametro, string requisicao){
     std::size_t found = requisicao.find(p_label);
      if (found!=std::string::npos){
	requisicao.replace(requisicao.find(p_label),p_label.length(),p_parametro);
      }
    return requisicao;
   }




//---------------------------------------------------------------------------------------------------------
// MAP
//---------------------------------------------------------------------------------------------------------
    MyStruct ConexaoWsGerais::retornaEstruturaChamada(int idAcao){
      MyStruct a;
    a_cadeado->obtemAcesso();

      a.resposta=false;
      std::map<int,MyStruct>::iterator it;
      if((it=dadosRequesicao.find(idAcao))!=dadosRequesicao.end()) {
	a=(*it).second;
	a.resposta=true;
      }
    a_cadeado->liberaAcesso();
    return a;
    }


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
    string ConexaoWsGerais::requestSubstituir (map<int,string> mapS, string request)
    {
	int contador=0;
	string s_aux;
	char s_i[15];

	//for (std::vector<string>::iterator it = findList.begin() ; it != findList.end(); ++it){


	if ((mapS.size()>0) && (request.size()>0)){

	  for (std::map<int,string>::iterator it2 =mapS.begin(); it2 != mapS.end(); ++it2){
	    printDebug ("PRINT MAP [%d] [%s]", (*it2).first, (*it2).second.c_str());

	    contador=(*it2).first;
    	    s_aux.clear();
	    memset(s_i,'\0', 15);
	    sprintf(s_i, "%d", contador);
	    s_aux.append(P_LABEL);
	    s_aux.append(s_i);

    	    request=substituirRequisicao(s_aux, (*it2).second, request);
	  }
	}
	else {
	  printDebug("MAP/request VAZIO!!!!")
	}
	return request;
    }


 //---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void ConexaoWsGerais::delDinamicaConf(int id_requisicao, string nomeArq, string labelAcao, string diretorio){
  a_cadeado->obtemAcesso();
      std::map<int,MyStruct>::iterator it;
      if(((it=dadosRequesicao.find(id_requisicao))!=dadosRequesicao.end())){
	dadosRequesicao.erase(it);
      }
  a_cadeado->liberaAcesso();
}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void ConexaoWsGerais::setExecCurl(int id_requisicao, string xml_curl){
a_cadeado->obtemAcesso();
    std::map<int,string>::iterator it;
    if(!((it=myInformacoesReqCurl.find(id_requisicao))!=myInformacoesReqCurl.end())){
      myInformacoesReqCurl.insert(std::pair<int,string>(id_requisicao,xml_curl));
    }
    else {
      it->second=xml_curl;
    }
a_cadeado->liberaAcesso();
}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
string ConexaoWsGerais::getTemplateCurlRequest(int id_requisicao){
a_cadeado->obtemAcesso();
    string retorno;
    std::map<int,string>::iterator it;
    if(((it=myInformacoesReqCurl.find(id_requisicao))!=myInformacoesReqCurl.end())){
      retorno= it->second;
    }
a_cadeado->liberaAcesso();
return retorno;
}



//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void ConexaoWsGerais::setExecCurlLabel(int id_requisicao, int posicao, string c_label){

  a_cadeado->obtemAcesso();

	std::map<int,MyStruct>::iterator it;
	std::map<int,string>::iterator it2;
	if(!((it=dadosRequesicao.find(id_requisicao))!=dadosRequesicao.end())){
	  MyStruct a;
	  //a.buildReqList.push_back(c_label);
	  a.buildReqList.insert(std::pair<int,string>(posicao,c_label));
	  dadosRequesicao.insert(std::pair<int,MyStruct>(id_requisicao,a));
	}
	else {
	  for (std::map<int,MyStruct>::iterator it=dadosRequesicao.begin(); it!=dadosRequesicao.end(); ++it){
	    if (it->first==id_requisicao){
	      //it->second.buildReqList.push_back(c_label);
	      	if(!((it2=it->second.buildReqList.find(posicao))!=it->second.buildReqList.end())){
		  //insere novo
		  (*it).second.buildReqList.insert(std::pair<int,string>(posicao,c_label));
		}
		else {
		  // substitui pelo novo
		  (*it2).second=c_label;
		}
	      break;
	    }
	  }
	}

  a_cadeado->liberaAcesso();
}


//---------------------------------------------------------------------------------------------------------
// VECTOR
//---------------------------------------------------------------------------------------------------------
//.push_back
//.find
//.

vector<string> retorno;
vector<int> produtoSistemaOrigem



// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
void ConexaoWsGerais::del_tab_tag_codigo_retorno_ws(int id_servico, int indice, string tag_inicio, string tag_final){
a_cadeado2->obtemAcesso();
    int x=0;
    it_tag_cr = find (vector_tab_tag_codigo_retorno_ws.begin(), vector_tab_tag_codigo_retorno_ws.end(), id_servico);
    if (it_tag_cr != vector_tab_tag_codigo_retorno_ws.end()){
	x= (((int)(vector_tab_tag_codigo_retorno_ws.begin()-it_tag_cr))*(-1));
	vector_tab_tag_codigo_retorno_ws.erase(vector_tab_tag_codigo_retorno_ws.begin()+x);
	vector_tab_tag_codigo_retorno_ws_d.erase(vector_tab_tag_codigo_retorno_ws_d.begin()+x);
    }
a_cadeado2->liberaAcesso();
}


// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
S_CODIGO_ERRO_RETORNO_WS ConexaoWsGerais::get_tab_codigo_erro_retorno_ws(int id_servico, string codigo_erro){
a_cadeado2->obtemAcesso();
  S_CODIGO_ERRO_RETORNO_WS retorno;
  retorno.status=0;
  string busca;
  char aux[8] ={'\0'}; sprintf(aux, "%d", id_servico);
  busca.append(aux);
  busca.append(codigo_erro);
  int x=0;
    it_erro_cr = find (vector_tab_codigo_erro_retorno_ws.begin(), vector_tab_codigo_erro_retorno_ws.end(), busca);
    if (it_erro_cr != vector_tab_codigo_erro_retorno_ws.end()){ //achou
	x= (((int)(vector_tab_codigo_erro_retorno_ws.begin()-it_erro_cr))*(-1));
	retorno= vector_tab_tab_codigo_erro_retorno_ws_d[x];
	retorno.status=1;
    }
a_cadeado2->liberaAcesso();
return retorno;
}


// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
void ConexaoWsGerais::del_tab_produto_cliente_new(string produto_cliente_new, string produto_convergente){
a_cadeado2->obtemAcesso();
    int x=0;
    it_produto = find (vector_tab_produto_cliente_new.begin(), vector_tab_produto_cliente_new.end(), produto_cliente_new);
    if (it_produto != vector_tab_produto_cliente_new.end()){
	x= (((int)(vector_tab_produto_cliente_new.begin()-it_produto))*(-1));
	vector_tab_produto_cliente_new.erase(vector_tab_produto_cliente_new.begin()+x);
	vector_tab_produto_convergente.erase(vector_tab_produto_convergente.begin()+x);
    }
a_cadeado2->liberaAcesso();
}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
bool ConexaoWsGerais::temAlgumErroTimeOut(string xml){

  size_t tagTimeout;
  bool retorno=true;
  std::vector<string>errosXml;
  errosXml.push_back("timeout");
  errosXml.push_back("timed out");

  for (std::vector<string>::iterator it = errosXml.begin() ; it != errosXml.end(); ++it){
    tagTimeout= xml.find((*it).c_str());  // aconteceu TIMEUOUT?
     if (tagTimeout!=string::npos) {
        printDebug ("Erro no acesso WEB SERVICE!");
	retorno=false;
	break;
     }
  }
  return retorno;
}



// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
vector<string> ConexaoWsGerais::retornaParametrosVector(string arqClienteNewXML, string tagi, string tagf){
   vector<string> retorno;
   vector<int> produtoSistemaOrigem, produtoSistemaOrigemF;
   vector<int>::iterator it99;
   std::size_t found, found2;
   int cont=0;
   while (true){
   if (cont==0) {
     found=arqClienteNewXML.find(tagi.c_str());
     if (!(found!=std::string::npos)) break;
   }
   else {
     found=arqClienteNewXML.find(tagi.c_str(), found2+1);
     if (!(found!=std::string::npos)) break;
   }
    produtoSistemaOrigem.push_back(found);
    found2=found;
    cont++;
   }

   cont=0;
   while (true){
   if (cont==0) {
     found=arqClienteNewXML.find(tagf.c_str());
     if (!(found!=std::string::npos)) break;
   }
   else {
     found=arqClienteNewXML.find(tagf.c_str(), found2+1);
     if (!(found!=std::string::npos)) break;
   }
    produtoSistemaOrigemF.push_back(found);
    found2=found;
    cont++;
   }
   //printDebug("TAMANHO_I:[%d]", produtoSistemaOrigem.size());
   //printDebug("TAMANHO_F:[%d]", produtoSistemaOrigemF.size());

   std::string str44;
   cont=0;
   for (it99 = produtoSistemaOrigem.begin() ; it99 != produtoSistemaOrigem.end(); ++it99) {
    str44.assign(arqClienteNewXML.substr (produtoSistemaOrigem[cont]+strlen(tagi.c_str()),produtoSistemaOrigemF[cont]-(produtoSistemaOrigem[cont]+strlen(tagi.c_str()))));
    retorno.push_back(str44);
    //printDebug("ADD_VETOR:[%s]", str44.c_str());
    str44.clear();
    cont++;
   }

 return retorno;
}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
string ConexaoWsGerais::getClienteNewXML(string si){
a_cadeado3->obtemAcesso();
  vector<string>::iterator it88;
  string reposta;
  int x=0;
  it88 = find (xml_cliente_new.begin(), xml_cliente_new.end(), si);
  if ((it88 != xml_cliente_new.end())){
    x= (((int)(xml_cliente_new.begin()-it88))*(-1));
    reposta=xml_cliente_new2[x];
  }
a_cadeado3->liberaAcesso();
return reposta;
}




//---------------------------------------------------------------------------------------------------------
// ARQUIVO
//---------------------------------------------------------------------------------------------------------
    string ConexaoWsGerais::getArquivoXML (string nome_arquivo)
    {
	  string retorno;
	  std::ifstream ifs;
	  ifs.open (nome_arquivo.c_str(), std::ifstream::in);
	  if (ifs.is_open()) {
	      char c = ifs.get();
	      char c2[2];
	      while (ifs.good()) {
		memset (c2, '\0', 2);
		c = ifs.get();
		sprintf(c2, "%c", c);
		retorno.append(c2);
	      }
	      ifs.close();
	   }
	   else {
	      printDebug("Error opening file [%s]", nome_arquivo.c_str());
	   }
	  return retorno;
    }


//------------------
//C/C++
//------------------
s_aux.clear();
memset(s_i,'\0', 3);
sprintf(s_i, "%d", contador);
