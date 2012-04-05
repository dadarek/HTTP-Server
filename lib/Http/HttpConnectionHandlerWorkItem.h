#ifndef HTTP_CONNECTION_HANDLER_WORK_ITEM_H
#define HTTP_CONNECTION_HANDLER_WORK_ITEM_H

#include "HttpConnectionHandler.h"
#include "WorkItem.h"

class HttpConnectionHandlerWorkItem
  : public HttpConnectionHandler
  , public WorkItem 
{
  private:
    int socketFD_;

  public:
    HttpConnectionHandlerWorkItem( SocketReader& socketReader, HttpRequestParser& parser, HttpRequestHandlerFactory& factory, HttpResponseWriter& writer, int socketFD );
    virtual ~HttpConnectionHandlerWorkItem();

    void execute(); 
};

#endif

