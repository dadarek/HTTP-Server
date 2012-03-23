#include "SocketApi.h"
#include "SocketWriter.h"

SocketWriter::SocketWriter( SocketApi& socketApi )
  : socketApi_( socketApi )
{ }

SocketWriter::~SocketWriter()
{ }

