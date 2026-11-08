*This project has been created as part of the 42 curriculum by anurmach.*

# NetPractice

## Description

NetPractice is a practical introduction to computer networking. The project consists of ten simulated network exercises in which incomplete or incorrect configurations must be fixed so that the required devices can communicate.

The goal is to understand how IPv4 networks operate and to apply that knowledge when assigning IP addresses, choosing subnet masks, configuring default gateways, and defining routes between networks.

No program has to be compiled for this project. The exercises are completed in a browser-based training interface, and the resulting configurations are exported for submission.

## Concepts Studied

- **TCP/IP addressing:** IPv4 addresses identify devices and networks. An IPv4 address contains a network part and a host part, determined by its subnet mask.
- **Subnet masks and CIDR notation:** Masks such as `255.255.255.0` or prefixes such as `/24` define the size and address range of a subnet.
- **Network and broadcast addresses:** The first address of a subnet identifies the network, while the last address is its broadcast address. Neither can be assigned to a host.
- **Default gateways:** A host sends packets to its default gateway when the destination is outside its local subnet.
- **Routing tables:** Routers use destination networks and next-hop gateways to forward packets. `0.0.0.0/0` represents the default route.
- **Routers:** Routers connect different IP networks and choose where packets should be forwarded.
- **Switches:** Switches connect devices inside the same local network. Unlike routers, they do not route traffic between different IP subnets.
- **OSI model:** The seven-layer model describes network communication from physical transmission to user-facing applications. NetPractice focuses mainly on Layer 3, the Network layer, where IP addressing and routing operate.

### Quick subnet reference

| CIDR | Subnet mask | Addresses per subnet | Usable host addresses |
| --- | --- | ---: | ---: |
| `/24` | `255.255.255.0` | 256 | 254 |
| `/25` | `255.255.255.128` | 128 | 126 |
| `/26` | `255.255.255.192` | 64 | 62 |
| `/27` | `255.255.255.224` | 32 | 30 |
| `/28` | `255.255.255.240` | 16 | 14 |
| `/29` | `255.255.255.248` | 8 | 6 |
| `/30` | `255.255.255.252` | 4 | 2 |

## Instructions

### 1. Start the training interface

Download the NetPractice files from the project page and extract them into a directory. From that directory, run:

```sh
./run.sh
```

If the script does not have execution permission, use:

```sh
bash run.sh
```

The script starts a local web server and opens the training interface in the default browser.

If `run.sh` does not work, start a local server manually:

```sh
python3 -m http.server 49242
```

Then open [http://localhost:49242](http://localhost:49242) in a web browser.

### 2. Load the exercises

Enter the login in the training interface to load the personal configuration. The **evaluation** tab may also be used to generate a random configuration for practice.

### 3. Solve each level

There are ten levels. For every level:

1. Read the communication objectives displayed at the top of the page.
2. Modify the editable IP addresses, subnet masks, gateways, and routes.
3. Select **Check again** to test the configuration.
4. Read the logs at the bottom of the page if the configuration fails. They indicate problems such as an invalid address, a missing route, or an incorrect gateway.
5. Once the level succeeds, select **Get my config** before moving to the next level.
6. Save the exported configuration file for submission.

## Submission

The repository root contains:

- this `README.md` file; and
- **10 exported configuration files, one for each of the 10 levels**.

## Resources

The following resources were used to study IPv4 addressing, subnetting, network devices, routing, default gateways, and the OSI/TCP-IP models:

- [Whiteboard Doodles — networking lessons](https://www.youtube.com/@WhiteboardDoodles24)
- [IP Addressing for Beginners — IPv4, IPv6, address classes, and public/private addresses](https://www.youtube.com/watch?v=aSZuzkC24XU&t=1066s)
- [Subnet Mask, CIDR, and Network ID](https://www.youtube.com/watch?v=qulRjRFavJI&t=47s)
- [Routers and Default Gateways](https://www.youtube.com/watch?v=JOomC1wFrbU)
- [Default Gateway Explained](https://www.youtube.com/watch?v=pCcJFdYNamc)
- [Network Devices Explained — routers, switches, hubs, and more](https://www.youtube.com/watch?v=MXr_cyY0BVc)
- [OSI and TCP/IP Models](https://www.youtube.com/watch?v=3b_TAYtzuho)

### Use of AI

AI was used as a study assistant for this project. It helped:

- clarify concepts such as subnet ranges, subnet masks, default gateways, and routing-table decisions;
- organize the README and improve its English wording;

