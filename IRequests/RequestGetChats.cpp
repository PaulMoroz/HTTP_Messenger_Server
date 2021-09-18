#pragma once
#include "IRequests.h"
#include "RequestGetChats.h"
#include <cpprest/json.h>
#include "../stringtowstring.h"
using namespace web;

RequestGetChats::RequestGetChats(MSSQLDatabase* db, AnswerContainerInterface* answercontainer, const std::string& userLogin) : IRequests(db, answercontainer),
user_login(userLogin) {}

void RequestGetChats::DoRequest() {
    json::value result;
    try{
        std::vector<ISXModel::Chat> chatList = db->GetUserChatsFromDB(this->user_login);
        result[L"size"] = json::value::Number(chatList.size());
        json::value chats;
        for (int i = 0; i < chatList.size(); i++) {
            json::value current = json::value();
            current[L"id"] = json::value::Number(chatList[i].get_id());
            current[L"title"] = json::value::string(to_wstring(chatList[i].get_title()));
            chats[i] = current;
        }
        result[L"chats"] = chats; 
        this->answercontainer->SetStatusCode(status_codes::Accepted);
    }
    catch (std::exception e) {
        result[L"what"] = json::value::string(to_wstring(e.what()));
        this->answercontainer->SetStatusCode(status_codes::BadRequest);
    }
    this->answercontainer->SetAnswer(result);
    this->answercontainer->MakeDone();
}
