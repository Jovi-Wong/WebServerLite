#ifndef SQLCONN
#define SQLCONN
#include "sqlconnpool.hpp"

/* 资源在对象构造初始化 资源在对象析构时释放*/
class SqlConn {
public:
    SqlConn(MYSQL** sql, SqlConnPool *connpool) {
        assert(connpool);
        *sql = connpool->GetConn();
        sql_ = *sql;
        connpool_ = connpool;
    }
    
    ~SqlConn() {
        if(sql_) { connpool_->FreeConn(sql_); }
    }
    
private:
    MYSQL *sql_;
    SqlConnPool* connpool_;
};

#endif //SQLCONN