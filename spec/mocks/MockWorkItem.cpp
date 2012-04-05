#include "MockWorkItem.h"

#include <iostream>
MockWorkItem::MockWorkItem()
  : executed_( 0 )
  , deleted_( 0 )
{ }

MockWorkItem::~MockWorkItem()
{
  if( 0 != deleted_)
    (*deleted_) = true;
}

void MockWorkItem::execute()
{
  if( 0 != executed_ )
    (*executed_) = true;
}
