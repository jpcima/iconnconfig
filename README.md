# iconnconfig
**renamed, as not only mio devices are supported**

Linux based configuration utility for IConnectivity interfaces. (Currently only MIDI configuration is implemented on combined interfaces)
After trying to get the vendor provided config-utility to work under Wine without success I started analyzing the usb packets to write an Linux enabled version.
Later I found the complete documentation for sysex-data from IConnectivity.

## Implemented
* Device detection
* Global Configuration
  * Device Name
  * IP Configuration
* MIDI Configuration
  * MIDI Routing
 
## Tested Devices
* MIO 10
* iConnect Audio 4+

## Status
* (2017-03-12) nothing relevant done so far
* (2017-03-15) base structure done
* (2017-03-17) device recognition works
* (2017-03-24) initiate device communication
* (2017-04-03) start with parser for returned messages
* (2017-04-09) decision for docked layout as main GUI 
* (2017-04-12) implemented method to check if commands are available for specific device before trying to execute them
* (2017-05-13) only scan all ports if no devices are in config
* (2017-05-14) First working update of device data: Device name can be changed
* (2017-05-15) Read all information from first ethernet device
* (2017-05-20) Some GUI-infrastructure to check for valid ip addresses
* (2017-05-22) Update of method (static, dhcp) for IP-connection implemented (still struggling with verifying static IP-Adresses)
* (2017-06-01) Reading and Displaying the Midi port routings works
* (2017-06-04) Applied a patch from Ralf Beck to make it compile with qt 4.8
* (2017-06-06) Added methods to update port routings
* (2017-06-07) Save settings to device and restore settings from device works
* (2017-06-12) Saving of static IP-address, netmask and gateway works
* (2017-06-14) Release of version v0.1-beta
* (2017-06-19) Added some screenshots to the WIKI-Page https://github.com/dehnhardt/iconnconfig/wiki
* (2017-07-14) Added error handling with exceptions
* (2017-07-18) "About Box" added, credits to everyone...
* (2017-08-05) Translations, translations....
* (2017-08-12) Tested with iConnect Audio 4+: MIDI functionality works, audio is to come
* (2017-09-05) Enhanced error messages 
