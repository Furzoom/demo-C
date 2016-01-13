## command

### arp

* arp -a
    * BSD style output.
* arp -d *address*
    * Delete an ARP table entry.
* arp -s *address* *hd_addr*
    * Set up a new table entry.

### tcpdump

* tcpdump -i *interface*
    * Listen on interface.
* tcpdump -e
    * Print link-level header on each dump line.
* tcpdump -n
    * Do not convert host addresses to names, can avoid DNS lookups.
* tcpdump -t
    * Do not print the timestamp on each dump line.
* tcpdump -s *snaplen*
    * Snarf snaplen bytes of data from each package rather than the default 65535 bytes.
* tcpdump -x
    * When parsing or printing, in addition to printing the header of each packet, print the data of the packet (minus its link level header) in hex.
* tcpdump -xx
    * When parsing or printing, in addition to printing the header of each packet, print the data of the packet, including its link level header, in hex.
* tcpdump -X
    * When parsing or printing, in addition to printing the header of each packet, print the data of the packet (minux its link level header) in hex and ASCII.
* tcpdump -XX
    * When parsing or printing, in addition to printing the header of each packet, print the date of the packet, including its link level header, in hex and ASCII.

### host

* host -t *type* *name*
    * Query type, type can be A, CNAME etc..
