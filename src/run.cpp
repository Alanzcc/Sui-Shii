#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;


string getEnvironmentVariable(const string& environmentVarKey) {
    const char* envValue = getenv(environmentVarKey.c_str());
    if (envValue != nullptr) {
        return std::string(envValue);
    } else {
        return "";
    }
}

vector<string> getDatabases(mongocxx::client& client)
{
    return client.list_database_names();
}

int main()
{
    // Create an instance.
    mongocxx::instance inst{};
    
    // Retrieve MongoDB URI from environment variable
    auto mongoURIStr = getEnvironmentVariable("MONGODB_URI");
    if (mongoURIStr.empty()) {
        cerr << "MongoDB URI not found in environment variables." << endl;
        return 1; // Return an error code
    }

    // Create MongoDB client
    mongocxx::uri mongoURI{ mongoURIStr };
    mongocxx::client conn{ mongoURI };

    // Get all the databases from the client
    auto dbs = getDatabases(conn);
    for (const auto& db : dbs)
    {
        cout << db << endl;
    }

    return 0;
}
