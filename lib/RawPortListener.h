#include "PortListener.h"
#include <netinet/in.h>

class RawPortListener
 : public PortListener
{
  private:
    int portNumber_;
    struct sockaddr_in serverAddress;

    int getNewSocketFD();
    void bindToSocket( int fd, int portNumber );
    void listenOnSocket( int fd );
    int getSocketFDForNextIncomingConnection( int fd );
    void closeSocket( int fd );

    void error( const char* msg );

  public:
    RawPortListener( int portNumber );
    bool listen();
};


