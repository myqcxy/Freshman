#include <stdlib.h> 
#include <graphics.h> 
#include <bios.h> 
#define mDRAW     5 
#define mLINE     6 
#define mADOWN    7 
#define mGEN      8 
#define mLEFT     75 
#define mRIGHT    77 
#define mSPACE    57 
#define mDOWN     80 
#define mESC      1 
#define TIMEINT   2 
#define MAXX      9 
#define MAXY   30 
#define BACKCOLOR BLACK 
#define WINX      50 
#define WINY      470 
#define GAP       6 
#define AREAX     (WINX+GAP) 
#define AREAY     (WINY-GAP) 
#define BOXW      15 

int oldarea[MAXY+1][MAXX]; 
int area[MAXY+1][MAXX]; 
int actW,actH,actX,actY; 
int curX,curY,curColor,curW,curH; 
int newX,newY,newColor,newW,newH; 
int active; 
int box[4][4]; 
int FORCOLOR; 
int MESSAGE; 
int BOX[7][4][4]={ 
 { 
  {1,1,1,1}, 
  {0,0,0,0}, 
  {0,0,0,0}, 
  {0,0,0,0} 
 },{ 
  {1,1,1,0}, 
  {1,0,0,0}, 
  {0,0,0,0}, 
  {0,0,0,0} 
 },{ 
  {1,1,1,0}, 
  {0,0,1,0}, 
  {0,0,0,0}, 
  {0,0,0,0} 
  
 },{ 
  {1,1,1,0}, 
  {0,1,0,0}, 
  {0,0,0,0}, 
  {0,0,0,0} 
 },{ 
  {1,1,0,0}, 
  {0,1,1,0}, 
  {0,0,0,0}, 
  {0,0,0,0} 
 },{ 
  {0,1,1,0}, 
  {1,1,0,0}, 
  {0,0,0,0}, 
  {0,0,0,0} 
 },{ 
  {1,1,0,0}, 
  {1,1,0,0}, 
  {0,0,0,0}, 
  {0,0,0,0} 
 } 
}; 

void init(); 
void draw(); 
int genBox(); 
int getKey(); 
void lineFull(); 
int moveLeft(); 
int moveRight(); 
int moveDown(); 
int rotate(); 
int getW(); 
int getH(); 
void clearOldBox(); 
void putNewBox(); 
int collisionRotate(int box[][4]); 
void getMessage(); 
void dispatchMessage(); 
int timeCome(); 
void fallDown(); 
int gameOver(); 

main() 
{ 
 int i; 
 init(); 
 do 
 { 
  getMessage(); 
  dispatchMessage(); 
 } 
 while(!gameOver()); 
 
 getch(); 
 closegraph(); 
} 

void getMessage() 
{ 
 if(MESSAGE) return; 
 if(timeCome()) 
 { 
  MESSAGE=mADOWN; 
  return; 
 } 
 if(bioskey(1)) 
 { 
  MESSAGE=bioskey(0)>>8; 
  return; 
 } 
} 

void dispatchMessage() 
{ 
 switch(MESSAGE) 
 { 
 case mLEFT:  moveLeft();break; 
 case mRIGHT: moveRight();break; 
 case mADOWN: moveDown();break; 
 case mSPACE: rotate();break; 
 case mDOWN:  fallDown(); break; 
 case mDRAW:  draw();break; 
 case mLINE:  lineFull();break; 
 case mGEN:   genBox();break; 
 case mESC:   closegraph(); exit(0); 
 default:     MESSAGE=0; 
 } 
} 

void fallDown() 
{ 
 while(active) 
 { 
  moveDown(); draw(); 
 } 
 
 MESSAGE=mLINE; 
} 

int timeCome() 
{ 
 
 static long tm, old; 
 tm=biostime(0,tm); 
 if(tm-old<TIMEINT) return 0; 
 else 
 { 
  old=tm; return 1; 
 } 
} 

