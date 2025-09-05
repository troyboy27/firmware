#pragma once
#include "Observer.h"
#include "SinglePortModule.h"
#include "mesh/generated/meshtastic/portnums.pb.h"

/**
 * Help LED Module - turns on an LED when a message containing the word "help" is received
 */
class HelpLedModule : public SinglePortModule, public Observable<const meshtastic_MeshPacket *>
{
  public:
    /** Constructor
     * name is for debugging output
     */
    HelpLedModule();

  protected:
    /** Called to handle a particular incoming message

    @return ProcessMessage::STOP if you've guaranteed you've handled this message and no other handlers should be considered for
    it
    */
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
};