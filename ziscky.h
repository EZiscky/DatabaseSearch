#ifndef ZISCKY_H
#define ZISCKY_H

//#include "ziscky_global.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>


using namespace std;
class Ziscky{
private:
   vector<string> Search(const vector<string> databases,const vector<string> crossReference,const vector<string> searchParam,string searchCondition,bool regex,boost::promise<vector<string> > &p);
   bool Regex(string haystack,string needle);
   string server;
   string uname;
   string pass;

public:
    Ziscky(string server,string uname,string pass);
    virtual ~Ziscky();
    vector<string> ParallelSearch(const vector<string> databases,const vector<string> crossReference,const vector<string> searchParam,string searchCondition,bool regex);
//    void operator() ();
//    struct Employee{};
};

#endif // ZISCKY_H
