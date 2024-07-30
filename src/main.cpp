#include <boost/asio.hpp>
#include "config.h"
#include "logger.h"
#include "http_client_pool.h"
#include "websocket_client.h"
#include "strategy.h"

int main() {
    try {
        Config::getInstance().loadConfig("config/config.json");
        Logger::init();

        boost::asio::io_context io_context;

        // Create the HTTP client pool
        auto http_pool = std::make_shared<HttpClientPool>(
            io_context,
            Config::getInstance().httpBaseUrl,
            Config::getInstance().httpPoolSize
        );

        // Create the WebSocket client
        auto ws_client = std::make_shared<WebSocketClient>(
            io_context,
            Config::getInstance().wsBaseUrl
        );

        // Connect to WebSocket server
        ws_client->connect();

        // Instantiate and execute the strategy
        Strategy strategy(http_pool, ws_client);
        strategy.execute();

        // Run the IO context
        io_context.run();

    } catch (const std::exception& e) {
        Logger::log(std::string("Exception: ") + e.what());
    }

    return 0;
}
