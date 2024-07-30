#include "http_client_pool.h"
#include "config.h"

HttpClientPool::HttpClientPool(boost::asio::io_context& io_context, const std::string& base_url, size_t pool_size)
    : io_context(io_context), base_url(base_url) {
    for (size_t i = 0; i < pool_size; ++i) {
        auto socket = std::make_shared<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>(io_context, ssl_context);
        pool.push_back(socket);
        available.push(socket);
    }
}

std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> HttpClientPool::acquire() {
    if (available.empty()) {
        throw std::runtime_error("No available HTTP client");
    }
    auto client = available.front();
    available.pop();
    return client;
}

void HttpClientPool::release(std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> client) {
    available.push(client);
}
