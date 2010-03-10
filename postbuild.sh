#!/bin/sh
kextunload /tmp/VoodooWireless.kext
rm -rf /tmp/VoodooWireless.kext
cp -Rv build/Debug/VoodooWireless.kext /tmp
chown -R root:wheel /tmp/VoodooWireless.kext
chmod -R 755 /tmp/VoodooWireless.kext
