// >gcc -o ht-mcrl2-gen ht-mcrl2-gen.c

#include <stdio.h>
#include <stdlib.h>

char * help =
"Generates mcrl2 (https://mcrl2.org) model of a d-dimensional communication grid connected in a hypertorus\n"
"as described in http://wpmedia.wolfram.com/uploads/sites/13/2018/04/26-4-3.pdf, ports' buffers removed\n\n"
"USAGE: >ht-mcrl2-gen d k p b\n"
"d - number of dimensions, k - grid size, p - number of packets, b - buffer size, p<=b\n\n"
"(C) Jan Friso Groote & Dmitry Zaitsev & Tim Willemse, tue.nl\n";

// THE MODEL TEMPLATE: s1, s2, s3, s4, s5 - constant fragments and variable text in between of them
// generated either directly or using routines: gen_actions, gen_device, gen_init
// explanations are written in comments for d=3, k=3, p=1, b=2

char *s1 =
"\% A switched grid, d-dimensions, hypertorus\n";

/******************************************************************** insert:
% dimension d=3, size k=3, packets p=1, buffer size b=2
*/

char *s2 =
"\% (C) Jan Friso Groote & Dmitry Zaitsev & Tim Willemse, tue.nl\n"
"\% bXnY : sections of internal buffer, X - dimension number (from 1 to d), Y - direction number ({1,2})\n"
"\% bs : buffer size (in packets)\n"
"\% inXnY - input of a packet\n"
"\% outXnY - output of a packet\n"
"\% cX1nY1tX2nY2 - communication of neighbour devices\n"
"\n"
"act\n"
"\n";

/************************************************************ gen_actions(3):
  in1n1, out1n1, in1n2, out1n2,
  in2n1, out2n1, in2n2, out2n2,
  in3n1, out3n1, in3n2, out3n2,

  c1n1t1n2, c1n2t1n1,
  c2n1t2n2, c2n2t2n1,
  c3n1t3n2, c3n2t3n1
  :Nat#Nat#Nat;
*/

char *s3 =
"\n"
"map GridSize:Nat;\n";

/******************************************************************* insert:
eqn GridSize=3;
*/

char *s4 =
"map prev,next:Nat->Nat;\n"
"var n:Nat;\n"
"eqn prev(n)=if(n==1, GridSize, max(0,n-1));\n"
"    next(n)=if(n==GridSize, 1, n+1);\n"
"\n"
"proc\n"
"\n";

/************************************************************ gen_device(3): 
  d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2,bs:Int, i1,i2,i3:Nat)=
% output
    ((b1n1>0) -> out1n1(prev(i1),i2,i3).d(b1n1-1,b1n2,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3))+
    ((b1n2>0) -> out1n2(next(i1),i2,i3).d(b1n1,b1n2-1,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3))+

    ((b2n1>0) -> out2n1(i1,prev(i2),i3).d(b1n1,b1n2,b2n1-1,b2n2,b3n1,b3n2, bs, i1,i2,i3))+
    ((b2n2>0) -> out2n2(i1,next(i2),i3).d(b1n1,b1n2,b2n1,b2n2-1,b3n1,b3n2, bs, i1,i2,i3))+

    ((b3n1>0) -> out3n1(i1,i2,prev(i3)).d(b1n1,b1n2,b2n1,b2n2,b3n1-1,b3n2, bs, i1,i2,i3))+
    ((b3n2>0) -> out3n2(i1,i2,next(i3)).d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2-1, bs, i1,i2,i3))+
% input & switching (nondeterministic)
    ((b1n1+b1n2+b2n1+b2n2+b3n1+b3n2 < bs) -> (
% from port 1n1
      in1n1(i1,i2,i3).d(b1n1,b1n2+1,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in1n1(i1,i2,i3).d(b1n1,b1n2,b2n1+1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in1n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2+1,b3n1,b3n2, bs, i1,i2,i3)+
      in1n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1+1,b3n2, bs, i1,i2,i3)+
      in1n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2+1, bs, i1,i2,i3)+
% from port 1n2
      in1n2(i1,i2,i3).d(b1n1+1,b1n2,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in1n2(i1,i2,i3).d(b1n1,b1n2,b2n1+1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in1n2(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2+1,b3n1,b3n2, bs, i1,i2,i3)+
      in1n2(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1+1,b3n2, bs, i1,i2,i3)+
      in1n2(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2+1, bs, i1,i2,i3)+
% from port 2n1
      in2n1(i1,i2,i3).d(b1n1+1,b1n2,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in2n1(i1,i2,i3).d(b1n1,b1n2+1,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in2n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2+1,b3n1,b3n2, bs, i1,i2,i3)+
      in2n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1+1,b3n2, bs, i1,i2,i3)+
      in2n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2+1, bs, i1,i2,i3)+
% from port 2n2
      in2n2(i1,i2,i3).d(b1n1+1,b1n2,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in2n2(i1,i2,i3).d(b1n1,b1n2+1,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in2n2(i1,i2,i3).d(b1n1,b1n2,b2n1+1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in2n2(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1+1,b3n2, bs, i1,i2,i3)+
      in2n2(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2+1, bs, i1,i2,i3)+
% from port 3n1
      in3n1(i1,i2,i3).d(b1n1+1,b1n2,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in3n1(i1,i2,i3).d(b1n1,b1n2+1,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in3n1(i1,i2,i3).d(b1n1,b1n2,b2n1+1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in3n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2+1,b3n1,b3n2, bs, i1,i2,i3)+
      in3n1(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2+1, bs, i1,i2,i3)+
% from port 3n2
      in3n2(i1,i2,i3).d(b1n1+1,b1n2,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in3n2(i1,i2,i3).d(b1n1,b1n2+1,b2n1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in3n2(i1,i2,i3).d(b1n1,b1n2,b2n1+1,b2n2,b3n1,b3n2, bs, i1,i2,i3)+
      in3n2(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2+1,b3n1,b3n2, bs, i1,i2,i3)+
      in3n2(i1,i2,i3).d(b1n1,b1n2,b2n1,b2n2,b3n1+1,b3n2, bs, i1,i2,i3)
    ));
*/

