#ARP Poisoning

## What is it

ARP (Address Resolution Protocol) poisoning is an attack where the attacker and the target are on the same network. ARP is a protocol that evaluates local ip addresses into MAC addresses
so when a machine wants to send a packet to an IP without knowing the MAC address that corresponds to it it broadcasts a request and the concerned machine sends a reply with its MAC address.
But in our case we exploit the fact that ARP is a stateless protocol (ie. it doesn't check if a reply has been requested before) so the attacker forges a reply pretending to be the router to the target.

## Step 1: Find the target's IP

![Alt text](../screens/18.png?raw=true "Demo")

## Step 2: Enable IP forwarding

Unless the machine is supposed to act as a router or a server IP forwarding is disabled by default on most distros.
So we have to enable it so that we can forward packets from the router to the target after intercepting them.

```
sudo sysctl net.ipv4.ip_forward = 1
```

![Alt text](../screens/19.png?raw=true "Demo")

## Step 3: Launch Ettercap

Launch ettercap with the command ```sudo ettercap -G``` and then set target 1 as the target's IP and target 2 as the router's IP and select the ARP poisoning attack.

If we go back to the targeted machine we can see that the attacker's IP and the router's IP have the same MAC address.

![Alt text](../screens/20.png?raw=true "Demo")

We can check the arp table with the command ```arp -a```

![Alt text](../screens/21.png?raw=true "Demo")

## Step 4: Sniffing packets with Wireshark

Set the filter to ```ip.addr == <target-IP>``` and start capturing.

![Alt text](../screens/22.png?raw=true "Demo")

![Alt text](../screens/23.png?raw=true "Demo")

![Alt text](../screens/24.png?raw=true "Demo")

You can see that as soon as the user supplies his credentials to a non https website the attacker intercepts them.