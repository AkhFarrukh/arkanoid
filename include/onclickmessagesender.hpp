//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_ONCLICKMESSAGESENDER_HPP
#define ARKANOID_ONCLICKMESSAGESENDER_HPP

#include <memory>
#include <string>
#include "messagereceiver.hpp"
#include "clickable.hpp"

using namespace std;
/*--------------------------------------------------
Send messages when clicked
--------------------------------------------------*/
class OnClickMessageSender : public virtual Clickable  {
    string                      message;
    shared_ptr<MessageReceiver> receiver;

protected:
    OnClickMessageSender(const OnClickMessageSender &)            = default;
    OnClickMessageSender(OnClickMessageSender &&)                 = default;
    OnClickMessageSender &operator=(const OnClickMessageSender &) = default;
    OnClickMessageSender &operator=(OnClickMessageSender &&)      = default;

public:
    OnClickMessageSender(string message, shared_ptr<MessageReceiver> receiver)
            : message{std::move(message)}, receiver{std::move(receiver)} {}
    void onClick() override { receiver->receiveMessage(message); }
    ~OnClickMessageSender() override = default;
};


#endif //ARKANOID_ONCLICKMESSAGESENDER_HPP
