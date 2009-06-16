#!/bin/sh
kextunload /tmp/VoodooIEEE80211.kext
rm -rf /tmp/VoodooIEEE80211.kext
cp -Rv build/Debug/VoodooIEEE80211.kext /tmp
chown -R root:wheel /tmp/VoodooIEEE80211.kext
chmod -R 755 /tmp/VoodooIEEE80211.kext