/********************************************************** gen_init(3,3,1,2):
init

  allow({c1n1t1n2, c1n2t1n1,
         c2n1t2n2, c2n2t2n1,
         c3n1t3n2, c3n2t3n1},

  comm({out1n1|in1n2 -> c1n1t1n2,
        out1n2|in1n1 -> c1n2t1n1,
        out2n1|in2n2 -> c2n1t2n2, 
        out2n2|in2n1 -> c2n2t2n1,
        out3n1|in3n2 -> c3n1t3n2, 
        out3n2|in3n1 -> c3n2t3n1},

  d(1,0,0,0,0,0, 2, 1,1,1)||
  d(1,0,0,0,0,0, 2, 1,1,2)||
  d(1,0,0,0,0,0, 2, 1,1,3)||
  d(1,0,0,0,0,0, 2, 1,2,1)||
  d(1,0,0,0,0,0, 2, 1,2,2)||
  d(1,0,0,0,0,0, 2, 1,2,3)||
  d(1,0,0,0,0,0, 2, 1,3,1)||
  d(1,0,0,0,0,0, 2, 1,3,2)||
  d(1,0,0,0,0,0, 2, 1,3,3)||

  d(1,0,0,0,0,0, 2, 2,1,1)||
  d(1,0,0,0,0,0, 2, 2,1,2)||
  d(1,0,0,0,0,0, 2, 2,1,3)||
  d(1,0,0,0,0,0, 2, 2,2,1)||
  d(1,0,0,0,0,0, 2, 2,2,2)||
  d(1,0,0,0,0,0, 2, 2,2,3)||
  d(1,0,0,0,0,0, 2, 2,3,1)||
  d(1,0,0,0,0,0, 2, 2,3,2)||
  d(1,0,0,0,0,0, 2, 2,3,3)||

  d(1,0,0,0,0,0, 2, 3,1,1)||
  d(1,0,0,0,0,0, 2, 3,1,2)||
  d(1,0,0,0,0,0, 2, 3,1,3)||
  d(1,0,0,0,0,0, 2, 3,2,1)||
  d(1,0,0,0,0,0, 2, 3,2,2)||
  d(1,0,0,0,0,0, 2, 3,2,3)||
  d(1,0,0,0,0,0, 2, 3,3,1)||
  d(1,0,0,0,0,0, 2, 3,3,2)||
  d(1,0,0,0,0,0, 2, 3,3,3)));
*/

char *s5 =
"\n"
"\% end of model\n";

// end of THE MODEL TEMPLATE

void gen_actions(int d);
void gen_device(int d);
void gen_init(int d,int k,int p,int b);
#define reve(n) (((n)==2)?1:2)

int main(int argc, char * argv[])
{
  int d, k, p, b;
  if( argc < 5 )
  {
    puts( help );
    exit(2);
  }
  else { d = atoi( argv[1] ); k = atoi( argv[2] ); p = atoi( argv[3] ); b = atoi( argv[4] );}

  printf("%s",s1);

  printf("%s dimension d=%d, size k=%d, packets p=%d, buffer size b=%d\n","%",d,k,p,b);
  
  printf("%s",s2);

  gen_actions(d);

  printf("%s",s3);

  printf("eqn GridSize=%d;\n",k);

  printf("%s",s4);

  gen_device(d);
 
  gen_init(d,k,p,b);

  printf("%s",s5);

  return 0;
} /* main */


