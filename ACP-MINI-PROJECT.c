#include<stdio.h>
char canvas[30][60];
int shapeType[100];
int sRow[100],sCol[100];
int sW[100],sH[100];
int shapeCount=0;
void initializeCanvas();
void clearCanvas();
void displayCanvas();
void drawLine(int row,int col,int length);
void drawRectangle(int row,int col,int width,int height);
void drawTriangle(int row,int col,int size);
void drawCircle(int centerX,int centerY,int radius);
void redrawAll();
void addShape();
void deleteShape();
void modifyShape();
void listShapes();
void saveDrawing();
void loadDrawing();
void initializeCanvas(){
    for(int i=0;i<30;i++){
        for(int j=0;j<60;j++){
            canvas[i][j]=' ';
        }
    }
}
void clearCanvas(){
    for(int i=0;i<30;i++){
        for(int j=0;j<60;j++){
            canvas[i][j]=' ';
        }
    }
}
void displayCanvas(){
    for(int i=0;i<30;i++){
        for(int j=0;j<60;j++){
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}
void drawLine(int row,int col,int length){
    for(int i=0;i<length;i++){
        canvas[row][col+i]='*';
    }
}
void drawRectangle(int row,int col,int width,int height){
    for(int i=0;i<width;i++){
        canvas[row][col+i]='*';
        canvas[row+height-1][col+i]='*';
    }
    for(int i=0;i<height;i++){
        canvas[row+i][col]='*';
        canvas[row+i][col+width-1]='*';
    }
}
void drawTriangle(int row,int col,int size){
    for(int i=0;i<size;i++){
        canvas[row+i][col]='*';
        canvas[row+size-1][col+i]='*';
        canvas[row+i][col+i]='*';
    }
}
void drawCircle(int centerX,int centerY,int radius){
    for(int i=0;i<30;i++){
        for(int j=0;j<60;j++){
            int dx=i-centerX;
            int dy=j-centerY;
            int d=dx*dx+dy*dy;
            if(d>=radius*radius-radius && d<=radius*radius+radius){
                canvas[i][j]='*';
            }
        }
    }
}
void redrawAll(){
    clearCanvas();
    for(int i=0;i<shapeCount;i++){
        if(shapeType[i]==1)
        drawLine(sRow[i],sCol[i],sW[i]);
        else if(shapeType[i]==2)
        drawRectangle(sRow[i],sCol[i],sW[i],sH[i]);
        else if(shapeType[i]==3)
        drawCircle(sRow[i],sCol[i],sW[i]);
        else if(shapeType[i]==4)
        drawTriangle(sRow[i],sCol[i],sW[i]);
    }
}
void listShapes(){
    if(shapeCount==0){
        printf("\n no shapes available\n");
        return;
    }
    printf("\n stored shape\n");
    for(int i=0;i<shapeCount;i++){
        printf("index %d -Type=%d Row=%d col=%d width=%d Height=%d\n",i,shapeType[i],sRow[i],sCol[i],sW[i],sH[i]);
    }
}
void addShape(){
    printf("\n--- ADD SHAPE _\n");
    printf("enter type(1-Line 2-Rectangle 3-Circle 4-Triangle):");
    scanf("%d",&shapeType[shapeCount]);
    printf("enter row col:");
    scanf("%d%d",&sRow[shapeCount],&sCol[shapeCount]);
    printf("enter width:");
    scanf("%d",&sW[shapeCount]);
    printf("enter height (0 if not needed):");
    scanf("%d",&sH[shapeCount]);
    shapeCount++;
    redrawAll();
    printf("shape Added\n");
}
void deleteShape(){
    int index;
    if(shapeCount==0){
        printf("no shape available to delete.\n");
        return;
    }
    listShapes();
    printf("Enter Shape index to delete:");
    scanf("%d",&index);
    if(index<0 || index>=shapeCount){
        printf("invalid index");
        return;
    }
    for(int i=index;i<shapeCount-1;i++){
        shapeType[i]=shapeType[i+1];
        sRow[i]=sRow[i+1];
        sCol[i]=sCol[i+1];
        sW[i]=sW[i+1];
        sH[i]=sH[i+1];
    }
    shapeCount--;
    redrawAll();
    printf("shape deleted\n");
}
void modifyShape(){
    int index;
    if(shapeCount==0){
        printf("no shapes available to modified\n");
        return;
    }
listShapes();
    printf("enter Shape index to modified");
    scanf("%d",&index);
    if(index<0 || index>=shapeCount){
        printf("invalid index\n");
        return;
    }
    printf("enter new type:");
    scanf("%d",&shapeType[index]);
    printf("enter new row col:");
    scanf("%d%d",&sRow[index],&sCol[index]);
    printf("new width");
    scanf("%d",&sW[index]);
    printf("enter new height");
    scanf("%d",&sH[index]);
    redrawAll();
    printf("shape Modified\n");
}
void saveDrawing(){
    FILE*fp=fopen("drawing.txt","w");
    if(fp==NULL){
        printf("error opening file\n");
        return;
    }
    for(int i=0;i<30;i++){
        for(int j=0;j<60;j++){
            fputc(canvas[i][j],fp);
        }
        fputc('\n',fp);
    }
    fclose(fp);
    printf("drawing saved to drawing.txt\n");
}
void loadDrawing(){
    FILE*fp=fopen("drawing.txt","r");
    if(fp==NULL){
        printf("drawing.txt not found\n");
        return;
    }
    for(int i=0;i<30;i++){
        for(int j=0;j<60;j++){
            canvas[i][j]=fgetc(fp);
        }
        fgetc(fp);
    }
    fclose(fp);
    printf("drawing loaded from drawing.txt\n");

}
int main()

{
   int choice;
   initializeCanvas();
   printf("\n=================================================================\n");
   printf("Project is made by Ranjan Ravindra Mamadapur SRN:R25EF212 CSE-D\n");
   printf("=================================================================\n");
   do{
    printf("\n===== 2D Graphics Editor =====\n");
    printf("1 Add Shape\n");
    printf("2 Display Canvas\n");
    printf("3 Delete Shape\n");
    printf("4 Modify Shape\n");
    printf("5 Clear Canvas\n");
    printf("6 List Shapes\n");
    printf("7 Exit\n");
    printf("8 Save Drawing\n");
    printf("9 Load Drawing\n");
    printf("Enter Choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        addShape();
        break;
        case 2:
        displayCanvas();
        break;
        case 3:
        deleteShape();
        break;
        case 4:
        modifyShape();
        break;
        case 5:
        clearCanvas();
        shapeCount=0;
        printf("Canvas Cleared\n");
        break;
        case 6:
        listShapes();
        break;
        case 7:
        printf("\n=================================================================\n");
        printf("  Thank you for using the 2D Graphics Editor! Exiting program...\n");
        printf("=================================================================\n");
        break;
        case 8:
        saveDrawing();
        break;
        case 9:
        loadDrawing();
        break;
        default:
        printf("Invalid Choice\n");
    }
   }
   while(choice!=7);
   return 0;
}