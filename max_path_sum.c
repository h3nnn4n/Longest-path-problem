#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>

int __max_path_sum(int **m, int *visited, int *path, int n, int s, int t){
    if(s==t){
        int i, cost;
        cost = 0;

        i = t;
        while(i!=0){
            //printf("%d <- ",i);
            cost += m[path[i]][i];
            i = path[i];
        }
        //printf("0 = %d \n", cost);
        //printf("--------------\n");

        return cost;
    }else{
        int max, tmp, i;

        max = -1;
        tmp = -1;

        for(i = 0; i<n; i++){
            if(visited[i] == 0 && m[s][i] > 0){
                visited[i] = 1;
                path[i] = s;
                tmp = __max_path_sum(m, visited, path, n, i, t);
                if(tmp > max){
                    max = tmp;
                }
                visited[i] = 0;
            }
        }

        return max;
    }
}

int max_path_sum(int **m, int n, int s, int t){
    int *v = (int*)malloc(sizeof(int) * n);
    int *p = (int*)malloc(sizeof(int) * n);
    int i;

    for(i=0; i<n; i++){
        v[i] = 0;
        p[i] = -1;
    }

    v[s] = 1;

    return __max_path_sum(m, v, p, n, s, t);
}

int main(int argc, char *argv[]){
    int **m;
    int i, j, n;
    int a, b, w;

    if(argc == 1){
        scanf("%d", &n);
    }else{
        n = atoi(argv[1]);
        srand(time(NULL));
    }

    m = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++){
        m[i] = (int*)malloc(sizeof(int) * n);
    }

    if (argc == 1){
        w = 1;
        while(w > 0){
            scanf("%d %d %d", &a, &b, &w);
            if(a < n && b < n && w > 0){
                m[a][b] = w;
            }
        }
    }else if(argc == 2){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                m[i][j]= (i != j) ? rand()%20 : 0;
            }
        }
    }else if(argc == 3){
        w = atoi(argv[2]);
        while (w > 0){
            a = rand()%n;
            b = rand()%n;
            m[a][b]= (a != j) ? rand()%20 : 0;
            w--;
        }
    }

    time_t t = clock();

    int max_path = max_path_sum(m, n, 0, n-1);

    t = clock() - t;

    fprintf(stderr,"max = %d\n", max_path);
    printf("%f %d\n",(double)t/CLOCKS_PER_SEC,n);

    return EXIT_SUCCESS;
}
