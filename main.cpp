#include <iostream>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;
#include <map>

void handle_get(http_request request){
    json::value answer;
    answer["OK"] = json::value::string("YES");
    request.reply(status_codes::OK,answer);
}
void handle_put(http_request request){
    std::cout<<"Handling put!\n";
}
void handle_post(http_request request){
    std::cout<<"Handling psot!\n";
}
void handle_del(http_request request){
    std::cout<<"Handling delete!\n";
}

int main() {
    http_listener listener("https://localhost/restdemo");
    listener.support(methods::GET, handle_get);
    listener.support(methods::POST, handle_post);
    listener.support(methods::PUT, handle_put);
    listener.support(methods::DEL, handle_del);
    try
    {
        listener
                .open()
                .then([&listener](){std::cout<<"Starting...";})
                .wait();
        while (true);
    }
    catch (std::exception const & e)
    {
        std::cout << e.what() << std::endl;
    }

}
