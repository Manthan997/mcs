def generate_pn_sequence():
    # Initialize the shift register with the specified initial values
    x1, x2, x3, x4 = 1, 1, 0, 1  # equivalent to the binary input 1101
    sequence = []

    # Generate the PN sequence for 15 cycles
    for _ in range(15):
        # Calculate the feedback bit (u1) as XOR of x3 and x4
        u1 = x3 ^ x4

        # Only append u1 to match C code output (which only prints u1)
        sequence.append(str(u1))

        # Shift the register values
        x4, x3, x2, x1 = x3, x2, x1, u1

    # Join and print the sequence as a single string
    pn_sequence = ''.join(sequence)
    print("PN Sequence:", pn_sequence)
    return pn_sequence

# Generate and print the PN sequence
result = generate_pn_sequence()