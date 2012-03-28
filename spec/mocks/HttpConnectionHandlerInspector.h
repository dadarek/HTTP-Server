#ifndef HTTP_CONNECTION_HANDLER_INSPECTOR_H
#define HTTP_CONNECTION_HANDLER_INSPECTOR_H

struct HttpConnectionHandlerInspector
{
  bool responseDestroyed;
  bool requestDestroyed;
  bool handlerDestroyed;
  HttpConnectionHandlerInspector()
    : responseDestroyed( false )
    , requestDestroyed( false )
    , handlerDestroyed( false )
  { }
};

#endif
