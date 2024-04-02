#include <stdio.h>

int twoStacks(int maxSum, int n, int m, int a[], int b[]) {
    int count = 0, sum = 0, i = 0, j = 0;

    // Ambil elemen dari stack a sampai melebihi maxSum
    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
        count++;
    }

    int maxCount = count;

    // Coba tambahkan elemen dari stack b ke stack a
    while (j < m && i >= 0) {
        // Jika tambahan elemen dari stack b tidak memperbesar jumlah,
        // hapus elemen dari stack a dan update jumlah
        if (sum + b[j] > maxSum && i > 0) {
            i--;
            sum -= a[i];
            count--;
            continue;
        }

        sum += b[j];
        j++;
        count++;

        // Periksa apakah jumlah sekarang lebih besar dari jumlah maksimum sebelumnya
        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}

int main() {
    int g;
    scanf("%d", &g);

    for (int i = 0; i < g; i++) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int a[n], b[m];
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[j]);
        }

        int result = twoStacks(maxSum, n, m, a, b);
        printf("%d\n", result);
    }

    return 0;
}
