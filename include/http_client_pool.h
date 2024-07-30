#ifndef HTTP_CLIENT_POOL_H
#define HTTP_CLIENT_POOL_H

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <vector>
#include <memory>
#include <queue>

class HttpClientPool {
public:
    HttpClientPool(boost::asio::io_context& io_context, const std::string& base_url, size_t pool_size);
    std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> acquire();
    void release(std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> client);

private:
    std::vector<std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>> pool;
    std::queue<std::shared_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>> available;
    boost::asio::io_context& io_context;
    std::string base_url;
};

#endif // HTTP_CLIENT_POOL_H
