//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_MESSAGERECEIVER_HPP
#define ARKANOID_MESSAGERECEIVER_HPP

#include <string>

using namespace std;
/*--------------------------------------------------
Message Receiver
--------------------------------------------------*/
class MessageReceiver {
protected:
    MessageReceiver()                                   = default;
    MessageReceiver(const MessageReceiver &)            = default;
    MessageReceiver(MessageReceiver &&)                 = default;
    MessageReceiver &operator=(const MessageReceiver &) = default;
    MessageReceiver &operator=(MessageReceiver &&)      = default;

public:
    virtual void receiveMessage(const string &message) = 0;
    virtual ~MessageReceiver()                         = default;
};


#endif //ARKANOID_MESSAGERECEIVER_HPP
