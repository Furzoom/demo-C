## command

### arp

* arp -a
    * BSD style output
* arp -d *address*
    * delete an ARP table entry
* arp -s *address* *hd_addr*
    * set up a new table entry

### tcpdump

* tcpdump -i *interface*
    * listen on interface
* tcpdump -e
    * print link-level header on each dump line
* tcpdump -n
    * do not convert host addresses to names, can avoid DNS lookups
* tcpdump -t
    * do not print the timestamp on each dump line
