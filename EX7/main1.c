#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
    int n = 0;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);
    
    FILE *fp = fopen("lotto.txt", "w");
    
    time_t curtime;
    time(&curtime);
    char *time_str = ctime(&curtime);
    time_str[strcspn(time_str, "\n")] = '\0';

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    srand((unsigned)time(NULL));

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int num[7];
            int used[70] = {0};

            for (int j = 0; j < 7; j++) {
                int r;
                do {
                    r = (rand() % 69) + 1;
                } while (used[r] == 1);
                used[r] = 1;
                num[j] = r;
            }

            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d%s", num[j], (j == 6) ? "" : " ");
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