void init() 
{ 
 int i,j,x1,y1,x2,y2; 
 int driver=DETECT, mode=0; 
 randomize(); 
 registerbgidriver(EGAVGA_driver); 
 initgraph(&driver,&mode,""); 
 cleardevice(); 
 setfillstyle(SOLID_FILL,BLUE); 
 bar(0,0,639,479); 
 x1=AREAX; 
 y1=AREAY-BOXW*MAXY; 
 x2=AREAX+MAXX*BOXW; 
 y2=AREAY; 
 rectangle(--x1,--y1,++x2,++y2); 
 setfillstyle(SOLID_FILL,BLACK); 
 bar(++x1,++y1,--x2,--y2); 
 y1=AREAY-MAXY*BOXW; y2=AREAY; 
 setcolor(DARKGRAY); 
 for(i=0;i<MAXX;i++) 
 { 
  x1=AREAX+i*BOXW; 
  line(x1,y1,x1,y2); 
 } 
 
 x1=AREAX; x2=x1+MAXX*BOXW; 
 for(j=0;j<MAXY;j++) 
 { 
  y1=AREAY-j*BOXW; 
  line(x1,y1,x2,y1); 
 } 
 for(j=0;j<MAXY;j++) 
  for(i=0;i<MAXX;i++) 
   area[j][i]=oldarea[j][i]=0; 
  actX=0; actY=0; actW=MAXX-1; actH=MAXY-1; 
  draw(); 
  MESSAGE=mGEN; 
} 

int genBox() 
{ 
 int i,j,boxidx; 
 boxidx=random(7); FORCOLOR=random(7)+1; 
 for(j=0;j<4;j++) 
  for(i=0;i<4;i++) 
   box[j][i]=BOX[boxidx][j][i]; 
  curW=getW(); curH=getH(); 
  curX=(MAXX+curW)/2; 
  if(curX+curW>=MAXX)curX=MAXX-1-curW; 
  curY=MAXY-1-curH; 
  newX=curX; newY=curY; actX=curX;actY=curY; 
  actW=newW=curW; actH=newH=curH; 
  active=1; 
  if(collision(box)) return 0; 
  putNewBox(); 
  draw(); MESSAGE=0; 
  return 1; 
} 

void lineFull() 
{ 
 int row,col, rowEnd,full,i,j; 
 rowEnd=newY+newH; 
 if(rowEnd>=MAXY-1) rowEnd=MAXY-2; 
 for(row=newY; row<=rowEnd;) 
 { 
  full=1; 
  for(col=0;col<MAXX;col++) 
   if(!area[row][col]){full=0; break;} 
   if(!full){++row; continue;} 
   for(j=row; j<MAXY-1;j++) 
    for(i=0;i<MAXX;i++) 
     area[j][i]=area[j+1][i]; 
    actX=0;actY=row; actW=MAXX-1; actH=MAXY-1-row; 
    draw(); rowEnd--; 
 } 
 MESSAGE=mGEN; 
} 

void draw() 
{ 
 int row,col,x1,y1,x2,y2; 
 for(row=actY;row<=actY+actH;row++) 
  for(col=actX;col<=actX+actW;col++) 
   if(area[row][col]!=oldarea[row][col]) 
   { 
    if(area[row][col]==0) 
     setfillstyle(SOLID_FILL,BACKCOLOR); 
    else 
     setfillstyle(SOLID_FILL,FORCOLOR); 
    
    x1=AREAX+col*BOXW; x2=x1+BOXW; 
    y1=AREAY-(row+1)*BOXW; y2=y1+BOXW; 
    bar(++x1,++y1,--x2,--y2); 
    oldarea[row][col]=area[row][col]; 
   } 
   
   MESSAGE=0; 
} 

