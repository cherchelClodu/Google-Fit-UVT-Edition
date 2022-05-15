#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

//matricile fiecarei activitati+dimensiuni
double walking[1000][5], running[1000][5], cycling[1000][5], swimming[1000][5];
int m, n;
//
long long repetitions;
double taim, distance, csspeed, steps, kcal;
//variabile specifice de afisat

int rep_w, rep_r, rep_c, rep_s;
//variabile de tinut minte nr repetari pt scriere

//initializare variabile repetari scriere
void startup()
{
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Walking.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<4; i++)
        {
            fscanf(fpointer, "%lf", &walking[rep_w][i]);
            if(i==0)
            {
                if(!feof(fpointer))
                    rep_w=walking[rep_w][i];
            }
        }
        fscanf(fpointer, "\n");
    }
    fclose(fpointer);

    fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Running.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<4; i++)
        {
            fscanf(fpointer, "%lf", &running[rep_r][i]);
            if(i==0)
            {
                if(!feof(fpointer))
                    rep_r=running[rep_r][i];
            }
        }
        fscanf(fpointer, "\n");
    }
    fclose(fpointer);

    fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Cycling.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<4; i++)
        {
            fscanf(fpointer, "%lf", &cycling[rep_c][i]);
            if(i==0)
            {
                if(!feof(fpointer))
                    rep_c=cycling[rep_c][i];
            }
        }
        fscanf(fpointer, "\n");
    }
    fclose(fpointer);

    fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Swimming.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<4; i++)
        {
            fscanf(fpointer, "%lf", &swimming[rep_s][i]);
            if(i==0)
            {
                if(!feof(fpointer))
                    rep_s=swimming[rep_s][i];
            }
        }
        fscanf(fpointer, "\n");
    }
    fclose(fpointer);
}

//scriere in fisiere
void walk_update(int tempo)
{
    srand(time(NULL));
    int dist;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Walking.txt", "a");
    rep_w++;
    dist=tempo*(75+rand()%50)/6;
    fprintf(fpointer,"%d %d %d %d\n", rep_w, tempo/60, dist/10000, dist/100*(rand()%20+20));
    fclose(fpointer);
}

void run_update(int tempo)
{
    srand(time(NULL));
    int dist;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Running.txt", "a");
    rep_r++;
    dist=tempo*(75+rand()%50)/3;
    fprintf(fpointer,"%d %d %d %d\n", rep_r, tempo/60, dist/10000, dist/100*(rand()%20+20));
    fclose(fpointer);
}

void cycle_update(int tempo)
{
    srand(time(NULL));
    int dist;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Cycling.txt", "a");
    rep_c++;
    dist=tempo*(75+rand()%50)*2/3;
    fprintf(fpointer,"%d %d %d %d\n", rep_c, tempo/60, dist/10000, dist/100/(tempo/36+1));
    fclose(fpointer);
}

void swim_update(int tempo)
{
    srand(time(NULL));
    int dist;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Swimming.txt", "a");
    rep_s++;
    dist=tempo*(75+rand()%50)/6;
    fprintf(fpointer,"%d %d %d %d\n", rep_s, tempo/60, dist/10000, dist/100/(tempo/36+1));
    fclose(fpointer);
}
//citirile din fisiere
void walk()
{
    m=0, n=4;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Walking.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<n; i++)
            fscanf(fpointer, "%lf", &walking[m][i]);
        fscanf(fpointer, "\n");
        m++;
    }
    fclose(fpointer);
    repetitions=(int)walking[m-1][0];
    taim=0, distance=0, steps=0;
    for(int i=0; i<m; i++)
    {
        taim+=walking[i][1];
        distance+=walking[i][2];
        steps+=walking[i][3];
    }
    taim/=repetitions;
    distance/=repetitions;
    steps/=repetitions;
}
void run()
{
    m=0, n=4;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Running.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<n; i++)
            fscanf(fpointer, "%lf", &running[m][i]);
        fscanf(fpointer, "\n");
        m++;
    }
    fclose(fpointer);
    repetitions=(int)running[m-1][0];
    taim=0, distance=0, kcal=0;
    for(int i=0; i<m; i++)
    {
        taim+=running[i][1];
        distance+=running[i][2];
        kcal+=running[i][3];
    }
    taim/=repetitions;
    distance/=repetitions;
    kcal/=repetitions;
}
void cycle()
{
    m=0, n=4;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Cycling.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<n; i++)
            fscanf(fpointer, "%lf", &cycling[m][i]);
        fscanf(fpointer, "\n");
        m++;
    }
    fclose(fpointer);

    repetitions=(int)cycling[m-1][0];
    taim=0, distance=0, csspeed=0;
    for(int i=0; i<m; i++)
    {
        taim+=cycling[i][1];
        distance+=cycling[i][2];
        csspeed+=cycling[i][3];
    }
    taim/=repetitions;
    distance/=repetitions;
    csspeed/=repetitions;
}
void swim()
{
    m=0, n=4;
    FILE * fpointer=fopen("D:\\projects\\c_c++\\proiect pp\\recordings\\Swimming.txt", "r");
    while(!feof(fpointer))
    {
        for(int i=0; i<n; i++)
            fscanf(fpointer, "%lf", &swimming[m][i]);
        fscanf(fpointer, "\n");
        m++;
    }
    fclose(fpointer);
    repetitions=(int)swimming[m-1][0];
    taim=0, distance=0, csspeed=0;
    for(int i=0; i<m; i++)
    {
        taim+=swimming[i][1];
        distance+=swimming[i][2];
        csspeed+=swimming[i][3];
    }
    taim/=repetitions;
    distance/=repetitions;
    csspeed/=repetitions;
}

