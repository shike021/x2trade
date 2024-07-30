#include "strategy.h"
#include "logger.h"

Strategy::Strategy(std::shared_ptr<HttpClientPool> http_pool, std::shared_ptr<WebSocketClient> ws_client)
    : http_pool(http_pool), ws_client(ws_client) {}

void Strategy::execute() {
    Logger::log("Executing strategy");
    // Implement your arbitrage strategy here
}