int moveLeft() 
{ 
 newX=curX-1; clearOldBox(); 
 if(collision(box)) 
 { 
  newX=curX; 
  putNewBox(); 
  MESSAGE=0; 
  return 0; 
 } 
 putNewBox(); 
 actW=curW+1; actX=curX=newX; 
 MESSAGE=mDRAW; 
 return 1; 
} 

int moveRight() 
{ 
 newX=curX+1; clearOldBox(); 
 if(collision(box)) 
 { 
  newX=curX; 
  putNewBox(); 
  MESSAGE=0; 
  return 0; 
 } 
 putNewBox(); 
 actW=curW+1; actX=curX; curX=newX; 
 MESSAGE=mDRAW; 
 return 1; 
} 

int moveDown() 
{ 
 int i,j; 
 newY=curY-1; 
 clearOldBox(); 
 if(collision(box)) 
 { 
  newY=curY; 
  putNewBox(); 
  active=0; 
  MESSAGE=mLINE; 
  return 0; 
 } 
 putNewBox(); 
 actH=curH+1; actY=newY; curY=newY; 
 MESSAGE=mDRAW; 
 return 1; 
} 

int rotate() 
{ 
 int newBox[4][4]; 
 int i,j; 
 clearOldBox(); 
 
 for(j=0;j<4;j++) 
  for(i=0;i<4;i++) 
   newBox[j][i]=0; 
  
  for(j=0;j<4;j++) 
   for(i=0;i<4;i++) 
    newBox[curW-i][j]=box[j][i]; 
   newW=curH; newH=curW; 
   if(collisionRotate(newBox)) 
   { 
    newW=curW; newH=curH; newX=curX; newY=curY; 
    putNewBox(); 
    MESSAGE=0; 
    return 0; 
   } 
   
   for(j=0;j<4;j++) 
    for(i=0;i<4;i++) 
     box[j][i]=newBox[j][i]; 
    putNewBox(); 
    actH=newH>curH? newH:curH; 
    actW=curX+actH-newX; 
    actX=newX; actY=newY; curX=newX; 
    curY=newY; curW=newW; curH=newH; 
    MESSAGE=mDRAW; 
    return 1; 
} 

int getW() 
{ 
 int i,j; 
 for(i=3;i>0;i--) 
  for(j=0;j<4;j++) 
   if(box[j][i]) return i; 
   return 0; 
} 

int getH() 
{ 
 int i,j; 
 for(j=3;j>0;j--) 
  for(i=0;i<4;i++) 
   if(box[j][i]) return j; 
   return 0; 
} 

void clearOldBox() 
{ 
 int i,j; 
 for(j=0;j<=curH; j++) 
  for(i=0;i<=curW; i++) 
   if(box[j][i]) 
    area[curY+j][curX+i]=0; 
} 

void putNewBox() 
{ 
 int i,j; 
 for(j=0;j<=newH;j++) 
  for(i=0;i<=newW;i++) 
   if(box[j][i]) 
    area[newY+j][newX+i]=FORCOLOR; 
} 

int collision(int cbox[][4]) 
{ 
 int i,j; 
 if(newX<0) return 1; 
 if(newX+newW>=MAXX) return 1; 
 if(newY<0) return 1; 
 for(j=0;j<=newH;j++) 
  for(i=0;i<=newW;i++) 
   if(area[newY+j][newX+i]&&cbox[j][i]) return 1; 
   return 0; 
} 

int collisionRotate(int cbox[][4]) 
{ 
 int i,j; 
 if(newX+newW>=MAXX) newX=MAXX-1-newW; 
 if(newY+newH>=MAXY) newY=MAXY-1-newH; 
 if(collision(cbox)) return 1; 
 for(i=0;i<=newW;i++) 
  for(j=0;j<=newH;j++) 
   if(area[newY+j][newX+i]) 
   { 
    newX-=newW-i+1; goto L; 
   } 
L: return collision(cbox); 
} 

int gameOver() 
{ 
 if(!active &&(curY+curH>MAXY-3)) return 1; 
 else return 0; 
}