void cooldown(int seconds)
{
    clock_t start = clock();
    clock_t period = seconds * CLOCKS_PER_SEC;
    clock_t elapsed;

    do
    {
        elapsed = clock() - start;
    }
    while(elapsed < period);
}

int main()
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    startup();
    int choice,choice_activity;
    char start_return, pause_stop;
    while(1)
    {
        //meniu smecher
        system("cls");

        //screen
        SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Google fit UVT edition"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=\n\n\n");
        printf("========================================================\n");
        SetConsoleTextAttribute(hc, 1); printf("1."); SetConsoleTextAttribute(hc, 7); printf(" ~~~~Record activity~~~~\n\n");
        SetConsoleTextAttribute(hc, 3); printf("2."); SetConsoleTextAttribute(hc, 7); printf(" ~~~~Show recent activity~~~~\n\n");
        SetConsoleTextAttribute(hc, 5); printf("3."); SetConsoleTextAttribute(hc, 7); printf(" ~~~~Exit~~~~\n");
        SetConsoleTextAttribute(hc, 2); printf("========================================================\n");
        SetConsoleTextAttribute(hc, 7); printf("Please insert what you want to do: ");
        //end of screen

        scanf("%d", &choice);//choice reading

        //variantele principale
        if(choice==1)
        {
            //activity recording
            system("cls");

            //screen
            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Record activity"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=\n\n\n");
            printf("=========================================================\n");
            SetConsoleTextAttribute(hc, 7); printf("Please select what type of workout you would like to do:\n");
            SetConsoleTextAttribute(hc, 1); printf("1."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Walking~~~\n\n");
            SetConsoleTextAttribute(hc, 3); printf("2."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Running~~~\n\n");
            SetConsoleTextAttribute(hc, 5); printf("3."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Cycling~~~\n\n");
            SetConsoleTextAttribute(hc, 6); printf("4."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Swimming~~~\n\n");
            printf("5. ~~~Go back~~~\n");
            SetConsoleTextAttribute(hc, 2); printf("==============================================================\n");
            SetConsoleTextAttribute(hc, 7);printf("Enter your choice: ");
            //end of screen

            scanf("%d", &choice_activity);//choice reading

            //optiuni workout pt inregistrare
            if(choice_activity==1)
            {
                system("cls");

                //screen
                SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Walking"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                SetConsoleTextAttribute(hc, 2); printf("======================"); SetConsoleTextAttribute(hc, 7); printf("Short Tutorial"); SetConsoleTextAttribute(hc, 2); printf("=======================\n\n");
                printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7);
                printf("To start press y. To go back press n.\n");
                printf("During the workout you will be able to see your time\n");
                printf("To pause the activity you can press any key\n");
                SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7); printf("Would you like to start? y/n\n");
                //end of screen

                scanf("%s",&start_return);//start or not activity

                //workout recording
                if(start_return=='y')
                {
                    int timp=0,x;
                    do
                    {
                        while(1)
                        {
                            system("cls");
                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Walking"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Recording...\n");
                            printf("Your time: ");
                            printf("%d:", timp/60);
                            if(timp%60<10)
                                printf("0");
                            printf("%d\n", timp%60);
                            SetConsoleTextAttribute(hc, 2); printf("===================="); SetConsoleTextAttribute(hc, 7); printf("press any key to pause"); SetConsoleTextAttribute(hc, 2); printf("=================\n");
                            //end of screen
                            cooldown(1);
                            timp++;
                            x=kbhit();
                            if(x)
                                break;
                        }
                        fflush(stdin);

                        system("cls");

                        //screen
                        SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Walking"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                        SetConsoleTextAttribute(hc, 7);
                        printf("Your time: ");
                        printf("%d:", timp/60);
                        if(timp%60<10)
                            printf("0");
                        printf("%d\n", timp%60);
                        printf("Paused. Press c to continue or s to stop.\n");
                        //end of screen

                        pause_stop='o';
                        while(pause_stop!='c' && pause_stop!='s')
                            scanf("%c", &pause_stop);

                        if(pause_stop=='c')
                            system("pause");

                        //stop
                        if(pause_stop=='s')
                        {
                            system("cls");

                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Walking"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Session ended. Press again to return to main menu.\n");
                            //end of screen

                            system("pause");
                            cooldown(1);
                        }

                    }
                    while(pause_stop!='s');
                    walk_update(timp);

                }

                //workout not recording
                if(start_return=='n')
                {
                    //screen
                    printf("Returning to main menu...\n");
                    //end of screen

                    cooldown(2);
                }
            }
            if(choice_activity==2)
            {
                system("cls");

                //screen
                SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Running"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                SetConsoleTextAttribute(hc, 2); printf("======================"); SetConsoleTextAttribute(hc, 7); printf("Short Tutorial"); SetConsoleTextAttribute(hc, 2); printf("=======================\n\n");
                printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7);
                printf("To start press y. To go back press n.\n");
                printf("During the workout you will be able to see your time\n");
                printf("To pause the activity you can press any key\n");
                SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7); printf("Would you like to start? y/n\n");
                //end of screen

                scanf("%s",&start_return);//start or not activity

                //workout recording
                if(start_return=='y')
                {
                    int timp=0,x;
                    do
                    {
                        while(1)
                        {
                            system("cls");
                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Running"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Recording...\n");
                            printf("Your time: ");
                            printf("%d:", timp/60);
                            if(timp%60<10)
                                printf("0");
                            printf("%d\n", timp%60);
                            SetConsoleTextAttribute(hc, 2); printf("===================="); SetConsoleTextAttribute(hc, 7); printf("press any key to pause"); SetConsoleTextAttribute(hc, 2); printf("=================\n");
                            //end of screen

                            cooldown(1);
                            timp++;
                            x=kbhit();
                            if(x)
                                break;
                        }
                        fflush(stdin);

                        system("cls");

                        //screen
                        SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Running"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                        SetConsoleTextAttribute(hc, 7);
                        printf("Your time: ");
                        printf("%d:", timp/60);
                        if(timp%60<10)
                            printf("0");
                        printf("%d\n", timp%60);
                        printf("Paused. Press c to continue or s to stop.\n");
                        //end of screen

                        pause_stop='o';
                        while(pause_stop!='c' && pause_stop!='s')
                            scanf("%c", &pause_stop);

                        if(pause_stop=='c')
                            system("pause");

                        //stop
                        if(pause_stop=='s')
                        {
                            system("cls");

                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Running"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Session ended. Press again to return to main menu.\n");
                            //end of screen

                            system("pause");
                            cooldown(1);
                        }

                    }
                    while(pause_stop!='s');
                    run_update(timp);
                }

                //workout not recording
                if(start_return=='n')
                {
                    //screen
                    printf("Returning to main menu...\n");
                    //end of screen

                    cooldown(2);
                }
            }
            if(choice_activity==3)
            {
                system("cls");

                //screen
                SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Cycling"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                SetConsoleTextAttribute(hc, 2); printf("======================"); SetConsoleTextAttribute(hc, 7); printf("Short Tutorial"); SetConsoleTextAttribute(hc, 2); printf("=======================\n\n");
                printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7);
                printf("To start press y. To go back press n.\n");
                printf("During the workout you will be able to see your time\n");
                printf("To pause the activity you can press any key\n");
                SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7); printf("Would you like to start? y/n\n");
                //end of screen

                scanf("%s",&start_return);//start or not activity

                //workout recording
                if(start_return=='y')
                {
                    int timp=0,x;
                    do
                    {
                        while(1)
                        {
                            system("cls");
                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Cycling"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Recording...\n");
                            printf("Your time: ");
                            printf("%d:", timp/60);
                            if(timp%60<10)
                                printf("0");
                            printf("%d\n", timp%60);
                            SetConsoleTextAttribute(hc, 2); printf("===================="); SetConsoleTextAttribute(hc, 7); printf("press any key to pause"); SetConsoleTextAttribute(hc, 2); printf("=================\n");
                            //end of screen

                            cooldown(1);
                            timp++;
                            x=kbhit();
                            if(x)
                                break;
                        }
                        fflush(stdin);

                        system("cls");

                        //screen
                        SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Cycling"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                        SetConsoleTextAttribute(hc, 7);
                        printf("Your time: ");
                        printf("%d:", timp/60);
                        if(timp%60<10)
                            printf("0");
                        printf("%d\n", timp%60);
                        printf("Paused. Press c to continue or s to stop.\n");
                        //end of screen

                        pause_stop='o';
                        while(pause_stop!='c' && pause_stop!='s')
                            scanf("%c", &pause_stop);

                        if(pause_stop=='c')
                            system("pause");

                        //stop
                        if(pause_stop=='s')
                        {
                            system("cls");

                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Cycling"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Session ended. Press again to return to main menu.\n");
                            //end of screen

                            system("pause");
                            cooldown(1);
                        }

                    }
                    while(pause_stop!='s');
                    cycle_update(timp);
                }

                //workout not recording
                if(start_return=='n')
                {
                    //screen
                    printf("Returning to main menu...\n");
                    //end of screen

                    cooldown(2);
                }
            }
            if(choice_activity==4)
            {
                system("cls");

                //screen
                SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Swimming"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                SetConsoleTextAttribute(hc, 2); printf("======================"); SetConsoleTextAttribute(hc, 7); printf("Short Tutorial"); SetConsoleTextAttribute(hc, 2); printf("=======================\n\n");
                printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7);
                printf("To start press y. To go back press n.\n");
                printf("During the workout you will be able to see your time\n");
                printf("To pause the activity you can press any key\n");
                SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                SetConsoleTextAttribute(hc, 7); printf("Would you like to start? y/n\n");
                //end of screen

                scanf("%s",&start_return);//start or not activity

                //workout recording
                if(start_return=='y')
                {
                    int timp=0,x;
                    do
                    {
                        while(1)
                        {
                            system("cls");
                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Swimming"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Recording...\n");
                            printf("Your time: ");
                            printf("%d:", timp/60);
                            if(timp%60<10)
                                printf("0");
                            printf("%d\n", timp%60);
                            SetConsoleTextAttribute(hc, 2); printf("===================="); SetConsoleTextAttribute(hc, 7); printf("press any key to pause"); SetConsoleTextAttribute(hc, 2); printf("=================\n");
                            //end of screen

                            cooldown(1);
                            timp++;
                            x=kbhit();
                            if(x)
                                break;
                        }
                        fflush(stdin);

                        system("cls");

                        //screen
                        SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Swimming"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                        SetConsoleTextAttribute(hc, 7);
                        printf("Your time: ");
                        printf("%d:", timp/60);
                        if(timp%60<10)
                            printf("0");
                        printf("%d\n", timp%60);
                        printf("Paused. Press c to continue or s to stop.\n");
                        //end of screen

                        pause_stop='o';
                        while(pause_stop!='c' && pause_stop!='s')
                            scanf("%c", &pause_stop);

                        if(pause_stop=='c')
                            system("pause");

                        //stop
                        if(pause_stop=='s')
                        {
                            system("cls");

                            //screen
                            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Swimming"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                            SetConsoleTextAttribute(hc, 7); printf("Session ended. Press again to return to main menu.\n");
                            //end of screen

                            system("pause");
                            cooldown(1);
                        }

                    }
                    while(pause_stop!='s');
                    swim_update(timp);
                }

                //workout not recording
                if(start_return=='n')
                {
                    //screen
                    printf("Returning to main menu...\n");
                    //end of screen

                    cooldown(2);
                }
            }
            if(choice_activity==5)
            {
                //screen
                printf("Returning to main menu...\n");
                //end of screen

                cooldown(1);
            }
        }
        else if(choice==2)
        {
            //activity report review
            system("cls");

            //screen
            SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Show recent activity"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=\n\n\n");
            printf("==============================================================\n");
            SetConsoleTextAttribute(hc, 7); printf("Please select the workout you would like to review:\n");
            SetConsoleTextAttribute(hc, 1); printf("1."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Walking~~~\n\n");
            SetConsoleTextAttribute(hc, 3); printf("2."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Running~~~\n\n");
            SetConsoleTextAttribute(hc, 5); printf("3."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Cycling~~~\n\n");
            SetConsoleTextAttribute(hc, 6); printf("4."); SetConsoleTextAttribute(hc, 7); printf(" ~~~Swimming~~~\n\n");
            printf("5. ~~~Go back~~~\n");
            SetConsoleTextAttribute(hc, 2); printf("==============================================================\n");
            SetConsoleTextAttribute(hc, 7);printf("Enter your choice: ");
            //end of screen

            scanf("%d", &choice_activity);//choice reading

            if(choice_activity==1)
            {
                walk();
                do
                {
                    system("cls");

                    //screen
                    SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Walking"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                    printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7);
                    printf("Your data:\n");
                    printf("Number of repetitions: %d\n", repetitions);
                    printf("Average time spent: %.2lf min\n", taim);
                    printf("Average distance: %.2lf km\n", distance);
                    printf("Average number of steps: %.0lf steps\n", steps);
                    SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7); printf("Go back? y/n\n");
                    //end of screen

                    scanf("%s", &start_return);

                    if(start_return=='y')
                    {
                        //screen
                        printf("Returning to main menu...\n");
                        //end of screen

                        cooldown(2);
                    }
                }
                while(start_return!='y');
            }
            if(choice_activity==2)
            {
                run();
                do
                {
                    system("cls");

                    //screen
                    SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Running"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                    printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7);
                    printf("Your data:\n");
                    printf("Number of repetitions: %d\n", repetitions);
                    printf("Average time spent: %.2lf min\n", taim);
                    printf("Average distance: %.2lf km\n", distance);
                    printf("Average kcal burnt: %.0lf kcal\n", kcal);
                    SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7); printf("Go back? y/n\n");
                    //end of screen

                    scanf("%s", &start_return);

                    if(start_return=='y')
                    {
                        //screen
                        printf("Returning to main menu...\n");
                        //end of screen

                        cooldown(2);
                    }
                }
                while(start_return!='y');
            }
            if(choice_activity==3)
            {
                cycle();
                do
                {
                    system("cls");

                    //screen
                    SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Cycling"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                    printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7);
                    printf("Your data:\n");
                    printf("Number of repetitions: %d\n", repetitions);
                    printf("Average time spent: %.2lf min\n", taim);
                    printf("Average distance: %.2lf km\n", distance);
                    printf("Average speed: %.2lf km/h\n", csspeed);
                    SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7); printf("Go back? y/n\n");
                    //end of screen

                    scanf("%s", &start_return);

                    if(start_return=='y')
                    {
                        //screen
                        printf("Returning to main menu...\n");
                        //end of screen

                        cooldown(2);
                    }
                }
                while(start_return!='y');
            }
            if(choice_activity==4)
            {
                swim();
                do
                {
                    system("cls");

                    //screen
                    SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~="); SetConsoleTextAttribute(hc, 4); printf("Swimming"); SetConsoleTextAttribute(hc, 2); printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n\n");
                    printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7);
                    printf("Your data:\n");
                    printf("Number of repetitions: %d\n", repetitions);
                    printf("Average time spent: %.2lf min\n", taim);
                    printf("Average distance: %.2lf km\n", distance);
                    printf("Average speed: %.2lf km/h\n", csspeed);
                    SetConsoleTextAttribute(hc, 2); printf("===========================================================\n");
                    SetConsoleTextAttribute(hc, 7); printf("Go back? y/n\n");
                    //end of screen

                    scanf("%s", &start_return);

                    if(start_return=='y')
                    {
                        //screen
                        printf("Returning to main menu...\n");
                        //end of screen

                        cooldown(2);
                    }
                }
                while(start_return!='y');
            }
            if(choice_activity==5)
            {
                //screen
                printf("Returning to main menu...\n");
                //end of screen

                cooldown(1);
            }
        }
        else if(choice==3)
        {
            //screen
            printf("Closing the app. Please wait...\n");
            //end of screen

            cooldown(3);
            return 0;
        }
        else if(choice>3 || choice<1)
        {
            printf("\n\nPlease enter a valid input\n\n");
            system("PAUSE");
        }
    }

    return 0;
}
