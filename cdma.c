// cdma
#include <stdio.h>

// Number of bits in the PN sequence
#define PN_LENGTH 7

// PN sequences for two users
int user1_PN[PN_LENGTH] = {1, -1, 1, 1, -1, 1, -1}; // Example PN code for user 1
int user2_PN[PN_LENGTH] = {1, 1, -1, 1, 1, -1, -1}; // Example PN code for user 2

// Function to spread the user data with the PN sequence
void spreadSignal(int dataBit, int *pnCode, int *spreadSignal) {
    for (int i = 0; i < PN_LENGTH; i++) {
        spreadSignal[i] = dataBit * pnCode[i];
    }
}

// Function to decode the signal using a PN sequence
int decodeSignal(int *receivedSignal, int *pnCode) {
    int sum = 0;
    for (int i = 0; i < PN_LENGTH; i++) {
        sum += receivedSignal[i] * pnCode[i];
    }
    return (sum > 0) ? 1 : 0; // Decode the bit as 1 if sum is positive, else 0
}

int main() {
    // Example data bits for each user (0 -> -1, 1 -> 1)
    int user1_data = 1;
    int user2_data = 0;

    int spreadSignal1[PN_LENGTH], spreadSignal2[PN_LENGTH];

    // Spread the data bits for each user
    spreadSignal((user1_data == 1) ? 1 : -1, user1_PN, spreadSignal1);
    spreadSignal((user2_data == 1) ? 1 : -1, user2_PN, spreadSignal2);

    // Superimpose the signals
    int combinedSignal[PN_LENGTH];
    for (int i = 0; i < PN_LENGTH; i++) {
        combinedSignal[i] = spreadSignal1[i] + spreadSignal2[i];
    }

    // Decode each user's data from the combined signal
    int decodedUser1 = decodeSignal(combinedSignal, user1_PN);
    int decodedUser2 = decodeSignal(combinedSignal, user2_PN);

    // Output the results
    printf("Combined Signal: ");
    for (int i = 0; i < PN_LENGTH; i++) {
        printf("%d ", combinedSignal[i]);
    }
    printf("\n");

    printf("Decoded User 1 Data: %d\n", decodedUser1);
    printf("Decoded User 2 Data: %d\n", decodedUser2);

    return 0;
}
