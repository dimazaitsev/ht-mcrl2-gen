
#include <stdio.h>
#include <stdlib.h>

char * HELP = "Generator of Petri net models of square grid with open edges\n"
              "No ports' buffers! Torus! \n"
              "Product of Dmitry Zaitsev member.acm.org/~daze\n\n"
              "USAGE: sqo k [p] [b] > pn_model.ndr\n"
              "  k - size of square grid,\n"
              "  p - number of packets in each buffer section,\n"
              "  b - available buffer size,\n"
              "  output format - .ndr file of Tina www.laas.fr/tina\n\n";


#define DI 600.0
#define DJ 600.0

#define next(k,x) (((x)<(k))?(x)+1:1)
#define prev(k,x) (((x)>1)?(x)-1:(k))

int main( int argc, char * argv[] )
{
 int k,i,j,p=0,b=0;
 
 if( argc < 2 )
 {
   fprintf(stderr,HELP);
   fprintf(stderr, "*** actually: %d arguments\n", argc);
   return 2;
 }
 
 k = atoi( argv[1] );
 if(argc>2) p = atoi( argv[2] );
 if(argc>3) b = atoi( argv[3] );

 /* generate connected communication devices */
 for(i=0; i<=k; i++)
   for(j=0; j<=k; j++)
   {
   	 /* generate nodes */
     if(i<k)
     {
       //printf("p %.1f %.1f {pol_1^%d.%d} 1 n\n",i*DI+280.0, j*DJ+50.0, j+1, i+1);
       //printf("p %.1f %.1f {pi_1^%d.%d} 0 n\n",i*DI+400.0, j*DJ+50.0, j+1, i+1);
       //printf("p %.1f %.1f {po_1^%d.%d} 0 n\n",i*DI+200.0, j*DJ+50.0, j+1, i+1);
       //printf("p %.1f %.1f {pil_1^%d.%d} 1 n\n",i*DI+480.0, j*DJ+50.0, j+1, i+1);
     }
     
     if(j<k)
     {
       //printf("p %.1f %.1f {pi_4^%d.%d} 0 n\n",i*DI+40.0, j*DJ+210.0, j+1, i+1);
       //printf("p %.1f %.1f {pil_4^%d.%d} 1 n\n",i*DI+40.0, j*DJ+290.0, j+1, i+1);
       //printf("p %.1f %.1f {po_4^%d.%d} 0 n\n",i*DI+40.0, j*DJ+410.0, j+1, i+1);
       //printf("p %.1f %.1f {pol_4^%d.%d} 1 n\n",i*DI+40.0, j*DJ+490.0, j+1, i+1);
     }

     if(i<k && j<k)
     {
       printf("p %.1f %.1f {pb_1^%d.%d} %d n\n",i*DI+340.0, j*DJ+230.0, j+1, i+1, p);
       printf("p %.1f %.1f {pb_2^%d.%d} %d n\n",i*DI+460.0, j*DJ+350.0, j+1, i+1, 0);
       printf("p %.1f %.1f {pb_3^%d.%d} %d n\n",i*DI+340.0, j*DJ+470.0, j+1, i+1, 0);
       printf("p %.1f %.1f {pb_4^%d.%d} %d n\n",i*DI+220.0, j*DJ+350.0, j+1, i+1, 0);
       printf("p %.1f %.1f {pbl^%d.%d} %d n\n",i*DI+340.0, j*DJ+350.0, j+1, i+1, b);

       //printf("t %.1f %.1f {to_1^%d.%d} 0 w n\n",i*DI+240.0, j*DJ+130.0, j+1, i+1);
       printf("t %.1f %.1f {ti_1,2^%d.%d} 0 w n\n",i*DI+380.0, j*DJ+130.0, j+1, i+1);
       printf("t %.1f %.1f {ti_1,3^%d.%d} 0 w n\n",i*DI+440.0, j*DJ+130.0, j+1, i+1);
       printf("t %.1f %.1f {ti_1,4^%d.%d} 0 w n\n",i*DI+500.0, j*DJ+130.0, j+1, i+1);
     
       //printf("t %.1f %.1f {to_2^%d.%d} 0 w n\n",i*DI+560.0, j*DJ+250.0, j+1, i+1);
       printf("t %.1f %.1f {ti_2,1^%d.%d} 0 w n\n",i*DI+560.0, j*DJ+510.0, j+1, i+1);
       printf("t %.1f %.1f {ti_2,3^%d.%d} 0 w n\n",i*DI+560.0, j*DJ+390.0, j+1, i+1);
       printf("t %.1f %.1f {ti_2,4^%d.%d} 0 w n\n",i*DI+560.0, j*DJ+450.0, j+1, i+1);
     
       //printf("t %.1f %.1f {to_3^%d.%d} 0 w n\n",i*DI+440.0, j*DJ+570.0, j+1, i+1);
       printf("t %.1f %.1f {ti_3,1^%d.%d} 0 w n\n",i*DI+240.0, j*DJ+570.0, j+1, i+1);
       printf("t %.1f %.1f {ti_3,2^%d.%d} 0 w n\n",i*DI+180.0, j*DJ+570.0, j+1, i+1);
       printf("t %.1f %.1f {ti_3,4^%d.%d} 0 w n\n",i*DI+300.0, j*DJ+570.0, j+1, i+1);
     
       //printf("t %.1f %.1f {to_4^%d.%d} 0 w n\n",i*DI+120.0, j*DJ+450.0, j+1, i+1);
       printf("t %.1f %.1f {ti_4,1^%d.%d} 0 w n\n",i*DI+120.0, j*DJ+310.0, j+1, i+1);
       printf("t %.1f %.1f {ti_4,2^%d.%d} 0 w n\n",i*DI+120.0, j*DJ+250.0, j+1, i+1);
       printf("t %.1f %.1f {ti_4,3^%d.%d} 0 w n\n",i*DI+120.0, j*DJ+190.0, j+1, i+1);
      
       /* generate arcs */
       //printf("e {to_1^%d.%d} {po_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pol_1^%d.%d} {to_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {to_1^%d.%d} {pbl^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pb_1^%d.%d} {to_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
//
           
       printf("e {ti_1,2^%d.%d} {pb_2^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pi_1^%d.%d} {ti_1,2^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {ti_1,2^%d.%d} {pil_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} 0.19867624 63.260881 {ti_1,2^%d.%d} 0.75 55.0 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_1,3^%d.%d} {pb_3^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pi_1^%d.%d} {ti_1,3^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {ti_1,3^%d.%d} {pil_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} {ti_1,3^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_1,4^%d.%d} 0.63117095 88.557635 {pb_4^%d.%d} 0.084458405 98.792865 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pi_1^%d.%d} {ti_1,4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {ti_1,4^%d.%d} {pil_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} {ti_1,4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       //printf("e {to_4^%d.%d} {po_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pol_4^%d.%d} {to_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pb_4^%d.%d} {to_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {to_4^%d.%d} {pbl^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_4,1^%d.%d} {pb_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pi_4^%d.%d} {ti_4,1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {ti_4,1^%d.%d} {pil_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} 0.44890717 63.383395 {ti_4,1^%d.%d} 0.0 60.14528 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_4,2^%d.%d} {pb_2^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {pi_4^%d.%d} {ti_4,2^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {ti_4,2^%d.%d} {pil_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} {ti_4,2^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_4,3^%d.%d} 0.88653944 99.384465 {pb_3^%d.%d} 0.3403722 130.47513 1 n\n",j+1, i+1,j+1, i+1);    
       //printf("e {pi_4^%d.%d} {ti_4,3^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {ti_4,3^%d.%d} {pil_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} {ti_4,3^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       //printf("e {pb_3^%d.%d} {to_3^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {to_3^%d.%d} {pbl^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_3,1^%d.%d} {pb_1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} {ti_3,1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_3,2^%d.%d} 0.14242383 96.137686 {pb_2^%d.%d} 0.58138495 91.956681 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} {ti_3,2^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_3,4^%d.%d} {pb_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} 0.70752689 57.018336 {ti_3,4^%d.%d} 0.26224811 65.192954 1 n\n",j+1, i+1,j+1, i+1);
     
       //printf("e {pb_2^%d.%d} {to_2^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       //printf("e {to_2^%d.%d} {pbl^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_2,1^%d.%d} 0.38108386 95.649137 {pb_1^%d.%d} 0.83907694 94.40404 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} {ti_2,1^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {ti_2,3^%d.%d} {pb_3^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {pbl^%d.%d} 0.94890719 63.383391 {ti_2,3^%d.%d} 0.5 60.14528 1 n\n",j+1, i+1,j+1, i+1);
     
       printf("e {pbl^%d.%d} {ti_2,4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
       printf("e {ti_2,4^%d.%d} {pb_4^%d.%d} 1 n\n",j+1, i+1,j+1, i+1);
     }   
   }
   
 /* generate remaining arcs */  
 for(i=0; i<=k; i++)
   for(j=0; j<=k; j++)
   {
     //new direct arcs
     if(i<k && j<k)
     {
       printf("e {pb_1^%d.%d} {ti_3,1^%d.%d} 1 n\n",j+1, i+1,prev(k,j+1), i+1);
       printf("e {ti_3,1^%d.%d} {pbl^%d.%d} 1 n\n",prev(k,j+1), i+1,j+1, i+1);
       printf("e {pb_1^%d.%d} {ti_3,2^%d.%d} 1 n\n",j+1, i+1,prev(k,j+1), i+1);
       printf("e {ti_3,2^%d.%d} {pbl^%d.%d} 1 n\n",prev(k,j+1), i+1,j+1, i+1);
       printf("e {pb_1^%d.%d} {ti_3,4^%d.%d} 1 n\n",j+1, i+1,prev(k,j+1), i+1);
       printf("e {ti_3,4^%d.%d} {pbl^%d.%d} 1 n\n",prev(k,j+1), i+1,j+1, i+1);

       printf("e {pb_3^%d.%d} {ti_1,2^%d.%d} 1 n\n",j+1, i+1,next(k,j+1), i+1);
       printf("e {ti_1,2^%d.%d} {pbl^%d.%d} 1 n\n",next(k,j+1), i+1,j+1, i+1);
       printf("e {pb_3^%d.%d} {ti_1,3^%d.%d} 1 n\n",j+1, i+1,next(k,j+1), i+1);
       printf("e {ti_1,3^%d.%d} {pbl^%d.%d} 1 n\n",next(k,j+1), i+1,j+1, i+1);
       printf("e {pb_3^%d.%d} {ti_1,4^%d.%d} 1 n\n",j+1, i+1,next(k,j+1), i+1);
       printf("e {ti_1,4^%d.%d} {pbl^%d.%d} 1 n\n",next(k,j+1), i+1,j+1, i+1);

       printf("e {pb_4^%d.%d} {ti_2,1^%d.%d} 1 n\n",j+1, i+1,j+1, prev(k,i+1));
       printf("e {ti_2,1^%d.%d} {pbl^%d.%d} 1 n\n",j+1, prev(k,i+1),j+1, i+1);
       printf("e {pb_4^%d.%d} {ti_2,3^%d.%d} 1 n\n",j+1, i+1,j+1, prev(k,i+1));
       printf("e {ti_2,3^%d.%d} {pbl^%d.%d} 1 n\n",j+1, prev(k,i+1),j+1, i+1);
       printf("e {pb_4^%d.%d} {ti_2,4^%d.%d} 1 n\n",j+1, i+1,j+1, prev(k,i+1));
       printf("e {ti_2,4^%d.%d} {pbl^%d.%d} 1 n\n",j+1, prev(k,i+1),j+1, i+1);

       printf("e {pb_2^%d.%d} {ti_4,1^%d.%d} 1 n\n",j+1, i+1,j+1, next(k,i+1));
       printf("e {ti_4,1^%d.%d} {pbl^%d.%d} 1 n\n",j+1, next(k,i+1),j+1, i+1);
       printf("e {pb_2^%d.%d} {ti_4,2^%d.%d} 1 n\n",j+1, i+1,j+1, next(k,i+1));
       printf("e {ti_4,2^%d.%d} {pbl^%d.%d} 1 n\n",j+1, next(k,i+1),j+1, i+1);
       printf("e {pb_2^%d.%d} {ti_4,3^%d.%d} 1 n\n",j+1, i+1,j+1, next(k,i+1));
       printf("e {ti_4,3^%d.%d} {pbl^%d.%d} 1 n\n",j+1, next(k,i+1),j+1, i+1);
     }
     if(j>0&&i<k)
     {
       //printf("e {to_3^%d.%d} {pi_1^%d.%d} 1 n\n",j, i+1,j+1, i+1);
       //printf("e {pil_1^%d.%d} {to_3^%d.%d} 1 n\n",j+1, i+1,j, i+1);
       
       //printf("e {po_1^%d.%d} {ti_3,1^%d.%d} 1 n\n",j+1, i+1,j, i+1);
       //printf("e {ti_3,1^%d.%d} {pol_1^%d.%d} 1 n\n",j, i+1,j+1, i+1);
     
       //printf("e {po_1^%d.%d} {ti_3,2^%d.%d} 1 n\n",j+1, i+1,j, i+1);
       //printf("e {ti_3,2^%d.%d} {pol_1^%d.%d} 1 n\n",j, i+1,j+1, i+1);
    
       //printf("e {po_1^%d.%d} {ti_3,4^%d.%d} 1 n\n",j+1, i+1,j, i+1);
       //printf("e {ti_3,4^%d.%d} {pol_1^%d.%d} 1 n\n",j, i+1,j+1, i+1);
     }    
     
     if(i>0&&j<k)
     {
       //printf("e {to_2^%d.%d} {pi_4^%d.%d} 1 n\n",j+1, i,j+1, i+1);
       //printf("e {pil_4^%d.%d} {to_2^%d.%d} 1 n\n",j+1, i+1,j+1, i);
     
       //printf("e {po_4^%d.%d} {ti_2,1^%d.%d} 1 n\n",j+1, i+1,j+1, i);
       //printf("e {ti_2,1^%d.%d} {pol_4^%d.%d} 1 n\n",j+1, i,j+1, i+1);
     
       //printf("e {po_4^%d.%d} {ti_2,3^%d.%d} 1 n\n",j+1, i+1,j+1, i);
       //printf("e {ti_2,3^%d.%d} {pol_4^%d.%d} 1 n\n",j+1, i,j+1, i+1);
     
       //printf("e {po_4^%d.%d} {ti_2,4^%d.%d} 1 n\n",j+1, i+1,j+1, i);
       //printf("e {ti_2,4^%d.%d} {pol_4^%d.%d} 1 n\n",j+1, i,j+1, i+1);
     }
   }
     
 printf("h {sqo-ndr%d}\n", k);  

} /* main */

/*
The MIT License (MIT)

Copyright (c) 2018 Dmitry Zaitsev

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

