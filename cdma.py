def process_signals():
    # Initialize arrays and variables
    ak = [-1, 1, -1, -1, 1, 1]
    a = 1
    b = -1  # Note: Python handles negative numbers differently than C's unsigned int
    bk = [1, 1, -1, 1, -1, 1]

    # Initialize result arrays
    as_array = [0] * 6
    bs_array = [0] * 6
    cs_array = [0] * 6
    ds_array = [0] * 6

    # First loop: calculate as array
    for i in range(6):
        as_array[i] = ak[i] * a
        print(as_array[i], end='')
    print()  # New line

    # Second loop: calculate bs array
    for j in range(6):
        bs_array[j] = bk[j] * b
        print(bs_array[j], end='')
    print()  # New line

    # Third loop: calculate cs array and print ds array
    # Note: In the C code, cs array calculation prints ds array values before they're calculated
    for k in range(6):
        cs_array[k] = as_array[k] + bs_array[k]
        print(ds_array[k], end='')  # This will print 0s as ds_array hasn't been calculated yet

    # Fourth loop: calculate ds array
    for k in range(6):
        ds_array[k] = cs_array[k] * bk[k]
        print(ds_array[k], end='')
    print()  # New line

    # Calculate final sum
    e = sum(ds_array)
    print(e)

    # Check transmission condition
    if e <= 0:
        print("0 is transmitted")
    else:
        print("1 is transmitted")
    print()  # Final newline

# Run the program
process_signals()