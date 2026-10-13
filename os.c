#include <stddef.h>
#include <stdio.h>

int main() {
    int n, m, i;
    int pages[20];
    int equal[20];
    int proportional[20];
    int totalPages = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the total number of available frames: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        printf("Enter the number of pages required by P%d: ", i + 1);
        scanf("%d", &pages[i]);
        totalPages += pages[i];
    }

    // Equal Allocation
    for (i = 0; i < n; i++) {
        equal[i] = m / n;
    }

    // Distribute any remaining frames
    for (i = 0; i < m % n; i++) {
        equal[i]++;
    }

    // Proportional Allocation
    int allocated = 0;

    for (i = 0; i < n; i++) {
        proportional[i] = (pages[i] * m) / totalPages;
        allocated += proportional[i];
    }

    // Distribute remaining frames based on fractional remainders
    while (allocated < m) {
        int maxIndex = 0;
        double maxRemainder = -1.0;

        for (i = 0; i < n; i++) {
            double remainder =
                ((double)pages[i] * m / totalPages)
                - proportional[i];

            if (remainder > maxRemainder) {
                maxRemainder = remainder;
                maxIndex = i;
            }
        }

        proportional[maxIndex]++;
        allocated++;
    }

    // Display results
    printf("\n--- Frame Allocation Results ---\n");
    printf("Process\tPages\tEqual Allocation\tProportional Allocation\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\n",
               i + 1, pages[i], equal[i], proportional[i]);
    }

    printf("\n--- Comparison ---\n");
    printf("Total Available Frames: %d\n", m);

    printf("Equal Allocation distributes frames as equally as possible.\n");
    printf("Proportional Allocation distributes frames based on process size.\n");

    return 0;
}