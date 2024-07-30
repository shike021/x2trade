#include "websocket_client.h"
#include "config.h"
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <iostream>

WebSocketClient::WebSocketClient(boost::asio::io_context& io_context, const std::string& uri)
    : io_context(io_context), ws(io_context), uri(uri) {}

void WebSocketClient::connect() {
    auto const results = resolver.resolve(host, port);
    boost::asio::connect(ws.next_layer(), results.begin(), results.end());
    ws.handshake(host, "/");
}

void WebSocketClient::send(const std::string& message) {
    ws.write(boost::asio::buffer(message));
}

void WebSocketClient::receive() {
    boost::beast::multi_buffer buffer;
    ws.read(buffer);
    std::cout << boost::beast::buffers_to_string(buffer.data()) << std::endl;
}