void gen_actions(int d)
{
  int j,n;

  for(j=1; j<=d; j++)
  {
    for(n=1; n<=2; n++)
      printf("in%dn%d,out%dn%d,",j,n,j,n);
    printf("\n");
  }
  printf("\n");

  for(j=1; j<=d; j++)
    printf("c%dn1t%dn2, c%dn2t%dn1%s",j,j,j,j,(j==d)?"\n":",\n");
  printf("\n");

  printf(":");  
  for(j=1; j<=d; j++)
    printf("Nat%s",(j==d)?";\n":"#");
} // gen_actions


void gen_device(int d)
{
  int j,j1,j2,n,n1,n2;

// d(b1n1,b1n2,b2n1,b2n2,b3n1,b3n2,bs:Int, i1,i2,i3:Nat)=
  printf("d(");
  for(j=1; j<=d; j++)
   for(n=1; n<=2; n++)
      printf("b%dn%d,",j,n);
  printf(" bs:Int, ");
  for(j=1; j<=d; j++)
    printf("i%d%s",j,(j==d)?"":",");
  printf(":Nat)=\n");
  
  printf("%c output\n", '%');
  
  for(j=1; j<=d; j++)
    for(n=1; n<=2; n++)
    {
      printf("((b%dn%d>0) -> out%dn%d(",j,n,j,n);
      for(j1=1; j1<=d; j1++)
        printf("%si%d%s%s",(j1==j)?((n==1)?"prev(":"next("):"",j1,(j1==j)?")":"",(j1==d)?"":",");
      printf(").d(");
      
      for(j1=1; j1<=d; j1++)
       for(n1=1; n1<=2; n1++)
        printf("b%dn%d%s,",j1,n1,(j1==j&&n1==n)?"-1":"");
      printf(" bs, ");
      for(j1=1; j1<=d; j1++)
        printf("i%d%s",j1,(j1==d)?"":",");
      printf("))+\n");
    }

  printf("%c input & switching (nondeterministic)\n", '%');
  printf("((");
  for(j=1; j<=d; j++)
   for(n=1; n<=2; n++)
      printf("b%dn%d%s",j,n,(j==d&&n==2)?"":"+");
  printf(" < bs) -> (\n");

  for(j=1; j<=d; j++)
    for(n=1; n<=2; n++)
    {
      printf("%c from port %dn%d\n", '%',j,n);
      for(j1=1; j1<=d; j1++)
        for(n1=1; n1<=2; n1++) 
        {
          if(j1==j&&n1==n) continue;
          printf("in%dn%d(",j,n);
          for(j2=1; j2<=d; j2++)
            printf("i%d%s",j2,(j2==d)?"":",");
          printf(").d(");
          for(j2=1; j2<=d; j2++)
            for(n2=1; n2<=2; n2++)
              printf("b%dn%d%s,",j2,n2,(j2==j1&&n2==n1)?"+1":"");
          printf(" bs, ");
          for(j2=1; j2<=d; j2++)
            printf("i%d%s",j2,(j2==d)?"":",");
          printf(")%s",(j==d&&n==2&j1==d&n1==1)?"\n":"+\n");
        }
    }

    printf("));\n\n");

} // gen_device


int next_cell(int *i, int d, int k)
{
  int j;

  for(j=d-1; j>=0; j--)
    if(i[j]<k){(i[j])++;return 1;}
    else{i[j]=1;}
  return 0;
} // next_cell

void gen_init(int d,int k,int p,int b)
{
  int j, j1, n, n1, go, *i;

  printf("init\n\nallow({");
  for(j=1; j<=d; j++)
    printf("c%dn1t%dn2,c%dn2t%dn1%s",j,j,j,j,(j==d)?"},\n":",");

  printf("comm({");
  for(j=1; j<=d; j++)
    for(n=1; n<=2; n++)
    {
      printf("out%dn%d|in%dn%d -> c%dn%dt%dn%d%s",j,n,j,reve(n),j,n,j,reve(n),(j==d&&n==2)?"},\n":",\n");
    }

  i=malloc(d*sizeof(int));
  for(j=1; j<=d; j++)i[j-1]=1;
  do
  {
    printf("d(");
    for(j1=1; j1<=d; j1++)
      for(n1=1; n1<=2; n1++)
        printf("%d,",(j1==1&&n1==1)?p:0);
    printf(" %d, ",b);
    for(j1=1; j1<=d; j1++)
      printf("%d%s",i[j1-1],(j1==d)?")":",");
    go=next_cell(i,d,k);
    printf("%s",(go)?"||\n":"));\n");
  }while(go);
  free(i);

} // gen_init

/*
The MIT License (MIT)

Copyright (c) 2018 Jan Friso Groote & Dmitry Zaitsev & Tim Willemse, tue.nl

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


