#include <unistd.h>
#include "webserverlite.hpp"

int main() {
    WebServerLite server(
        1234,            // port
        3,               // trigMode
        60000,           // timeoutMS
        false,           // OptLinger
        3306,            // sqlPort
        "root",          // sqlUser
        "1234",          // sqlPwd
        "WebServerLite", // dbName
        12,              // connPoolNum
        6,               // threadNum
        true,            // openLog
        1,               // logLevel
        1024             // logQueSize
    );
    server.Start();
} 