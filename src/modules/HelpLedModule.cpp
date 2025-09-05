#include "HelpLedModule.h"
#include "MeshService.h"
#include "NodeDB.h"
#include "PowerFSM.h"
#include "buzz.h"
#include "configuration.h"
#include "main.h"
#include <FastLED.h>
#include <algorithm>
#include <string>

// LED configuration
#define LED_DURATION_MS 5000 // LED will stay on for 5 seconds

HelpLedModule *helpLedModule;

// Constructor
HelpLedModule::HelpLedModule() : SinglePortModule("help_led", meshtastic_PortNum_TEXT_MESSAGE_APP) 
{
    // Nothing to initialize here since FastLED is initialized in main.cpp
}

ProcessMessage HelpLedModule::handleReceived(const meshtastic_MeshPacket &mp)
{
    // Get the message payload
    auto &p = mp.decoded;
    
    // Check if this is a text message
    if (p.portnum == meshtastic_PortNum_TEXT_MESSAGE_APP) {
        // Convert payload to string
        std::string msgStr((const char*)p.payload.bytes, p.payload.size);
        
        // Convert to lowercase for case-insensitive comparison
        std::string lowerMsg = msgStr;
        std::transform(lowerMsg.begin(), lowerMsg.end(), lowerMsg.begin(), ::tolower);
        
        // Check if the message contains the word "help"
        if (lowerMsg.find("help") != std::string::npos) {
            LOG_INFO("Help message received: %s", msgStr.c_str());
            
            // Turn on the LED
            leds[0] = CRGB::Red;
            FastLED.show();
            
            // Note: In a real implementation, we would set up a timer to turn off the LED
            // after LED_DURATION_MS. For now, we're just demonstrating the LED response.
        }
    }

    return ProcessMessage::CONTINUE; // Let others look at this message also if they want
}