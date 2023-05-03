from idnp import protocols
from idnp.capture import PcapReader

# Open the packet capture file
pcap_file = PcapReader('example.pcap')

# Loop through each packet in the file
for packet in pcap_file:

    # Identify the protocol used in the packet
    protocol = protocols.identify(packet)

    # Print the protocol name and metadata
    print('Protocol:', protocol.name)
    print('Metadata:', protocol.metadata)
