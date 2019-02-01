//
// Created by tristan on 25/01/19.
//

#ifndef BROCKENBRICK_REMOTE_H
#define BROCKENBRICK_REMOTE_H

#include <curl/curl.h>
#include <map>
#include <string>
#include "HTTPResponse.h"

enum HttpMethod {
    GET, POST, DELETE
};

class HTTP {

public:
    explicit HTTP(char *baseURI, char *baseKEY);

    ~HTTP();

    HTTPResponse get(std::string path, std::map<std::string, std::string> parameters = {});

//    HTTPResponse post(std::string path);
//
//    HTTPResponse delet(std::string path);

    bool init();

private:
    /**
     * TODO : on peut proposer à l'utilisateur de choisir
     * qui il est dans une list déroulante qui viendra d'un
     * appel au serveur ==> /players
     */
    CURL *curlHandler;
    std::string baseURI;
    std::string baseKEY;
    char errorBuffer[CURL_ERROR_SIZE];
    std::string buffer;

    std::string buildURL(std::string &path, std::map<std::string, std::string> &parameters);

    void setUrl(std::string url);

    static size_t writer(char *inputContent, size_t sizeFactor, size_t contentSize, std::string *outputContent);

};


#endif //BROCKENBRICK_REMOTE_H
