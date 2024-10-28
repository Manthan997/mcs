def generate_sequence():
    # Initialize the array and variables
    t = [1, 0, 1, 0, 0]
    x1, x2, x3 = 0, 0, 0
    sequence = []

    # Generate sequence for 5 iterations
    for i in range(5):
        x1 = t[i]
        u1 = x1 ^ x2 ^ x3  # XOR of x1, x2, and x3
        u2 = x1 ^ x3       # XOR of x1 and x3

        # Append both u1 and u2 to match C code output
        sequence.append(str(u1))
        sequence.append(str(u2))

        # Shift the register values
        x3 = x2
        x2 = x1

    # Join and print the sequence as a single string
    result = ''.join(sequence)
    print("Sequence:", result)
    return result

# Generate and print the sequence
sequence = generate_sequence()