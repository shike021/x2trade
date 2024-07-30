#ifndef STRATEGY_H
#define STRATEGY_H

#include <memory>
#include "http_client_pool.h"
#include "websocket_client.h"

class Strategy {
public:
    Strategy(std::shared_ptr<HttpClientPool> http_pool, std::shared_ptr<WebSocketClient> ws_client);
    void execute();

private:
    std::shared_ptr<HttpClientPool> http_pool;
    std::shared_ptr<WebSocketClient> ws_client;
};

#endif // STRATEGY_H
