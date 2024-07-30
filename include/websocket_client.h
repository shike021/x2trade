#ifndef WEBSOCKET_CLIENT_H
#define WEBSOCKET_CLIENT_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>
#include <string>

class WebSocketClient {
public:
    WebSocketClient(boost::asio::io_context& io_context, const std::string& uri);
    void connect();
    void send(const std::string& message);
    void receive();

private:
    boost::asio::io_context& io_context;
    boost::beast::websocket::stream<boost::asio::ip::tcp::socket> ws;
    std::string uri;
};

#endif // WEBSOCKET_CLIENT_H
