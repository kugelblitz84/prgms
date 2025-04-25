#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int width=20;
int height=20;
int i=0,j=0,x=0,y=0,padd=5,fruitx,fruity,movem,gameover,score=0;
int tailx[100],taily[100],tailcount=0;
//The border in which the game will be played.
void setup()
{
    x=width/2;//position of the snake heada
    y=height/2;
    gameover=1;
label1:
    fruitx=rand()%20;//fruits to be spawned randomly inside the height and width
    if(fruitx==0)
    {
        goto label1;
    }
label2:
    fruity=rand()%20;
    if(fruity==0)
    {
        goto label2;
    }
}
void input()//key inputs
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'w':
            movem=1;
            break;
        case 's':
            movem=2;
            break;
        case 'a':
            movem=3;
            break;
        case 'd':
            movem=4;
            break;
        case 'x':
            gameover=0;

        }
    }
}
void logic()
{
    int prevx1,prevy1,prevx2,prevy2;//tail logic using array and array exchaning
    prevx1=tailx[0];
    prevy1=taily[0];
    tailx[0]=x;
    taily[0]=y;
    for(int i=1; i<tailcount; i++)
    {
        prevx2=tailx[i];
        prevy2=taily[i];
        tailx[i]=prevx1;
        taily[i]=prevy1;
        prevx1=prevx2;
        prevy1=prevy2;
    }
    switch(movem)//movement after key input
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    }
    if(x<0||x>width||y<0||y>height)
    {
        gameover=0;
    }
    if(x==fruitx&&y==fruity)
    {
label3:
        fruitx=rand()%20;
        if(fruitx==0)
        {
            goto label3;
        }
label4:
        fruity=rand()%20;
        if(fruity==0)
        {
            goto label4;

        }
        score+=10;
        tailcount++;
    }
    for(int i=0;i<tailcount;i++){//if head touches tail then gameover
    if(x==tailx[i]&&y==taily[i]){
        gameover=0;
    }
}
}
void draw()
{
    system("cls");
   for(int i=0; i<padd; i++)
    {
        printf("\n");
        for(i=0; i<height; i++)
        {
            for(int i=0; i<padd; i++)
            {
                printf("  ");//Padding the sides.
            }
            for(j=0; j<width; j++)
            {
                if(i==0||i==height-1||j==0||j==width-1) //Drawing the border
                {
                    printf("\033[1;37m");//Colour
                    printf("!");
                }
                else
                {
                    if(i==x&&j==y)
                    {
                        printf("\033[1;34m");
                        printf("O");//Drawing head
                    }
                    else if(i==fruitx&&j==fruity)
                    {
                        printf("\033[1;33m");
                        printf("+");//Drawing fruit
                    }
                    else
                    {
                        printf("\033[1;34m");
                        int per=0;
                        for(int t=0; t<tailcount; t++)
                        {
                            if(i==tailx[t] && j==taily[t]){//Drawing the tail

                                printf("o");
                            per=1;
                            }
                        }
                        if(per==0)
                        {
                            printf(" ");
                        }
                    }


                }
            }
            printf("\n");
        }
    }
              printf("\033[1;36m");
    printf("Score: %d",score);//prints score
}//draw ends


int main()
{
    setup();
    while(gameover)
    {
        draw();

        input();
        logic();
        for(int i=0; i<10000; i++)
        {
            for(int j=0; j<9500; j++)
            {

            }

        }
    }
    printf("\nYour score is %d\nBy ***Md.qaiyum,nizam,riya,shubhon***",score);
}
