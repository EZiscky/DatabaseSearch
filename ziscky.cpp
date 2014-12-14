#include "ziscky.h"
#include <map>
#include <vector>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace sql;

Ziscky::Ziscky(string server,string uname,string pass):
    server(server),uname(uname),pass(pass){

}
Ziscky::~Ziscky(){}
//search param and cross reference size have to be equal
vector<string> Ziscky::Search(const vector<string> databases, const vector<string> crossReference, const vector<string> searchParam,string searchCondition,bool regex,boost::promise<vector<string> > &p ){
    try{
    sql::Driver *driver = get_driver_instance();
    sql::Connection *connection = driver->connect(this->server,this->uname,this->pass);
    sql::Statement *statement = connection->createStatement();
    sql::ResultSet *resultSet,*tableSet;
    vector<string> finalResult;

    std::map<string,string> searchParamPair;
    std::map<string,string>::const_iterator mapIterator;
    vector<string>::const_iterator crossIterator;
    vector<string>::const_iterator searchIterator;
    for(crossIterator = crossReference.begin();crossIterator != crossReference.end();crossIterator++){//Fill the map
        for(searchIterator = searchParam.begin();searchIterator != searchParam.end();searchIterator++){
            searchParamPair[*crossIterator] = *searchIterator;
        }
    }

    vector<string>::const_iterator databaseIterator = databases.begin();
for(mapIterator = searchParamPair.begin();mapIterator!=searchParamPair.end();mapIterator++){
    while(databaseIterator != databases.end()){//database loop
        string DATABASE_LIST = "USE ";
        DATABASE_LIST+= *databaseIterator;
        string TABLE_LIST = "SHOW TABLES";
        statement->execute(DATABASE_LIST);
        resultSet = statement->executeQuery(TABLE_LIST);
        while(resultSet->next()){
            string append = "Tables_in_";
            append+=*databaseIterator;
            string query = "SELECT * FROM ";
            query+=resultSet->getString(append);
            string condition = " WHERE";
            condition.append(mapIterator->first);
            if(!regex){
            condition.append(" = ");
            condition.append(mapIterator->second);
            if(searchParamPair.size()  > 1){//add and clauses
                for(unsigned int i=1;i<searchParamPair.size();i++){//1 since we already added a statement
                    condition.append(" ");
                    condition.append(searchCondition);
                    condition.append(" ");
                    condition.append(mapIterator->first);
                    condition.append(" = ");
                    condition.append(mapIterator->second);
                }
            }
            query += condition;
            tableSet = statement->executeQuery(query);
            while(tableSet->next()){
                   finalResult.push_back(tableSet->getString("Email"));
            }
            }else{//basically same code as above but implementing regex search in sql
                   condition.append(" REGEXP ");//sql regex;
                   condition.append(mapIterator->first);
                   if(searchParamPair.size() > 1){
                       condition.append(" ");
                       condition.append(searchCondition);
                       condition.append(" ");
                       condition.append(mapIterator->first);
                       condition.append(" REGEXP ");
                       condition.append(mapIterator->second);
                   }
                   query+=condition;
                   tableSet = statement->executeQuery(query);
                   while(tableSet->next()){
                       finalResult.push_back(tableSet->getString("Email"));
                   }
            }
        }
        databaseIterator++;
    }
    delete connection;
    delete statement;
    delete resultSet;
    p.set_value(finalResult);
    return finalResult;
}
    }catch(exception *e){
          cout<< e->what();
    }
}


vector<string> Ziscky::ParallelSearch(const vector<string> databases, const vector<string> crossReference, const vector<string> searchParam,string searchCondition,bool regex){
    size_t databaseCount = databases.size();
    int modulus = databaseCount%2;
    vector<string> results;//final result
    vector<string>::const_iterator iterator;
    if(modulus<1){//Divide databases into 2
        vector<string> division1,division2,result1,result2;//temp vectors
        for(unsigned int s=0;s<databases.size()/2;s++){
            division1.push_back(databases[s]);
        }
        for(unsigned int s = databases.size()/2;s<databases.size();s++){
            division2.push_back(databases[s]);
        }
        //create threads
        boost::promise<vector<string> > p,p2;//promises for return values
        boost::thread thread1(&Ziscky::Search,this,division1,crossReference,searchParam,searchCondition,regex,boost::ref(p));
        boost::thread thread2(&Ziscky::Search,this,division2,crossReference,searchParam,searchCondition,regex,boost::ref(p2));
        result1 = p.get_future().get();
        result2 = p.get_future().get();
        results.reserve(result1.size() + result2.size());
        //insert values
        results.insert(results.end(),result1.begin(),result1.end());
        results.insert(results.end(),result2.begin(),result2.end());
    }else{//can't divide databases into two
        vector<string> division1,division2,result1,result2;//temp vectors
        for(unsigned int s = 0;s<databases.size()/2 +1;s++){
            division1.push_back(databases[s]);
        }
        for(unsigned int s = databases.size() /2 +1;s<databases.size();s++){
            division2.push_back(databases[s]);
        }
        //create threads
        boost::promise<vector<string> > p,p2;//promises for return values
        boost::thread thread1(boost::bind(&Ziscky::Search,this,division1,crossReference,searchParam,searchCondition,regex,boost::ref(p)));
        boost::thread thread2(boost::bind(&Ziscky::Search,this,division2,crossReference,searchParam,searchCondition,regex,boost::ref(p2)));
        result1 = p.get_future().get();
        result2 = p.get_future().get();
        results.reserve(result1.size() + result2.size());
        //insert values
        results.insert(results.end(),result1.begin(),result1.end());
        results.insert(results.end(),result2.begin(),result2.end());
    }
    return results;
}
bool Ziscky::Regex(string haystack, string needle){ return true;}
//void Ziscky::operator ()(){}//functor

