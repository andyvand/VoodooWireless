#!/bin/sh
kextunload /System/Library/Extensions/VoodooWirelessCipher.kext/Contents/PlugIns/VoodooWirelessCipher_WEP.kext
kextunload /System/Library/Extensions/VoodooWirelessCipher.kext
rm -rf /System/Library/Extensions/VoodooWirelessCipher.kext
cp -R build/Debug/VoodooWirelessCipher.kext /System/Library/Extensions
chown -R root:wheel /System/Library/Extensions/VoodooWirelessCipher.kext
chmod -R 755 /System/Library/Extensions/VoodooWirelessCipher.kext
