#ifndef IDNP_H
#define IDNP_H

// Define the maximum payload size for IDNP packets
#define IDNP_MAX_PAYLOAD_SIZE 1024

// Define the different types of IDNP packets
typedef enum {
  IDNP_PACKET_TYPE_DATA,
  IDNP_PACKET_TYPE_ACK,
  IDNP_PACKET_TYPE_NAK
} idnp_packet_type_t;

// Define the IDNP packet structure
typedef struct {
  uint32_t sequence_number;
  idnp_packet_type_t packet_type;
  uint16_t payload_size;
  char payload[IDNP_MAX_PAYLOAD_SIZE];
} idnp_packet_t;

#endif
