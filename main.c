#include <stdio.h>

struct process {
    int arrivalTime;
    int duration;
};

int main(){
    int qtdproc = 0, quantum = 0, proc = 0;
    int ftime = 0, rtime = 0, wtime = 0;
    int fexec = 0;
    int res = 0;
    int a1 = 0, a2 = 0;

    
    scanf("%d %d", &qtdproc, &quantum);
    struct process mainp[qtdproc + 1];
    int time[qtdproc + 1];

    

    for (int i = 0; i < qtdproc; i++){
        scanf("%d %d", &mainp[i].arrivalTime, &mainp[i].duration);
        time[i] = mainp[i].duration;
    }

    proc = qtdproc;

    for (int i = 0, fexec = 0; proc != 0;) {

        if(time[i] > 0 && time[i] <= quantum){
            fexec = fexec + time[i];
            time[i] = 0;
            a2 = 1;
        } else if (time[i] > 0){
            time[i] = time[i] - quantum;
            fexec = fexec + quantum;
            if (a1 == 1){
                res++;
                a1 = 0;
            }
        }

        if (a2 == 1 && time[i] == 0){
            proc--;
            wtime += fexec - mainp[i].duration - mainp[i].arrivalTime;
            ftime += fexec - mainp[i].arrivalTime;
            a2 = 0;
        }

        if(i == qtdproc - 1){
            i = 0;
            a1 = 1;
        } else if (mainp[i+1].arrivalTime <= fexec){
            i++;
        } else {
            i = 0;
        }
    }

    float avftime = 0, avrtime = 0, avwtime = 0;

    avftime = ftime * 1.0 / qtdproc;
    avwtime = wtime * 1.0 / qtdproc;
    avrtime = res * 1.0 / qtdproc;

    printf("RR %.1f %.1f %.1f\n", avftime + 1, avrtime, avwtime + 1);
    
    return 0;
                                                                    

}