/*
//  main.cpp
//  Sudoku solving program
//
//  Created by HongjunYun on 2019-03-08.
//  Copyright © 2019 HongjunYun. All rights reserved.
//
*/

#include <stdio.h>
#define N 9

struct sudoku{
    int value;
    int x_cor;
    int y_cor;
    bool empty=true;
    bool error=false;
    int candidate_cnt=-1;
    int candidate[N];
};

sudoku in[N][N];

int box_test(int x,int y);
int horizontal_line_test(int y);
int vertical_line_test(int x);

int main()
{
    char tmp;
    
    //input the original empty sudoku with N*N size
    //set the variables in the structure sudoku
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%c ",&tmp);
            in[i][j].x_cor=i;
            in[i][j].y_cor=j;
            if(tmp>='1'&&tmp<='9')
            {
                in[i][j].empty=false;
                in[i][j].value=tmp-'0';
                in[i][j].candidate_cnt=-1;
            }
            else if(tmp==' ')
            {
                in[i][j].empty=false;
                in[i][j].candidate_cnt=0;
            }
        }
    }//input & empty test & save cordinates of the location end
    
    //check function start
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i%3==0)
            {
                if(j%3==0)
                {
                    box_test(j, i);
                }
            }
            horizontal_line_test(i);
            vertical_line_test(j);
            
        }
    }//check function end
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(in[i][j].empty==false)
            {
                for(int k=0;k<N;k++)
                {
                    in[i][k].candidate[in[i][j].value-1]=0;
                    in[k][j].candidate[in[i][j].value-1]=0;
                    //need to add the box candidant deleting solution
                }
            }
        }
    }
    
}//main function end

int box_test(int x,int y)//box test starts
{
    int missing[N];//if missing array is 1, the number '(the number of array)+1' is missing
    
    for(int i=0;i<N;i++)
    {
        missing[i]=1;
    }
    for(int i=y;i<y+3;i++)
    {
        for(int j=x;j<x+3;j++)
        {
            if(in[i][j].empty==false)
            {
                missing[in[i][j].value-1]=0;
            }
        }
    }
    
    for(int i=y;i<y+3;i++)
    {
        for(int j=x;j<x+3;j++)
        {
            if(in[i][j].empty==true)
            {
                for(int k=0;k<N;k++)
                {
                    if(missing[k]==1)
                    {
                        in[i][j].candidate[k]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(in[y][i].empty==true)
        {
            for(int j=0;j<N;j++)
            {
                if(missing[j]==1)
                {
                    in[y][i].candidate[j]=1;
                }
            }
        }
    }
    
    return 0;
}//box test ends

int vertical_line_test(int x)//vertical line test starts
{
    int missing[N];//if missing array is 1, the number '(the number of array)+1' is missing
    
    for(int i=0;i<N;i++)
    {
        missing[i]=1;
    }
    for(int i=0;i<N;i++)
    {
        if(in[i][x].empty==false)
        {
            missing[in[i][x].value-1]=0;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(in[i][x].empty==true)
        {
            for(int j=0;j<N;j++)
            {
                if(missing[j]==1)
                {
                    in[i][x].candidate[j]=1;
                }
            }
        }
    }
    
    return 0;
}//vertical line test starts

int horizontal_line_test(int y)//horizontal line starts
{
    int missing[N];//if missing array is 1, the number '(the number of array)+1' is missing
    
    for(int i=0;i<N;i++)
    {
        missing[i]=1;
    }
    for(int i=0;i<N;i++)
    {
        if(in[y][i].empty==false)
        {
            missing[in[y][i].value-1]=0;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(in[y][i].empty==true)
        {
            for(int j=0;j<N;j++)
            {
                if(missing[j]==1)
                {
                    in[y][i].candidate[j]=1;
                }
            }
        }
    }
    
    return 0;
}//horizontal line ends
